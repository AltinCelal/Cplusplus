#include<iostream>

#define LOG(x) std::cout<< x <<std::endl;

/* 
C dilinde reference yoktur.!!

C++ da reference mevcut bir değişken için oluşturulan takma
addır.(Alias).
yeni bir bellek alanı oluşturmaz.Mevcut değişkeni işaret eder.

int a = 5;
int& ref = a;

ref = 20;
a artık 20 oldu.
ref a nın başka bir ismidir.
ref değişirse a da değişir.
ayrı bir kopya oluşturmaz yada bellekte bir değişken oluşturulmaz.


1-> Tanımlandığı anda bir değişkene bağlanmak zorundadır.
int& r ;//HATA ! Başlangıç değeri verilmedi.

2->Sonradan başka bir değişkene bağlanamaz.
int x = 5;
int y = 7;

int& ref = x;
ref = y; // x artık 7 olur (ref hala x e bağlı.)

3->Null olamaz.

*/

void increase (int& x)
{
    x++;
}
int main()
{
    int ival = 5;
    increase(ival);
    LOG(ival);


    return 0;
}