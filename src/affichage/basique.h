#include "../controles/controles.h"

// Affiche un caractère à une position (x, y) dans le gestionnaire
void afficher_caractere(Gestionnaire* gestionnaire, char caractere, int x, int y);

// Réaffiche tout l’écran en parcourant les caractères et leurs couleurs
void rafraichir_affichage(Gestionnaire* gestionnaire);

// Affiche une chaîne de texte horizontalement à partir de (x, y)
void afficher_texte(Gestionnaire* gestionnaire, char* texte, int x, int y);

// Définit la couleur à la position (x, y)
void colorer_emplacement(Gestionnaire* gestionnaire, int couleur_texte, int x, int y);
