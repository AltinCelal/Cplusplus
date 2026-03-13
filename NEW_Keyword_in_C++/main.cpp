#include<iostream>
/*
Heap - dinamik bellek 
Programın çalışma sırasında istediği kadar bellek ayırabildiği alan.

Burada bellek manuel yönetilir.
Heap kullanmak için:
C++ da new
c de malloc kullanılır.

Boyutu runtime da belli olacaksa
Uzun süre yaşaması gerekiyorsa
Büyük verilerse(Stack e sığmayacak kadar)
New kullanılır.

Adress döndürür bu yüzden pointer da tutulur.
veriyi gösteren pointer stack de tutulur asıl veri 
heap dedir.

int* p = new int;
Heap de int kadar bellek ayırır.
adress döner
pointer da bu adresi tutar.

New ile ayrılan bellek delete ile manuel
olarak serbest bırakılmaz zorundadır yoksa memory leak.

pointer olmadan new kullanılmaz çünkü new adress döndürür.


C++ da new sadece bellek ayırmaz aynı zamanda kullanıldığında
constructor da çağırır.
delete komutu da sadece belleği boşaltmaz destructor uda çağırır.(örnek kodu aşağıda)

class Test
{
public:
    Test()
    {
        cout << "Constructor calisti\n";
    }
};
Test* t = new Test();


malloc vs new

Malloc: C dilinden gelir.
int* p = (int*)malloc(sizeof(int));
-Constructor çağırmaz.
-tip güvenliği yok
-void* döndürür


New: C++ için tasarlanmıştır.
-Constructor çağırır.
-type-safe
-cast gerekmez

new başarısız olursa new exeption fırlatır.

Yukarıda new in hem bellek ayırdığını hemde 
constructor çağırdığını söyledik.

Şimdide operator new konusu var.

Operatör New:Sadece bellek ayırır.Constructor ı çağırmaz.
void* memory = operator new(sizeof(int));
Heap'te 4 byte ayırır
ama int oluşturmaz


Test* t = new Test();
gerçekte olan
void* mem = operator new(sizeof(Test));
Test* t = new(mem) Test();
yukarıdaki kodlar aynı şeyi yapar.


şimdide Placement New

Normal new belleği kendisi ayırıç
Placement new ise var olan bellekte object oluşturur.

new(memory) Type(arguments)

char buffer[sizeof(int)];

int* p = new(buffer) int(10);
Bu embedded sistemlerde kullanılır.
placement new ile oluşturulan object için delete kullanılmaz 
sadece destructor çağrılır. 

operatör new overload edilebilir.Ben çok görmediğim için araştırmadım.

Aslında bunu bilerek sonda söyledim Modern C++ da new pek önerilmez
onun yerine smart pointer önerilir :)

Son olarak RAII((Resource Acquisition Is Initialization[C++ memory yönetiminin en önemli felsefesi]))
Resource constructor da alınır ,Destructor da bırakılır.
*/
class Test
{
public:
    Test()
    {
        std::cout << "Constructor calisti\n";
    }
    ~Test()
    {
        std::cout << "destructor calisti\n";
    }
};
int main()
{
    Test* t = new Test();//Constructor calisti çıktısı aldık.

    Test* t2 = (Test*)operator new(sizeof(Test));//Constructor calisti çıktısı ALMADIK.
    delete t;
    void* memory = operator new(sizeof(int));
    return 0;
}