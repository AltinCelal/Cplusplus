#include<iostream>

#define LOG(x) std::cout<< x <<std::endl


/*
Kendi veri tipimizi oluşturmamıza olanak sağlar.

struct ile en temel farklarından biri struct lar default olarak
public gelir class lar privite gelir.

Clasların içine fonksiyonda yazılabilir.
privite değişkenlere veya fonksiyonlara class dışından erişilemez.
sadece class içinde erişilir

*/
//classlar default olarak private olarak oluşturulur
//public kullanım için belirtmek gerekir.
class Player
{
    public:

        int x,y;
        int speed;
        void Move ( int xa,int ya)
        {
            x +=xa * speed;
            y +=ya * speed;

        }
};



int main()
{
    Player player;
    player.speed = 15;
    player.Move(1,-1);


    return 0;
}