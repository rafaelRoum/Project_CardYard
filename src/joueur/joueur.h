/*
Cette structure matérialise les propriétés de chaque 
joueur de la partie.
*/

#include "../pioche/pioche.h"

typedef struct Joueur
{
    int* cartes;               
    int* configuration;       // État des cartes (0 = cachée, 1 = visible) en parallèle avec "cartes"
    int nb_cartes;            // Nombre total de cartes que possède le joueur
    Pioche defausse;          // Pile de cartes défaussées du joueur (face visible)
    int score;                // Score du joueur (somme des cartes visibles à la fin)
    int id;                   
    char* nom;               
    int dernier_coup;         // Dernière action effectuée (utile pour la logique de jeu)
} Joueur;

// Crée un nouveau joueur avec un nom, ses cartes et son identifiant
Joueur* nouveau_joueur(char* nom, int nb_cartes, int* cartes, int id);
