#include<iostream>
#include<string>
#include<cstring>

/*
Normal kopyalama basit değer , reference yada pointer copy.

aslında class nesneleri kopyalama da basit:) çok büyütmemek lazım.



class Book
{
    public:
    std::string title;
    int pages;
};

 Book b1;
    b1.title = "C++ programing";
    b1.pages = 980;

    Book b2;
    b2 = b1;
    
    std::cout<<"pages: "<<b2.pages<<"Title"<<b2.title<<std::endl;
    std::cout<<"pages: "<<b1.pages<<"Title"<<b1.title<<std::endl;
    
    b2.title = "C programing";
    b2.pages = 690;

     std::cout<<"pages: "<<b2.pages<<"Title"<<b2.title<<std::endl;
    std::cout<<"pages: "<<b1.pages<<"Title"<<b1.title<<std::endl;
    

    Copy Her Zaman Güvenli midir?

Hayır.

Şu durumda problem çıkar:

class içinde pointer varsa

Örnek:

class Test
{
public:
    int* data;
};

Bu durumda:

pointer adresi kopyalanır

Bu konu Shallow Copy problemidir.

Bunu birazdan göreceğiz çünkü C++’ın en kritik bug kaynaklarından biridir.

Küçük Bir Özet

Copy demek:

Bir değişkenin değerinin başka bir değişkene aktarılması

Primitive tiplerde:

value copy

Classlarda:

member-wise copy

Pointerlarda:

address copy


C++’ta Copy Constructor, bir nesneden başka bir nesne oluşturulurken çalışan özel bir constructor’dır.

Yani:

Bir nesne var → ondan yeni bir nesne üretmek istiyoruz

İşte bu durumda copy constructor çağrılır.

Copy constructor’ın genel formu:

ClassName(const ClassName &other)
{
}

Örnek:

Student(const Student &other)

Burada:

other = kopyalanacak nesne

class Student
{
public:

    string name;
    int age;

    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    Student(const Student &other)
    {
        name = other.name;
        age = other.age;

        cout << "Copy Constructor Called" << endl;
    }
};

int main()
{
    Student s1("Ali",20);

    Student s2 = s1;

    cout << s2.name << endl;
}

Copy constructorun çalıştığı zamanlar:
Nesne kopyalanırken
Student s1("Ali",20);
Student s2 = s1;


Fonksiyona nesne value olarak gönderilirse
void printStudent(Student s)
{
    cout << s.name;
}

Fonksiyondan nesne dönerse
Student createStudent()
{
    Student s("Ali",20);
    return s;
}
__________________________________________________________________
Shallow Copy vs Deep Copy

Bir class içinde pointer varsa, default copy constructor ciddi problemlere yol açabilir.

Bu probleme:

Shallow Copy Problem

denir.

Önce Pointer İçeren Bir Class Yazalım
#include <iostream>
using namespace std;

class Number
{
public:
    int *value;

    Number(int v)
    {
        value = new int(v);
    }

    void print()
    {
        cout << *value << endl;
    }
};

Burada:

value → heap memory'de bir integer tutuyor
Nesne Oluşturalım
int main()
{
    Number n1(10);

    n1.print();
}

Bellek diyagramı:

Stack                Heap
-----                -----

n1
value ----------->   10
Şimdi Kopyalama Yapalım
int main()
{
    Number n1(10);

    Number n2 = n1;

    n1.print();
    n2.print();
}

Program çalışır ve çıktı:

10
10

Ama burada gizli bir problem var.

Bellekte Gerçekte Ne Oldu?

C++ default copy constructor kullanır.

Bu şu demektir:

member-wise copy

Yani:

n2.value = n1.value;

Bellek:

Stack

n1.value ----\
               ---> Heap: 10
n2.value ----/

Yani:

İki nesne aynı heap adresini kullanıyor

Bu Shallow Copy’dir.

Shallow Copy Problemi

Şimdi şöyle bir kod yazalım.

#include <iostream>
using namespace std;

class Number
{
public:
    int *value;

    Number(int v)
    {
        value = new int(v);
    }

    ~Number()
    {
        delete value;
    }
};

int main()
{
    Number n1(10);

    Number n2 = n1;
}

Burada destructor var.

Program sonunda:

n2 destructor
n1 destructor

çalışır.

Ama ikisi de şunu yapar:

delete value;

Sonuç:

double free error

Program crash olur.

Problem Özeti

Shallow copy:

sadece pointer adresini kopyalar

Yani:

n1.value
n2.value

aynı heap alanını gösterir.

Çözüm: Deep Copy

Deep copy demek:

pointer'ın gösterdiği veriyi de kopyalamak

Yani:

yeni memory allocate etmek
Deep Copy Constructor Yazalım
#include <iostream>
using namespace std;

class Number
{
public:

    int *value;

    Number(int v)
    {
        value = new int(v);
    }

    Number(const Number &other)
    {
        value = new int(*other.value);
    }

    ~Number()
    {
        delete value;
    }

    void print()
    {
        cout << *value << endl;
    }
};
Test Edelim
int main()
{
    Number n1(10);

    Number n2 = n1;

    *n2.value = 50;

    n1.print();
    n2.print();
}

Output:

10
50
Bellek Diyagramı (Deep Copy)
Stack

n1.value ------> Heap: 10

n2.value ------> Heap: 50

Artık:

iki farklı heap memory var

Dolayısıyla:

double free olmaz
Shallow vs Deep Copy
Shallow Copy
pointer adresi kopyalanır
obj1.ptr ----\
              ---> heap
obj2.ptr ----/
Deep Copy
heap verisi de kopyalanır
obj1.ptr ---> heap1
obj2.ptr ---> heap2
*/
class Book
{
    public:
    std::string title;
    int pages;
};
class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size+1];
        memcpy(m_Buffer,string,m_Size);

    }
    friend std::ostream& operator<<(std::ostream&, const String& string);
    ~String()
    {
        delete[] m_Buffer; 
    }
};


std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

class Test
{
public:

    int x;

    Test(int a)
    {
        x = a;
    }

    Test(const Test &other)
    {
        std::cout << "Copy Constructor" << std::endl;
        x = other.x;
    }
};
int main()
{
    //String string = "Celal";
    //String string2 =string;
    //std::cout<<string<<std::endl;

    Book b1;
    b1.title = "C++ programing";
    b1.pages = 980;

    Book b2;
    b2 = b1;
    
    std::cout<<"pages: "<<b2.pages<<"Title"<<b2.title<<std::endl;
    std::cout<<"pages: "<<b1.pages<<"Title"<<b1.title<<std::endl;
    
    b2.title = "C programing";
    b2.pages = 690;

     std::cout<<"pages: "<<b2.pages<<"Title"<<b2.title<<std::endl;
    std::cout<<"pages: "<<b1.pages<<"Title"<<b1.title<<std::endl;
    
    Test t1(5);

    Test t2 = t1;

    return 0;
}