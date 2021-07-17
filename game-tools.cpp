/**
 * @file game-tools.cpp
 * @author Patrick Etcheverry
 * @brief Corps du module game-tools
 * @date 2021-07-12
 */
#include "game-tools.h"

#include <random> // pour la fonction random

#include <unistd.h> // pour la fonction usleep

#define RESET "\e[0m"
#define ROUGE "\e[0;31m"
#define VERT "\e[0;32m"
#define JAUNE "\e[0;33m"
#define BLEU "\e[0;34m"
#define VIOLET "\e[0;35m"
#define CYAN "\e[0;36m"
#define BLANC "\e[0;37m"

int random(int min, int max)
{
    thread_local std::mt19937 intervalle(std::random_device{}());
    std::uniform_real_distribution<double> dist(min, max+1);

    return dist(intervalle);
}

void pause(unsigned int dureeEnSecondes)
{
    if (dureeEnSecondes == 0)
    {
        std::cin.ignore();
    }
    else
    {
        const unsigned int MICRO_SECONDE = 1000000;
        usleep(dureeEnSecondes * MICRO_SECONDE);
    }
}

void effacer (void)
{
    cout << "\033[2J\033[1;1H";
}

// Retourne le code couleur de la couleur passé en paramètre
string getCodeCouleur (Couleur couleur)
{
    string codeCouleur;
    switch (couleur)
    {
    case bleu:
        codeCouleur = BLEU;
        break;

    case vert:
        codeCouleur = VERT;
        break;

    case cyan:
        codeCouleur = CYAN;
        break;

    case rouge:
        codeCouleur = ROUGE;
        break;

    case violet:
        codeCouleur = VIOLET;
        break;

    case jaune:
        codeCouleur = JAUNE;
        break;

    case blanc:
        codeCouleur = BLANC;
        break;

    default:
        codeCouleur = RESET;
        break;
    }

    return codeCouleur;
}

void afficherTexteEnCouleur(string chaine, Couleur couleur, bool retourALaLigne)
{
    string codeCouleur = getCodeCouleur(couleur);
    cout << codeCouleur << chaine << RESET;
    if (retourALaLigne)
    {
        cout << endl;
    }
}

void afficherTexteEnCouleur(char caractere, Couleur couleur, bool retourALaLigne)
{
    string codeCouleur = getCodeCouleur(couleur);
    cout << codeCouleur << caractere << RESET;
    if (retourALaLigne)
    {
        cout << endl;
    }
}

void afficherNombreEnCouleur(double nombre, Couleur couleur, bool retourALaLigne)
{
    string codeCouleur = getCodeCouleur(couleur);

    cout << codeCouleur << nombre << RESET;
    if (retourALaLigne)
    {
        cout << endl;
    }
}
