#include "funcionesGenerales.h"


/**
 *
 * @author [Diego Patricio Gutierrez]
 * @date [5-mayo-2018]
 * @brief [Funcion que imprime el direccionamiento]
 * @file [muestraRuta.c]
 *
 * @nodoEstructura *nodo [Recibo la estructura del nodo]
 * @i[nodo inicial]
 *
 * */
void funcionDireccionamiento (nodoEstructura *nodo, int i) {

    int n = 1;
    int j = 0;
    char *ruta = malloc(n);
    verticeE *auxVerti, *auxVerticeE;
    i = i - 'a';
    auxVerti = nodo->vertices[i];

    if (auxVerti->distancia == 99999) {

        printf("No se encuentra ruta....\n");
        return;
    }

    for (auxVerticeE = auxVerti; auxVerticeE->distancia; auxVerticeE = nodo->vertices[auxVerticeE->nodoPrevio], n++) {
    }

    ruta[n - 1] = 'a' + i;
	printf("La ruta es: \n\n");
    for (auxVerticeE = auxVerti; auxVerticeE->distancia; auxVerticeE = nodo->vertices[auxVerticeE->nodoPrevio], j++) {

        ruta[n - j - 2] = 'a' + auxVerticeE->nodoPrevio;
        printf("Ruta: %c con costo de: %d\n", ruta[n - j - 2], auxVerticeE->nodoPrevio);
    }

    printf("%d <-%.*s\n", auxVerti->distancia, n, ruta);
}
