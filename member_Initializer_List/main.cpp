#include<iostream>
/*
Member initializer list: Bir sınıfın constructor'ı
çalışırken class üyelerini doğrudan initialize
etmek için kullanışan çzel bir söz dizimidir.
Özellikle const değişkenler,referanslar,base class'lar
ve bazı performans durumları için çok önemlidir.
Genel yapı:

class Sinif {
private:
    int a;
    int b;

public:
    Sinif(int x, int y) : a(x), b(y) {
        // constructor body
    }
};

Burada:

: a(x), b(y)

kısmına initializer list denir.
Normal Atama ile Initializer List Arasındaki Fark

Normal Atama (Constructor Body içinde)
class Ornek {
private:
    int x;
    int y;

public:
    Ornek(int a, int b) {
        x = a;
        y = b;
    }
};

Bu durumda süreç şöyle olur:

x ve y önce default initialize edilir

sonra constructor içinde tekrar değer atanır

Yani 2 işlem olur.

Initializer List ile
class Ornek {
private:
    int x;
    int y;

public:
    Ornek(int a, int b) : x(a), y(b) {
    }
};

Burada süreç:

x doğrudan a ile initialize edilir

y doğrudan b ile initialize edilir

Yani tek işlem yapılır → daha verimli.

Syntax Detayı

Genel yapı:

Constructor(parameters) : member1(value1), member2(value2), member3(value3)
{
    // constructor body
}

Örnek:

class Araba {
private:
    int hiz;
    int yil;

public:
    Araba(int h, int y) : hiz(h), yil(y) {
        cout << "Constructor calisti\n";
    }
};
Const Üyeler İçin Zorunlu

Eğer class içinde const değişken varsa, initializer list zorunludur.

Hatalı kullanım
class Test {
private:
    const int x;

public:
    Test(int a) {
        x = a;   // HATA
    }
};

Çünkü:

const değişken sonradan değiştirilemez

Doğru kullanım
class Test {
private:
    const int x;

public:
    Test(int a) : x(a) {
    }
};
Reference Üyeler İçin Zorunlu

Referanslar da sonradan atanamaz, sadece initialize edilir.

Hatalı
class Test {
private:
    int &ref;

public:
    Test(int &x) {
        ref = x; // HATA
    }
};
Doğru
class Test {
private:
    int &ref;

public:
    Test(int &x) : ref(x) {
    }
};
Base Class Constructor Çağırma

Initializer list base class constructor çağırmak için kullanılır.

class Base {
public:
    Base(int x) {
        cout << "Base constructor\n";
    }
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) {
        cout << "Derived constructor\n";
    }
};

Çalışma sırası:

Base constructor
Derived constructor
Object Member Initialize Etme

Eğer class içinde başka bir class nesnesi varsa, initializer list kullanmak en doğru yöntemdir.

class Motor {
public:
    Motor(int guc) {
        cout << "Motor olusturuldu\n";
    }
};

class Araba {
private:
    Motor m;

public:
    Araba() : m(150) {
        cout << "Araba olustu\n";
    }
};
Initialize Sırası (Çok Önemli)

C++’ta initializer listteki sıra değil, class içindeki tanımlama sırası önemlidir.

Örnek:

class Test {
private:
    int a;
    int b;

public:
    Test(int x, int y) : b(y), a(x) {
    }
};

Initialize sırası:

a önce
b sonra

Çünkü class içinde:

int a;
int b;

şeklinde tanımlı.

Default Constructor ile Kullanım
class Test {
private:
    int x;

public:
    Test() : x(0) {
    }
};
Birden Fazla Üye
class Student {
private:
    string name;
    int age;
    double gpa;

public:
    Student(string n, int a, double g)
        : name(n), age(a), gpa(g) {
    }
};
Performans Avantajı

Özellikle şu tiplerde çok önemli performans sağlar:

string

vector

class object

large structs

Örnek:

class Test {
private:
    string name;

public:
    Test(string n) : name(n) {}
};

Burada:

string direkt oluşturulur

Ama normal atamada:

string önce default oluşur
sonra assignment olur
 Default Member + Initializer List
class Test {
private:
    int x = 5;

public:
    Test() : x(10) {
    }
};

Sonuç:

x = 10

Constructor initializer default değeri override eder.

 Çok Önemli Özet

Initializer List kullanmak zorunlu olduğu durumlar

 const üyeler
 reference üyeler
 base class constructor çağrısı
 class object members

Performans için önerilen durumlar

string

vector

class objects

büyük veri yapıları

Profesyonel C++ Kuralı

Modern C++’ta genelde şu kural kullanılır:

Constructor içinde atama yapmak yerine
her zaman initializer list kullan.

*/



int main()
{

    return 0;
}