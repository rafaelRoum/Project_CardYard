#include <stdio.h>
#include <string.h>
#include "nombre.h"

void afficher_nombre(Gestionnaire* gestionnaire, int nombre, int x, int y)
{
    char str[12];
    sprintf(str, "%d", nombre);
    int longeur = strlen(str);
    int n_espaces = gestionnaire->longeur_max - longeur;
    for (int i = 0; i < gestionnaire->longeur_max; i++)
    {
        if (i > n_espaces-1)
        {
            afficher_caractere(gestionnaire, str[i - n_espaces], x+i, y);
        }
    }
}
