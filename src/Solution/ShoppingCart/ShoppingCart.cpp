#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
    this->payMethod=payMethod;
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod=payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
    if(quantity>0)
    {
        shoppingCart.insert(std::pair<int, int>(id, quantity));
    }
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
    shoppingCart[id]=quantity+shoppingCart[id];
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
    shoppingCart[id]=shoppingCart[id]-quantity;
}

int ShoppingCart::getQuantity(int productID)
{
    if (shoppingCart.find(productID) == shoppingCart.end() )
    {
        return -1;
    }
    else
    {
        return shoppingCart[productID];
    }
}

void ShoppingCart::deleteProduct(int productID)
{
	shoppingCart.erase(productID);
}

map<int, int> &ShoppingCart::getShoppingCart()
{
    return shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
    for (map<int, int>::iterator it = shoppingCart.begin();
         it != shoppingCart.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
	cout<<"Metoda de plata "<<payMethod<<endl;
}

json ShoppingCart::toJSON()
{
  return json(*this);
}