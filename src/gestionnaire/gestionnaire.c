
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "gestionnaire.h"
#include "../donnees/cartes_config.h"

void melanger(int *tableau, int taille) {
    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = tableau[i];
        tableau[i] = tableau[j];
        tableau[j] = temp;
    }
}


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
    gestionnaire->mode = 0;
    gestionnaire->etat = 0;
    gestionnaire->fin_jeu = 0;
    gestionnaire->choix = INT_MAX;
    gestionnaire->temp_choix = INT_MAX;
    gestionnaire->selection_alt = 0;

    // Tableau de toutes les cartes
    int total_cartes[NB_CARTES] = CARTES;
    melanger(total_cartes, NB_CARTES);
    
    // Initialisation de la pioche centrale
    gestionnaire->pioche_centrale = nouvelle_pioche(1000);
    for (int i = 0; i < NB_CARTES - (nb_cartes * nb_joueurs); i++)
        ajouter_carte(gestionnaire->pioche_centrale, total_cartes[i + (nb_cartes * nb_joueurs)]);


    vider_affichage(gestionnaire, dimension_x, dimension_y);
    
    // Initialisation des Joueurs
    Joueur** joueurs = malloc(sizeof(Joueur) * nb_joueurs);
    for (int i = 0; i < nb_joueurs; i++)
    {
        int* cartes = malloc(sizeof(int) * nb_cartes);  
        for (int j = 0; j < nb_cartes; j++)
            cartes[j] = total_cartes[i * nb_cartes + j];
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

void rendre_cartes_visibles(Gestionnaire* gestionnaire)
{
    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        for (int j = 0; j < gestionnaire->nb_cartes; j++)
        {
            gestionnaire->joueurs[i]->configuration[j] = 1;
        }
    }
}