cls
@echo off
gcc main.c src/affichage/basique.c src/affichage/nombre.c src/affichage/carte.c src/joueur/joueur.c src/gestionnaire/gestionnaire.c src/pioche/pioche.c src/affichage/partie.c src/systeme/systeme.c src/controles/controles.c src/affichage/menu.c -o main.exe
main.exe 