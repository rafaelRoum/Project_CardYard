#include <stdio.h>
#include <limits.h>
#include "src/affichage/partie.h"

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int main()
{
    char* noms[7] = {"Joueur 1", "Joueur 2", "Joueur 3", "Joueur 4", "Joueur 5", "Joueur 6", "Joueur 7"};
    Gestionnaire* gestionnaire = nouveau_gestionnaire(80, 30, 2, 7, noms, 6);
    for (int i = 0; i < 15; i++)
    {
        vider_console();
        vider_affichage(gestionnaire, 80, 30);
        int* dimensions = afficher_joueurs(gestionnaire, 2, 1);
        afficher_table(gestionnaire, 0, 0, dimensions[0], 20, maximum(dimensions[1], gestionnaire->nb_joueurs * 4 - 1));
        afficher_pioches(gestionnaire, 55, 1);
        rafraichir_affichage(gestionnaire);
        printf("%d", gestionnaire->tour);
        char* touche = attendre_touche();
        controles(gestionnaire, touche);
        
    }
    return 0;
}

