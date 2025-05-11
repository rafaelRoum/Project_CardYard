#include "nombre.h" // Pour l'affichage des nombres dans les cartes

// Affiche une pioche (centrale ou défausse)
void afficher_pioche(Gestionnaire* gestionnaire, char* texte, int nombre, int x, int y, int carte, int colorer);

// Affiche toutes les cartes d’un joueur et son nom
void afficher_joueur(Gestionnaire* gestionnaire, Joueur* joueur, int x, int y);
