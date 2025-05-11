#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include "src/affichage/menu.h"

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

void verifications_jeu(Gestionnaire* gestionnaire)
{
    if (gestionnaire->fin_jeu == 1)
        gestionnaire->joueurs[gestionnaire->tour]->dernier_coup = 1;

    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        int joueur_toutes_cartes_visibles = 1;
        for (int j = 0; j < gestionnaire->nb_cartes; j++)
        {
            if (gestionnaire->joueurs[i]->configuration[j] == 0)
            {
                joueur_toutes_cartes_visibles = 0;
                break; 
            }
        }
        if (joueur_toutes_cartes_visibles)
        {
            gestionnaire->fin_jeu = 1;
            rendre_cartes_visibles(gestionnaire);
            break;  
        }
    }
}


int derniers_tours_accomplis(Gestionnaire* gestionnaire)
{
    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        if (gestionnaire->joueurs[i]->dernier_coup == 0)
            return 0;
    }
    return 1;
}



int main()
{
    vider_console();
    srand(time(NULL));
    int nb_joueurs;
    int resultat;
    do {
        afficher_texte_colore("Entrez le nombre de joueurs : ", COULEUR_VERT);
        resultat = scanf("%d", &nb_joueurs);

        while (getchar() != '\n'); // Vide le tampon d'entrée

        if (resultat != 1) {
            afficher_texte_colore("Veuillez entrer un entier valide.\n", COULEUR_ROUGE);
        } else if (nb_joueurs < 2 || nb_joueurs > 8) {
            afficher_texte_colore("Le nombre de joueurs doit etre entre 2 et 8. Essayez a nouveau :\n", COULEUR_ROUGE);
            resultat = 0; // force la répétition
        }

    } while (resultat != 1);

    char* noms[nb_joueurs];
    for (int i = 0; i < nb_joueurs; i++) {
        noms[i] = malloc(50 * sizeof(char)); 
        char texte[100];
        sprintf(texte, "Entrez le nom du joueur %d : ", i + 1);
        afficher_texte_colore(texte, COULEUR_VERT);
        scanf(" %49[^\n]", noms[i]);  
    }
    sleep(1);
    Gestionnaire* gestionnaire = nouveau_gestionnaire(120, 40, 2, nb_joueurs, noms, 6);
    gestionnaire->mode = 0;
    while (1)
    {
        vider_console();
        vider_affichage(gestionnaire, 120, 40);
        if (gestionnaire->etat == 1)
        {
            verifications_jeu(gestionnaire);
            int* dimensions = afficher_joueurs(gestionnaire, 3, 1);
            afficher_table(gestionnaire, 1, 0, dimensions[0], 20, maximum(dimensions[1], (gestionnaire->nb_joueurs + 1) * 4 - 1));
            afficher_pioches(gestionnaire, 56, 1);
            if (gestionnaire->choix != INT_MAX)
                afficher_selection(gestionnaire, gestionnaire->choix, dimensions[0] + 28, 0);
            if (derniers_tours_accomplis(gestionnaire))
            {
                gestionnaire->etat = 3;
            }
        } else if (gestionnaire->etat == 0) {
            afficher_menu(gestionnaire, 3, 3);
        } else if (gestionnaire->etat == 2) {
            afficher_menu_pause(gestionnaire, 23, 3);
        } else if (gestionnaire->etat == 3) 
        {
            afficher_fin(gestionnaire, 10, 3);
        }
        rafraichir_affichage(gestionnaire);
        char* touche = attendre_touche();
        controles(gestionnaire, touche);
        
    }
    return 0;

}

