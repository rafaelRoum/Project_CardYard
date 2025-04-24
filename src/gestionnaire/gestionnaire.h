/*
Le Gestionnaire est la structure principale du Jeu
qui gère aussi bien l'affichage que le déroulé de la 
partie.
*/

#include "../joueur/joueur.h"

typedef struct Gestionnaire
{  
    char** caracteres; // Disposition des caractère affichés à l'écran
    int dimensions[2]; // Dimensions de l'espace alloué aux graphismes (en terme de caractères)
    int longeur_max;   // Longeur maximale d'un nombre au sein d'une carte
    int nb_joueurs;    // Nombre de joueurs
    Joueur** joueurs;   // Liste des joueurs
    int nb_cartes;     // Nombre de cartes par joueur
} Gestionnaire;

// Prototypes
Gestionnaire* nouveau_gestionnaire(int dimension_x, int dimension_y, int longeur_max, int nb_joueurs, char** noms_joueurs, int nb_cartes);


