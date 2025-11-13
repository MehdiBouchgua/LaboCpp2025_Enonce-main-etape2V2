/****** Car.cpp *******/

#include "Car.h"
#include "Option.h"
#include <string.h>
#include <iostream>

using namespace std;
using namespace carconfig;

// Constructeur par défaut

Car::Car() {
	cout << ">>> Car = constructeur par defaut" << endl;
	name = "Projet_sans_nom"; //
	Model mod; //model par defaut
	setModel(mod); // assignation de ce modele a la voiture a l'aide du setter
	for(int i=0;i<5;i++)
	{
		options[i] = nullptr;
	}
}

// Constructeur d'initialisation

Car::Car(const string &n,const Model &mod) {
	cout << ">>> Car : constructeur d'initialisation <<<" << endl;
	setName(n);
	setModel(mod);
	for(int i=0;i<5;i++)
	{
		options[i] = nullptr;
	}
}

// Constructeur de copie


Car::Car(const Car &c) {
	cout << ">>> Car : Constructeur de copie <<<" << endl;
	//passage en ref de l'objet c const pour eviter une copie inutile
	name = c.name;
	model = c.model; //La copie automatique est safe car string
	for(int i=0;i<5;i++)
	{
		if(c.options[i])
		{
			options[i] = new Option(*c.options[i]);
		}
		else
		{
			options[i] = nullptr;
		}
	}

}

// Destructeur

Car::~Car()
{
	cout << ">>> Car : destructeur <<<" << endl;
	// Rien a désallouer car pas de pointeur ni de mémoire dynamique -> destructeur de "Model" appelé auto
	for(int i=0;i<5;i++)
	{
		delete options[i];
		options[i] = nullptr;
	}
}


// SETTERS

void Car::setName(const string &n)
{
	name = n; //affectation directe de la valeur passé en parametre a l'attribut privé "string name"
}

void Car::setModel(const Model &mod)
{
	model = mod; //On recopie le model passé en paramètre
}


//GETTERS

string Car::getName() const
{
	return name; // on retourne une copie du nom et pas de modif de l'objet car const
}

Model Car::getModel() const
{
	return model; // Test2a.cpp getModel().display() donc retour par valeur
}


void Car::addOption(const Option &opt)
{
	for(int i=0;i<5;i++)
	{
		if(options[i] == nullptr)
		{
			options[i] = new Option(opt);
			return;
		}
	}
	cout << " Impossible de rajouter une option (5 max)";
}

void Car::removeOption(const string &code)
{
	for(int i=0;i<5;i++)
	{
		if(options[i] && options[i]->getCode() == code)
		{
			delete options[i];
			options[i] = nullptr;
			cout << "Option" << code << "retiree." << endl;
			return;
		}
	}
	cout << "Option" << code <<  "introuvable" << endl;
}

float Car::getPrice() const
{
	float total = model.getBasePrice();
	for(int i=0;i<5;i++)
	{
		if(options[i])
		{
			total += options[i]->getPrice();
		}
	}
	return total;
}

//Affichage complet

void Car::display() const
{
	cout << ">>>> Voiture <<<<" << endl;
	cout << "Nom : " << name << endl;
	cout << ">>>> Model <<<<" << endl;
	model.display();
	cout << ">>>> Option <<<<" << endl;
	bool hasOption = false;
	for(int i=0;i<5;i++)
	{
		if(options[i])
		{
			options[i]->display();
			hasOption = true;
		}
	}
	if(!hasOption)
	{
		cout << "Aucune option" << endl;
	}
	cout << "Prix total : " << getPrice() << " € " << endl;
}