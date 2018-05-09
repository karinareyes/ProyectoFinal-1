#include "funciones.h"

void dijkstra (nodoEstructura *nodo, int nodoOrigen, int nodoDestino) {
    int i, j;
    FILE *archivoRuteo;
    archivoRuteo=fopen("ruteo.txt","wt");
    fprintf(archivoRuteo,"\t\t\t\t%s%s%s%s%s\n","Tabla"," ","de"," ","ruteo");
    fprintf(archivoRuteo,"%s%s%s%s%s\n","NodoOrigen"," ","NodoDestino"," ","Distancia");
    char concatenaArchivoRuteo="";
    nodoOrigen = nodoOrigen - 'a';
    nodoDestino = nodoDestino - 'a';
    for (i = 0; i < nodo->longitudVertices; i++) {
        verticeE *auxVerti = nodo->vertices[i];
        auxVerti->distancia = INT_MAX;
        auxVerti->nodoPrevio = 0;
        auxVerti->nodoVisitado = 0;
    }
    verticeE *auxVerti = nodo->vertices[nodoOrigen];
    auxVerti->distancia = 0;
    pilaNodoE *auxPilaNodoE = creaPila(nodo->longitudVertices);
    //printf("---> LONG %d ---> NODO ORIGEN %d ---> DISTANCIA %d \n",auxPilaNodoE->longitudNodo,nodoOrigen, auxVerti->distancia);
    guardaPilaNodos(auxPilaNodoE, nodoOrigen, auxVerti->distancia);
    while (auxPilaNodoE->longitudNodo) {
        i = propPila(auxPilaNodoE);
        if (i == nodoDestino)
            break;
        auxVerti = nodo->vertices[i];
        auxVerti->nodoVisitado = 1;
        for (j = 0; j < auxVerti->longitudAristas; j++) {
            aristaE *auxAristaE = auxVerti->aristas[j];
            verticeE *auxVerticeE = nodo->vertices[auxAristaE->vertice];
            if (!auxVerticeE->nodoVisitado && auxVerti->distancia + auxAristaE->peso <= auxVerticeE->distancia) {
                auxVerticeE->nodoPrevio = i;
                auxVerticeE->distancia = auxVerti->distancia + auxAristaE->peso;
                //printf("---> LONG %d ---> VERTICE %d ---> DISTANCIA %d \n",auxPilaNodoE->longitudNodo,auxAristaE->vertice, auxVerticeE->distancia);
        
        int desplegarLetraVertice=auxAristaE->vertice+97;
        char letraVertice=desplegarLetraVertice;
        int desplegarLetraNodoAnterior=auxVerticeE->nodoPrevio+97;
        char letraNodoAnterior=desplegarLetraNodoAnterior;
        //printf("---> LONG %d ---> VERTICE %d .--->NODO PREVIO %d ---> DISTANCIA %d \n",auxPilaNodoE->longitudNodo,auxAristaE->vertice, auxVerticeE->nodoPrevio,auxVerticeE->distancia);
        printf("\n \t \t %c \t \t %c \t \t %d \n",letraNodoAnterior,letraVertice,auxVerticeE->distancia);
        //concatenaArchivoRuteo=letraNodoAnterior+letraVertice+auxVerticeE->distancia;
        fprintf(archivoRuteo,"\t\t%c\t\t\t\t\t%c\t\t\t\t\t%d\n",letraNodoAnterior,letraVertice,auxVerticeE->distancia);
        
                guardaPilaNodos(auxPilaNodoE, auxAristaE->vertice, auxVerticeE->distancia);
            }
        }
    }
    fclose(archivoRuteo);
}