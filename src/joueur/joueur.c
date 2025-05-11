#include <stdlib.h>
#include "joueur.h"

// Crée un nouveau joueur et initialise tous ses attributs
Joueur* nouveau_joueur(char* nom, int nb_cartes, int* cartes, int id)
{
    Joueur* joueur = malloc(sizeof(Joueur));            // Allocation mémoire pour le joueur

    joueur->nom = nom;                                  // Affectation du nom
    joueur->defausse = nouvelle_pioche(1000);           // Création d'une pioche vide pour la défausse

    joueur->cartes = cartes;                            // Affectation des cartes du joueur
    joueur->nb_cartes = nb_cartes;                      // Stocke le nombre de cartes

    joueur->configuration = malloc(sizeof(int) * nb_cartes); // Crée le tableau d'états (visible/caché)

    joueur->id = id;                                    // Attribue l'identifiant
    joueur->dernier_coup = 0;                           // Initialise la mémoire du dernier coup joué

    // Par défaut, toutes les cartes sont cachées (configuration = 0)
    for(int i = 0; i < nb_cartes; i++)
        joueur->configuration[i] = 0;

    return joueur;
}
