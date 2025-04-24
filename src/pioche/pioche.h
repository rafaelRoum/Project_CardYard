/*
La Pioche est une structure de donnée qui fonctionne comme 
une Pile mais dont la mémoire est gérée de façon statique.

Elle permet de gérer la pioche principale du jeu ainsi que 
les différentes défausses des joueurs.
*/

typedef struct 
{
    int taille;
    int* contenu;
} *Pioche;

// Prototypes
Pioche nouvelle_pioche(int taille);
void ajouter_carte(Pioche pioche, int carte);
void debug_pioche(Pioche pioche);
int piocher_carte(Pioche pioche);
int pioche_vide(Pioche pioche);
