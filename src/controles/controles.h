#include "../sauvegarde/charger.h" // Pour la gestion des sauvegardes (non utilisé ici directement)

// Gère les actions clavier en fonction de l’état du jeu
void controles(Gestionnaire* gestionnaire, char* touche);

// Calcule le nombre de défausses non vides disponibles dans le jeu
int defausses_disponibles(Gestionnaire* gestionnaire);
