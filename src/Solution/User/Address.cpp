#include "Address.h"

using namespace std;

//Modificat

Address::Address()
{
    county="";
    locality="";
    street="";
    number=0;
    block="";
    apartment=0;
}

Address::Address(const Address &address)
{
	*this=address;
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
    county=jud;
    locality=loc;
    street=str;
    number=nr;
    block=bl;
    apartment=ap;
}

const Address &Address::operator=(const Address &adr)
{
    this->county=adr.county;
    this->locality=adr.locality;
    this->street=adr.street;
    this->number=adr.number;
    this->block=adr.block;
    this->apartment=adr.apartment;
    return *this;
}

void Address::setStrada(const string &str)
{
	street=str;
}

void Address::setNumber(int nr)
{
	number=nr;
}

void Address::setBlock(const string &bl)
{
	block=bl;
}

void Address::setApartment(int ap)
{
    apartment=ap;
}

void Address::setCounty(const string &jud)
{
    county=jud;
}

void Address::setLocality(const string &loc)
{
    locality=loc;
}

string &Address::getStreet()
{
	return street;
}

int Address::getNumber()
{
	return number;
}
string &Address::getBlock()
{
	return block;
}

int Address::getApartment()
{
	return apartment;
}

string &Address::getCounty()
{
    return county;
}

string &Address::getLocality()
{
	return locality;
}

bool Address::operator==(const Address &address)
{
    if(county!=address.county)
        return false;
    if(locality!=address.locality)
        return false;
    if(street!=address.street)
        return false;
    if(number!=address.number)
        return false;
    if(block!=address.block)
        return false;
    if(apartment!=address.apartment)
        return false;

    return true;
}


bool Address::operator!=(const Address &address)
{
    if(*this==address)
        return false;
    else
        return true;
}

ostream &operator<<(ostream &os, const Address &a)
{
    os<<a.county<<" ";
    os<<a.locality<<" ";
    os<<a.street<<" ";
    os<<a.number<<" ";
    os<<a.block<<" ";
    os<<a.apartment<<" ";
    return os;
}

json Address::toJSON()
{
	return json(*this);
}