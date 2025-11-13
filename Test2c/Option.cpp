/*****Option.cpp*****/
 

#include "Option.h"
#include <iostream>

using namespace	std;
using namespace carconfig;
//// CONSTRUCTEUR PAR DEFAUT
Option::Option()
{
	cout << ">>> Option : Constructeur par defaut <<<<<" << endl;
	code = "";
	label = "";
	price = 0.0f;
}

//// CONSTRUCTEUR D'INITIALISATION

Option::Option(const string &l,const string &c, float p)
{
	cout << ">>>> Option : Constructeur d'initialisation <<<<<" << endl;
	code = c;
	label = l;
	price = p;
}


// CONSTRUCTEUR DE COPIE
Option::Option(const Option &opt)
{
	cout << ">>>> Option : Constructeur de copie <<<<<" << endl;
	code = opt.code;
	label = opt.label;
	price = opt.price;
}


Option::~Option()
{
	cout << ">>>> Option : Destructeur <<<<<" << endl;

}


// SETTERS

void Option::setLabel(const string &l)
{
	label = l;
}

void Option::setCode(const string &c)
{
	code = c;
}

void Option::setPrice(float p)
{
	price = p;
}


//GETTERS  (permet la lecture Private)

//renvoi le code
string Option::getCode() const
{
	return code;
}

//Renvoi Libellé...
string Option::getLabel() const
{
	return label;
}

float Option::getPrice() const // ne s'applique pas au float mais a l'objet (THIS) par lequel la methode est appelé
{
	return price;
}

//Méthode d'affichage
void Option::display() const
{
	cout << "Code : " << code << " | Label : " << label << " | Prix : " << price << "€" << endl;
}

