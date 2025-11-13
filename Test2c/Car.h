/******** Car.h ******/

#ifndef CAR_H
#define CAR_H

#include "Model.h"
#include "Option.h"
#include <string>
#include <iostream>
using namespace std;

namespace carconfig{

class Car {

private:
	string name;
	Model model;
	Option* options[5];
public:
	Car();
	Car(const string &n,const Model &mod); // Initialisation
	Car(const Car &c); //Copie
	~Car();

	//Setters
	void setName(const string &n);
	void setModel(const Model &mod);

	//Getters
	string getName() const;
	Model getModel() const;
	float getPrice() const;


	// Gestion des options
	void addOption(const Option &options);
	void removeOption(const string &code);
	//affichage
	void display() const;

};

}

#endif