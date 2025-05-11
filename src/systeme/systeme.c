#include "systeme.h"
#include <stdio.h> 
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>

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


void afficher_caractere_colore(char c, int couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, couleur);
    putchar(c);
    SetConsoleTextAttribute(hConsole, 7); 
}

void vider_console() {
    system("cls");
}

void afficher_texte_colore(char* texte, int couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD couleur_originale = csbi.wAttributes; // Sauvegarde de la couleur actuelle

    SetConsoleTextAttribute(hConsole, couleur); // Changement de couleur
    printf("%s\n", texte);
    SetConsoleTextAttribute(hConsole, couleur_originale); // Restauration de la couleur
}

#else
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

char* attendre_touche() {
    struct termios oldt, newt;
    static char touche[8] = {0};  // Tableau pour stocker la touche appuyée

    // Sauvegarde les réglages de terminal et désactive l'echo et le mode canonique
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Désactive ICANON et ECHO
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int c = getchar();  // Lire un caractère de l'entrée standard

    if (c == 27) {  // Si c'est un ESC (27 en ASCII)
        if (getchar() == 91) {  // Si le prochain caractère est '[' (pour les touches fléchées)
            switch (getchar()) {
                case 'A': strcpy(touche, "HAUT"); break;
                case 'B': strcpy(touche, "BAS"); break;
                case 'C': strcpy(touche, "DROITE"); break;
                case 'D': strcpy(touche, "GAUCHE"); break;
                default: strcpy(touche, "INCONNU"); break;
            }
        } else {
            strcpy(touche, "ESC");  // Si ce n'est pas suivi d'une flèche, c'est juste ESC
        }
    } else if (c == 10) {  // Si c'est un ENTER (code ASCII 10)
        strcpy(touche, "ENTER");
    } else if (c == 32) {  // Si c'est un espace (code ASCII 32)
        strcpy(touche, "ESPACE");
    } else if (c == 27) {  // Vérifier si c'est la touche ESC seule (pas suivi de flèches)
        strcpy(touche, "ESC");
    } else {
        touche[0] = (char)c;  // Sinon, c'est un caractère normal
        touche[1] = '\0';  // Ajouter le caractère de fin de chaîne
    }
    
    // Restaurer les réglages de terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return touche;  // Retourner la touche détectée
}


void afficher_caractere_colore(char c, int couleur) {
    printf("\033[1;%dm%c\033[0m", couleur, c);
}

void afficher_texte_colore(const char* texte, int couleur) {
    while (*texte) {
        afficher_caractere_colore(*texte, couleur);
        texte++;
    }
    printf("\n");
}

void vider_console() {
    system("clear");
}

#endif