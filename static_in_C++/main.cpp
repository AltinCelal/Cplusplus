#include<iostream>

/*
C++ da 4 farklı yerde kullanılır.
1->Foksiyon içinde 
void test(){
    int x = 0;
    x++;
    std::cout<< x <<std::endl;
}
yukarıdaki kodda test fonksiyonunu her çağırdığımızda 
x 0 dan başlar ve her çağrıda ekrana 1 yazdırır. 
her çağrıldığında değişken tekrar oluşturulur.

void test(){
    static int x = 0;
    x++;
    std::cout<< x << std::endl;
}
bu şekildeki kullanımda x değerini korur her çağrıldığında 
bir önceki değerinin 1 fazlasını ekrana yazdırır.
Bellekte sadece 1 kere oluşturulur(ilk çağrıldığında)
program bitene kadar bellekte yerini ve değerini korur

====================================================================
2-> Global değişkende static:
Sadece bulunduğu .cpp dosyası içinde görülür başka
.cpp dosyalarından erişilemez.
static int ival = 5;


======================================================

3-> Class içide static:
Normal member:
class A{
public:
    int x;
}

Yukarıdaki kodda her nesne için ayrı bir x oluşturulur.


static member:
class A{
public: 
    static int x;
}
x A sınıfından oluşturulan tüm nesneler için ortaktır.


============================================================
4->Static Fonksiyon (Class İçinde)
class Math {
public:
    static int topla(int a, int b) {
        return a + b;
    }
};


Kullanım:

cout << Math::topla(3, 4);


Önemli:

static fonksiyon this kullanamaz

Çünkü nesneye bağlı değildir


!!!!!!!!!!!!!!!!!!!!!!!!!
class içinde static olmayan fonksiyon nesne oluşturulmadan 
kullanılamaz sadece static fonksiyonlar nesne oluştrumadan kullanılabilir
çünkü nesneye bağlı değildir bellekte 1 tane vardır.
Aynı özellik static değişkenlerde de vardır.
!!!!!!!!!!!!!!!!!!!!!!!!!!



!!!!!!!!!!!!!!!!!!!!!1
Normal (Non-Static) Member Değişkenler
🔹 C++11 öncesi

Eskiden class içinde direkt initialize edemezdin:

class A {
public:
    int x = 5;  // eski C++'ta hata
};


Initialize etmek için constructor kullanılırdı:

class A {
public:
    int x;

    A() {
        x = 5;
    }
};

🔹 C++11 ve sonrası (Modern C++)

Artık class içinde direkt initialize edebilirsin:

class A {
public:
    int x = 5;
};


Bu özelliğe denir:

In-class member initializer

Çalışma Mantığı
class A {
public:
    int x = 5;
};

int main() {
    A a;
    cout << a.x;  // 5
}


Her nesne oluşturulduğunda x = 5 olur.

 Constructor Override Eder mi?

Evet

class A {
public:
    int x = 5;

    A() {
        x = 10;
    }
};


Sonuç:

10


Constructor içindeki atama, class içi initialize’ı ezer.

 Static Member Değişkenler

Burada iş biraz farklı.

🔹 C++11 öncesi

Class içinde initialize edemezsin:

class A {
public:
    static int x = 5;  //hata
};


Dışarıda tanımlaman gerekir:

int A::x = 5;

🔹 C++17 ile gelen özellik

Artık şöyle yazabilirsin:

class A {
public:
    inline static int x = 5;
};

Artık dışarıda tanım gerekmez.

Bu çok önemli bir modern C++ özelliği.
!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

struct Demo{

    int a = 5;
   
};
 void artir(Demo &d)
    {
        d.a++;
    }
struct Entity
{

    static int x,y;
    static void print()
    {
        std::cout<< x<<" , "<< y<<std::endl;
    }
};

int Entity::x;
int Entity::y;
int main()
{
    Entity e;
    e.x=1;
    e.y=2;
    /*Entity::x=1;
    Entity::y=2;
    Bu şekilde yazmak daha mantıklı çünkü nesneye bağlı değil
    sınıfa veya yapıya bağlı bir değişken(static olduğu için)
    */
    Entity e1;
    e1.x=56;
    e1.y=65;
    e.print();
    e1.print();



    Demo d;
    std::cout<<d.a<<std::endl;
    artir(d);
    std::cout<<d.a<<std::endl;
    return 0;
}
/*
Static bir metot static olmayan bir değişkene erişemez.!!! 
çünkü static metotlarda this pointer ı yoktur.Nesneye bağlı değildir.,

This pointer: Bir non-static üye fonksiyonun içinde, o fonksiyonun çağrıldığı nesnenin adresini tutan gizli pointer’dır.
class A {
public:
    int x;

    void set(int v) {
        x = v;
    }
};

Şunu yazdığında:

A a;
a.set(10);

Derleyici bunu aslında şöyle düşünür:

A::set(&a, 10);
Yani arka planda:

void set(A* this, int v)

gibi çalışır.

this = &a

Gerçekten Pointer mı?

Evet.

Tipi:

A* const this

Yani:

Pointer sabittir (başka nesneyi gösteremez)

Ama nesnenin içeriği değiştirilebilir (const değilse)
this Neden Var?

Çünkü class bir şablondur.

Birden fazla nesne olabilir:

A a1;
A a2;

a1.set(5)
a2.set(10)

Aynı fonksiyon çalışır ama:

İlkinde this = &a1

İkincisinde this = &a2

Bu yüzden method nesneye bağlanır.


Static Method'ta Neden Yok?

Static method:

static void foo();

Bu:

Sınıfa ait

Nesneye bağlı değil

this pointer’ı yok

Bu yüzden:

x = 5;  // HATA

Çünkü hangi nesne?

Neden this e ihtiyaç var?
this olmadan:

Aynı sınıftan birden fazla nesne olduğunda hangi nesne 
üzerinde işlem yaptığımızı bilemezdik.

class A {
public:
    int x;

    void set(int v) {
        x = v;
    }
};

Şimdi:

A a1;
A a2;

a1.set(5);
a2.set(10);

Soru:

set fonksiyonu nasıl biliyor hangi x’i değiştireceğini?

a1’in mi?

a2’nin mi?

İşte burada this devreye girer.

Derleyici Aslında Şunu Yapıyor

a1.set(5);

yazıyorsun ama derleyici şunu düşünüyor:

A::set(&a1, 5);

Yani gizlice şunu ekliyor:

void set(A* this, int v)

Bu yüzden:

x = v;

aslında:

this->x = v;

demektir.
*/
