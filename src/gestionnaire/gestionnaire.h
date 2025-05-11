#include "../joueur/joueur.h"
#include "../systeme/systeme.h"

typedef struct Gestionnaire
{  
    char** caracteres;       // Matrice des caractères affichés (terminal graphique)
    int** couleurs;          // Matrice des couleurs associées à chaque caractère
    int dimensions[2];       // Largeur et hauteur de l'écran (terminal)
    int longeur_max;         // Nombre max de chiffres à afficher dans une carte
    int nb_joueurs;          // Nombre total de joueurs dans la partie
    Joueur** joueurs;        // Tableau de pointeurs vers les joueurs
    int nb_cartes;           // Nombre de cartes personnelles par joueur
    int tour;                // Tour de jeu actuel
    int selection;           // Sélection courante dans les menus / interface
    int mode;                // Mode d'interaction (ex: pioche, sélection)
    int etat;                // État global du jeu (définit la logique d'affichage / phase)
    int choix;               // Dernier choix utilisateur
    int temp_choix;          // Temporaire pour sauvegarder un choix intermédiaire
    int selection_alt;       // Autre sélection (utile pour gestion secondaire)
    int selection_menu;      // Choix de l'entrée du menu principal
    int fin_jeu;             // 1 si le jeu est terminé, 0 sinon
    Pioche pioche_centrale;  // Pioche principale commune à tous les joueurs
} Gestionnaire;

// Fonctions de gestion
Gestionnaire* nouveau_gestionnaire(int dimension_x, int dimension_y, int longeur_max, int nb_joueurs, char** noms_joueurs, int nb_cartes);
char* gerer_clavier(Gestionnaire* gestionnaire);
void vider_affichage(Gestionnaire* gestionnaire, int dimension_x, int dimension_y);
void rendre_cartes_visibles(Gestionnaire* gestionnaire);
