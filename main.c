#include <stdio.h>
#include <limits.h>
#include "src/affichage/partie.h"
#include "src/systeme.h"



int main()
{
    
    char* noms[5] = {"MeziFire", "Rayane", "Zbi", "Hmoa","////" };
    Gestionnaire* gestionnaire = nouveau_gestionnaire(80, 50, 2, 5, noms, 6);
    int* dimensions = afficher_joueurs(gestionnaire, 2, 1);
    afficher_table(gestionnaire, 0, 0, dimensions[0], 20, dimensions[1]);
    afficher_pioche(gestionnaire, "Rayane", 3, 55, 2);
    rafraichir_affichage(gestionnaire);
    return 0;
}

