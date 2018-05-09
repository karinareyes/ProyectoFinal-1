#include "funciones.h"

int propPila (pilaNodoE *auxPilaNodoE) {
    int v = auxPilaNodoE->datosAlmacenados[1];
    int i = 1;
    while (1) {
        int j = sacaMenor(auxPilaNodoE, auxPilaNodoE->longitudNodo, 2 * i, 2 * i + 1);
        if (j == auxPilaNodoE->longitudNodo)
            break;
        auxPilaNodoE->datosAlmacenados[i] = auxPilaNodoE->datosAlmacenados[j];
        auxPilaNodoE->auxNodo[i] = auxPilaNodoE->auxNodo[j];
        auxPilaNodoE->indice[auxPilaNodoE->datosAlmacenados[i]] = i;
        i = j;
    }
    auxPilaNodoE->datosAlmacenados[i] = auxPilaNodoE->datosAlmacenados[auxPilaNodoE->longitudNodo];
    auxPilaNodoE->auxNodo[i] = auxPilaNodoE->auxNodo[auxPilaNodoE->longitudNodo];
    auxPilaNodoE->indice[auxPilaNodoE->datosAlmacenados[i]] = i;
    auxPilaNodoE->longitudNodo--;
    return v;
}