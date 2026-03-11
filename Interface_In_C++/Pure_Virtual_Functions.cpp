#include<iostream>
#include<string>
/*
Bir sınıfın ne yapacağını tanımlar ama nasıl yapılacağını belirtmez.
Sadece fonksiyonun imzası var gövdesi yok.
C++ da Java daki gibi interface anahtar kelimesi yoktur.
Bunun yerine soyut sınıflar kullanılır.
Bu da pure virtual function(saf sanal fonksiyon) ile yapılır.
Bu sınıflardan nesne ÜRETİLEMEZ.
Miras alan sınıflar bu fonksiyonu İMPLEMENTE ETMEK ZORUNDA.

Alt sınıfın kendi tanımını yapmasına zorluyoruz.


1- Saf Sanal fonksiyon(Pure Virtual Functions):
Sadece fonksiyon bildiirmi var gövdesi yok.
virtual void Print() = 0; Miras alan bu fonksiyonu tanımlamak zorunda
(fonksiyon() = 0; ile tanımlanır.)

2- Abstract Class :
Sınıfın içinde en az 1 tane pure virtual fonksiyon varsa o fonksiiyon otomatik olarak 
abstract class olur.
doğrudan nesne oluşturamazsın 

3-Interface: 
Abstract sınıfın özel halidir.içinde sadece pure virtual fonksiyonlar vardır.
Hiçbir veri üyesi ve implementasyon yoktur.


Şimdi sınıflarımızın ismini ekrana yazdıracağımız bir fonksiyonumuz olsun.

void Print(??? obj)
{
    virtual std::cout<< obj->GetClassName() << std::endl;
}

??? bir tür olmalı hatta pointer olmalı.

class Printable{
    std::string GetClassName() = 0;
};

yukarıdaki sınıfımız bir interface oldu kalıtım alan tüm sınıflar bu fonksiyonu 
implemente etmek zorunda örnek aşağıda.


*/
class Printable
{
    public:
    virtual std::string GetClassName() = 0;
};
class Entity : public Printable
{
public:
    std::string GetClassName()override{return "Entity";}
    virtual std::string GetName(){
        return "Entity";
    }

};
class Player :public Entity
{
private:
    std::string m_Name;
public:
    std::string GetClassName()override{return "Player";}
    Player(const std::string& name)
        :m_Name(name){}

    std::string GetName()override {return m_Name;}
};

void PrintName(Entity* entity)
{
    std::cout<< entity->GetName()<<std::endl;
}
void print(Printable* obj)
{
    std::cout<<obj->GetClassName()<<std::endl;
}

class a :public Printable
{
    std::string GetClassName() override {return "a";}
};
int main()
{
    Entity* e = new Entity();
    //PrintName(e);
    print(e);
    Player* p = new Player("Celal");
    print(p);

    Printable* ptr = new a();
    print(ptr);
    //PrintName(p); 




    return 0;
}