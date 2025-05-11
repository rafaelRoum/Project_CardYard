#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "carte.h"

// Affiche une carte avec un cadre + le nombre si visible
void afficher_carte(Gestionnaire* gestionnaire, int nombre, int x, int y)
{
    int pas[2] = {0, 2}; // Ligne du haut et du bas du cadre

    for (int p = 0; p < 2; p++)
    {
        afficher_caractere(gestionnaire, '#', x, y + pas[p]);
        for (int i = 0; i < gestionnaire->longeur_max; i++)
            afficher_caractere(gestionnaire, '-', x + i + 1, y + pas[p]);
        afficher_caractere(gestionnaire, '#', x + gestionnaire->longeur_max + 1, y + pas[p]);
    }

    // Si la carte est visible (≠ INT_MAX), on affiche sa valeur
    if (nombre != INT_MAX)
        afficher_nombre(gestionnaire, nombre, x + 1, y + 1);

    // Bordures latérales
    afficher_caractere(gestionnaire, '|', x, y + 1);
    afficher_caractere(gestionnaire, '|', x + gestionnaire->longeur_max + 1, y + 1);

    // Couleur de fond selon la valeur de la carte
    int couleur;
    switch(nombre)
    {
        case -2:
            break; // erreur : aucun `couleur = ...` défini ici
        case -1:
            couleur = COULEUR_JAUNE_CLAIR;
            break;
        case 0:
            couleur = COULEUR_ROSE_CLAIR;
            break;
        case 1:
            couleur = COULEUR_GRIS;
            break;
        case 2:
            couleur = COULEUR_VERT;
            break;
        case 3:
            couleur = COULEUR_MAGENTA;
            break;
        case 4:
            couleur = COULEUR_MARRON;
            break;
        case 5:
            couleur = COULEUR_JAUNE_CLAIR;
            break;
        case 6:
            couleur = COULEUR_ROSE_CLAIR;
            break;
        case 7:
            couleur = COULEUR_GRIS;
            break;
        case 8:
            couleur = COULEUR_VERT;
            break;
        case 9:
            couleur = COULEUR_MAGENTA;
            break;
        case 10:
            couleur = COULEUR_MARRON;
            break;
        case 11:
            couleur = COULEUR_JAUNE_CLAIR;
            break;
        case 12:
            couleur = COULEUR_ROSE_CLAIR;
            break;
    }

    // Colore le fond de la carte
    colorer_emplacement(gestionnaire, couleur, x + 1, y + 1);
    colorer_emplacement(gestionnaire, couleur, x + 2, y + 1);
}

// Affiche un joueur avec son nom et ses cartes disposées en grille
void afficher_joueur(Gestionnaire* gestionnaire, Joueur* joueur, int x, int y)
{
    // Centre le nom du joueur dans l’espace de 3 cartes
    int espacement = ((3 + gestionnaire->longeur_max) * 3 - (strlen(joueur->nom) + 2)) / 2;

    afficher_caractere(gestionnaire, '[', x + espacement, y);
    afficher_texte(gestionnaire, joueur->nom, x + espacement + 1, y);
    afficher_caractere(gestionnaire, ']', x + espacement + strlen(joueur->nom) + 1, y);

    // Colore le fond si c’est son tour
    if (joueur->id == gestionnaire->tour)
    {
        for (int i = 0; i < (gestionnaire->longeur_max + 2) * 3; i++)
        {
            colorer_emplacement(gestionnaire, COULEUR_BLEU_CLAIR, x + i, y);
        }
    }

    // Affiche chaque carte (en 3 colonnes max, plusieurs lignes)
    for (int i = 0; i < joueur->nb_cartes; i++)
    {
        int colonne = i % 3;
        int ligne = i / 3;

        // Affiche la carte si visible, sinon case vide
        int affichage = (joueur->configuration[i] == 1) ? joueur->cartes[i] : INT_MAX;

        int origine_x = x + colonne * (3 + gestionnaire->longeur_max);
        int origine_y = y + ligne * 3 + 1;

        afficher_carte(gestionnaire, affichage, origine_x, origine_y);

        // Met en surbrillance si la carte est sélectionnée
        if (gestionnaire->selection == i && joueur->id == gestionnaire->tour && gestionnaire->mode == 1)
        {
            for (int i = 0; i < gestionnaire->longeur_max + 2; i++)
            {
                for (int j = 0; j < 3; j++)
                    colorer_emplacement(gestionnaire, COULEUR_BLEU_CLAIR, origine_x + i, origine_y + j);
            }
        }
    }
}

// Affiche une ligne contenant le nom de la pioche/défausse et une carte (facultatif)
void afficher_pioche(Gestionnaire* gestionnaire, char* texte, int nombre, int x, int y, int carte, int colorer)
{
    // Affichage du titre [texte]
    afficher_caractere(gestionnaire, '[', x, y);
    afficher_texte(gestionnaire, texte, x + 1, y);
    afficher_caractere(gestionnaire, ']', x + strlen(texte) + 1, y);

    // Affiche la carte si demandé
    if (carte)
        afficher_carte(gestionnaire, nombre, x + strlen(texte) + 4, y);

    // Colore le texte si demandé
    if (colorer)
    {
        for (int i = 0; i < strlen(texte) + 2; i++)
            colorer_emplacement(gestionnaire, COULEUR_BLEU_CLAIR, x + i, y);
    }
}
