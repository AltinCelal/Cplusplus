#include<iostream>
/*
Enum(enumeration):
Bir değişkenin alabileceği değerleri önceden belirlenmiş sabit 
isimlerle sınırlandırmamızı sağlar.

Örneğin haftanın günleri.
Enum olmadan 
int pazartesi = 1; 
int sali = 2;.......

Enum ile 
enum gun{
Pazartesi,
Sali,
Carsamba....

}




enum Gun {
    Pazartesi,
    Sali,
    Carsamba,
    Persembe,
    Cuma,
    Cumartesi,
    Pazar
};

int main() {
    Gun bugun = Carsamba;

    cout << bugun << endl;
    return 0;
}
*/

enum Example 
{
    A, B, C
/*
Yukarıdaki ifadeler tam sayılardan ibaretler.
A=0, B=1, C=2 şeklindedir.
Bunlar default olarak gelir biz özelleştirebiliriz.
A = 5, B = 8, C = 11 gibi
*/
};

int a = 0;
int b = 1;
int c = 2;
int main()
{
    Example value = B;

    if (value == b)
    {
        std::cout<<"Yes"<<std::endl;
    }
    else 
    std::cout<<"No"<<std::endl;
    
    return 0;
}