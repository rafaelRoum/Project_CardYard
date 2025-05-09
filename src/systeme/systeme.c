#include "systeme.h"
#include <stdio.h> 

#ifdef _WIN32
#include <windows.h>
#include <conio.h>

char* attendre_touche() {
    int c = getch(); 

    if (c == 0 || c == 224) { 
        int code = getch(); 
        switch (code) {
            case 72: return "HAUT";    
            case 80: return "BAS";     
            case 75: return "GAUCHE";  
            case 77: return "DROITE";  
            default: return "INCONNU"; 
        }
    }

  
    static char touche[2] = {0}; 
    touche[0] = (char)c;
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

#else
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

char* attendre_touche() {
    struct termios oldt, newt;
    static char touche[8] = {0};

    // Sauvegarde de l'état actuel du terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Mode brut : désactiver l'écho et la mise en tampon
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int c = getchar();

    if (c == 27) { // ESC
        if (getchar() == 91) { // [
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
    } else {
        touche[0] = (char)c;
        touche[1] = '\0';
    }

    // Restaure les paramètres d'origine du terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return touche;
}

void afficher_caractere_colore(char c, int couleur) {
    printf("\033[1;%dm%c\033[0m", couleur, c);
}

void vider_console() {
    system("clear");
}
#endif