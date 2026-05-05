#pragma once
#include <string>
using namespace std;

class Employe
{
private:
    // Attributs prives : on protege les donnees de l'objet
    string numero;
    string nom;

public:
    // Constructeur avec valeurs par defaut
    Employe(string numero = "", string nom = "");

    // Accesseurs const : ils lisent seulement les donnees
    string getNumero() const;
    string getNom() const;

    // Permet de comparer un employe avec un numero saisi
    bool operator==(const string& numeroSaisi) const;
};