#include "utility.h"



//Query 3c
bool compare (Product* x, Product* y)
{
    NonFoodProduct *a = dynamic_cast<NonFoodProduct *>(x);
    NonFoodProduct *b = dynamic_cast<NonFoodProduct *>(y);
    return ((*a).getPrice()< b->getPrice());
}

void Utility::ordoneaza_dupa_pret(list<Product*> &mylist)
{
    mylist.sort(compare);
}

//Query 3d
bool compare_nume_tara_pret(Product* x, Product* y)
{
    if((*x).getName()==(*y).getName())
    {
        FoodProduct *a = dynamic_cast<FoodProduct *>(x);
        FoodProduct *b = dynamic_cast<FoodProduct *>(y);
        if((*a).getCountryOfOrigin()==(*b).getCountryOfOrigin())
        {
            return ((*a).getLeiPerKg()<(*b).getLeiPerKg());
        }
        else return ((*a).getCountryOfOrigin()<(*b).getCountryOfOrigin());

    }
    else return((*x).getName()<(*y).getName());

}

void Utility::ordoneaza_nume_tara_pret(list<Product*> &mylist)
{
    mylist.sort(compare_nume_tara_pret);
}

//Query 8e
void Utility::multi_in_judet(string& judet, Server *&server)
{
    std::map<string,int> jud;
    for(list<User*>::iterator it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
    {
        //daca judetul nu se afla in map il introducem
        if(jud.find((*it)->getDeliveryData().getCounty())==jud.end())
        {
           jud.insert(std::pair<string,int>((*it)->getDeliveryData().getCounty(),1));
        }
        //altfel crestem numarul lor
        else
        {
            jud[(*it)->getDeliveryData().getCounty()]=jud[(*it)->getDeliveryData().getCounty()]+1;
        }
    }
    //Calcularea maximului
    int currentMax = 0;
    string jud_max;
    for(std::map<string,int>::iterator iter = jud.begin(); iter != jud.end(); ++iter )
    {
        if (iter ->second > currentMax)
        {
            jud_max = iter->first;
            currentMax = iter->second;
        }
    }
    judet=jud_max;

    jud.clear();
}

bool compara_userId(User* x, User* y)
{
    return (x->getUserID()< y->getUserID());
}

void Utility::ordoneaza_userId(list<User*>&mylist)
{
    mylist.sort(compara_userId);
}