#include "charger.h"

int corriger_index(int x) {
    return x / 2;
}


char** lire_lignes(int* nb_lignes) {
    FILE* fichier = fopen("src/sauvegarde/sauvegarde.txt", "r");
    if (!fichier) return NULL;

    int capacite = 10;
    int taille = 0;
    char** lignes = malloc(sizeof(char*) * capacite);
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fichier)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        if (taille >= capacite) {
            capacite *= 2;
            lignes = realloc(lignes, sizeof(char*) * capacite);
        }

        lignes[taille] = strdup(buffer);
        taille++;
    }

    fclose(fichier);
    *nb_lignes = taille;
    return lignes;
}

void charger_gestionnaire()
{
    int nb;
    char** lignes = lire_lignes(&nb);
    int nb_joueurs = atoi(lignes[0]);
    int nb_cartes = atoi(lignes[nb_joueurs + 1]);
    int tour = atoi(lignes[nb_joueurs + 2]);
    char** noms = malloc(sizeof(char*) * nb_joueurs);
    for (int i = 0; i < nb_joueurs; i++)
    {
        noms[i] = lignes[i + 1];
    }
    int** cartes_config = malloc(sizeof(int*) * nb_joueurs * 2);
    for (int i = 0; i < nb_joueurs * 2; i++) 
    {
        cartes_config[i] = malloc(sizeof(int) * nb_cartes);
        for (int j = 0; j < nb_cartes; j++)
        {
            cartes_config[i][j] = atoi(lignes[nb_joueurs + 3 + i * nb_cartes + j]);
        }
    }
}