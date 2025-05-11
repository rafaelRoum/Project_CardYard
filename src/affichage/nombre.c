#include <stdio.h>
#include <string.h>
#include "nombre.h"

// Affiche un nombre centré/droite dans une carte à l'écran
void afficher_nombre(Gestionnaire* gestionnaire, int nombre, int x, int y)
{
    char str[12];                              // Assez grand pour stocker n'importe quel int
    sprintf(str, "%d", nombre);                // Convertit le nombre en chaîne de caractères

    int longeur = strlen(str);                 // Longueur réelle du nombre (ex : "12" → 2)
    int n_espaces = gestionnaire->longeur_max - longeur; // Nombre d'espaces avant le début du nombre

    for (int i = 0; i < gestionnaire->longeur_max; i++)
    {
        // Affiche le chiffre si on dépasse la zone d'espacement
        if (i > n_espaces - 1)
        {
            afficher_caractere(gestionnaire, str[i - n_espaces], x + i, y);
        }
    }
}
