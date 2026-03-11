#include<iostream>

/*
Bir nesne yok edilirken otomatik çalışan özel bir fonksiyondurç
Constructor un tersi gibi düşünülebilir.

~classname şeklinde tanımlanır.

Biz manuel yazmasak bile otomatik oluşan bir destructor vardır constructordaki gibi.
Lifo mantığıyla çalışır 
A a;
B b;

Çıkış sırası:

b destructor

a destructor

inheritence varsa her zaman önce child daha sonra parent destructors çalışır.  
*/
class Entity{

public:
    float X,Y;
    Entity()
    {
        std::cout<<"Constructor is working"<<std::endl;
    }
    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }
    void Print()
    {
        std::cout<< X << " , " << Y << std::endl;
    }
    ~Entity()
    {
        std::cout<<"destructors is working" << std::endl;
    }

};
int main()
{
    Entity e;
    
    e.Print();
    //e.~Entity(); manuel olarak da çağırabiliriz ama pek mantıklı görünmüyor.
    return 0;
}