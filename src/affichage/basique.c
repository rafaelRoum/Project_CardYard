#include <stdio.h>
#include <string.h>
#include "basique.h"

// Place un caractère à la position (x, y) dans la matrice d'affichage
void afficher_caractere(Gestionnaire* gestionnaire, char caractere, int x, int y)
{
    gestionnaire->caracteres[x][y] = caractere;
}

// Modifie la couleur du caractère situé en (x, y)
void colorer_emplacement(Gestionnaire* gestionnaire, int couleur_texte, int x, int y)
{
    gestionnaire->couleurs[x][y] = couleur_texte;
}

// Écrit du texte horizontalement à partir de la position (x, y)
void afficher_texte(Gestionnaire* gestionnaire, char* texte, int x, int y)
{
    for (int i = 0; i < strlen(texte); i++)
        afficher_caractere(gestionnaire, texte[i], x + i, y);
}

// Rafraîchit l’affichage de tout l’écran (appelée à chaque tour)
void rafraichir_affichage(Gestionnaire* gestionnaire)
{
    for (int y = 0; y < gestionnaire->dimensions[1]; y++)
    {
        for (int x = 0; x < gestionnaire->dimensions[0]; x++)
        {
            // Affiche chaque caractère avec sa couleur
            afficher_caractere_colore(gestionnaire->caracteres[x][y], gestionnaire->couleurs[x][y]);
        }
        printf("\n"); // Nouvelle ligne après chaque ligne d’écran
    }
}
