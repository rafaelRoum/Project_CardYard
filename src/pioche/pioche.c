#include "pioche.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// Crée une nouvelle pioche de taille donnée et l'initialise à vide
Pioche nouvelle_pioche(int taille) 
{
    Pioche pioche = malloc(sizeof(Pioche));               // Allocation du pointeur vers la structure
    pioche->taille = taille;
    pioche->contenu = malloc(sizeof(int) * taille);       // Allocation du tableau des cartes

    for (int i = 0; i < taille; i++) 
        pioche->contenu[i] = INT_MAX;                     // INT_MAX = case vide (aucune carte)

    return pioche;
}

// Ajoute une carte dans la première case vide de la pioche
void ajouter_carte(Pioche pioche, int carte)
{
    for(int i = 0; i < pioche->taille; i++)
    {
        if (pioche->contenu[i] == INT_MAX)                // Trouve la première case vide
        {
            pioche->contenu[i] = carte;
            break;
        }
    }
}

// Affiche toutes les cartes présentes dans la pioche (debug)
void debug_pioche(Pioche pioche)
{
    printf("[");
    for (int i = 0; i < pioche->taille; i++)
    {
        if (pioche->contenu[i] != INT_MAX)
            printf("%d, ", pioche->contenu[i]);
    }
    printf("]\n");
}

// Vérifie si la pioche est vide (aucune carte)
int pioche_vide(Pioche pioche)
{
    return (pioche->contenu[0] == INT_MAX) ? 1 : 0;
}

// Retire la dernière carte ajoutée à la pioche (comme une pile)
int piocher_carte(Pioche pioche)
{
    for (int i = 0; i < pioche->taille; i++)
    {
        if (pioche->contenu[i] == INT_MAX)
        {
            int carte = pioche->contenu[i-1];             // Carte du dessus
            pioche->contenu[i-1] = INT_MAX;               // On la retire
            return carte;
        }
    }
    // Si la pioche est pleine, on prend la dernière
    int carte = pioche->contenu[pioche->taille - 1];
    pioche->contenu[pioche->taille - 1] = INT_MAX;
    return carte;
}

// Récupère la carte du dessus sans la retirer
int carte_dessus(Pioche pioche)
{
    for (int i = 0; i < pioche->taille; i++)
    {
        if (pioche->contenu[i] == INT_MAX)
        {
            int carte = pioche->contenu[i-1];             // Dernière carte ajoutée
            return carte;
        }
    }
    return pioche->contenu[pioche->taille - 1];           // Si pleine
}
