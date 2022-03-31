#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include <map>
#include"../Solution/Server/Server.h"

class Utility{

public:
        void ordoneaza_dupa_pret(list<Product*>&);
        void ordoneaza_nume_tara_pret(list<Product*>&);
        void multi_in_judet(string&, Server*&);
        void ordoneaza_userId(list<User*>&);
};