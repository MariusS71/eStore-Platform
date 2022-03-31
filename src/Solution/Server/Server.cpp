#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__() {
    for (list<User *>::iterator it = usr.begin(); it != usr.end(); ++it)
    {
        if(__UserID__ProductsCart__.find((*it)->getUserID())==__UserID__ProductsCart__.end())
        {
            ShoppingCart *c = new ShoppingCart;
            __UserID__ProductsCart__.insert(  std::pair<int,ShoppingCart *>((*it)->getUserID(), c));
        }
    }
}

list<Product *> &Server::getProductsList()
{
	return prod;
}

list<User *> &Server::getUsersList()
{
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
  if (quantity<1)
      return false;

    //verificam daca exista in lista de useri unul cu acest ID
    int verif=0;
    for(list<User*>::iterator it = usr.begin(); it != usr.end(); ++it){
        if((*it)->getUserID()==userID)
        {
            verif++;
            break;
        }
    }
    if(verif!=1)
        return false;

    //verificam daca exista produse in stoc
    verif=0;
    list<Product*>::iterator iter;
    for(iter = prod.begin(); iter != prod.end(); ++iter){
        if((*iter)->getId()==productID && (*iter)->checkQuantity(quantity))
        {
            verif++;
            break;
        }
    }
    if(verif==0)
        return false;

    //verificam daca mai are acel tip de produse in cos deja: daca da, crestem cantitatea, altfel adaugam produsul nou in cos
   map<int, int>::iterator itt=__UserID__ProductsCart__[userID]->getShoppingCart().find(productID);
    if(itt != __UserID__ProductsCart__[userID]->getShoppingCart().end())
    {
        __UserID__ProductsCart__[userID]->raiseQuantity(productID, quantity);
        (*iter)->decreaseQuantity(quantity);
    }
    else
    {
        __UserID__ProductsCart__[userID]->addProduct(productID, quantity);
        (*iter)->decreaseQuantity(quantity);
    }
    return true;

}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
    if (quantity<1)
    return false;
    //verificam daca exista in lista de useri unul cu acest ID
    int verif=0;
    for(list<User*>::iterator it = usr.begin(); it != usr.end(); ++it){
        if((*it)->getUserID()==userID)
        {
            verif++;
            break;
        }
    }
    if(verif!=1)
        return false;



    //verificam daca mai are acel tip de produse in cos deja: daca sunt mai multe decat quantity, scadem cantitatea,
    //daca sunt mai putine stergem produsul din cos
    map<int, int>::iterator itt=__UserID__ProductsCart__[userID]->getShoppingCart().find(productID);
    if(itt != __UserID__ProductsCart__[userID]->getShoppingCart().end())
    {
        if(__UserID__ProductsCart__[userID]->getQuantity(productID)>quantity)
        {
            __UserID__ProductsCart__[userID]->lowerQuantity(productID, quantity);
            list<Product*>::iterator it;
            for(it = prod.begin(); it != prod.end(); ++it)
            {
                if((*it)->getId()==productID )
                {
                    (*it)->increaseQuantity(quantity);
                }
            }

        }
        else
        {
            __UserID__ProductsCart__[userID]->deleteProduct(productID);
            list<Product*>::iterator it;
            for(it = prod.begin(); it != prod.end(); ++it)
            {
                if((*it)->getId()==productID )
                {
                    (*it)->increaseQuantity(__UserID__ProductsCart__[userID]->getQuantity(productID));
                }
            }
        }
    }
    else return false;
    return true;

}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}