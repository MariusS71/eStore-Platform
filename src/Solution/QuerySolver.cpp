#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
    std::list<Product*> mylist;
    for(list<Product*>::iterator it = server->getProductsList().begin(); it != server->getProductsList().end(); ++it)
    {

        if((*it)->getProductType()=="redus" && (*it)->getCategory()=="espressor" && (*it)->getQuantity()>0)
        {
            DiscountedProduct *x = dynamic_cast<DiscountedProduct *>(*it);
            if(x!=NULL)
            {
                if ((*x).getDiscountPercentage() > 0)
                    mylist.push_back(*it);
            }
        }
    }
    return mylist;
}

list<User*> QuerySolver::Query_3b(){
    std::list<User*> mylist;
    for(list<User*>::iterator it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
    {
        if((*it)->getUserType()=="nonPremium")
        {
            BasicUser *x = dynamic_cast<BasicUser *>(*it);
            if(x!=NULL)
            {
                if ((*x).getTransportCost() <= 11.5)
                    mylist.push_back(*it);
            }
        }
    }
    return mylist;
}

list<Product*> QuerySolver::Query_3c(){
    std::list<Product*> mylist;
    for(list<Product*>::iterator it = server->getProductsList().begin(); it != server->getProductsList().end(); ++it)
    {
        if((*it)->getProductType()=="resigilat")
        {
            ResealedProduct *x = dynamic_cast<ResealedProduct *>(*it);
            if(x!=NULL)
            {
                if ((*x).getReason()=="lipsa_accesorii")
                    mylist.push_back(*it);
            }
        }
    }
    Utility *u=NULL;
    u->ordoneaza_dupa_pret(mylist);

    return mylist;
}

list<Product*> QuerySolver::Query_3d(){
    std::list<Product*> mylist;
    for(list<Product*>::iterator it = server->getProductsList().begin(); it != server->getProductsList().end(); ++it)
    {
        if((*it)->getProductType()=="alimentar")
        {
            mylist.push_back(*it);
        }
    }
    Utility *u=NULL;
    u->ordoneaza_nume_tara_pret(mylist);
    return mylist;
}

list<User*> QuerySolver::Query_3e(){
    std::list<User*> mylist;
    Utility *u=NULL;
    string judet;
    u->multi_in_judet(judet, server);
    for(list<User*>::iterator it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
    {
        if((*it)->getDeliveryData().getCounty()==judet && (*it)->getDeliveryData().getBlock()=="-" && (*it)->getBillingData().getBlock()=="-")
        {
            mylist.push_back(*it);
        }
    }
    //ordonare dupa user id
    u->ordoneaza_userId(mylist);
    return mylist;
}

list<User*> QuerySolver::Query_3f()
{/*
    std::list<User*> mylist;
    for(list<User*>::iterator it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
    {
        if((*it)->getUserType()=="premium")
        {
            PremiumUser *x = dynamic_cast<PremiumUser *>(*it);
            for(map<int, int>::iterator iter = (*x).getDiscounts().begin(); iter !=(*x).getDiscounts().end() ;++iter)
            {
                if((*iter).first>1000)
                {
                    if(((*iter).first/100)%10==1 || ((*iter).first/100)%10==6)
                    {
                        mylist.push_back(*it);
                    }
                }
                else if((*iter).first<1000)
                {
                    if(((*iter).first/10)%10==1 || ((*iter).first/10)%10==6)
                    {
                        mylist.push_back(*it);
                        break;
                    }
                }
            // cout<<(*iter).first<<endl;
            }
        }
    }*/
    std::list<User*> mylist;
    std::list<int> idlist;
    //Cautam telefoanele si imprimantele din stoc pentru a le stoca id ul
    for(list<Product*>::iterator it = server->getProductsList().begin(); it != server->getProductsList().end(); ++it)
    {
        if((*it)->getCategory()=="telefon" || (*it)->getCategory()=="imprimanta")
        {
            idlist.push_back((*it)->getId());
        }
    }
    //in mapele de reducere ale userilor premium verificam daca se gasesc vreun id din lista creata anterior
    for(list<User*>::iterator it = server->getUsersList().begin(); it != server->getUsersList().end(); ++it)
    {
        if ((*it)->getUserType() == "premium")
        {
            PremiumUser *x = dynamic_cast<PremiumUser *>(*it);
            for(list<int>::iterator iter= idlist.begin(); iter!= idlist.end(); ++iter)
            {
                if((*x).getDiscounts().find((*iter))!=(*x).getDiscounts().end())
                {
                    mylist.push_back(*it);
					break;
                }
            }
        }
    }
    idlist.clear();
    return mylist;
}
