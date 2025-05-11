#include "controles.h"
#include <string.h>
#include <limits.h>
#include <stdlib.h>

// Copie toutes les données d’un gestionnaire vers un autre
void reassigner_gestionnaire(Gestionnaire* gestionnaire, Gestionnaire* gestionnaire_)
{
    // Copie toutes les propriétés du gestionnaire
    gestionnaire->caracteres = gestionnaire_->caracteres; 
    gestionnaire->couleurs = gestionnaire_->couleurs;
    gestionnaire->dimensions[0] = gestionnaire_->dimensions[0];
    gestionnaire->dimensions[1] = gestionnaire_->dimensions[1];
    gestionnaire->longeur_max = gestionnaire_->longeur_max;
    gestionnaire->nb_joueurs = gestionnaire_->nb_joueurs;
    gestionnaire->joueurs = gestionnaire_->joueurs;
    gestionnaire->nb_cartes = gestionnaire_->nb_cartes;
    gestionnaire->tour = gestionnaire_->tour;
    gestionnaire->selection = gestionnaire_->selection;
    gestionnaire->mode = gestionnaire_->mode;
    gestionnaire->etat = 0;
    gestionnaire->choix = gestionnaire_->choix;
    gestionnaire->temp_choix = gestionnaire_->temp_choix;
    gestionnaire->selection_alt = gestionnaire_->selection_alt;
    gestionnaire->selection_menu = gestionnaire_->selection_menu;
    gestionnaire->fin_jeu = gestionnaire_->fin_jeu;
    gestionnaire->pioche_centrale = gestionnaire_->pioche_centrale; 
}

// Compte les défausses contenant au moins une carte
int defausses_disponibles(Gestionnaire* gestionnaire)
{
    int dispo = 0;
    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        if (!pioche_vide(gestionnaire->joueurs[i]->defausse))
        {
            dispo++;
        }
    }
    return dispo + 1; // +1 pour inclure la pioche centrale
}

// Gère les actions de l’utilisateur selon l’état du jeu et la touche appuyée
void controles(Gestionnaire* gestionnaire, char* touche)
{ 
    // État 1 : phase de sélection pendant le tour d’un joueur
    if (gestionnaire->etat == 1)
    {
        int cycle = (gestionnaire->mode == 1) ? gestionnaire->nb_cartes : defausses_disponibles(gestionnaire);

        // Navigation entre les options
        if (strcmp(touche, "DROITE") == 0)
            gestionnaire->selection = (gestionnaire->selection + 1) % cycle;
        if (strcmp(touche, "GAUCHE") == 0)
            gestionnaire->selection = (gestionnaire->selection - 1 + cycle) % cycle;

        // Validation
        if (strcmp(touche, "ENTER") == 0)
        {
            if (gestionnaire->mode == 0)
            {
                // Choix de la carte à piocher
                gestionnaire->choix = gestionnaire->temp_choix;
                gestionnaire->mode = 1;
                gestionnaire->selection = 0;

                // Si aucune défausse sélectionnée, on pioche la carte centrale
                if (gestionnaire->selection_alt == INT_MAX)
                    piocher_carte(gestionnaire->pioche_centrale);
                else
                    piocher_carte(gestionnaire->joueurs[gestionnaire->selection_alt]->defausse);
                return;
            }

            if (gestionnaire->mode == 1)
            {
                // Échange de carte : la carte actuelle va dans la défausse
                ajouter_carte(gestionnaire->joueurs[gestionnaire->tour]->defausse, gestionnaire->joueurs[gestionnaire->tour]->cartes[gestionnaire->selection]);

                // Remplacement par la carte piochée
                gestionnaire->joueurs[gestionnaire->tour]->cartes[gestionnaire->selection] = gestionnaire->choix;
                gestionnaire->joueurs[gestionnaire->tour]->configuration[gestionnaire->selection] = 1;

                // Réinitialisation du tour
                gestionnaire->choix = INT_MAX;
                gestionnaire->mode = 0;
                gestionnaire->tour = (gestionnaire->tour + 1) % gestionnaire->nb_joueurs;
                gestionnaire->selection = 0;
            }
        }

        // Pause (retour au menu)
        if (strcmp(touche, "ESC") == 0)
        {
            gestionnaire->etat = 2;
        }
    }

    // État 0 : écran d’accueil
    else if (gestionnaire->etat == 0) {
        if (strcmp(touche, "ESPACE") == 0)
        {
            gestionnaire->etat = 1; // Démarrer la partie
        }
    }

    // État 2 : menu pause
    else if (gestionnaire->etat == 2) {
        if (strcmp(touche, "ESC") == 0)
        {
            gestionnaire->etat = 1; // Reprendre la partie
        }
        if (strcmp(touche, "DROITE") == 0)
        {
            gestionnaire->selection_menu = (gestionnaire->selection_menu + 1) % 4;
        }
        if (strcmp(touche, "GAUCHE") == 0)
        {
            gestionnaire->selection_menu = (gestionnaire->selection_menu + 3) % 4;    
        }
        if (strcmp(touche, "ENTER") == 0) 
        {
            switch (gestionnaire->selection_menu)
            {
            case 0:
                vider_console(); // Efface l'écran (défini ailleurs)
                exit(0);         // Quitte le programme
                break;
            }
        }
    }

    // État 3 : écran de fin
    else if (gestionnaire->etat == 3) {
        if (strcmp(touche, "ESPACE") == 0)
        {
            exit(0); // Quitte le jeu
        }
    }
}
