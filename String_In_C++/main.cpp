#include <iostream>
#include<string>
#include<cstring>
/*
String: Karakterlerin(harf, sayı, sembol vb.) bir araya gelmesiyel 
oluşan metin veri tipi.


temelde string bir karakter dizisidir.

2 tür string vardır temelde 1- C tarzı(karakter dizisi oluşturma yada char*)

2-std::string
 

sizeof() bellekte kapladığı tüm alanı verir '\0' dahil.

strlen() '\0' a gelene kadarki karakter sayısını verir.



string literal: Programın içine doğrudan yazılan sabit stringler.
çift tırknak içindekiler.

Bellekte char dizisi olarak tutulur. Sonunda \0 bulunur.
const ile kullanmak mantıklı zaten değiştirilemez-read only memoride tutulur.
bir kez tanımlandıktan sonra tekrar değiştirilemez.

*/
int main()
{
    //char* name = "Celal";
    //name[0] = 'a'; bu bir hata değiştirilemez o yüzdne başına const eklemek önemli
    std::string name3 = "Celalll";
    const char* name = "Celal";
    //sonunda '\0' sonlandırma karakteri vardır.
    
    // eğer diziyi değiştirmek istiyorsak 
    char name2[] = "Aelal";
    name2[0] = 'C';
    std::cout<<name2<<std::endl;

    /*std::string name = "Celal";
    char name2[]="Celal";
    std::cout<<name.size()<<std::endl;
    std::cout<<strlen(name2)<<std::endl;*/

    const char* message = "Warning ! temperature \0 is hight";
    std::cout<<strlen(message)<<std::endl;
    std::cout<<message<<std::endl;
    return 0;
}