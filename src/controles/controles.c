#include "controles.h"
#include <string.h>

void controles(Gestionnaire* gestionnaire, char* touche)
{ 
    if (strcmp(touche, "DROITE") == 0)
    {
        gestionnaire->selection = gestionnaire->selection + 1;
    }
    if (strcmp(touche, "GAUCHE") == 0)
    {
        gestionnaire->selection = gestionnaire->selection - 1;
    }
}