#include<iostream>
/*
iyi bir fonksiyon için: 

1- single responsibility(tek bir iş yapsın)

2- kısa olmalı.

3-ismi anlamlı olmalı.

4-Yan etkileri minimum olmalı.

5-Aldığı parametre sayısı az olmalı.

6-Test edilebilir olmalı.

!!!Genel olarak yorum satırı olan kod kötü koddur!!!



konulara devam edilecek şimdilik burada kalsın.



===================FUNCTION OVERLOADING================

Aynı isimde birden fazla fonksiyonu farklı parametre listereliyle
tanımlanmasıdır.

void print(int);
void print(double);
void print(const std::string&);

C++ da var C de yok.

Overload imzası (signature) nedir?

Bir fonksiyonun overload imzası şunlardan oluşur:

 Fonksiyon adı
 Parametre sayısı
 Parametre türleri
 Return type dahil değildir

 Geçersiz overload
int  f(int);
double f(int); 


Neden?

f(10);


Derleyici:

“Hangi return type’ı seçeceğim?”

Return type çağrıdan önce bilinmez.

2-Overloading nasıl mümkün oluyor? (name mangling)

C++ derleyicisi kaynak kodu doğrudan link etmez.
Fonksiyon isimlerini benzersiz sembollere çevirir.

void f(int);
void f(double);


g++ yaklaşık olarak şuna çevirir:

_Z1fi
_Z1fd


Yani:

Aynı isim

Ama binary seviyesinde farklı semboller

İşte bu yüzden:

C++’ta overloading var

C’de yok


Derleyici overload seçimini nasıl yapar? (yüksek seviye)

Derleyici 3 aşamalı bir süreç izler:

1. Candidate functions

İsmi uyan tüm fonksiyonlar

2. Viable functions

Argüman sayısı uyanlar

3. Best viable function

En az dönüşüm gerektiren

Dönüşüm öncelikleri (ÇOK ÖNEMLİ)

Derleyici şu sıraya göre karar verir:

4.1 En iyi (no conversion)
void f(int);
f(10);   // TAM EŞLEŞME

4.2 Promotion
void f(int);
f('a');  // char → int (promotion)

4.3 Standard conversion
void f(double);
f(10);   // int → double

4.4 User-defined conversion
struct A {
    A(int);
};

void f(A);
f(10);   // int → A

Ambiguous overload (en sık hata)
void f(long);
void f(double);

f(10);   // ambiguous


Neden?

int → long

int → double

İkisi de aynı seviye dönüşüm.

6.1 Parametrede const fark yaratmaz
void f(int);
void f(const int); // aynı imza

6.2 Reference + const fark yaratır
void f(int&);
void f(const int&);

int a = 10;
const int b = 20;

f(a); // int&
f(b); // const int&


Bu çok kullanılan bir tekniktir

Pointer vs reference overload
void f(int*);
void f(int&);

int x;
f(x);   // int&
f(&x);  // int*


Net ve güvenli.


En kritik overload kuralları (ezber)

Return type overload’a dahil değildir

const parametre fark yaratmaz (value için)

Reference + const overload yaratır

En az dönüşüm kazanan olur

Ambiguity = compile error
*/
void f(int a)
{
    a++;
    std::cout<<a<<std::endl;

}
void f(const int a)
{
  
    std::cout<<a<<std::endl;
}

int main()
{
    int c = 5;
    f(c);
}
//ASAGISI YUKARIDAKILERIN BENZERI VEYA AYNI BILGILERI ICERIR


/*
Overload Signature: Derleyicinin iki fonksiyonu aynı mı yoksa 
farklı mı olduğuna karar verirken kullandığı kimlik bilgisi

Dahil olanlar

Fonksiyon adı

Parametre sayısı

Parametre türleri

Parametrelerin sırası

(Member fonksiyonlarda) const / ref-qualifier (&, &&)


Dahil olmayanlar

Return type

Parametre isimleri

Default argument’ler

typedef / using isimleri
=================================================================
overload olmayanlar

int    f(int);
double f(int);
(return type farklı olması önemli değildir.)



void f(int x);
void f(int y);
(parametre isimleri farklı olması da önemli değildir.)


void f(int);
void f(const int);
(ikisi de aynı fonskiyon)




===================================================
void f(int&);
void f(const int&);

Signature’lar farklı:burada overloading geçerli


!!!Aynı fonksiyon birden fazla kez declare edilebilir
ama sadece bir kez define edilmek zorunda!!!




OVERLOAD RESOLUTION
Bir fonksiyon çağrısında mevcut overload lar arasında
hangisinin çağrılacağını seçme süreci

bunu 3 adımda yapar.


ADIM 1: Candidade functions
Ismi uyan tüm fonksiyonalr


ADIM 2:Viable functions 
Argüman sayısı 


ADIM 3:Best viable function
Sönüşüm maliyeti düşük olanlar


Eğer bu 3 adımda da eşitlik varsa :AMBIGUOUS->Compiler error.


Kısaca Kontrol Flow

break

Döngüyü veya switch’i bitirir

while (true) {
    if (x == 0)
        break;
}




continue

Döngünün bir iterasyonunu atlar

for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0)
        continue;
    cout << i;
}
*/