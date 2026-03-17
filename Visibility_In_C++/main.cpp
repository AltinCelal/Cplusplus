#include<iostream>
int a =5;

/*

Bir değişkenin yada fonksiyonun kimler tarafından 
erişilebilir olduğunu tanımlar

public: Her yerden erişim vardır.(struct lar default olarak public gelir.)

privite:Sadece sınıf içi erişim vardır(class lar default olarak privite gelir.)

protected: Sınıf ve türeyen sınıflar erişebilir.

*/
class Animal
{
public:
    int a;
protected:
    int b;
private: 
    int c;
};

class Cat: public Animal
{
public:
    Cat()
    {
        a = 18;
        b = 54;
       // c = 45; base class da private olduğu için derived class dan erişilemez.
    }

};

class Entity{
private:
    int X;
    

protected:
    int Y;

public: 
    int Z;
    static void Hello()
    {std::cout<<"Hello"<<std::endl;}

};

class Player : public Entity
{
public:
    Player()
    {
        Z = 5;
    }
    void yazdir()
    {
        std::cout<< Z << std::endl;
    }
   
};
Player player2;

int main()
{
    Entity::Hello();//global scope da yazılamaz.

    //Player player;
    //player.yazdir();

    Cat cat;
    player2.yazdir();
    
    
    return 0;
}
/*
C++ da class içinde :
Değişken tanımı, 
Fonksiyon tanımı,
Constructor,
Destructor,
Typedef/using,
statik üyeler vb


ama Rastgele bir atama işlemi yapılamaz!
class Player : public Entity
{
public:
    Z = 5;
}; bu hatadır.
*/
 
/*
 Global Scope’ta Neler Yazılabilir?
 Değişken Tanımları
int globalVar = 10;
double pi = 3.14;
Global object da olabilir:
Player player1;

Program başlamadan önce constructor çalışır.

 Fonksiyon Tanımları
void foo() {
    std::cout << "Hello\n";
}
Class / Struct Tanımları
class A {
public:
    int x;
};
 Namespace Tanımları
namespace MySpace {
    int x = 5;
}
Using Bildirimleri
using namespace std;
Typedef / using alias
typedef int myInt;

using myDouble = double;
Enum Tanımları
enum Color {
    Red,
    Green,
    Blue
};
Template Tanımları
template<typename T>
T add(T a, T b) {
    return a + b;
}
Static Global Değişken
static int x = 5;

Bu dosya içi internal linkage sağlar.

Global Scope’ta Neler Yazılamaz?
Direkt Fonksiyon Çağrısı
foo();  // HATA

Çünkü:

Runtime başlamadan kod çalıştırılamaz.

If / For / While Bloğu
if (true) { }   // HATA

Kontrol yapıları fonksiyon içinde olmalı.

Expression
5 + 3;  // HATA
Peki Global Object Neden Serbest?

Çünkü bu:

Player player1;

Bir tanımlamadır, çağrı değildir.

Ama derleyici arka planda:

Constructor’ı program başlamadan önce çağırır.

Çok Kritik Kavram: Storage Duration

Global değişkenler:

Static storage duration’a sahiptir.

Program başında oluşturulur.

Program sonunda yok edilir.

Tehlike

Birden fazla dosyada global object varsa:

Initialization order undefined olabilir.

Buna:

“Static Initialization Order Fiasco” denir.

*/
