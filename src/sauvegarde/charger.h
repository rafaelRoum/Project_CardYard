// Non utilisé dans la version actuelle du programme, mais défini pour extensions futures

#include "../gestionnaire/gestionnaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lit toutes les lignes du fichier de sauvegarde et renvoie un tableau de chaînes
char** lire_lignes(int* nb_lignes);

// Charge un gestionnaire depuis les lignes du fichier (non encore relié à l'exécution principale)
void charger_gestionnaire();
