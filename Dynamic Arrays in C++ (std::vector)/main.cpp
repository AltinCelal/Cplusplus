#include<iostream>
/*
standart array:
int sayilar[5] = {1, 2, 3, 4, 5};
Bu satırda olan her şey derleme zamanında (compile time) belirlenir:

Boyut sabittir: 5
Bellek stack'te ayrılır
Kapsam bitince otomatik silinir
Boyut değiştirilemez.
Stack memory de oluşur.

#include <iostream>

int main() {
    int n;
    std::cout << "Kac eleman? ";
    std::cin >> n;

    int dizi[n];  // Derleme hatası veya tanımsız davranış!
                  // Boyut derleme zamanında bilinmek zorunda
}

Problem 1 — Boyut sabittir
int arr[5];

5 elemandan fazla koyamazsın.

Problem 2 — Dynamic array zor
int* arr = new int[5];

Sonra büyütmek istersen:

yeni array aç
eski array kopyala
eskiyi sil

Bu zahmetlidir.

Problem 3 — Memory yönetimi
delete[] arr;

unutursan memory leak olur.

Vector Bu Problemleri Çözer

Vector:

✔ otomatik büyür
✔ memory yönetir
✔ kolay kullanılır
✔ güvenlidir

_________________________________________________________________________________________________________________________________________
std::vector-> Standart kütüphanenin (STL) sunduğu, dinamik boyutlu, heap'te yaşayan, kendini otomatik yöneten dizi yapısıdır.


#include <vector>   // ← bu header gerekli

std::vector<int>         sayilar;   // int dizisi
std::vector<double>      notlar;    // double dizisi
std::vector<std::string> isimler;   // string dizisi

size ≤ capacity her zaman geçerlidir.

cppstd::vector<int> v = {10, 20, 30};

std::cout << v.size()     << std::endl;  // 3
std::cout << v.capacity() << std::endl;  // 3, 4, veya 5 (derleyiciye göre)

Vector'a Eleman Eklemek

Vector'a eleman eklemek için:

push_back()


Vector Boyutunu Öğrenmek
numbers.size()


Vector ile Loop Kullanmak
for(int i = 0; i < numbers.size(); i++)
{
    cout << numbers[i] << endl;
}


Range-Based For Loop

C++11 ile gelen güzel bir özellik:

for(int x : numbers)
{
    cout << x << endl;
}

Bu şu anlama gelir:

vector içindeki her elemanı sırayla al


Vector Başlangıç Değeri

Vector başlangıç değerleri ile oluşturulabilir.

vector<int> v = {1,2,3,4,5};

Bir std::vector aslında 3 temel bilgiyi tutar:

1) pointer (verinin başladığı adres)
2) size (kaç eleman var)
3) capacity (kaç eleman sığabilir)

Bunu şöyle düşünebilirsin:

vector
+-------------------+
| pointer -> data   |
| size              |
| capacity          |
+-------------------+

Pointer ise heap'teki array’i gösterir.

size vector içinde kaç eleman olduğunu gösterir.

capacity, vector’ün maksimum kaç eleman tutabileceğini gösterir yeniden bellek ayırmadan.

capacity genelde *2 şekilde büyür.

capacity dolduğunda arka planda:
1) daha büyük bir array oluştur
2) eski elemanları kopyala
3) eski belleği sil



resize()

resize() vector'ün size’ını değiştirir.

vector<int> v;


Eğer kaç eleman ekleyeceğini biliyorsan:

vector<int> v;
v.reserve(1000);

Bu şunu yapar:

capacity = 1000

Böylece reallocation olmaz.


v.resize(5);

Bellek:

+----+----+----+----+----+
|0   |0   |0   |0   |0   |
+----+----+----+----+----+


reserve() vs resize()
Fonksiyon	Ne yapar
reserve()	capacity artırır
resize()	size değiştirir

push_back → sona ekleme
pop_back → sondan silme
insert → araya ekleme
erase → eleman silme
front → ilk eleman
back → son eleman
at → güvenli erişim
clear → hepsini sil

Iterator: container içindeki elemanları gezmeye yarayan nesne
Başka bir şekilde söyleyelim:

iterator = container pointer'ı gibi davranan nesne

Yani iterator çoğu zaman pointer gibi çalışır.


Basit Iterator Örneği
#include <iostream>
#include <vector>


int main()
{
    std::vector<int> v = {10,20,30};

    std::vector<int>::iterator it = v.begin();

    std::cout << *it << std::endl;
}

Çıktı:10

v.begin()

vector'ün ilk elemanını gösteren iterator döndürür.

Bellek:

[10][20][30]
 ^
 it



 Iterator’dan değeri almak için:

*it

kullanılır.

Bu pointer gibi çalışır.


Iterator İleri Gitme

Iterator artırılabilir.

it++;

Bellek:

Başlangıç:

[10][20][30]
 ^
 it

it++

[10][20][30]
     ^
     it



begin() ve end()

Vector iki önemli iterator fonksiyonu sağlar.

begin()
end()



begin()

İlk elemanı gösterir.

[10][20][30]
 ^
begin
end()

Son elemandan bir sonraki adresi gösterir.

[10][20][30]
            ^
           end

Bu adres eleman değildir.

Modern C++ Iterator

C++11’den sonra daha kısa yazılabilir:

for(auto it = v.begin(); it != v.end(); it++)
{
    cout << *it << endl;
}

auto compiler’ın tipi otomatik çıkarmasını sağlar.

Iterator Aritmetiği

Vector iterator’ları pointer gibi davranır.

Şunları yapabiliriz:

it++
it--
it + n
it - n

vector<int> v = {10,20,30,40};

auto it = v.begin();

it = it + 2;

cout << *it;

Çıktı:30


Iterator ve STL Algoritmaları

Iterator’ün en önemli nedeni:

STL algoritmaları iterator kullanır

Örneğin:

sort(v.begin(), v.end());

Bu şu anlama gelir:

begin ile end arasını sırala


shrink_to_fit()

Vector kapasitesi gereksiz büyümüşse küçültür.

Örnek:

vector<int> v;

v.reserve(100);

v.push_back(1);
v.push_back(2);

Durum:

size = 2
capacity = 100

Şimdi:

v.shrink_to_fit();

Durum:

capacity = 2
______________________________________________________________

Vector’ü Fonksiyona Parametre Olarak Göndermek (Copy)

En basit yöntem: vector’ü değer olarak göndermek.

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    for(int x : v)
        cout << x << " ";

    cout << endl;
}

int main()
{
    vector<int> nums = {1,2,3,4};

    printVector(nums);
}
Burada ne olur?

Fonksiyon çağrıldığında:

nums → kopyalanır → v

Memory'de:

nums: 1 2 3 4
v:    1 2 3 4

Yani:

✔ güvenli
❌ pahalı (büyük vectorlerde)

Örnek
void addElement(vector<int> v)
{
    v.push_back(100);
}
vector<int> a = {1,2,3};

addElement(a);

Sonuç:

a = 1 2 3

Çünkü kopya değişti.

2️⃣ Vector'ü Referans ile Göndermek

Gerçek programlarda çoğu zaman referans kullanılır.

void addElement(vector<int>& v)
{
    v.push_back(100);
}

Kullanım:

vector<int> a = {1,2,3};

addElement(a);

Sonuç:

a = 1 2 3 100
Çünkü
v → a'nın kendisini gösterir

Memory:

a: 1 2 3 100

kopya yok.

Örnek Program
void multiply(vector<int>& v)
{
    for(int &x : v)
        x *= 2;
}

int main()
{
    vector<int> nums = {1,2,3};

    multiply(nums);

    for(int x : nums)
        cout << x << " ";
}

Çıktı:

2 4 6
3️⃣ const Vector Parametreleri

Eğer fonksiyon vectorü değiştirmeyecekse en doğru yöntem:

const reference
void printVector(const vector<int>& v)
{
    for(int x : v)
        cout << x << " ";
}

Avantajları:

✔ kopya yok
✔ güvenli (değiştirilemez)

Derleme Hatası Örneği
void printVector(const vector<int>& v)
{
    v.push_back(5); // HATA
}

Çünkü:

const vector değiştirilemez
4️⃣ Fonksiyondan Vector Döndürmek

C++'ta fonksiyonlar vector döndürebilir.

vector<int> createVector()
{
    vector<int> v = {1,2,3,4};

    return v;
}

Kullanım:

int main()
{
    vector<int> nums = createVector();

    for(int x : nums)
        cout << x << " ";
}
        Vector Oluşturup Döndüren Fonksiyon

Örnek:

vector<int> generate(int n)
{
    vector<int> v;

    for(int i=0;i<n;i++)
        v.push_back(i);

    return v;
}

Kullanım:

vector<int> numbers = generate(10);

Vector:

0 1 2 3 4 5 6 7 8 9

int sum(const vector<int>& v)
{
    int total = 0;

    for(int x : v)
        total += x;

    return total;
}

Kullanım:

vector<int> nums = {10,20,30};

cout << sum(nums);

Çıktı:60

Genelde fonksiyon parametresi şöyle olur:

void func(const vector<int>& v);

Çünkü:

copy yok
safe
performanslı


Şu kullanım çok tehlikelidir:

vector<int>& create()
{
    vector<int> v = {1,2,3};

    return v;   // HATA
}

Çünkü:

v fonksiyon bitince yok olur

Bu dangling reference üretir.
______________________________________________________________

2D Vector Nedir?

Normal vector:

vector<int> v;

Bu yapı:

[1,2,3,4]

2D vector ise:

vector<vector<int>> matrix;

Bu yapı:

[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]

Yani:

satırlar → vector
matrix → satırların vectorü
2️⃣ 2D Vector Tanımlama
vector<vector<int>> matrix;

Şu an:

matrix = []

hiç satır yok.

3️⃣ 2D Vector Oluşturma (Boyut Vererek)

Örnek: 3x4 matrix

vector<vector<int>> matrix(3, vector<int>(4));

Açılımı:

3 satır
4 sütun

Sonuç:

[
 [0,0,0,0],
 [0,0,0,0],
 [0,0,0,0]
]

Çünkü vector default olarak 0 ile doldurur.

Örnek Program
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> matrix(3, vector<int>(4));

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Çıktı:

0 0 0 0
0 0 0 0
0 0 0 0
4️⃣ Başlangıç Değeri Vererek Matrix Oluşturma
vector<vector<int>> matrix(3, vector<int>(4, 7));

Sonuç:

[
 [7,7,7,7],
 [7,7,7,7],
 [7,7,7,7]
]
5️⃣ Matrix Elemanına Erişim

Syntax:

matrix[row][col]

Örnek:

matrix[1][2] = 10;

Matrix:

[
 [0,0,0],
 [0,0,10],
 [0,0,0]
]
6️⃣ Matrix'e Değer Atama
vector<vector<int>> matrix(3, vector<int>(3));

matrix[0][0] = 1;
matrix[0][1] = 2;
matrix[0][2] = 3;
7️⃣ Matrix Yazdırma

En klasik yöntem:

for(int i=0;i<matrix.size();i++)
{
    for(int j=0;j<matrix[i].size();j++)
    {
        cout << matrix[i][j] << " ";
    }

    cout << endl;
}
8️⃣ Range Based Loop ile Matrix
for(const auto& row : matrix)
{
    for(int x : row)
    {
        cout << x << " ";
    }

    cout << endl;
}

Bu modern C++ stilidir.

9️⃣ Dinamik Matrix Oluşturma

Mesela kullanıcıdan boyut alalım.

int rows, cols;

cin >> rows >> cols;

vector<vector<int>> matrix(rows, vector<int>(cols));
Değer Okuma
for(int i=0;i<rows;i++)
{
    for(int j=0;j<cols;j++)
    {
        cin >> matrix[i][j];
    }
}
Satır Eklemek (push_back)

2D vectorün güzel tarafı satır ekleyebilmemizdir.

vector<vector<int>> matrix;

matrix.push_back({1,2,3});
matrix.push_back({4,5,6});
matrix.push_back({7,8,9});

Sonuç:

[
 [1,2,3]
 [4,5,6]
 [7,8,9]
]

Matrix Boyutları

Satır sayısı:

matrix.size()

Sütun sayısı:

matrix[0].size()

Örnek:

cout << matrix.size();     // rows
cout << matrix[0].size();  // cols


2D vector gerçek matrix değildir.

Memory şu şekilde tutulur:

row1 -> [1,2,3]
row2 -> [4,5,6]
row3 -> [7,8,9]

Yani:

vector -> satır pointerları

Bu yüzden her satır farklı memory'de olabilir.
*/

int main()
{


    return 0;
}