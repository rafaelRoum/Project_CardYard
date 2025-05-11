#include <stdlib.h>
#include "joueur.h"

Joueur* nouveau_joueur(char* nom, int nb_cartes, int* cartes, int id)
{
    Joueur* joueur = malloc(sizeof(Joueur));
    joueur->nom = nom;
    joueur->defausse = nouvelle_pioche(1000);
    joueur->cartes = cartes;
    joueur->nb_cartes = nb_cartes;
    joueur->configuration = malloc(sizeof(int) * nb_cartes);
    joueur->id = id;
    joueur->dernier_coup = 0;
    for(int i = 0; i < nb_cartes; i++)
        joueur->configuration[i] = 0;
    return joueur;
}


