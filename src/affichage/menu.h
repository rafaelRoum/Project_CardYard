#include "partie.h" // Nécessaire pour avoir accès à la structure Gestionnaire

// Affiche le menu d’accueil principal
void afficher_menu(Gestionnaire* gestionnaire, int x, int y);

// Affiche le menu de pause (lorsque ESC est appuyé en jeu)
void afficher_menu_pause(Gestionnaire* gestionnaire, int x, int y);

// Affiche l’écran de fin avec les scores des joueurs
void afficher_fin(Gestionnaire* gestionnaire, int x, int y);
