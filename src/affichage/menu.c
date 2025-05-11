#include "menu.h"
#include <limits.h>

void afficher_menu(Gestionnaire* gestionnaire, int x, int y)
{
    afficher_texte(gestionnaire, "  /$$$$$$                          /$$       /$$     /$$                      /$$", x, y);
    afficher_texte(gestionnaire, " /$$__  $$                        | $$      |  $$   /$$/                     | $$", x, y + 1);
    afficher_texte(gestionnaire, "| $$  \\__/ /$$$$$$   /$$$$$$  /$$$$$$$       \\  $$ /$$/$$$$$$   /$$$$$$  /$$$$$$$", x, y + 2);
    afficher_texte(gestionnaire, "| $$      |____  $$ /$$__  $$/$$__  $$        \\  $$$$/____  $$ /$$__  $$/$$__  $$", x, y + 3);
    afficher_texte(gestionnaire, "| $$       /$$$$$$$| $$  \\__/ $$  | $$         \\  $$/ /$$$$$$$| $$  \\__/ $$  | $$", x, y + 4);
    afficher_texte(gestionnaire, "| $$    $$/$$__  $$| $$     | $$  | $$          | $$ /$$__  $$| $$     | $$  | $$", x, y + 5);
    afficher_texte(gestionnaire, "|  $$$$$$/  $$$$$$$| $$     |  $$$$$$$          | $$|  $$$$$$$| $$     |  $$$$$$$", x, y + 6);
    afficher_texte(gestionnaire, " \\______/ \\_______/|__/      \\_______/          |__/ \\_______/|__/      \\_______/", x, y + 7);
    afficher_texte(gestionnaire, "                            Pressez ESPACE pour Jouer !    ", x, y + 10);
}

void afficher_menu_pause(Gestionnaire* gestionnaire, int x, int y)
{
    afficher_texte(gestionnaire, " #-------------------------#", x, y);
    afficher_texte(gestionnaire, "||          MENU           ||", x, y + 1);
    afficher_texte(gestionnaire, "||                         ||", x, y + 2);
    afficher_texte(gestionnaire, "||         Quitter         ||", x, y + 3);
    afficher_texte(gestionnaire, "||                         ||", x, y + 4);
    afficher_texte(gestionnaire, " #-------------------------#", x, y + 5); 
    afficher_caractere(gestionnaire, '>', x + 8, y + gestionnaire->selection_menu + 3);
}

void afficher_fin(Gestionnaire* gestionnaire, int x, int y) {
    afficher_texte(gestionnaire, "  #-----------------------------------#", x, y);
    afficher_texte(gestionnaire, " ||         TABLEAU DES SCORES        ||", x, y + 1);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 2);
    afficher_texte(gestionnaire, " ||       Gagnant :                   ||", x, y + 3);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 4);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 5);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 6);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 7);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 8);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 9);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 10);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 11);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 12);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 13);
    afficher_texte(gestionnaire, " ||    Pressez ESPACE pour quitter    ||", x, y + 14);
    afficher_texte(gestionnaire, " ||                                   ||", x, y + 15);
    afficher_texte(gestionnaire, "  #-----------------------------------#", x, y + 16);
    int score_min = INT_MAX; 
    char* nom;

    for (int i = 0; i < gestionnaire->nb_joueurs; i++)
    {
        int score = 0;
        for (int j = 0; j < gestionnaire->nb_cartes; j++)
        {
            score = score + gestionnaire->joueurs[i]->cartes[j];
        }
        if (score < score_min)
        {
            score_min = score;
            nom = gestionnaire->joueurs[i]->nom;
        }
        char score_texte[100];
        sprintf(score_texte, "%s (%d)",  gestionnaire->joueurs[i]->nom, score);
        afficher_texte(gestionnaire, score_texte, x + 10, y + i + 5);
        afficher_texte(gestionnaire, nom, x + 20, y + 3);
    }
}