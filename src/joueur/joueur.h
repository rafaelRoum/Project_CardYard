/*
Cette structure matérialise les propriétées de chaque 
joueurs de la partie.
*/

#include "../pioche/pioche.h"

typedef struct Joueur
{
    int* cartes; // liste des cartes que le joueur possède
    int* configuration; /*
        tableau jummelé à celui des cartes qui gère l'état 'visible' 
        ou 'caché' de chacune d'entre elles
     */
    // Les autres propriétées sont suffisamment explicites
    int nb_cartes;
    Pioche defausse; 
    int score;
    int id;
    char* nom;
    int dernier_coup;
} Joueur;

// Prototypes
Joueur* nouveau_joueur(char* nom, int nb_cartes, int* cartes, int id);
