#include "partie.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

// Renvoie la longueur (en nombre de chiffres) d'un entier
int longueur_nombre(int nombre) {
    char str[100]; 
    sprintf(str, "%d", nombre);
    return strlen(str);
}

// Affiche les cartes de chaque joueur en grille et retourne les dimensions totales de l'affichage
int* afficher_joueurs(Gestionnaire* gestionnaire, int x, int y)
{
    const int nb_colonnes = 3; // Maximum 3 joueurs par ligne
    const int espacement_x = 3 * gestionnaire->longeur_max + 11; // Largeur par joueur
    int nb_lignes = (gestionnaire->nb_cartes - 1) / 3 + 1; // Lignes de cartes à afficher
    const int hauteur_joueur = 2 + 3 * nb_lignes; // Hauteur de l'affichage par joueur

    int* dimensions = malloc(sizeof(int) * 2); // Pour retourner largeur et hauteur totales
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

// Dessine une table avec deux zones de jeu encadrées
void afficher_table(Gestionnaire* gestionnaire, int x, int y, int longeur1, int longeur2, int hauteur)
{
    // Coins
    afficher_caractere(gestionnaire, '#', x, y);
    afficher_caractere(gestionnaire, '#', x, y + hauteur + 1);
    afficher_caractere(gestionnaire, '#', x + longeur1 + 1, y);
    afficher_caractere(gestionnaire, '#', x + longeur1 + 1, y + hauteur + 1);
    afficher_caractere(gestionnaire, '#', x + longeur1 + longeur2 + 2, y);
    afficher_caractere(gestionnaire, '#', x + longeur1 + longeur2 + 2, y + hauteur + 1);

    // Lignes horizontales
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

    // Lignes verticales
    for (int i = 1; i < hauteur + 1; i++)
    {
        afficher_caractere(gestionnaire, '|', x, y + i);
        afficher_caractere(gestionnaire, '|', x + longeur1 + 1, y + i);
        afficher_caractere(gestionnaire, '|', x + longeur1 + longeur2 + 2, y + i);
        afficher_caractere(gestionnaire, '|', x - 1, y + i);
        afficher_caractere(gestionnaire, '|', x + longeur1 + longeur2 + 3, y + i);
    }
}

// Affiche les pioches (défausses + pioche centrale) avec surbrillance si sélectionnées
void afficher_pioches(Gestionnaire* gestionnaire, int x, int y)
{
    int compteur = -1;

    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        int afficher = (pioche_vide(gestionnaire->joueurs[i]->defausse)) ? 0 : 1;
        int valeur = 0;

        if (afficher)
        {
            valeur = carte_dessus(gestionnaire->joueurs[i]->defausse);
            compteur++;
        }

        afficher_pioche(
            gestionnaire,
            gestionnaire->joueurs[i]->nom,
            valeur,
            x,
            y + 4 * i,
            afficher,
            (compteur == gestionnaire->selection && gestionnaire->mode == 0 && afficher) ? 1 : 0
        );

        if (afficher && compteur == gestionnaire->selection)
        {
            gestionnaire->temp_choix = valeur;
            gestionnaire->selection_alt = i;
        }
    }

    // Pioche centrale
    int afficher = (pioche_vide(gestionnaire->pioche_centrale)) ? 0 : 1;
    afficher_pioche(
        gestionnaire,
        "Pioche",
        INT_MAX,
        x,
        y + 4 * gestionnaire->nb_joueurs,
        afficher,
        (gestionnaire->selection == defausses_disponibles(gestionnaire) - 1 && gestionnaire->mode == 0) ? 1 : 0
    );

    if (afficher && gestionnaire->selection == defausses_disponibles(gestionnaire) - 1)
    {
        gestionnaire->temp_choix = carte_dessus(gestionnaire->pioche_centrale);
        gestionnaire->selection_alt = INT_MAX;
    }
}

// Affiche une petite fenêtre avec la carte sélectionnée (pendant le tour)
void afficher_selection(Gestionnaire* gestionnaire, int nombre, int x, int y)
{
    afficher_texte(gestionnaire, "#-------------#", x, y);
    afficher_texte(gestionnaire, "||  SELECTION  ||", x - 1, y + 1);

    char ligne_nombre[50];
    if (longueur_nombre(nombre) == 1)
        sprintf(ligne_nombre, "||    > %d      ||", nombre); 
    else
        sprintf(ligne_nombre, "||    > %d     ||", nombre); 

    afficher_texte(gestionnaire, ligne_nombre, x - 1, y + 2);
    afficher_texte(gestionnaire, "#-------------#", x, y + 3);
}
