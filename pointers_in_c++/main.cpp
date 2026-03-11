#include<iostream>
/*

Adres tutar.

int *ptr -> ptr değişkeinini türü int pointer(int *)

int * ptr, int* ptr, int *ptr 3 ü de aynı şey.

bellekte 
int* p;
double* q;
char* r;..... hepsi aynı boyutta yer kaplar. bu sistemde 8 byte.

int * ptr; // int türünden bir değişkenin adresini tutacak.

int a = 5;

ptr = &a; & burada adres operatörüdür.

* dereference operatörü.
*ptr -> ptr adresindeki değeri getir demek.

std::cout<<*ptr<<std::endl;


const int* p;   // gösterdiği değer const
int* const p;   // pointer const

*/
void ptrDemo(int *& ptr);
void ptrfunc(int *ptr);

int i = 15;
int main()
{
    /*std::cout << sizeof(int*)    << std::endl;
    std::cout << sizeof(double*) << std::endl;
    std::cout << sizeof(char*)   << std::endl;*/
    int ival = 15;
    int *ptr = &ival;

    std::cout<<"adress of ival:"<<&ival<<std::endl;
    std::cout <<"value of ptr:"<<ptr<<std::endl<<std::endl;

    std::cout<<"value of ival :"<<ival<<std::endl;
    std::cout<<"value of *ptr :"<<*ptr<<std::endl<<std::endl; 


    int iarr[] ={15,65,89,45,123,78,85,99,789};
    
    int *iptrarr =iarr; // iarr zaten direk kullanımda ilk elemanın adresini döndürü.
    //iarr ile iarr[0] aynı şey.
    std::cout<<"value of iptrarr :"<<iptrarr<<std::endl;
    std::cout<<"value of iarr :"<<iarr<<std::endl;
    std::cout<<"value of &iarr :"<<&iarr<<std::endl;
    std::cout<<"value of &iarr[0] :"<<&iarr[0]<<std::endl<<std::endl;

    //&iarr++ dediğimizde arraydaki eleman sayısı * 4(int) kadar ilerler.!!!!

    iptrarr++;
    std::cout<<"value of iptrarr :"<<iptrarr<<std::endl;
    std::cout<<"value of *iptrarr :"<<*iptrarr<<std::endl;
    std::cout<<"value of &iarr[1] :"<<&iarr[1]<<std::endl;

    //iptrarr++; dediğimizde pointer aritmetiği uygulatıyoruz.
    //bu 1 byte değil sizeof(int) kadar ilerideki adresi gösterir.
    //arrayler de ram da ardışık olduğu için iptrarr++ = iarr[1] demek. 

    //fonksiyona array gönderirken de bu kullanılır fonksiyon parametre olarak 
    //pointer alır yada array yani array gönderilmez aslında arrayin ilk elemanının 
    //adresi gönderilir.

    ptrfunc(iarr);


    int k = 55;
    int *Ptr2 = &k;
    std::cout<<"\n\n"<<std::endl;

    std::cout<<"*Ptr2 :"<<*Ptr2<<std::endl;
    
    ptrDemo(Ptr2);
    std::cout<<"*Ptr2 :"<<*Ptr2<<std::endl;

    return 0;
}

void ptrfunc(int * ptr)//(int ptr[]) şeklinde de tanımlanabilirdi.
{
    std::cout<<"function parameter adress:"<<ptr<<std::endl;
    
}
/*
ptrDemo(Ptr2);
void ptrDemo2 (int *ptr)
{
    ptr = &i;
}

burada call by value oluyor. pointerin kopyasını kullanıyoruz.Eğer call by
referance olarak göndermek istiyorsak birkaç yolu var 1. si aşağıda

2. si 
ptrDemo(&Ptr2);
void ptrDemo2 (int **ptr)
{
    ptr = &i;
}
bu şekilde de gönderilebilir 
yada çift pointer kullanılıp onu bu fonksiyona besleyebilriz.
*/

void ptrDemo(int*& ptr)
{

    ptr = &i;
}
