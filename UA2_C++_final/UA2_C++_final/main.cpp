#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Employe.h"
#include "Article.h"
#include "Panier.h"
using namespace std;

// Fonctions utilitaires : elles gardent le main plus propre
void afficherMenu();
void afficherCatalogue(const vector<Article>& catalogue);
bool codeArticleValide(const vector<Article>& catalogue, const string& code);
Article trouverArticle(const vector<Article>& catalogue, const string& code);
bool numeroEmployeValide(const vector<Employe>& employes, const string& numero);
Employe trouverEmploye(const vector<Employe>& employes, const string& numero);

int main()
{
    // Initialise le generateur aleatoire une seule fois
    srand((unsigned int)time(0));

    // Liste des employes autorises
    vector<Employe> employes;
    employes.push_back(Employe("001", "Andrew"));
    employes.push_back(Employe("002", "Nabil"));
    employes.push_back(Employe("003", "Marc"));
    employes.push_back(Employe("004", "Jean-Gabriel"));
    employes.push_back(Employe("005", "Caroline"));

    // Catalogue officiel du projet
    vector<Article> catalogue;
    catalogue.push_back(Article("A1", "Crayons", 3.99));
    catalogue.push_back(Article("A2", "Cahier Canada", 1.59));
    catalogue.push_back(Article("B1", "Table pliante", 66.99));
    catalogue.push_back(Article("B2", "Fauteuil en cuir", 199.99));
    catalogue.push_back(Article("B3", "Bureau d'etudiant", 118.99));
    catalogue.push_back(Article("L1", "Laptop ASUS", 600.89));
    catalogue.push_back(Article("L2", "Laptop HP", 700.89));
    catalogue.push_back(Article("L3", "Laptop Acer", 250.99));

    string numeroSaisi;
    Employe caissier;

    // Authentification : on boucle jusqu'a obtenir un numero valide
    do
    {
        cout << "Veuillez vous identifier: ";
        cin >> numeroSaisi;

        if (!numeroEmployeValide(employes, numeroSaisi))
        {
            cout << "ERREUR: Numero d'employe invalide" << endl;
        }
        else
        {
            caissier = trouverEmploye(employes, numeroSaisi);
            cout << "Bonjour, " << caissier.getNom() << endl;
            break;
        }

    } while (true);

    Panier panier;
    string choix;

    // Boucle principale du menu
    do
    {
        afficherMenu();
        cout << "Votre choix: ";
        cin >> choix;

        if (choix == "1")
        {
            string code;

            cout << "********************" << endl;
            cout << " AJOUT ARTICLE " << endl;
            cout << "********************" << endl;

            afficherCatalogue(catalogue);

            cout << "Votre choix: ";
            cin >> code;

            if (!codeArticleValide(catalogue, code))
            {
                cout << "Choix invalide..." << endl;
            }
            else
            {
                // On cherche l'article dans le catalogue puis on l'ajoute au panier
                panier.ajouterArticle(trouverArticle(catalogue, code));
            }
        }
        else if (choix == "2")
        {
            string code;

            cout << "********************" << endl;
            cout << " RETIRER ARTICLE " << endl;
            cout << "********************" << endl;

            if (panier.estVide())
            {
                cout << "Le panier est vide." << endl;
            }
            else
            {
                cout << panier;
                cout << "Votre choix: ";
                cin >> code;

                if (!panier.retirerArticle(code))
                {
                    cout << "Choix invalide..." << endl;
                }
            }
        }
        else if (choix == "3")
        {
            cout << "********************" << endl;
            cout << " AFFICHER PANIER " << endl;
            cout << "********************" << endl;

            if (panier.estVide())
            {
                cout << "Le panier est vide." << endl;
            }
            else
            {
                cout << panier;
            }
        }
        else if (choix == "0")
        {
            if (panier.estVide())
            {
                cout << "Le panier est vide." << endl;
            }
            else
            {
                // Le paiement affiche la facture complete
                panier.payer(caissier);
            }
        }
        else
        {
            // Gestion des mauvais choix de menu
            cout << "Choix invalide..." << endl;
        }

    } while (choix != "0");

    return 0;
}

void afficherMenu()
{
    cout << "********************" << endl;
    cout << " MENU PRINCIPAL " << endl;
    cout << "********************" << endl;
    cout << "1. Ajouter un article" << endl;
    cout << "2. Supprimer un article" << endl;
    cout << "3. Afficher le panier" << endl;
    cout << "0. Payer" << endl;
}

void afficherCatalogue(const vector<Article>& catalogue)
{
    for (int i = 0; i < catalogue.size(); i++)
    {
        cout << catalogue[i] << endl;
    }
}

bool codeArticleValide(const vector<Article>& catalogue, const string& code)
{
    for (int i = 0; i < catalogue.size(); i++)
    {
        if (catalogue[i] == code)
        {
            return true;
        }
    }

    return false;
}

Article trouverArticle(const vector<Article>& catalogue, const string& code)
{
    for (int i = 0; i < catalogue.size(); i++)
    {
        if (catalogue[i] == code)
        {
            return catalogue[i];
        }
    }

    // Retour par defaut si jamais rien n'est trouve
    return Article();
}

bool numeroEmployeValide(const vector<Employe>& employes, const string& numero)
{
    for (int i = 0; i < employes.size(); i++)
    {
        if (employes[i] == numero)
        {
            return true;
        }
    }

    return false;
}

Employe trouverEmploye(const vector<Employe>& employes, const string& numero)
{
    for (int i = 0; i < employes.size(); i++)
    {
        if (employes[i] == numero)
        {
            return employes[i];
        }
    }

    return Employe();
}