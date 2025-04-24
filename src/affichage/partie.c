#include "partie.h"
#include <stdlib.h>

void afficher_joueurs(Gestionnaire* gestionnaire, int x, int y)
{
    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        int colonne = i % 3;
        int ligne = i / 3;
        afficher_joueur(gestionnaire, gestionnaire->joueurs[i], x + colonne * (3*gestionnaire->longeur_max + 11), y + ligne * 8);
    }
}

