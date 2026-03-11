#include<iostream>
/*
g++ -save-temps main.cpp log.cpp -o test

komutu ile oluşan ara dosyalarda görülebilir.

çıktılar: 

.ii uzantılılar: Preprocessor çıktısı
=======================================================================
.s uzantılılar:Assembly çıktısı

Ne içerir?

Hedef mimariye göre assembly kodu (x86_64 vs)

Fonksiyon çağrıları

Register kullanımı

Stack frame yapısı

Ne içermez?

C++ sözdizimi

Tip bilgisi (çoğu silinmiş)
=======================================================================


.o çıktısı:Object file (ELF)

Ne içerir?

Makine kodu

Symbol table (fonksiyonlar, global değişkenler)

Relocation bilgileri

Debug bilgisi (varsa -g ile)

Linker devreye girer tek bir derlenmiş dosyaya çevirir.

=======================================================
Final executable

Ne içerir?

Link edilmiş ELF binary

libstdc++, libc sembolleri bağlanmış

Runtime startup code (_start)




log dosyasını c diline çevirince bir hata olmadı.
*/
extern "C"{
    void logg(const char* log);
}
int main()
{
    logg("Celal");

    return 0;
}

/*

name mangling: Name mangling (isim karıştırma, name decoration), C++ derleyicisinin fonksiyon isimlerini linker için benzersiz hâle getirme yöntemidir.

C++’ta aynı isimle birden fazla fonksiyon olabilir (function overloading)

Fonksiyonlar class içinde veya namespace içinde olabilir

Linker ise sadece düz isimlerle çalışır → derleyici isimleri “mangle” ederek benzersiz yapar

Özet: Name mangling, linker’ın doğru fonksiyonu bulabilmesi için fonksiyon adını + parametre tiplerini + namespace/class bilgisini birleştirip tek bir sembol hâline getirir.



Neden gerek var?

Örnek C++ kodu:

void foo(int x);
void foo(double y);


İki fonksiyon aynı isim: foo

Eğer linker sadece isimleri görseydi → çakışma olurdu

Çözüm: derleyici fonksiyon isimlerini farklılaştırır

C ile fark

C fonksiyonları → mangling yapılmaz

C++ fonksiyonları → overload, class, namespace gibi bilgiler name mangling ile eklenir

Eğer C++’tan C fonksiyonunu çağıracaksan:

extern "C" void log(const char* msg);


extern "C" → name mangling yapmaz → C fonksiyonunu linker bulabilir


Eğer hem c kodunu hemde c++ kodunu aynı projede kullanmam gerekirse:
gcc -c logg.c // c için obje dosyasını oluşturur

g++ -c main.cpp // c++ için obje dosyasını oluşturur.

g++ main.o logg.o -o program// daha sonra bu obje dosyalarını linker e veriyoruz

./program programı çalıştırıyoruz.

*/