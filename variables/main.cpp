#include<iostream>
#include<stdint.h>


/*
Size of int : 4
Size of char : 1
Size of float : 4
Size of short : 2
Size of double : 8
Size of long : 8
Size of uint64_t : 8

*/
int main()
{
    int a = 15;
    char c = 'C';
    float f = 1.2f;
    double d ;
    long l;
    uint64_t ui6;
    short s ;


    std::cout<<"Size of int : "<<sizeof(a)<<std::endl;
    std::cout<<"Size of char : "<<sizeof(c)<<std::endl;
    std::cout<<"Size of float : "<<sizeof(f)<<std::endl;
    std::cout<<"Size of short : "<<sizeof(s)<<std::endl;
    std::cout<<"Size of double : "<<sizeof(d)<<std::endl;
    std::cout<<"Size of long : "<<sizeof(l)<<std::endl;
    std::cout<<"Size of uint64_t : "<<sizeof(ui6)<<std::endl;



    
}
/*

C++’ta implicit conversion (örtük dönüşüm)

C++’ta implicit dönüşümler hala vardır, ama:

Daha sınırlı

Bir kısmı uyarı veya hata üretir

2.1 Integer promotions (aynı C gibi)
char c = 10;
int i = c;   // OK


Kurallar:

char / short → int (veya unsigned int)

2.2 Usual arithmetic conversions (aritmetik işlemler)
Küçük → büyük (rank bazlı)
int i = 5;
double d = 2.5;

auto x = i + d;   // int → double


✔ Güvenli
✔ Veri kaybı yok

2.3 signed + unsigned (C++’ta DAHA TEHLİKELİ)
int i = -1;
unsigned int u = 10;

auto x = i + u;

Ne olur?

int ve unsigned int aynı rank

signed olan (int) → unsigned int’e dönüştürülür

-1 → 4294967295

 C++’ta bu davranış aynen C gibi, ama:

Overload seçimini

Template türünü

auto sonucunu

sessizce bozar

3️⃣ C++’ta NARROWING dönüşümler (çok kritik fark)
3.1 Atama ile (hala izinli)
double d = 3.7;
int i = d;   // mantıksal hata ama derlenir

3.2 Liste başlatmada {} YASAK 
int i{3.7};   // compile-time error


 C++11+ farkı
 Bilinçli güvenlik mekanizması

 Floating-point dönüşümleri (C++)
float f = 3.14;   // double → float (implicit, uyarı olabilir)
float g = 3.14f;  // OK

Overload farkı:
void foo(float);
void foo(double);

foo(3.14);   // foo(double)
foo(3.14f);  // foo(float)

Pointer dönüşümleri (C++ çok katı)
Dönüşüm	C	C++
void* → T*	implicit	 yasak
T* → void*	implicit	implicit
void* p = malloc(10);
int* ip = p;          //  C++ hata
int* ip2 = (int*)p;  // OK ama tehlikeli

 Explicit dönüşümler (cast) – C++ tarzı

C++’ta C-style cast yerine şunlar önerilir:

static_cast<int>(3.7);        // güvenli sayısal dönüşüm
reinterpret_cast<char*>(p);  // düşük seviye pointer cast
const_cast<char*>(str);      // const kaldırma


 Neden?

Ne yaptığını açıkça belli eder

Derleyici daha iyi uyarır

 signed ↔ unsigned: C++ için ALTIN KURAL 
if (x < vec.size())   //  vec.size() unsigned


Doğru:

if (x < static_cast<int>(vec.size()))


veya

size_t x;
if (x < vec.size())


 STL neredeyse her yerde size_t (unsigned) kullanır.

 Özet tablo (C++)
Dönüşüm	Durum
Küçük → büyük	implicit
signed → unsigned	 implicit ama tehlikeli
Büyük → küçük	 implicit
{} ile narrowing	 compile error
void* → T*	
Overload etkisi	 çok önemli

*/
