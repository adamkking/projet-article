#include "Panier.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>

void Panier::ajouterArticle(const Article& a)
{
    // Ajoute un article a la fin du vector
    articles.push_back(a);
}

bool Panier::retirerArticle(const string& code)
{
    for (int i = 0; i < articles.size(); i++)
    {
        if (articles[i] == code)
        {
            // begin() donne le debut du vector, + i cible la position a supprimer
            articles.erase(articles.begin() + i);
            return true;
        }
    }

    return false;
}

double Panier::calculerSousTotalBrut() const
{
    double total = 0.0;

    for (int i = 0; i < articles.size(); i++)
    {
        total += articles[i].getPrix();
    }

    return total;
}

bool Panier::estVide() const
{
    return articles.empty();
}

void Panier::payer(const Employe& caissier) const
{
    double sousTotalBrut = calculerSousTotalBrut();
    double rabais = 0.0;

    // 50% de chance d'obtenir un rabais de 25%
    if (rand() % 2 == 0)
    {
        rabais = sousTotalBrut * 0.25;
    }

    // Les taxes sont calculees apres le rabais
    double sousTotalApresRabais = sousTotalBrut - rabais;
    double tps = sousTotalApresRabais * 0.05;
    double tvq = sousTotalApresRabais * 0.09975;
    double total = sousTotalApresRabais + tps + tvq;

    // Recuperation de la date et de l'heure actuelles
    time_t maintenant = time(0);
    tm infoTemps;
    localtime_s(&infoTemps, &maintenant);

    char dateBuffer[11];
    char heureBuffer[9];

    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", &infoTemps);
    strftime(heureBuffer, sizeof(heureBuffer), "%H:%M:%S", &infoTemps);

    cout << "******************************" << endl;
    cout << "** FACTURE **" << endl;
    cout << "******************************" << endl;

    for (int i = 0; i < articles.size(); i++)
    {
        cout << "- " << articles[i].getCode() << ": "
            << articles[i].getNom() << " "
            << fixed << setprecision(2) << articles[i].getPrix() << endl;
    }

    if (rabais > 0)
    {
        cout << "Rabais mystere: " << fixed << setprecision(2) << rabais << endl;
    }
    else
    {
        cout << "Rabais mystere: 0.00" << endl;
    }

    cout << "------------------------------" << endl;
    cout << "Sous-total: " << fixed << setprecision(2) << sousTotalApresRabais << endl;
    cout << "TPS: " << fixed << setprecision(2) << tps << endl;
    cout << "TVQ: " << fixed << setprecision(2) << tvq << endl;
    cout << "Total: " << fixed << setprecision(2) << total << endl;
    cout << "******************************" << endl;
    cout << "Vous avez ete servi par " << caissier.getNom() << endl;
    cout << "Date: " << dateBuffer << endl;
    cout << "Heure: " << heureBuffer << endl;
    cout << "******************************" << endl;
}

ostream& operator<<(ostream& os, const Panier& p)
{
    if (p.articles.empty())
    {
        os << "Le panier est vide." << endl;
        return os;
    }

    for (int i = 0; i < p.articles.size(); i++)
    {
        os << p.articles[i] << endl;
    }

    return os;
}