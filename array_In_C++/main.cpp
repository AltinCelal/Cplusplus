/*#include<iostream>


Diziler bellekte ardışık olarak tutulur.

Dizi ismi aslında ilk elemanı gösteren bir pointerdır.


Cache friendly dir.

cach friendly:Bir veri yapısının yada algoritmanın cache 
sistemini verimli şekilde kullanılması anlamına gelir.


cache friendly olması için gereken şey:
verilerin bellekte birbirine yakın olması ve programın
onları sırayla kullanması.



Cache line: Cpu nun Ram den cache'e veri getirirken kullandığı
en küçük veri bloğudur.Cpu veriyi tek tek byte olarak değil blok halinde 
getirir.Bu bloğa cache line denir.
genelde 64byte dır. 

int main()
{
    int example[5];
    
    for(int i=0 ; i<5 ;i++ )
    {
        example[i]= 2;
    } 

    std::cout<<*(example+1)<<std::endl;
    int *ptr = example;

    *(ptr+4) = 156;
    std::cout<<example[4]<<std::endl;

    return 0;
}*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 10 Milyon toplama işlemi yapacağız
const int ITERATIONS = 10 * 1024 * 1024; 
// Atlamalı erişim için 16 kat daha büyük bir alan lazım (16 * 4 byte = 64 byte = 1 Cache Line)
const size_t VECTOR_SIZE = (size_t)ITERATIONS * 16 + 1;

int main() {
    // Bellekte büyük bir yer ayırıyoruz (~640MB)
    vector<int> data(VECTOR_SIZE, 1);

    // 1. DURUM: Sıralı Erişim (Cache-Friendly)
    auto start1 = high_resolution_clock::now();
    long long sum1 = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        sum1 += data[i]; // Yan yana elemanlar, prefetcher bayram ediyor.
    }
    auto end1 = high_resolution_clock::now();

    // 2. DURUM: Atlayarak Erişim (Cache-Unfriendly)
    auto start2 = high_resolution_clock::now();
    long long sum2 = 0;
    for (int i = 0; i < ITERATIONS; ++i) {
        // Her seferinde tam bir cache line (64 byte) atlıyoruz.
        // i=0 -> data[0], i=1 -> data[16], i=2 -> data[32]...
        sum2 += data[i * 16]; 
    }
    auto end2 = high_resolution_clock::now();

    cout << "Sirali (10M islem): " << duration_cast<milliseconds>(end1 - start1).count() << "ms" << endl;
    cout << "Atlayarak (10M islem): " << duration_cast<milliseconds>(end2 - start2).count() << "ms" << endl;

    // Derleyicinin döngüleri optimize edip silmesini engellemek için sonuçları yazdıralım
    if (sum1 != sum2) cout << "Hata!" << endl;
    
    return 0;
}