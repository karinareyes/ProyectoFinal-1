#include "funciones.h"

pilaNodoE *creaPila (int nodoss) {
    pilaNodoE *auxiliarPila = calloc(1, sizeof (pilaNodoE));
    auxiliarPila->datosAlmacenados = calloc(nodoss + 1, sizeof (int));
    auxiliarPila->auxNodo = calloc(nodoss + 1, sizeof (int));
    auxiliarPila->indice = calloc(nodoss, sizeof (int));
    return auxiliarPila;
}