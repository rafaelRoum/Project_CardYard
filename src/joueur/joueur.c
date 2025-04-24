#include <stdlib.h>
#include "joueur.h"

Joueur* nouveau_joueur(char* nom, int nb_cartes, int* cartes)
{
    Joueur* joueur = malloc(sizeof(Joueur));
    joueur->nom = nom;
    joueur->defausse = nouvelle_pioche(nb_cartes);
    joueur->cartes = cartes;
    joueur->nb_cartes = nb_cartes;
    joueur->configuration = malloc(sizeof(int) * nb_cartes);
    for(int i = 0; i < nb_cartes; i++)
        joueur->configuration[i] = 0;
    return joueur;
}
