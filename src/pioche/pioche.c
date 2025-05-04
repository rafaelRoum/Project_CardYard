#include "pioche.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

Pioche nouvelle_pioche(int taille) 
{
    Pioche pioche = malloc(sizeof(Pioche));
    pioche->taille = taille;
    pioche->contenu = malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++) 
        pioche->contenu[i] = INT_MAX;
    return pioche;
}

void ajouter_carte(Pioche pioche, int carte)
{
    for(int i = 0; i < pioche->taille; i++)
    {
        if (pioche->contenu[i] == INT_MAX)
        {
            pioche->contenu[i] = carte;
            break;
        }
    }
}

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

int pioche_vide(Pioche pioche)
{
    return (pioche->contenu[0] == INT_MAX) ? 1 : 0;
}

/*
<=>  
if (pioche->contenu[0] == INT_MAX)
{
    return 1; 
} else {
    return 0;
}
*/


int piocher_carte(Pioche pioche)
{
    if (pioche_vide(pioche)) 
    {
        fprintf(stderr, "Vous ne pouvez pas piocher dans une pioche vide.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < pioche->taille; i++)
    {
        if (pioche->contenu[i] == INT_MAX)
        {
            int carte = pioche->contenu[i-1];
            pioche->contenu[i-1] = INT_MAX;
            return carte;
        }
    }
}
