#include "funcionesGenerales.h"

void agregarArista (nodoEstructura *nodo, int nodoOrigen, int nodoDestino, int costoArista) {
    printf("NODO ORIGEN %d\n\n",nodoOrigen);
    nodoOrigen = nodoOrigen - 'a';
    printf("NODO DESTINO %d\n\n",nodoDestino);
    nodoDestino = nodoDestino - 'a';

    agregaVertice(nodo, nodoOrigen);
    agregaVertice(nodo, nodoDestino);
    verticeE *auxVertice = nodo->vertices[nodoOrigen];
    if (auxVertice->longitudAristas >= auxVertice->tamanioArista) {
        auxVertice->tamanioArista = auxVertice->tamanioArista ? auxVertice->tamanioArista * 2 : 4;
        auxVertice->aristas = realloc(auxVertice->aristas, auxVertice->tamanioArista * sizeof (aristaE *));
    }
    aristaE *auxiliarArista = calloc(1, sizeof (aristaE));
    auxiliarArista->vertice = nodoDestino;
    auxiliarArista->peso = costoArista;
    auxVertice->aristas[auxVertice->longitudAristas++] = auxiliarArista;
}

void agregaVertice (nodoEstructura *nodo, int i) {
    if (nodo->tamanioVertice < i + 1) {
        int tamanioNodo = nodo->tamanioVertice * 2 > i ? nodo->tamanioVertice * 2 : i + 4;
        nodo->vertices = realloc(nodo->vertices, tamanioNodo * sizeof (verticeE *));
        for (int j = nodo->tamanioVertice; j < tamanioNodo; j++)
            nodo->vertices[j] = NULL;
        nodo->tamanioVertice = tamanioNodo;
    }
    if (!nodo->vertices[i]) {
        nodo->vertices[i] = calloc(1, sizeof (verticeE));
        nodo->longitudVertices++;
    }
}
