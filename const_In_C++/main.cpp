#include<iostream>
#include<string>
/*
const: Bir değerin değiştirilemeyeceğini belirtir
sadece okunabilir değiştirilemez.

3 ana sebeple kullanılır.
1-Yanlışlıkla değiştirilmeyi önlemek için
2-Kodun güvenilirliği için(1. sebepten kaynaklı)
3-Bazen daha iyi öptimize edilir.


tanımlanırken değer verilmeli!.

pointer ile kullanımda 3 farklı anlama gelebilir.
1-> Pointer sabir olabilir.
int * const ptr = &x; burada pointer sabit
ama gösterdiği değer değişebilir yani:
*ptr=15; olabilir ama
ptr = &y; olamaz 
  

2->pointer ın gösterdiği değer sabit olabilir.
const int* ptr = &x;
burada 
*ptr = 185; hata ama
ptr = &y; olabilir


3->Her ikisi de sabit olabilir.
const int* const ptr = &x;
hem göstediği adres hem de değer sabit değiştirilemez.

ALTIN KURAL:    
const kendisinin solundaki şeyi sabit yapar eğer solunda 
bir şey yoksa sağındakini sabit yapar.



int ival = 15;
const int& ref = ival;

//burada hata oluşur const dan dolayı ref = 20;
//fakat ival = 20 yapabiliriz.
ival = 20;
std::cout<<ref<<std::endl;


2 farklı kullanım alanı daha var 1 parametrelerde:

Bir fonksiyon gelen veriyi değiştirmemeli diyorsak kullanılır.

void print(const int& x)
{
    cout << x << endl;
}



2. Class metotlarında const kullanımı:

class Player{
public:
    int getHealth() const;
};

Buradaki metot class içindeki hiçbir değişkenin değerini değiştirmeyeceğini
garanti eder.(Bu metot sadece okuma yapabilir. Getter metotlar vb.).

const bir nesne oluşturduğumuzda sadece const metotlar çağrılabilir.


Normalde const bir metodun içinde bir değişkeni değiştiremeyiz
Ama değiştirmenin bir yolu var bu da Mutable:

mutable bir değişken:Bu değişken const object veya const method içinde değiştirilebilir.
class Test
{
    mutable int x;

public:

    int getX() const
    {
        x++; // HATA
        return x;
    }
};


neden böyle bir şey var?

Bazı değişkenler logical state in bir parçası değildir.
ama yardımcı bilgiler tutar.

En yaygın kullanım: Call counter
Bir fonksiyonun kaç kez çağrıldığını saymak:
class Logger
{
    mutable int callCount;

public:

    Logger()
    {
        callCount = 0;
    }

    int getValue() const
    {
        callCount++;
        return 100;
    }

    int getCallCount() const
    {
        return callCount;
    }
};

Kullanım:

int main()
{
    const Logger log;

    log.getValue();
    log.getValue();
    log.getValue();

    cout << log.getCallCount();
}

Çıktı:

3




Önce Temel Kural (ÇOK ÖNEMLİ)

C++’ta şu kuralı kullanırsan asla karıştırmazsın:

const kendisinden solundaki şeyi sabit yapar.

Eğer solunda bir şey yoksa:

sağındaki şeyi sabit yapar

1 const Player* p
const Player* p;

Bunu şöyle de yazabilirsin:

Player const* p;

İkisi aynı şeydir.

Anlamı

Pointer başka objeleri gösterebilir
ama gösterdiği object değiştirilemez

Bellek Mantığı
p  ----> Player object
          (const)
Örnek
class Player
{
public:
    int health;
};
Player p1;
Player p2;

const Player* p = &p1;
Ne Yapabiliriz?
pointer değişebilir
p = &p2;   // OK
object değiştirilemez
p->health = 100;  // HATA

çünkü:

pointer const object gösteriyor
Ama Object Başka Yerden Değişebilir
Player p1;

const Player* p = &p1;

p1.health = 50; // OK

Çünkü:

p1 normal object
2 Player* const p

Şimdi farklı bir durum.

Player* const p
Anlamı

pointer sabit
object değişebilir

Bellek Mantığı
const pointer p ----> Player object
Örnek
Player p1;
Player p2;

Player* const p = &p1;
Object değiştirilebilir
p->health = 100; // OK
Pointer değiştirilemez
p = &p2; // HATA

Çünkü:

p const pointer
3 const Player* const p

Şimdi ikisi de const.

const Player* const p
Anlamı

pointer sabit
object sabit

Bellek Mantığı
const pointer p ----> const Player object
Örnek
Player p1;
Player p2;

const Player* const p = &p1;
Pointer değiştirilemez
p = &p2; // HATA
Object değiştirilemez
p->health = 100; // HATA
4 Hepsini Tek Tabloyla Görelim
yazım	pointer	object
const Player* p	değişir	değişmez
Player* const p	değişmez	değişir
const Player* const p	değişmez	değişmez
5 Gerçek Hayat Kullanımı

En çok kullanılanı:

const Player* p

Bu genelde şu anlama gelir:

sadece okuma

Örneğin:

void printPlayer(const Player* p)
{
    cout << p->health;
}

Fonksiyon:

player'ı değiştirmez
6 Pointer ile const object

Şu da önemli bir durum:

const Player player;

Sonra:

const Player* p = &player; // OK

ama:

Player* p = &player; // HATA

Çünkü:

const object → non-const pointer ile tutulamaz
7 Gerçek Proje Örneği
class Game
{
public:

    void printPlayer(const Player* p)
    {
        cout << p->health;
    }
};

Bu fonksiyon:

Player'ı değiştirmeyeceğini garanti eder
8 Küçük Bir Zihin Testi

Bu kod çalışır mı?

Player p1;
Player p2;

const Player* p = &p1;

p = &p2;

Cevap:

✔ çalışır

Ama:

p->health = 50;

❌ hata.

9️⃣ İleri Seviye Okuma Tekniği

C++ geliştiricileri pointer'ı sağdan sola okur.

Örneğin:

const Player* const p

okuma:

p is const pointer to const Player
*/

int main()
{
    const int Max_Age = 90;
    int *a = new int;

    a = (int*)&Max_Age;
    *a = 15;
    
    std::cout<<Max_Age<<std::endl; 


    int x = 15;
    int y = 20;

    const int * ptr = &x;
    //*ptr = 20; bu hata gösterilend eğer değiştirilemez.
    //fakat ptr = &y; olabilir.
    std::cout<<*ptr<<std::endl;
    
    ptr = &y;
    std::cout<<*ptr<<std::endl; 


    int val1 = 1;
    int val2 = 2;

    int* const ptr2 =&val1;

    std::cout<<"*ptr2: "<<*ptr2<<std::endl;

    //ptr2 = &val2; bu hata gösterdiği adres değişemez.
    //ama bu seferde *prt2 = 18; yazabiliriz.
    *ptr2 = 191;
    std::cout<<"*ptr2:"<<*ptr2<<std::endl;

    int ival = 15;
    
    const int& ref = ival;
    
    //burada hata oluşur const dan dolayı ref = 20;
    //fakat ival = 20 yapabiliriz.
    ival = 20;
    std::cout<<ref<<std::endl;

    
    return 0;
}

/*Göreceğimiz şeyler:

const member variable

const constructor

mutable

const object

const pointer to object

ve özellikle şu konu:

this pointer ve const

Bu konu senior C++ seviyesine girer ve çok ilginçtir.*/
