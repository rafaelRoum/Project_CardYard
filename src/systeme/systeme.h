#ifndef SYSTEME_H
#define SYSTEME_H
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>

// Déclarations de fonctions
char* attendre_touche();
void afficher_caractere_colore(char c, int couleur);
void vider_console();
void dimensions_terminal(int* lignes, int* colonnes);
void afficher_texte_colore(char* texte, int couleur);

// Codes couleur texte Windows
#define COULEUR_NOIR         0
#define COULEUR_BLEU         1
#define COULEUR_VERT         2
#define COULEUR_CYAN         3
#define COULEUR_ROUGE        4
#define COULEUR_MAGENTA      5
#define COULEUR_MARRON       6
#define COULEUR_GRIS_CLAIR   7
#define COULEUR_GRIS         8
#define COULEUR_BLEU_CLAIR   9
#define COULEUR_VERT_CLAIR   10
#define COULEUR_CYAN_CLAIR   11
#define COULEUR_ROUGE_CLAIR  12
#define COULEUR_ROSE_CLAIR   13
#define COULEUR_JAUNE_CLAIR  14
#define COULEUR_BLANC        15

#else
#include <stdio.h>

// Déclarations de fonctions
char* attendre_touche();
void afficher_caractere_colore(char c, int couleur);
void vider_console();
void dimensions_terminal(int* lignes, int* colonnes);
void afficher_texte_colore(const char* texte, int couleur);

// Codes ANSI pour les couleurs Linux
#define COULEUR_NOIR         30
#define COULEUR_ROUGE        31
#define COULEUR_VERT         32
#define COULEUR_JAUNE        33
#define COULEUR_BLEU         34
#define COULEUR_MAGENTA      35
#define COULEUR_CYAN         36
#define COULEUR_BLANC        37
// Couleurs "vives" (utilisables avec séquences ANSI)
#define COULEUR_NOIR_CLAIR   90
#define COULEUR_ROUGE_CLAIR  91
#define COULEUR_VERT_CLAIR   92
#define COULEUR_JAUNE_CLAIR  93
#define COULEUR_BLEU_CLAIR   94
#define COULEUR_MAGENTA_CLAIR 95
#define COULEUR_CYAN_CLAIR   96
#define COULEUR_BLANC_CLAIR  97
#define COULEUR_GRIS         37
#define COULEUR_ROSE_CLAIR   200
#define COULEUR_MARRON       31

#endif // _WIN32

#endif // SYSTEME_H
