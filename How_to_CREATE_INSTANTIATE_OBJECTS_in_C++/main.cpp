#include <iostream>
using namespace std;
/*
Öncelikle c++ daki Class ı hatırlayalım.
C++ da class, nesnelerin(object) nasıl görüneceğini ve nasıl davranacağını
tanımlayan bir blueprint(şablon)dur.

class = veri + fonksiyonları bir araya getiren bir veri tipi.

C++ class ı yeni bir type olarak görür.(int, double, char* gibi).

Class içinde 
1-Data members
2-member functions(methods)
3-Constructors
4-Destructors
5-Access Modifiers(public,protected,private)

Class tanımlamak memoriden yer ayırmaz.Sadece compiler a bu bu şekilde bir 
veri tipi var biligisi verir.class Empty {};sizeof(Empty) sonuç:1 byte
Çünkü c++ standartına göre her object'in uniqur bir adresi olmalı.

Memory object oluşturulunca ayrılır.

Bir obje oluşturunca data memberle o objede yer alır fakat member functionlar
object içinde değildir.

class Car
{
public:
    int speed;

    void drive()
    {
        std::cout << "Driving";
    }
};

compiler tarafından aşağı yukarı şuna çevrilir:

struct Car
{
    int speed;
};

void Car_drive(Car* this)
{
    std::cout << "Driving";
}

this pointer burada ortaya çıkar.

Object bir class ın gerçek memory de oluşturulmuş bir instance ıdır.

Object oluşturulduğunda memory allocate edilir.

object = Memory + Behavior


object lifetime: 

Stack object:Fonksiyon bitince object yok olur.

Heap object:Delete edilene kadar yaşar.

STACK ÜZERİNDE OBJE OLUŞTURMA:
Stack: Program çalışırken kullanılan çok hızlı bir memory bölgesidir.
-Çok hızlıdır
-Otomatik yönetilir.
-LIFO mantığıyla çalışır.
-Küçük boyutludur.

Car myCar;şeklinde çalıştırılabilir.
Ömrü scope ile sınırlıdır.

Stack küçük olduğu için çok büyük veya çok sayıda obje oluşturulunca 
Stack overflow riski vardır.

Mümkünse stack kullanmak mantıklı.

Heap memory:Stack küçük olduğu için bazı durumlarda yeterli olmaz.

Heap üzerinde nesne oluşturmak için new keywordu kullanılırç
Car* car = new Car();

1 heap'te memory allocate edilir
2 constructor çağrılır
3 pointer döndürülür

pointer stack de object heap de tutulur.

pointer olduğu için erişim -> ile sağlanır.
Otomatik silinmez delete car; komutuyla silinir.

delete unutulursa memory leak oluşma riski var.
*/


class Car
{
public:
    int speed;

    Car(int s)
    {
        speed = s;
        cout << "Constructor called -> Speed: " << speed << endl;
    }

    ~Car()
    {
        cout << "Destructor called -> Speed: " << speed << endl;
    }

    void drive()
    {
        cout << "Driving at " << speed << " km/h" << endl;
    }
};

int main()
{
    cout << "STACK OBJECT\n";

    Car car1(120);   // Stack'te nesne

    car1.drive();

    cout << "\nHEAP OBJECT\n";

    Car* car2 = new Car(200);   // Heap'te nesne

    car2->drive();

    cout << "\nDeleting heap object...\n";

    delete car2;   // Heap nesnesini sil

    cout << "\nProgram ending...\n";

    return 0;
}