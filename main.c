#include <stdio.h>
#include <limits.h>
#include "src/affichage/partie.h"

int main()
{
    char* noms[4] = {"MeziFire", "Rayane", "Zbi", "Hmoa"};
    int cartes[6] = {0, 1, 2, 3, 4, 5};
    Gestionnaire* gestionnaire = nouveau_gestionnaire(80, 80, 2, 4, noms, 6);
    gestionnaire->joueurs[1]->configuration[2] = 1;
    afficher_joueurs(gestionnaire, 0, 0);
    afficher_pioche(gestionnaire, "Ayoub", 5, 52, 0);
    rafraichir_affichage(gestionnaire);
    
    return 0;
}

