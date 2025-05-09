#include "partie.h"
#include <stdlib.h>
#include <math.h>

int* afficher_joueurs(Gestionnaire* gestionnaire, int x, int y)
{
    const int nb_colonnes = 3;
    const int espacement_x = 3 * gestionnaire->longeur_max + 11;
    int nb_lignes = (gestionnaire->nb_cartes - 1)/3 + 1;
    const int hauteur_joueur = 2 + 3 * nb_lignes; 
    int* dimensions = malloc(sizeof(int) * 2);
    dimensions[0] = nb_colonnes * espacement_x;
    dimensions[1] = ((gestionnaire->nb_joueurs - 1) / nb_colonnes + 1) * hauteur_joueur - 1;

    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        int colonne = i % nb_colonnes;
        int ligne = i / nb_colonnes;

        int pos_x = x + colonne * espacement_x;
        int pos_y = y + ligne * hauteur_joueur; 

        afficher_joueur(gestionnaire, gestionnaire->joueurs[i], pos_x, pos_y);
    }
    return dimensions;
}

void afficher_table(Gestionnaire* gestionnaire, int x, int y, int longeur1, int longeur2, int hauteur)
{
    afficher_caractere(gestionnaire, '#', x, y);
    afficher_caractere(gestionnaire, '#', x, y + hauteur + 1);
    afficher_caractere(gestionnaire, '#', x + longeur1 + 1, y);
    afficher_caractere(gestionnaire, '#', x + longeur1 + 1, y + hauteur + 1);
    afficher_caractere(gestionnaire, '#', x + longeur1 + longeur2 + 2, y);
    afficher_caractere(gestionnaire, '#', x + longeur1 + longeur2 + 2, y + hauteur + 1);

    for (int i = 0; i < longeur1; i++)
    {
        afficher_caractere(gestionnaire, '-', x + i + 1, y);
        afficher_caractere(gestionnaire, '-', x + i + 1, y + hauteur + 1);
    }
    
    for (int i = 0; i < longeur2; i++)
    {
        afficher_caractere(gestionnaire, '-', x + i + longeur1 + 2, y);
        afficher_caractere(gestionnaire, '-', x + i + longeur1 + 2, y + hauteur + 1);
    }

    for (int i = 1; i < hauteur+1; i++)
    {
        afficher_caractere(gestionnaire, '|', x, y + i);
        afficher_caractere(gestionnaire, '|', x + longeur1 + 1, y + i);
        afficher_caractere(gestionnaire, '|', x + longeur1 + longeur2 + 2, y + i);
    }
}

void afficher_pioches(Gestionnaire* gestionnaire, int x, int y)
{
    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        afficher_pioche(gestionnaire, gestionnaire->joueurs[i]->nom, 0, x, y + 4 * i);
    }
}