#include<iostream>
#include<vector>
/*

Şimdi aşağıda basit bir struct yapımız var.
3 adet int değişkeni var. Constructor ile 3 adet int
değer alıp bu değişkenlere atıyoruz.Daha sonra bir de 
copy constructors yazdık ki kaç adet kopylama yapıyor bir bakalım.

Aşağıdaki ilk programda:
0
Copied!
1
Copied!
Copied!
2
Copied!
Copied!
Copied!
4
çıktısı alıyoruz. Peki neden?

ilk başta vektörümüzün kapasitesi(capacity) 0.
biz ilk elemanımı eklemeye çalıştığımızda (1,2,3)
kapasite 1 e artıyor ve objemiz ilk baştya Temporary olarak oluşturuluyor.
Main alanıda stack de oluşturuluyor daha sonra bu oluşturulan Temporary
objesi vektöre kopyalanıyor.Bu yüzden copy constructor çalışıyor yani
1 eleman eklemek için aşağıdaki programda 1 adet kopyalama yapılıyor.

Bu kopylamadan sonra vektör ün kapasitesi 1 di ce size da 1.
Biz vektöre bir eleman daha eklemek istiyoruz.
( vertices.push_back({4,5,6});)

bu sefer capacity nin artamsı lazım 2 oluyor.
ilk baştaki vektör yeni artırılmış kapasiteli alana kopyalanıp ilk adresdeki değerler siliniyor.Bu ilk kopyalama.Daha sonra yeni eklediğimiz değer de ilk eklediğimizdeki gibi temporary objesi olarak oluşturulup main de oluşturulur daha sonra bu da vektöre kopyalanır burada da bir kopyalama oluşuyor(2. koypalama.)

vektöre bir değer daha eklemek istediğimizde 
(vertices.push_back({7,8,9});) capacity 2 ydi sonra 4 e yükseldi(eski kapasite * 2) şimdi yeni artırılmış alana önceki 2 eleman kopyalanak fazldana 2 kopya ve yeni oluşturdupumuz temporary obje de yeni alana kopyalanacak bu yüzden 1 kopyalamada buradan bu adımda toplamda 3 kopya.

bir vektör yapısına 3 tane Vertex nesnesi eklemek için toplamda 6 adet kopyalama yapıldı.Bu neden önemli:
Her kopylama sistemin performansını düşürür.

Bunun önüne ise 2 adımda geçebiliriz.
1- Eğer vektörümüze ekleneden veri sayısı belli ise bunu ilk oluştururken belirtip (capacity i ilk başta belirleyip sürekli
artırılmaktan kaçılarak) kopyalamadan kaçınmak.

2-emplace_back kullanmak.emplace_back temporary objesi oluşturmadan 
direk vektöre yerleştirir.

2. yazdığımız programda aynı işlemi gerçekleştiyor ama çıktısı:
Capacity:3
Size:0
Capacity:3
Size:1
Capacity:3
Size:2
Capacity:3
Size:3

burada copy constructor hiç çalışmadı yani hiç kopyalama yapılmadı.
2.Program (yorum satırı dışındaki) ilkine göre çok daha hızlı-performanslı çalışacaktır.

*/

struct Vertex
{
    int x, y, z;

    Vertex(int x, int y, int z)
    :x(x), y(y),z(z)
    {}

    Vertex(const Vertex& vertex)
    :x(vertex.x),y(vertex.y),z(vertex.z)
    {
        std::cout<<"Copied!"<<std::endl;
    }
};

int main()
{
    /*std::vector<Vertex> vertices;
    std::cout<<vertices.capacity()<<std::endl;

    vertices.push_back({1,2,3});
    std::cout<<vertices.capacity()<<std::endl;

    vertices.push_back({4,5,6});
    std::cout<<vertices.capacity()<<std::endl;

    vertices.push_back({7,8,9});
    std::cout<<vertices.capacity()<<std::endl;*/




    std::vector<Vertex> vertices;
    vertices.reserve(3);
    std::cout<<"Capacity:"<<vertices.capacity()<<std::endl;
    std::cout<<"Size:"<<vertices.size()<<std::endl;

    vertices.emplace_back(1,2,3);
    std::cout<<"Capacity:"<<vertices.capacity()<<std::endl;
    std::cout<<"Size:"<<vertices.size()<<std::endl;

    vertices.emplace_back(4,5,6);
    std::cout<<"Capacity:"<<vertices.capacity()<<std::endl;
    std::cout<<"Size:"<<vertices.size()<<std::endl;

    vertices.emplace_back(7,8,9);
    std::cout<<"Capacity:"<<vertices.capacity()<<std::endl;
    std::cout<<"Size:"<<vertices.size()<<std::endl;

    return 0;
}