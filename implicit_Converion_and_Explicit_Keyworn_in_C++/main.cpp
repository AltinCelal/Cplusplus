#include<iostream>
/*
Derleyicinin otomatik yaptığı tür dönüşümleridir.
Programcı açıkca yazmak yerine derleyici otomatik yapar.
_______________________________________________________
                    Numeric Promotion

Küçük sayısal tiplerin daha büyük sayısal tiplere otomatik yükseltilmesidir.
C++’ta şu tipler integer promotion geçirir:

bool
char
signed char
unsigned char
short
unsigned short

Bu tipler aritmetik işlemde genellikle:

→ int

tipine yükseltilir.

ÖR:
char a = 10;
    char b = 20;

    auto result = a + b;

    cout << result << endl;


_______________________________________________________________________
        Usual Aritmatic Conversions(Standart aritmatik dönüşümler)

C++ da aritmatik işlemler sırasında farklı sayısal tipler bir araya gelirse:
iki operant tipini common type'a yükselterek işlemi güvenli biçimde yapar.

Operand’lardan biri floating point ise, diğeri floating point’e yükseltilir (numeric promotion dahil).

İkisi integer ise:

Küçük integer tipleri önce integer promotion geçer

Sonra signed/unsigned ve genişlik kurallarına göre common type seçilir.
int main() {
    int a = 5;
    double b = 2.5;

    auto result = a + b;

    std::cout << result << std::endl;

    result tipi double.

      float f = 3.5f;
    double d = 2.25;

    auto result = f + d;

    std::cout << result << std::endl;

    }
    Burada da result tipi double.


    Eğer biri unsigned ve diğer signed:

signed’ın range, unsigned’ı kapsayabiliyorsa signed tip kullanılır

aksi durumda operand’lar unsigned’a yükseltilir

Eğer tipler farklı genişlikte:

küçük tip promote edilir (char → int, short → int)

geniş olan tip result tipi olur


!!!!!!!!!!!!!!!!!!!!!ÖNEMLİ!!!!!!!!!!!!!!!!!!!!!!
int main() {
    int a = -2;               // signed
    unsigned int b = 1;       // unsigned

    auto result = a + b;
    cout << result << endl;
}
    Burada önemli bir nokta var.
    signed int a → unsigned int (signed → unsigned conversion)

result tipi: unsigned int

-2 + 1 → unsigned int olarak işlem görür → UINT_MAX değerine yakın olur
çıktı:4294967295 

-2 int e çevrilirken  4294967294 olarak çevrilir.çünkü tipi ilk bit belirler sadece ilk bit değişir.

Bu yüzden signed + unsigned karışımına çok dikkat etmek lazım.



KURAL:
char + char → int
short + short → int
int + unsigned int → unsigned int (overflow riski!)
float + double → double


_____________________________________________________________
Pointer Conversion:bir pointer tipinin başka bir pointer tipine implicit (otomatik) olarak dönüştürülmesidir.

Bu dönüşümler genellikle güvenli upcast veya standard conversion olarak tanımlanır.

Ama bazı durumlarda explicit cast gerekir.
Null Pointer Conversion

C++’ta en basit pointer conversion:

int* p = nullptr;   // nullptr → int* implicit
double* q = nullptr; // nullptr → double* implicit

nullptr her pointer tipine dönüşebilir.

C++’ta derived class pointer’ı base class pointer’a otomatik olarak dönüştürülebilir.

#include <iostream>
using namespace std;

struct Base { 
    void f() { cout << "Base\n"; } 
};

struct Derived : Base { 
    void g() { cout << "Derived\n"; } 
};

int main() {
    Derived d;
    Derived* dp = &d;

    Base* bp = dp; // Derived* → Base* implicit conversion

    bp->f(); // Base member çağrılır
}

ters yönde explicit cast gerekir.

C++’ta her object pointer türü void* pointer’ına implicit olarak dönüştürülebilir.

int x = 10;
int* p = &x;
void* vp = p; // int* → void* implicit

Ama ters yönde (void* → int*) implicit dönüşüm yok, explicit cast gerekir:


C++’ta function pointers da implicit olarak dönüşebilir.

void foo(int x) { cout << "foo: " << x << endl; }

int main() {
    void (*fptr)(int) = foo; // function name → pointer implicit conversion
    fptr(5);
}

____________________________________________________________
Conversion Constructor

Bir sınıfın tek parametreli constructor’ı varsa, C++ bunu implicit conversion için kullanabilir.
class A {
public:
    int x;
    // Conversion constructor
    A(int val) : x(val) { }
};

void print(A a) {
    std::cout << "x = " << a.x << std::endl;
}

int main() {
    print(42);  // int → A implicit conversion
}

________________________________________________________________-
                        EXPLICIT KEYWORD

C++’ta explicit keyword özellikle class type conversions konusuyla ilgilidir
ve istenmeyen implicit dönüşümleri engellemek için kullanılır.
*/
class A {
public:
    int x;
    // Conversion constructor
    explicit A(int val) : x(val) { }
};

void print(A a) {
    std::cout << "x = " << a.x << std::endl;
}




int main()
{

    /*int a = -2;               // signed
    unsigned int b = 1;       // unsigned

    auto result = a + b;
    std::cout << result << std::endl;
    
    print(42);*/
    //print(15);//Burada 15 otomatik olarak A nın nesnesine dönüştü
    //Bunu engellemek için explicit keyword ü kullanılır

    // A(int val) : x(val) { } constructor u bu şekilde değilde
    // explicit A(int val) : x(val) { } bu şekilde tanımlarsak implicit
    //dönüşümün önüne geçeriz
    //print(15); bu artık hata
    print(A(15));//bu şekilde çağırabiliriz.Explicit comversion
    return 0;
}