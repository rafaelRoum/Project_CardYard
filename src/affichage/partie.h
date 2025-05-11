#include "carte.h" // Nécessaire pour les fonctions d'affichage liées aux cartes

// Affiche tous les joueurs (noms + cartes) et retourne les dimensions (largeur, hauteur) utilisées
int* afficher_joueurs(Gestionnaire* gestionnaire, int x, int y);

// Affiche le cadre principal de la table de jeu
void afficher_table(Gestionnaire* gestionnaire, int x, int y, int longeur1, int longeur2, int hauteur);

// Affiche toutes les pioches (défausses des joueurs + pioche centrale)
void afficher_pioches(Gestionnaire* gestionnaire, int x, int y);

// Affiche une boîte indiquant la carte actuellement sélectionnée par le joueur
void afficher_selection(Gestionnaire* gestionnaire, int nombre, int x, int y);
