#include<iostream>
#include<memory>
/*
!memory kütüphanesini ekle!
Neden Smart Pointer a ihtiyaç var?

1-Manuel Memory Management Problemi.
New kullandıysa delete yi de kullanmak zorundasın.


2-Memory Leak
void foo()
{
    int* p = new int(5);
}

Fonksiyon bittiğinde:

p yok
ama heap'teki int hala duruyor


Exception durumlarında memory leak:
void foo()
{
    int* p = new int(5);

    throw runtime_error("error");

    delete p;
}
    throw çalışır
fonksiyon hemen çıkar
delete p çalışmaz


3-Double Delete problemi:
int* p = new int(5);

delete p;
delete p; Bu UB oluşturur.

4-Ownership Problemi:
int* create()
{
    return new int(5);
}

Kullanım:

int* p = create();

Soru:

delete kim yapacak?

create mi?

caller mı?

Belirsiz.

5- Pointer paylaşımı problemi:

int* p1 = new int(10);
int* p2 = p1;

Memory:

p1 de p2 de 10 u gösteriyor.
Sorular:

delete p1 mi?
delete p2 mi?
ikisi mi?

Yanlış yaparsan:

memory leak

double delete


Yukarıdaki tüm problemleri smart pointer çözer.
Smart pointer 3 şeyi garanti eder.
1-Automatic delete
Scope bitince otomatik delete edilir.Manuel yazmaya gerek yok.

2-Ownership modeli

Smart pointer türleri ownership belirler.

pointer	anlamı
unique_ptr	tek sahip
shared_ptr	paylaşılan sahip
weak_ptr	sahip değil

3-Exception Safety

Exception olsa bile destructor çalışır.

delete garanti

Smart pointer aslında şuna benzer:
class SmartPointer
{
    int* ptr;

public:

    SmartPointer(int* p)
    {
        ptr = p;
    }

    ~SmartPointer()
    {
        delete ptr;
    }
};
___________________________________________________________________________________
C++ da 3 tür smart pointer vardır.
1-unique_ptr(tek sahip, hızlı)
2-shared_ptr(birden fazla sahip)
3-weak_ptr(shared_ptr döngü sorununu çözer)


std::unique_ptr : Modern c++ da varsayılan smart pointerdır.
önce unique_ptr kullan gerekiyorsa shared_ptr kullan.
-En hızlısıdır
-En güvenlisidir.
-En basit ownership modeline sahip

-Sadece bir sahibi olabilir.
Yani aynı anda sedece tek pointer o objeyi yönetebilir.
    std::unique_ptr<int> p(new int(10));

    std::cout << *p << std::endl;
Program bitince:

~unique_ptr()
delete

Yani delete otomatik yapılır.

Modern kullanım:make_unique

modern C++ da std::unique_ptr<int> p(new int(10)); yazılmaz

Bunun yerine:

auto p = std::make_unique<int>(10);
Avantajları: 
Daha güvenli 
daha temiz
exceptio-safe

unique_ptr Memory Modeli
Stack               Heap
-----               ----
unique_ptr p  --->  [10]

Scope bitince:

p destructor
delete

Copy Yasak

unique_ptr kopyalanamaz.

Bu kod:

auto p1 = std::make_unique<int>(10);
auto p2 = p1;

Derleme hatası verir:

error: use of deleted function

Sebep:

2 sahip olamaz

Ownership Transfer (Move)

unique_ptr taşınabilir (move).

auto p1 = std::make_unique<int>(10);

auto p2 = std::move(p1);

Son durum:

p1 = nullptr
p2 -> int

Memory:

Stack

p1 -> null
p2 -> [10]

Örnek kod:
int main()
{
    auto p1 = std::make_unique<int>(10);

    auto p2 = std::move(p1);

    std::cout << *p2 << std::endl;
}
___________________________________________________________________________________
Fonksiyonlara unique_ptr Gönderme

3 farklı yöntem vardır.
(Ownership: Bir objeyi silme sorumluluğu kimde)
1- Ownership Transfer

Fonksiyon ownership alır.

void foo(std::unique_ptr<int> p)
{
    std::cout << *p << std::endl;
}
Bir objenin sahipliğinin değişmesi.
bir unique_ptr den başka unique_ptr e taşınmasıdır.

Kullanım:

auto p1 = std::make_unique<int>(10);

auto p2 = std::move(p1);

Son durum:

p1 → nullptr
p2 → objenin yeni sahibi

Önce:

p1 ─────> [10]
p2 ─────> (yok)

Sonra:

p1 ─────> null
p2 ─────> [10]
unique_ptr copy edilemediğinden move kullanıyoruz.
Bu yasak:

auto p2 = p1;  

Ama bu doğru:

auto p2 = std::move(p1);  

Örnek:
#include <iostream>
#include <memory>

void foo(std::unique_ptr<int> p)
{
    std::cout << *p << std::endl;
}

Çağırma:

auto p = std::make_unique<int>(10);

foo(std::move(p));
Ne oluyor?

Adım adım:

1 p oluşturuldu
p → [10]
2 std::move(p)
p → "ben artık owner değilim"
3 foo çağrılır
foo içindeki p → yeni owner
4 main’deki p
p → nullptr
5 foo biter
~unique_ptr → delete

Memory temizlenir.

___________________________________________________________________________________

2- Reference ile

Temel fikir:Ben sahipliği vermek istemiyorum, sadece kullanmak istiyorum.
Ownership değişmez.


void foo(const std::unique_ptr<int>& p)
{
    std::cout << *p << std::endl;
}

Kullanım:

foo(p);
ownership transfer YOK
copy YOK
aynı obje kullanılıyor

Memory:

main'deki p ───────┐
                   ├──> [10]
foo'daki p --------┘

reference = sahiplik değişmez

Yani:

delete hala main’deki p tarafından yapılır
foo sadece kullanır

peki dikkatinizi bir şey çekmiş olabilir burada const reference kullanıyoruz.
void foo(std::unique_ptr<int>& p)

ve

void foo(const std::unique_ptr<int>& p)

aynı şey DEĞİL.
Doğru kullanım (%90 senaryo)
void foo(const std::unique_ptr<int>& p)

Bu ne demek?

- ownership değişmez
- pointer değiştirilemez
- sadece okunur
Tehlikeli kullanım:
void foo(std::unique_ptr<int>& p)
{
    p.reset();   // 💣
}

Çağırma:

auto p = std::make_unique<int>(10);

foo(p);

Sonuç:

p silinir!

yani ownership değişmiyorsa const kullanmak mantıklı
___________________________________________________________________________________
3- Raw Pointer

void foo(int* p)
{
    std::cout << *p << std::endl;
}

Çağırma:

auto p = std::make_unique<int>(10);

foo(p.get());
get() Nedir?
p.get()

şunu yapar:

unique_ptr içindeki raw pointerı verir
ownership DEĞİŞMEZ

Memory Durumu
main:

unique_ptr p ───────┐
                    ├──> [10]
foo param p --------┘

raw pointer = ownership YOK

Yani:

foo delete ETMEMELİ
foo sadece kullanmalı

raw pointer aldıysan delete yapma
___________________________________________________________________________________
unique_ptr Array

Array için özel syntax var.

auto arr = std::make_unique<int[]>(5);

Stack                Heap
-----                ----
unique_ptr arr ---> [ ? ? ? ? ? ]

Scope bitince:

~unique_ptr → delete[]

otomatik olarak delete[] çağırılır

Kullanım:

arr[0] = 10;
arr[1] = 20;

Tam örnek:

#include <memory>
#include <iostream>

int main()
{
    auto arr = std::make_unique<int[]>(3);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    std::cout << arr[1];
}
-reset()Pointer'ı siler.

auto p = std::make_unique<int>(10);

p.reset();

Ne olur?

delete yapılır
p = nullptr

- release()Ownership bırakır.

auto p = std::make_unique<int>(10);

int* raw = p.release();

Sonuç:

p = nullptr
raw -> int

Ama dikkat:

delete artık sana ait

1-Ownership transfer
void foo(std::unique_ptr<int[]> arr)

Çağırma:

foo(std::move(arr));
2 Reference
void foo(const std::unique_ptr<int[]>& arr)
3 Raw pointer (EN yaygın)
void foo(int* arr)

Çağırma:

foo(arr.get());

Array Boyutu Problemi
Çok önemli:

auto arr = std::make_unique<int[]>(5);

Ama:

arr size bilgisini tutmaz
Yani:
sizeof(arr)  // işe yaramaz
Doğru kullanım:
size_t size = 5;

for (size_t i = 0; i < size; i++)
{
    arr[i] = i;
}


-get()
auto p = std::make_unique<int>(10);

int* raw = p.get();
Ne olur?
p hala owner
raw sadece adresi kopyalar

Memory:

p -----> [10]
raw ----^
En önemli nokta
delete hala p tarafından yapılır
Kullanım amacı

✔ sadece erişmek
✔ fonksiyona vermek
✔ ownership değiştirmemek

Örnek
void foo(int* p)
{
    std::cout << *p;
}

auto p = std::make_unique<int>(10);

foo(p.get());
get() ile yapılan büyük hata
int* raw = p.get();
delete raw;  

Sonuç:

double delete
-release() 
auto p = std::make_unique<int>(10);

int* raw = p.release();
Ne olur?
p = nullptr
raw = artık owner

Memory:

p ----> null
raw ---> [10]
En önemli fark
delete sorumluluğu sana geçer
Doğru kullanım
int* raw = p.release();

delete raw;  // artık sen sorumlusun
release() ile yapılan büyük hata
auto p = std::make_unique<int>(10);

int* raw = p.release();
// delete yok 
Sonuç:memory leak
___________________________________________________________________________________
shared_ptr:Bir objenin birden fazla sahibi olabilir.
auto p1 = std::make_shared<int>(10);
auto p2 = p1;

p1 ───┐
      ├──> [10]
p2 ───┘

shared_ptr içinde:

1. pointer
2. reference counter tutulur.

p1 ----┐
       ├----> [10]
p2 ----┘        ↑
                counter = 2

std::cout << p1.use_count();//çıktı 2

scope bitince otomatik olarak:
p1 gider → count = 1
p2 gider → count = 0 → delete

En büyük tehlikelerden biride Circular reference
class A;
class B;

class A {
public:
    std::shared_ptr<B> b;
};

class B {
public:
    std::shared_ptr<A> a;
};
A → B
B → A
count asla 0 olmaz
memory leak
bu sorunu çözmek içinse weak_ptr kullanılabilir.

yukarıda gördük reference count asla 0 olmuyordu bu döngüyü kırmak için weak_ptr kullanabiliriz.

weak_ptr:Sahibi olmayan smart pointer.Objeyi gösterir ama sahibi değildir.

Yukarıdaki sorunda pointerlardan biri weak pointer olursa sorun çözülebilir.

std::shared_ptr<int> sp = std::make_shared<int>(10);
std::weak_ptr<int> wp = sp;
Ne oldu?
wp → aynı objeyi gösteriyor
ama count artırmıyor
sp ─────> [10]
wp ─────> [10]
Ama count = 1

weak_ptr objenin hayatta olup olmadığı bilmediği için direk kullanıma izin vermez.
*wp hata yani
bu yüzden kullanmak için lock()var
Eğer obje yaşıyorsa->shared_ptr yi döndürür.
eğer obje silinmişse->nullptr döndürür.
örneği main içinde.

wp.expired()
obje silinmiş mi kontrol eder
if (wp.expired())
{
    std::cout << "deleted\n";
}

circular pointer sorununun çözümü:
class A {
public:
    std::shared_ptr<B> b;
};

class B {
public:
    std::weak_ptr<A> a;  
};

gerçek hayat örneği:
class Node
{
public:
    std::shared_ptr<Node> child;
    std::weak_ptr<Node> parent;
};
çocuk parent'ı sahiplenmemeli


ne zaman ne kullanılır?
Ownership varsa → smart pointer
Ownership yoksa → raw pointer / reference

İlk Soru (HER ZAMAN)

“Bu objenin sahibi kim?”

Cevap: “Tek bir yer”
std::unique_ptr

Cevap: “Birden fazla yer”
std::shared_ptr

Cevap: “Ben sahip değilim, sadece bakıyorum”
raw pointer veya reference

Cevap: “Döngü oluşabilir”
weak_ptr
*/
class B;

class A {
public:
    std::shared_ptr<B> b;

    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> a;

    ~B() { std::cout << "B destroyed\n"; }
};
int main()
{
    
    auto arr = std::make_unique<int[]>(5);
    std::cout<<sizeof(arr)<<std::endl;//çalıştı fakat 8 verdi.(32 bitlik sistemlerde 4 verecektir.)
    //deöndürdüğü cevap array in boyutu değil unique_ptr objesinin boyutunu verir
    /*
    Çünkü:

    auto arr = std::make_unique<int[]>(5);

    aslında:

    arr = unique_ptr<int[]>

    ve unique_ptr içinde:sadece bir pointer var
    Stack                Heap
    -----                ----
    arr (8 byte) -----> [ int int int int int ] 
    */

    auto p1 = std::make_shared<int>(10);
    auto p2 = p1;
    std::cout << p1.use_count()<<std::endl;//2
    p2.reset();
    std::cout << p1.use_count()<<std::endl;//1

    {
        auto a = std::make_shared<A>();
        auto b = std::make_shared<B>();
        a->b = b;
        b->a = a;
        /*
        a->b = b;
        b->a = a;
        bu satırlar olmasaydı çıktımız 
        B destroyed
        A destroyed
        lakin artık a objesinin içindeki b pointer ı b yi gösteriyor
        b objesinin içindeki a pointer ı da a objesini gösteriyor.
        yani:
        a gider → ama B hala A'yı tutuyor
        b gider → ama A hala B'yi tutuyor 
        */
    }

     std::weak_ptr<int> wp;

    {
        auto sp = std::make_shared<int>(42);
        wp = sp;

        if (auto temp = wp.lock())
        {
            std::cout << *temp << std::endl; // 42
        }
    }

    // sp burada yok edildi

    if (auto temp = wp.lock())
    {
        std::cout << *temp;
    }
    else
    {
        std::cout << "object destroyed\n";
    }/*Scope dışı:
    sp yok → count = 0 → delete
    wp hala pointer var ama obje yok*/
    return 0;
}