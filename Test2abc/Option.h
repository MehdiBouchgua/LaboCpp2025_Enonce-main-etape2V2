/*****Option.h*****/

#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <vector>
#include "Model.h"
//#include "Car.h"

using namespace std;
namespace carconfig{

class Option {
private:
	string code; // Identifiant de l'option
	string label;
	float price;

public:
	Option();
	Option(const string &c, const string &l, float p); //Constructeur d'init
	Option(const Option &opt);
	~Option(); //destructeur

	//SETTERS
	void setCode(const string &c);
	void setLabel(const string &l);
	void setPrice(float p);

	//GETTERS
	string getCode() const;
	string getLabel() const;
	float getPrice() const;

	//AFFICHAGE
	void display() const;

	
};

}

#endif