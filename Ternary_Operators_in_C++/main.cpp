#include <iostream>
#include <string>
/*
üçlü operatör kısa bir if-else yazım şeklidir.

kosul ? deger1: deger2;

kosul doğru ise deger1 döndürülür
yanliş ise deger2 döndürülür.

int a=10, b = 20;

int max = (a>b)?a:b;
std::cout<< "buyuk sayi:"<<max<<std::endl;


string ile kullanım:
int yas = 18;
string sonuc = (yas>=18)?"yetiskin":"cocuk";
std::cout<<sonuc<<std::endl;


iç içe kullanım :
int sayi = 0;

string sonuc = (sayi > 0) ? "Pozitif"
               : (sayi < 0) ? "Negatif"
               : "Sifir";


ternary ile fonksiyon çağırma:
void tek() { cout << "Tek sayi"; }
void cift() { cout << "Cift sayi"; }

int main() {

    int sayi = 5;

    (sayi % 2 == 0) ? cift() : tek();

}



Uzun ve karmşık kodlarda kullanılmaktan kaçınılmalıdır.Bunun yerine if
-else yazılmalıdır.


*/
int main()
{
    int a=30, b = 20;

    int max = (a>b)?a:b;
    std::cout<< "buyuk sayi:"<<max<<std::endl;



    int yas = 18;
    const char* sonuc = (yas>=18)?"yetiskin":"cocuk";
    //string litaraller const olduğu için char* sonuc kullanmak hata.
    //c de implicit dönüşüm vardır ama burada yok !
    //daha modern şekilde std::string kullanılabilir.
    std::cout<<sonuc<<std::endl;

    return 0;
}