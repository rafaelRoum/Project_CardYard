#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "carte.h"


void afficher_carte(Gestionnaire* gestionnaire, int nombre, int x, int y)
{
    int pas[2] = {0, 2};
    for (int p = 0; p < 2; p++)
    {
        afficher_caractere(gestionnaire, '#', x, y + pas[p]);
        for (int i = 0; i < gestionnaire->longeur_max; i++)
            afficher_caractere(gestionnaire, '-', x + i + 1, y + pas[p]);
        afficher_caractere(gestionnaire, '#', x + gestionnaire->longeur_max + 1, y + pas[p]);
    }
    if (nombre != INT_MAX)
        afficher_nombre(gestionnaire, nombre, x + 1, y + 1);
    afficher_caractere(gestionnaire, '|', x, y + 1);
    afficher_caractere(gestionnaire, '|', x + gestionnaire->longeur_max + 1, y + 1);
}


void afficher_joueur(Gestionnaire* gestionnaire, Joueur* joueur, int x, int y)
{
    int espacement = ((3+gestionnaire->longeur_max)*3 - (strlen(joueur->nom)+2))/2;

    afficher_caractere(gestionnaire, '[', x + espacement, y);
    afficher_texte(gestionnaire, joueur->nom, x + espacement + 1, y);
    afficher_caractere(gestionnaire, ']', x + espacement + strlen(joueur->nom) + 1, y);

    for (int i = 0; i < joueur->nb_cartes; i++)
    {
        int colonne = i % 3;
        int ligne = i / 3;
        int affichage = (joueur->configuration[i] == 1) ? joueur->cartes[i] : INT_MAX;
        afficher_carte(gestionnaire, affichage, x + colonne * (3 + gestionnaire->longeur_max), y + ligne * 3 + 1);
    }
}

void afficher_pioche(Gestionnaire* gestionnaire, char* texte, int nombre, int x, int y)
{
    afficher_caractere(gestionnaire, '[', x, y);
    afficher_texte(gestionnaire, texte, x + 1, y);
    afficher_caractere(gestionnaire, ']', x + strlen(texte) + 1, y);
    afficher_carte(gestionnaire, nombre, x + strlen(texte) + 4, y);
}