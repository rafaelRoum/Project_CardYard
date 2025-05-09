
#include <stdlib.h>
#include <stdio.h>
#include "gestionnaire.h"


Gestionnaire* nouveau_gestionnaire(int dimension_x, int dimension_y, int longeur_max, int nb_joueurs, char** noms_joueurs, int nb_cartes)
{
    Gestionnaire* gestionnaire = malloc(sizeof(Gestionnaire));
    gestionnaire->dimensions[0] = dimension_x;
    gestionnaire->dimensions[1] = dimension_y;
    gestionnaire->longeur_max = longeur_max;
    gestionnaire->nb_cartes = nb_cartes;
    gestionnaire->nb_joueurs = nb_joueurs;
    gestionnaire->tour = 0;
    gestionnaire->selection = 0;

    vider_affichage(gestionnaire, dimension_x, dimension_y);
    
    Joueur** joueurs = malloc(sizeof(Joueur) * nb_joueurs);
    for (int i = 0; i < nb_joueurs; i++)
    {
        int* cartes = malloc(sizeof(int) * nb_cartes);  
        for (int j = 0; j < nb_cartes; j++)
            cartes[j] = 0;
        joueurs[i] = nouveau_joueur(noms_joueurs[i], nb_cartes, cartes, i);
    }
    gestionnaire->joueurs = joueurs;
    return gestionnaire;
}




void vider_affichage(Gestionnaire* gestionnaire, int dimension_x, int dimension_y)
{
    char** caracteres = malloc(sizeof(char*) * dimension_x);
    for (int i = 0; i < dimension_x; i++)
    {
        caracteres[i] = malloc(sizeof(char) * dimension_y);
        for (int j = 0; j < dimension_y; j++)
            caracteres[i][j] = ' ';
    }
    gestionnaire->caracteres = caracteres;
    
    int** couleurs = malloc(sizeof(int*) * dimension_x);
    for (int i = 0; i < dimension_x; i++)
    {
        couleurs[i] = malloc(sizeof(int) * dimension_y);
        for (int j = 0; j < dimension_y; j++)
            couleurs[i][j] = 15;
    }
    gestionnaire->couleurs = couleurs;
}
