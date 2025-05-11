/*
La Pioche est une structure de donnée qui fonctionne comme 
une Pile mais dont la mémoire est gérée de façon statique.

Elle permet de gérer la pioche principale du jeu ainsi que 
les différentes défausses des joueurs.
*/

typedef struct 
{
    int taille;         // Taille maximale de la pioche
    int* contenu;       // Tableau dynamique contenant les cartes (INT_MAX = case vide)
} *Pioche;

// Prototypes des fonctions de gestion de pioche
Pioche nouvelle_pioche(int taille);       // Crée une nouvelle pioche vide
void ajouter_carte(Pioche pioche, int carte);  // Ajoute une carte à la pioche
void debug_pioche(Pioche pioche);         // Affiche les cartes présentes (debug)
int piocher_carte(Pioche pioche);         // Retire et renvoie la carte du dessus
int pioche_vide(Pioche pioche);           // Vérifie si la pioche est vide
int carte_dessus(Pioche pioche);          // Donne la carte sur le dessus sans la retirer
