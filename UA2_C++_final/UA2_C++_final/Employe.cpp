#include "Employe.h"

Employe::Employe(string numero, string nom)
{
    // this-> permet de distinguer les attributs des parametres
    this->numero = numero;
    this->nom = nom;
}

string Employe::getNumero() const
{
    return numero;
}

string Employe::getNom() const
{
    return nom;
}

bool Employe::operator==(const string& numeroSaisi) const
{
    // Compare le numero de l'objet avec celui saisi
    return numero == numeroSaisi;
}