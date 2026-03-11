#include<iostream>
/*
Birbirleriyle ilişkili sınıflardan oluşan bir hiyerarşi oluşturmamızı sağlar.
Ortak işlevselliğe sahip temel bir sınıfa sahip olmamızı sağlar.

Bir sınıfın başka bir sınıfın özellik ve metotlarını devralmasıdır. 

Kod tekrarını azaltır. 

Sınıflar arasındaki ortak işlevsellikleri üst sınıfa taşıyabiliriz daha sonra bu üst sınıftan 
alt sınıflar oluşturmamız yeterlidir.


Temelde inheritence: Birçok sınıf arasındaki ortak kodu tek bir temel sınıfa yerleştirmemizi sağlar.
Kendimizi tekrar etmemizi engeller.

*/
//==============================================================================================-
class Entity{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }

};

class Player : public Entity
{
public:
    const char* Name;
    void printName()
    {
        std::cout<< Name << std::endl;
    }
     
};
//==============================================================================================-



int main()
{
    std::cout<<sizeof(Entity)<<std::endl;//8
    std::cout<<sizeof(Player)<<std::endl;//8+8
    Player player;

    return 0;
}