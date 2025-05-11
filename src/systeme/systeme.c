#include "systeme.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <string.h>

// Fonction pour attendre une touche (Windows)
char* attendre_touche() {
    static char touche[8] = {0};
    int c = _getch();

    if (c == 0 || c == 224) {
        int special = _getch();
        switch (special) {
            case 72: strcpy(touche, "HAUT"); break;
            case 80: strcpy(touche, "BAS"); break;
            case 75: strcpy(touche, "GAUCHE"); break;
            case 77: strcpy(touche, "DROITE"); break;
            default: strcpy(touche, "INCONNU"); break;
        }
    } else if (c == 13) {
        strcpy(touche, "ENTER");
    } else if (c == 27) {
        strcpy(touche, "ESC");
    } else if (c == 32) {
        strcpy(touche, "ESPACE");
    } else {
        touche[0] = (char)c;
        touche[1] = '\0';
    }

    return touche;
}

// Affiche un caractère avec une couleur (Windows)
void afficher_caractere_colore(char c, int couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, couleur);
    putchar(c);
    SetConsoleTextAttribute(hConsole, 7); // Couleur par défaut
}

// Efface la console (Windows)
void vider_console() {
    system("cls");
}

// Affiche du texte en couleur (Windows)
void afficher_texte_colore(char* texte, int couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD couleur_originale = csbi.wAttributes;

    SetConsoleTextAttribute(hConsole, couleur);
    printf("%s\n", texte);
    SetConsoleTextAttribute(hConsole, couleur_originale);
}

#else
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

// Fonction pour attendre une touche (Linux / Unix)
char* attendre_touche() {
    struct termios oldt, newt;
    static char touche[8] = {0};

    // Désactive le mode canonique
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int c = getchar();

    if (c == 27) {
        if (getchar() == 91) {
            switch (getchar()) {
                case 'A': strcpy(touche, "HAUT"); break;
                case 'B': strcpy(touche, "BAS"); break;
                case 'C': strcpy(touche, "DROITE"); break;
                case 'D': strcpy(touche, "GAUCHE"); break;
                default: strcpy(touche, "INCONNU"); break;
            }
        } else {
            strcpy(touche, "ESC");
        }
    } else if (c == 10) {
        strcpy(touche, "ENTER");
    } else if (c == 32) {
        strcpy(touche, "ESPACE");
    } else {
        touche[0] = (char)c;
        touche[1] = '\0';
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return touche;
}

// Affiche un caractère coloré en utilisant les codes ANSI
void afficher_caractere_colore(char c, int couleur) {
    printf("\033[1;%dm%c\033[0m", couleur, c);
}

// Affiche du texte entier avec couleur (Linux)
void afficher_texte_colore(const char* texte, int couleur) {
    while (*texte) {
        afficher_caractere_colore(*texte, couleur);
        texte++;
    }
    printf("\n");
}

// Efface la console (Linux)
void vider_console() {
    system("clear");
}

#endif
