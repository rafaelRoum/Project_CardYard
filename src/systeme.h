#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <unistd.h>
    #include <termios.h>
#endif


#ifdef _WIN32

char attendre_touche() {
    return getch();
}

void afficher_caractere_colore(char c, int couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, couleur);
    putchar(c);
    SetConsoleTextAttribute(hConsole, 7); 
}

#else

char attendre_touche() {
    struct termios oldt, newt;
    char c;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    read(STDIN_FILENO, &c, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

void afficher_caractere_colore(char c, int couleur) {
    // Code ANSI pour les couleurs
    printf("\033[38;5;%dm%c\033[0m", couleur, c);
}

#endif
