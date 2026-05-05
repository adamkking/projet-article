#pragma once
#include <string>
#include <iostream>
using namespace std;

class Article
{
private:
    // Chaque article connait seulement son code, son nom et son prix
    string code;
    string nom;
    double prix;

public:
    Article(string code = "", string nom = "", double prix = 0.0);

    string getCode() const;
    string getNom() const;
    double getPrix() const;

    // Permet de comparer un article avec un code saisi
    bool operator==(const string& codeSaisi) const;

    // Fonction amie pour afficher facilement un article avec cout
    friend ostream& operator<<(ostream& os, const Article& a);
};
