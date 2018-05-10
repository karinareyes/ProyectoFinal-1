#include "funcionesGenerales.h"


//DIreccionamiento por Juan Pablo
pilaNodoE *creaPila (int nodoss) {
    pilaNodoE *auxiliarPila = calloc(1, sizeof (pilaNodoE));
    auxiliarPila->datosAlmacenados = calloc(nodoss + 1, sizeof (int));
    auxiliarPila->auxNodo = calloc(nodoss + 1, sizeof (int));
    auxiliarPila->indice = calloc(nodoss, sizeof (int));
    return auxiliarPila;
}
int sacaMenor (pilaNodoE *h, int longNodo2, int z, int y) {
    int m = longNodo2;
    if (z <= h->longitudNodo && h->auxNodo[z] < h->auxNodo[m])
        m = z;
    if (y <= h->longitudNodo && h->auxNodo[y] < h->auxNodo[m])
        m = y;
    return m;
}
 

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


void dijkstra (nodoEstructura *nodo, int nodoOrigen, int nodoDestino) {
    int i, j;
    FILE *archivoRuteo;
    archivoRuteo=fopen("ruteo.txt","wt");
    fprintf(archivoRuteo,"\t\t\t\t%s%s%s%s%s\n","Tabla"," ","de"," ","ruteo");
    fprintf(archivoRuteo,"%s%s%s%s%s\n","NodoOrigen"," ","NodoDestino"," ","Distancia");
    char concatenaArchivoRuteo;;
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
