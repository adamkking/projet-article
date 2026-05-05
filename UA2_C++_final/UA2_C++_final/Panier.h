#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Article.h"
#include "Employe.h"
using namespace std;

class Panier
{
private:
    // Le panier gere uniquement les articles qu'il contient
    vector<Article> articles;

public:
    void ajouterArticle(const Article& a);
    bool retirerArticle(const string& code);
    double calculerSousTotalBrut() const;
    bool estVide() const;
    void payer(const Employe& caissier) const;

    friend ostream& operator<<(ostream& os, const Panier& p);
};