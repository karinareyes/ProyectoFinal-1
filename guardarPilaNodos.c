#include "funciones.h"

void guardaPilaNodos (pilaNodoE *auxPilaNodos, int v, int p) {
    int pos = auxPilaNodos->indice[v] == 0 ? ++auxPilaNodos->longitudNodo : auxPilaNodos->indice[v];
    int pos2 = pos / 2;
    while (pos > 1) {
        if (auxPilaNodos->auxNodo[pos2] < p)
            break;
        auxPilaNodos->datosAlmacenados[pos] = auxPilaNodos->datosAlmacenados[pos2];
        auxPilaNodos->auxNodo[pos] = auxPilaNodos->auxNodo[pos2];
        auxPilaNodos->indice[auxPilaNodos->datosAlmacenados[pos]] = pos;
        pos = pos2;
        pos2 = pos2 / 2;
    }
    auxPilaNodos->datosAlmacenados[pos] = v;
    //printf("POSICION : %d\n",v);
    auxPilaNodos->auxNodo[pos] = p;
    auxPilaNodos->indice[v] = pos;
}