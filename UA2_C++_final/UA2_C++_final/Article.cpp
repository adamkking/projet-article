#include "Article.h"
#include <iomanip>

Article::Article(string code, string nom, double prix)
{
    this->code = code;
    this->nom = nom;
    this->prix = prix;
}

string Article::getCode() const
{
    return code;
}

string Article::getNom() const
{
    return nom;
}

double Article::getPrix() const
{
    return prix;
}

bool Article::operator==(const string& codeSaisi) const
{
    return code == codeSaisi;
}

ostream& operator<<(ostream& os, const Article& a)
{
    // fixed et setprecision(2) forcent l'affichage monetaire sur 2 decimales
    os << a.code << ": " << a.nom << " - " << fixed << setprecision(2) << a.prix << "$";
    return os;
}