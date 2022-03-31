#include "NonFoodProduct.h"

//Modificat

NonFoodProduct::NonFoodProduct()
{
    producer="";
    yearsOfWarranty=0;
    price=0;
}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{
	this->producer=producer;
	this->yearsOfWarranty=yearsOfWarranty;
	this->price=price;
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
    producer=pn.producer;
    yearsOfWarranty=pn.yearsOfWarranty;
    price=pn.price;
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	yearsOfWarranty=garantieAni;
}

void NonFoodProduct::setPrice(float price)
{
	this->price=price;
}

void NonFoodProduct::setProducer(const string &producer)
{
	this->producer=producer;
}

int NonFoodProduct::getYearsOfWarranty()
{
	return yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	return price;
}

string &NonFoodProduct::getProducer()
{
	return this->producer;
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{

    if(obj.producer!=producer)
        return false;
    if(obj.yearsOfWarranty!=yearsOfWarranty)
        return false;
    if(obj.price!=price)
        return false;
    if(obj.id!=id)
        return false;
    if(obj.name!=name)
        return false;
    if(obj.quantity!=quantity)
        return false;
    if(obj.category!=category)
        return false;
    return true;
}


const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	price=a.price;
	yearsOfWarranty=a.yearsOfWarranty;
	producer=a.producer;
	name=a.name;
	quantity=a.quantity;
	category=a.category;
	id=a.id;
    return *this;
}

string NonFoodProduct::getProductType()
{
	return "nealimentar";
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
