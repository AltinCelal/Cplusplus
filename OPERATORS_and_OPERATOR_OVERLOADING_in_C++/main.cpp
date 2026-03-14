#include<iostream>
#include<string>
#include<ostream>
/*
Amaç: Kod ayzmayı daha doğal,basit ve okunabilir yapmak
5+3 
yerine add(5,3) yazmak zorunda kalmamak için.

C++ da operatörler aslında fonksiyon gibi davranır.

Arithmetic Operators	Matematik işlemleri
Relational Operators	Karşılaştırma
Logical Operators	    Mantıksal işlemler
Assignment Operators	Değer atama
Increment / Decrement	Artırma azaltma
Bitwise Operators	    Bit seviyesinde işlemler
Conditional Operator	Ternary operator
Special Operators	    sizeof, address vb

a+b aslında operator+(a,b) yle aynı.

______________________________________________
Operator Overloading
Operator Overloading, bir operatörün davranışını kendi yazdığımız sınıflar 
için yeniden tanımlamak
int a = 5;
int b = 3;

int c = a + b;

Burada + operatörü int için tanımlıdır.

std::string s1 = "Hello ";
    std::string s2 = "World";

    std::string s3 = s1 + s2;
    std::cout<<s3<<std::endl;
    ama burada C++ string sınıfı içinde + operatörü overload edilmiştir.

Operator Overloading Syntax:returnType operatorOP(parameters)

<< operatörün overload ı sık kullanılabilir.

class Point
{
public:
    int x;
    int y;

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

Şimdi:

int main()
{
    Point p(2,3);

    cout << p;

    return 0;
}

Bu compile error verir.
çözüm << operatörünü overload etmek
ostream& operator<<(ostream& os, Point p)
{
    os << p.x << " " << p.y;
    return os;
}


aynı şekilde >> operatörünün overloading i yazılabilir.
std::istream& operator>>(std::istream& is, Point2& p)
{
    is >> p.x >> p.y;
    return is;
}
*/
class Point2
{
public:
    int x;
    int y;

    Point2(int a, int b)
    {
        x = a;
        y = b;
    }
};

class Point
{
public:
    int x;
    int y;
};
std::ostream& operator<<(std::ostream& os, Point2 p)
{
    os << p.x << " " << p.y;
    return os;
}

std::ostream& operator<<(std::ostream& os, Point p)
{
    os << p.x << " " << p.y;
    return os;
}
std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}
int main()
{

   /*Point p1(2,3);
    Point p2(4,5);

    Point p3 = p1 + p2;

    std::cout << p3.x << " " << p3.y<<std::endl;*/
    Point2 p2(2,3);

    std::cout<< p2<<std::endl;
    Point p;

    std::cin >> p;

    std::cout << p.x << " " << p.y;
    
    return 0;

    
}