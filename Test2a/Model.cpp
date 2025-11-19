/*Model.cpp*/                      
#include "Model.h"                 // Inclusion du fichier d'en-tête de la classe
#include <string.h>                // Fonctions C pour la gestion de chaînes (strlen, strcpy)

using namespace std;
//using namespace carconfig;
/* ---------- CONSTRUCTEUR--------------- */

// Constructeur par défaut
Model::Model()
{
    cout << ">>> Model = constructeur par defaut" << endl; // Message de debug
    name = NULL;                    // Pointeur name initialisé à NULL
    setName("nom");                 // Nom par défaut "nom"
    setPower(0);                    // Puissance par défaut = 0
    setEngine(Engine::Petrol);      // Type de moteur par défaut = essence
    setBasePrice(0.0);              // Prix par défaut = 0
}

// Constructeur d’initialisation
Model::Model(const char* n, int p, Engine e, float bp)
{
    cout << ">>> Model : constructeur d'initialisation <<<" << endl;
    name = NULL;                // Toujours initialiser à NULL avant allocation
    setName(n);                 // Affecte le nom passé en paramètre
    setPower(p);                // Affecte la puissance
    setEngine(e);               // Affecte le type de moteur
    setBasePrice(bp);           // Affecte le prix
}

// Constructeur de copie
Model::Model(const Model &mod)
{
    cout << ">>> Model = constructeur de copie" << endl;
    name = NULL;                        // On part d’un pointeur NULL
    setName(mod.getName());               // Copie du nom (allocation mémoire)
    setPower(mod.getPower());             // Copie de la puissance
    setEngine(mod.getEngine());           // Copie du type de moteur
    setBasePrice(mod.getBasePrice());     // Copie du prix
}

// Destructeur
Model::~Model()
{
    cout << ">>> Model = Destructeur par defaut <<<" << endl;
    if(name)
        delete [] name;
    name = NULL;
}

// OPERATEUR AFFECTATION

Model& Model::operator=(const Model& other)
{
    if(this == &other) return *this;

    //Utiliser SetName pour liberation préalable si nécessaire
    setName(other.getName());
    power = other.getPower();
    engine = other.getEngine();
    basePrice = other.getBasePrice();

    return *this;
}

/* ------------------SETTER------------------------ */

// Définit un nouveau nom
void Model::setName(const char*n)
{
    if(!n) return;

    if(name){
        delete[] name;
        name = NULL;
    }           // Libère l’ancien nom si déjà alloué

    name = new char[strlen(n)+1];        // Alloue un tableau de char (+1 pour '\0')
    strcpy(name,n);                      // Copie la chaîne
}

// Définit la puissance
void Model::setPower(int p)
{
    if( p < 0) return;                   // Refuse les valeurs négatives
    power = p;
}

// Définit le type de moteur
void Model::setEngine(Engine e)
{
    engine = e;
}

// Définit le prix
void Model::setBasePrice(float bp)
{
    if(bp < 0.0) return;                 // Refuse les valeurs négatives
    basePrice = bp;
}

/* ------------------GETTER------------------------ */

// Retourne le nom
const char* Model::getName() const
{
    return name;
}

// Retourne la puissance
int Model::getPower() const
{
    return power;
}

// Retourne le moteur
Engine Model::getEngine() const
{
    return engine;
}

// Retourne le prix
float Model::getBasePrice() const
{
    return basePrice;
}

/* -------------- METHODE D'INSTANCE -------------- */

// Affiche les informations du modèle
void Model :: display() const
{
    cout << "Model: ";               
    if (name)                       // Si un nom existe
        cout << name;               // On l’affiche
    else
        cout << "pas de nom";       // Sinon message par défaut

    cout << "( " << power << " Ch, "; // Affiche la puissance

    // Affiche le moteur en fonction de l’énumération
    switch (engine)
    {
    case Engine::Petrol:   cout << "essence, ";    break;
    case Engine::Diesel:   cout << "diesel, ";     break;
    case Engine::Electric: cout << "electrique, "; break;
    }

    cout << basePrice << " euros)" << endl; // Affiche le prix
}
