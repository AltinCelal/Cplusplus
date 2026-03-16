#include<iostream>
/*
C++ da this mevcut nesneyi gösteren bir pointerdor.

Yani bir class içindeki fonksiyonu (metodu) çağırırken:
this şu anda fonksiyonu çağıran nesnenin adresi.

class Person
{
public:
    int age;

    void printAge()
    {
        std::cout<<age<<std::endl;
    }

};

int main()
{
    Person p;
    p.age = 24;
    p.printAge();

}

burada aslında düşünmemiz gereken bir olay var.
printAge e herhangi bir parametre vermedik sadece bir nesne oluşturduk ve o nesneyle metodu
çağırdık.
Peki printAge hangi age verisini kullanacak çünkü birden fazla nesne oluşturabiliriz mesela

Person p1;
Person p2;
Person p3;

biz burada 3 farklı nesne oluşturduk nesneyle bir metodu çağırdık peki
metot hangi nesnenin çağırdığını hangi age verisini yazdıracağını nereden biliyor?

Bu bilgi(fonksiyonu çağıran nesnenin age verisi) this pointer ile taşınır.

p.printAge(); dediğimizde compiler aslında arka planda 
printAge(&p); şeklinde gönderiri yani gizli bir parametre ekler.

Ve gerçek fonksiyon aslında 
void printAge(Person* this)
{
    std::cout<<this->age<<std::endl;
}
buna benzerdir.

Yani this burada fonksiyonu çağıran nesnenin adresidir.
Bu sayede fonksiyonu hangi nesne çağırmış bilinmiş olur ve ona ait age verisi döndürülür.

This bir pointerdır. Türü ClassName* dir burada this Person* türünde.

Diğer bir kullanım şekli ise (En çok gördüğüm ama aslında benim çok kullanamyı tercih etmediğim yöntem)
Bir class member ile bir metodun parametresi aynı isimde olursa bunları birbirinden ayırmk için kullanılır.

class Person
{
public:
    int age;

    void setAge(int age)
    {
        this->age = age;
    }

    void printAge()
    {
        cout << age << endl;
    }
};

int main()
{
    Person p;

    p.setAge(25);
    p.printAge();
}
buradaki this-> aslında class member olan age i temsil eder yukarıda anlatmıştım fonksiyon çağrılırken
aslında gizli parametreyle çağrılır diye.

Tabi burada bir sorun yok sorunu biz oluşturuyoruz member olan age i m_age olarak tanımlarsak
this kullanmaya gerek kalmaz.
class Person
{
public:
    int m_age;

    void setAge(int age)
    {
        m_age = age;
    }

    void printAge()
    {
        cout << m_age << endl;
    }
};

int main()
{
    Person p;

    p.setAge(25);
    p.printAge();
}
    Yukarıdaki kodda aynı şeyi yapar fakat this li kullanımda oldukça yaygındır.
özellikle büyük class larda çok kullanılır.
class User
{
    string name;
    int age;
    string email;

public:
    User(string name, int age, string email)
    {
        this->name = name;
        this->age = age;
        this->email = email;
    }
}; burada da deiğim gibi this kullanmak zorunda değiliz(member isimlerini değiştirebilirz)
ama bu şekilde kullanımda oldukça yaygın .Bilmekte fayda var.

Şimdi this pointer ının gerçek tipine biraz daha derinlemesine bakalım.

class Person
{
public:
    int age;

    void printAge()
    {
        std::cout << age<<std::endl;
    }
};
burada printAge içindeki this aslında Person* const this dir.
yani int*const x gibi düşünülebilir.

This in adresi değiştirilemez this = nullptr; yapılamaz ama
this->age  =50; yapılabilir.

this dediğim gibi aslında nesnenin adresini tutar

class Test
{
public:
    int x;

    void print()
    {
        std::cout << this << std::endl;
        
    }
};
int main()
{
    Test t;
    t.print();
    std::cout<<&t<<std::endl;

    return 0;
}
Yukarıdaki kod daha açıklayıcı olmuştur inşaAllah.


This pointer sadece non-static member functionlarda vardır bu yüzden static bir nesne
static olmayan bir metodu çağıramaz.


This nesnenin pointer ı olduğu için aşağıdaki gibi bir kullanımda mevcut


class Point
{
public:
    int x = 0;
    int y = 0;

    Point& setX(int x)
    {
        this->x = x;
        return *this;
    }

    Point& setY(int y)
    {
        this->y = y;
        return *this;
    }
};

int main()
{
    Point p;

    p.setX(10).setY(20);

    cout << p.x << " " << p.y;
}
*/
class Point
{
public:
    int x = 0;
    int y = 0;

    Point& setX(int x)
    {
        this->x = x;
        return *this;
    }

    Point& setY(int y)
    {
        this->y = y;
        return *this;
    }
};
class Test
{
public:
    int x;

    void print()
    {
        std::cout << this << std::endl;
        //std::cout << *this << std::endl;
    }
};
int main()
{
    Test t;
    t.print();
    std::cout<<&t<<std::endl;

    Point p;

    p.setX(10).setY(20);

    std::cout << p.x << " " << p.y<<std::endl;
    return 0;
}