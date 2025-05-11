// Non utilisé pour le programme actuellement

#include "charger.h"

// Fonction utilitaire pour convertir un index pair en un index logique (division entière par 2)
int corriger_index(int x) {
    return x / 2;
}

// Lit toutes les lignes du fichier "sauvegarde.txt" dans un tableau dynamique
char** lire_lignes(int* nb_lignes) {
    FILE* fichier = fopen("src/sauvegarde/sauvegarde.txt", "r");
    if (!fichier) return NULL;

    int capacite = 10; // capacité initiale du tableau
    int taille = 0;    // nombre actuel de lignes lues
    char** lignes = malloc(sizeof(char*) * capacite);
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fichier)) {
        // Retire le caractère de retour à la ligne
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Agrandit le tableau si besoin
        if (taille >= capacite) {
            capacite *= 2;
            lignes = realloc(lignes, sizeof(char*) * capacite);
        }

        lignes[taille] = strdup(buffer); // duplique la ligne lue
        taille++;
    }

    fclose(fichier);
    *nb_lignes = taille;
    return lignes;
}

// Charge les données d’un gestionnaire depuis les lignes du fichier
void charger_gestionnaire()
{
    int nb;
    char** lignes = lire_lignes(&nb);

    int nb_joueurs = atoi(lignes[0]);                // Ligne 0 : nombre de joueurs
    int nb_cartes = atoi(lignes[nb_joueurs + 1]);    // Ligne après les noms : nombre de cartes
    int tour = atoi(lignes[nb_joueurs + 2]);         // Ligne suivante : tour actuel

    // Récupération des noms des joueurs
    char** noms = malloc(sizeof(char*) * nb_joueurs);
    for (int i = 0; i < nb_joueurs; i++)
    {
        noms[i] = lignes[i + 1]; // Les noms commencent à la ligne 1
    }

    // Récupération des cartes et configurations (deux blocs pour chaque joueur)
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
