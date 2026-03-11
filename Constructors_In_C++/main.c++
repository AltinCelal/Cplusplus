#include<iostream>
/*
Constructors: Bir nesne oluşturduğumuzda her seferinde çalışan özel bir 
metot türü.

Bir sınıfı örneklediğimizde nesne oluşturduğumuzda bellekten bu nesneye
bir alan tahsis edilir.Ama bu alan önceki değerinde tahsis edilir.
Yani otomatik olarak bir değere set edilmez önceside ne varsa 
nesnemizin değeri o olur.

Aşağıdaki örnekte Entity sınıfından her nesne oluşturduğumuzda X ve Y 
değerlerini belli bir değerle başlatmanın bir yolu olmalı.
Bunu 
void Init()
{
    X = 0;
    Y = 0;
} fonksiyonu yazarak ve her nesne oluşturduğumuzda bu fonksiyonu
çağırarak yapabiliriz ama bu kod satırını artırı ve kodu kirletir:)

her nesne oluşturduğumuzda otomatik biz çağırmadan çalışacak bir kod 
yazabilirsek bu sorun çözülür.
Bunu Constructor sayesinde yapıyoruz.
Özel bir metottur. Her nesne oluşturduğumuzda her seferinde çağrılır.

Tanımı diğer metotlar gibidir ama dönüş değeri yoktur ve adı sınıf adıyla aynıdır.
Parametre alabilir.

Biz tanımlamasak bile hiçbir şey yapmayan bir constructor otomatik 
olarak oluşturulur.


Bir veya birden daha fazla(parametreleri farkı olacak biçimde)
constructor yazılabilri. 


Constructor bir nesne oluşturmazsak çalışmaz. Yani bir sınıfta
sadece statik metotlar kullanırsak çalışmaz.


Eğer bir sınıfı statik olarak tanımlayıp o sınıftan nesne
oluşturulmasını engellemek istiyorsak 2 farklı yolu var:
1.
class Log{
    private: 
        Log(){}

    public:
        static void Write()
        {
        
        }

};
Burada constructor ı private yaptık ve dışarıdan erişilemiyor yani sınıf başlatılamıyor.


2.

class Log{
    public:
        Log() = delete;
        static void Write()
        {
            std::cout<<"Log Class"<<std::endl;
        }

};
Burada da constructor u sildik başlatılamaz.

Bu sayede sınıflarımızdan nesne üretilemez.
*/
class Log{
    private: 
        Log(){}

    public:
        static void Write()
        {
            std::cout<<"Log Class"<<std::endl;
        }

};
class Entity{
    public:
        float X, Y;
    

        void Print()
        {
            std::cout<< X << ", "<< Y << std::endl;
        }
        Entity()
        {
            std::cout<<"Work the Entity() constructors"<<std::endl;
            X = 15.5f;
            Y = 45.6f;
        }
        Entity(float x, float y)
        {
            std::cout<<"Work the Entity(float x, float y) constructors"<<std::endl;
            X = x;
            Y = y;
        }

};
int main()
{
    Entity e(1.1f,2.2f);
    std::cout<< e.X<<std::endl;
    e.Print();

    Log::Write();
    //Log l;
    return 0;
}