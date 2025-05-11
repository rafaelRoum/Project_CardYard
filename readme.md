## 🎴 CardYard Project
Ce projet consiste à développer un jeu de société numérique basé sur des cartes, entièrement codé en langage C. L’objectif est de proposer une expérience interactive et éducative, tout en mettant en pratique les concepts de modularité, de gestion de ressources et de manipulation de fichiers pour les sauvegardes.
Le projet utilise des interfaces en console pour l’affichage des menus et du plateau de jeu, conformément aux designs fournis (design.txt)

## 📁 Contenu du Projet
Le répertoire contient les fichiers suivants :

README.md : Le fichier que vous êtes en train de lire.
design.txt : Ce a quoi doit ressembler l'affichage
src/ : Fichiers sources du projet.
main.c : fonction principale du programme
Makefile : Permet de compiler et de lancer le programme sous linux
run.bat : Permet de compiler et de lancer le programme sous windows


## 🛠️ Installation
Pour installer et exécuter ce projet, suivez ces étapes :
Clonez le dépôt :
git clone https://github.com/votre-repo/CardYard.git

Allez dans le répertoire du projet :
cd ./chemin/vers/CardYard

## Lancer avec les commandes : (LINUX)

### make
Compile le fichier avec le makefile


### ./main 
Execute le programme

## Pour windows : 

### run
Execute le programme grace au run.bat

## 📐 Exemple d’Affichage du Plateau
#---------------------------------------------------#--------------------# #-------------#                                                                                             
|   [Joueur 1]       [Joueur 2]       [Joueur 3]    |  [Joueur 1]        | |  SELECTION  |
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |                    | |   >  5      |
| | 0| | 0| | 8|   | 7| | 4| |11|   | 0| | 5| | 8|  |                    | #-------------#
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |                    |
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |  [Joueur 2]  #--#  |
| | 8| | 5| | 7|   | 9| | 5| | 5|   |11| | 2| |12|  |              | 1|  |
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |              #--#  |
|                                                   |                    |
|   [Joueur 4]       [Joueur 5]       [Joueur 6]    |  [Joueur 3]        |
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |                    |
| | 6| | 1| |11|   | 4| | 2| | 4|   | 1| | 3| |-1|  |                    |
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |                    |
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |  [Joueur 4]  #--#  |
| | 7| |12| | 6|   | 3| |10| |10|   | 9| | 0| | 6|  |              | 3|  |
| #--# #--# #--#   #--# #--# #--#   #--# #--# #--#  |              #--#  |
|                                                   |                    |
|   [Joueur 7]       [Joueur 8]                     |  [Joueur 5]        |
| #--# #--# #--#   #--# #--# #--#                   |                    |
| | 8| | 6| | 0|   | 3| | 0| |-1|                   |                    |
| #--# #--# #--#   #--# #--# #--#                   |                    |
| #--# #--# #--#   #--# #--# #--#                   |  [Joueur 6]        |
| | 4| | 0| |-1|   | 0| | 7| |10|                   |                    |
| #--# #--# #--#   #--# #--# #--#                   |                    |
|                                                   |                    |
|                                                   |  [Joueur 7]        |
|                                                   |                    |
|                                                   |                    |
|                                                   |                    |
|                                                   |  [Joueur 8]        |
|                                                   |                    |
|                                                   |                    |
|                                                   |                    |
|                                                   |  [Pioche]  #--#    |
|                                                   |            |  |    |
|                                                   |            #--#    |
#---------------------------------------------------#--------------------#






    #-----------------------------------#
   ||         TABLEAU DES SCORES        ||
   ||                                   ||
   ||     Gagnant :                     ||
   ||                                   ||
   ||          1. Ayoub     (3)         ||
   ||          2. Rayane    (5)         ||
   ||          3. Michel    (10)        ||
   ||          4. Zbouba    (15)        ||
   ||          5. Zbibou    (31)        ||
   ||                                   ||
   ||                                   ||
   ||                                   ||
   ||                                   ||
   ||  Pressez ENTER pour aller au Menu ||
   ||                                   ||
    #-----------------------------------#



  /$$$$$$                          /$$       /$$     /$$                      /$$      
 /$$__  $$                        | $$      |  $$   /$$/                     | $$      
| $$  \__/ /$$$$$$   /$$$$$$  /$$$$$$$       \  $$ /$$/$$$$$$   /$$$$$$  /$$$$$$$      
| $$      |____  $$ /$$__  $$/$$__  $$        \  $$$$/____  $$ /$$__  $$/$$__  $$      
| $$       /$$$$$$$| $$  \__/ $$  | $$         \  $$/ /$$$$$$$| $$  \__/ $$  | $$      
| $$    $$/$$__  $$| $$     | $$  | $$          | $$ /$$__  $$| $$     | $$  | $$      
|  $$$$$$/  $$$$$$$| $$     |  $$$$$$$          | $$|  $$$$$$$| $$     |  $$$$$$$      
 \______/ \_______/|__/      \_______/          |__/ \_______/|__/      \_______/  

                            
  Pressez ENTER pour Jouer !    

 #-------------------------#
||          MENU           ||
||                         ||
||        Recommencer      ||
||        Sauvegarder      ||
||        Charger          ||
||                         ||
||                         ||
 #-------------------------# 


## 👥 Auteurs

Rafael Roumiantsev

Michel Kamal

Rayane Houari

