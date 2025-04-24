#include <stdio.h>
#include <string.h>
#include "basique.h"

void afficher_caractere(Gestionnaire* gestionnaire, char caractere, int x, int y)
{
    gestionnaire->caracteres[x][y] = caractere;
}

void afficher_texte(Gestionnaire* gestionnaire, char* texte, int x, int y)
{
    for (int i = 0; i < strlen(texte); i++)
        afficher_caractere(gestionnaire, texte[i], x+i, y);
}

void rafraichir_affichage(Gestionnaire* gestionnaire)
{
    for (int x = 0; x < gestionnaire->dimensions[0]; x++)
    {
        for (int y = 0; y < gestionnaire->dimensions[1]; y++)
        {
            printf("%c", gestionnaire->caracteres[y][x]);
        }
        printf("\n");
    }
}
