/* Model.h */              // Nom du fichier d'en-tête

#ifndef MODEL_H            // Vérifie si le symbole MODEL_H n’a pas déjà été défini
#define MODEL_H            // Définit le symbole MODEL_H pour éviter les inclusions multiples (include guard)

#include <iostream>        // Inclusion de la bibliothèque standard pour l’affichage (cout, cin, etc.)
using namespace std;       // Permet d’éviter de devoir écrire std::cout, std::endl, etc.

/*#include "cstream"*/     // Ligne commentée, probablement inutile ou oubliée

// Déclaration d’un type énuméré Engine qui peut prendre 4 valeurs possibles
enum Engine {Petrol, Diesel, Electric, Hybrid};

//namespace carconfig{

// Déclaration de la classe Model
class Model {

private:                   // Partie privée : accessible uniquement à l’intérieur de la classe
    char* name;            // Pointeur vers une chaîne de caractères (nom du modèle)
    int power;             // Puissance du modèle (en chevaux par ex.)
    Engine engine;         // Type de moteur (Petrol, Diesel, Electric, Hybrid)
    float basePrice;       // Prix de base du modèle

public:                    // Partie publique : accessible à l’extérieur de la classe
    Model();               // Constructeur par défaut (initialisation sans paramètres)
    Model(const char* n, int p, Engine e, float bp); // Constructeur d’initialisation
    Model(const Model &mod); // Constructeur de copie (permet de dupliquer un objet)
    ~Model();              // Destructeur (libère la mémoire quand l’objet est détruit)

    Model& operator=(const Model& other);

    // Setters : méthodes pour modifier les attributs privés
    void setName(const char* n);  // Modifier le nom
    void setPower(int p);         // Modifier la puissance
    void setEngine(Engine e);     // Modifier le type de moteur
    void setBasePrice(float bp);  // Modifier le prix de base

    // Getters : méthodes pour accéder aux attributs privés
    const char* getName() const;  // Retourne le nom (en lecture seule)
    int         getPower() const; // Retourne la puissance
    Engine      getEngine() const;// Retourne le moteur
    float       getBasePrice() const; // Retourne le prix de base

    void display() const;         // Affiche les infos du modèle (implémentée ailleurs)
};

//}

#endif // Fin de la protection contre l’inclusion multiple
