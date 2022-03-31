#include "BasicUser.h"

using namespace std;

//Modificat

BasicUser::BasicUser()
{
    costTransport=0;
}

BasicUser::BasicUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int id, const string &nume, const string &prenume, const string &email, float costTransport) : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
	this->costTransport=costTransport;
}

BasicUser::BasicUser(const BasicUser &unp) : User(unp)
{
	//good
}

BasicUser &BasicUser::operator=(const BasicUser &unp)
{
    costTransport=unp.costTransport;
    UserID=unp.UserID;
    email=unp.email;
    firstName=unp.firstName;
    lastName=unp.lastName;
    billingData=unp.billingData;
    deliveryData=unp.deliveryData;
    return *this;
}

void BasicUser::setTransportCost(int cost)
{
    costTransport=cost;
}

float BasicUser::getTransportCost()
{
	return costTransport;
}

void BasicUser::displayUser()
{
    cout << "Basic User" << endl;
    cout << "billingData : " << this->billingData << endl;
    cout << "deliveryData : " << this->deliveryData << endl;
    cout << "Nume : " << this->lastName << endl;
    cout << "Prenume : " << this->firstName << endl;
    cout << "Email : " << this->email << endl;
    cout << "User id : " << this->UserID << endl;
    cout << "Cost transport : " << this->costTransport << endl
         << endl;
}

string BasicUser::getUserType()
{
	return "nonPremium";
}

json BasicUser::toJSON()
{
	return json(*this);
}
