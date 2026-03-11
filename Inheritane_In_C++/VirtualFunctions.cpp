#include<iostream>
#include<string>
/*

Virtula functions: base class da tanımlanan ve türetilmiş sınıflarda override edilebilen bir metottur

Base clastaki metotu virtual yaparsak subclass taki metotun üzerine yazabiliriz. 

*/
class Entity{
public:
    virtual std::string GetName(){
        return "Entity";
    }

};
class Player :public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        :m_Name(name){}

    std::string GetName()override {return m_Name;}
};

void PrintName(Entity* entity)
{
    std::cout<< entity->GetName()<<std::endl;
}
int main()
{
    /*Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("Celal");
    PrintName(p); 
    */
   Entity e;
   PrintName(&e);

   Player p("Celal");
   PrintName(&p);

   Entity* e2 = new Player("player");
   PrintName(e2);

   std::cout<< sizeof(e) << std::endl;
   std::cout<< sizeof(p) << std::endl;

    return 0;
}