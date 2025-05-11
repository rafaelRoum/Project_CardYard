#ifdef _WIN32
    #include <conio.h>    // Pour getch() sous Windows
    #include <windows.h>  // Pour SetConsoleTextAttribute()
#else
    #include <unistd.h>   // Pour read() et STDIN_FILENO
    #include <termios.h>  // Pour modifier les attributs du terminal
#endif
#include <stdio.h>

// ==== WINDOWS ====
#ifdef _WIN32

// Lit une touche sans appuyer sur "Entrée" (Windows)
char attendre_touche() {
    return getch();
}

// Affiche un caractère en couleur dans la console (Windows)
void afficher_caractere_colore(char c, int couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, couleur);  // Change la couleur
    putchar(c);                                  // Affiche le caractère
    SetConsoleTextAttribute(hConsole, 7);        // Restaure la couleur par défaut
}

// ==== LINUX / UNIX ====
#else

// Lit une touche sans appuyer sur "Entrée" (Linux)
char attendre_touche() {
    struct termios oldt, newt;
    char c;

    // Sauvegarde des paramètres du terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Passage en mode non-canonique et sans écho
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Lecture d’un caractère
    read(STDIN_FILENO, &c, 1);

    // Restauration des paramètres du terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

// Affiche un caractère en couleur dans la console (Linux)
void afficher_caractere_colore(char c, int couleur) {
    // Utilise les séquences ANSI 256 couleurs (38;5;)
    printf("\033[38;5;%dm%c\033[0m", couleur, c);
}

#endif
