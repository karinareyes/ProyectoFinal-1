#include "funcionesGenerales.h"

/*

@Autor: Juan Pablo Velasco Medina
@Nombre del archivo: funcionesRuteo.c
@Funciones:

pilaNodoE *creaPila(int nodoss);
Entrada: valor entero nodo
Salida: estructura de la pila del nodo
Proceso: crea la pila donde se guardaran los datos ordenados

int sacaMenor(pilaNodoE *h, int longNodo2, int z, int y);
Entrada: estructura del nodo, longitud y dos nodos a comparar con valor entero
Salida: valor del nodo entero menor
Proceso: compara los nodos para sacar el menor y guardarlo en la estructura

void guardaPilaNodos (pilaNodoE *auxPilaNodos, int v, int p);
Entrada: estructura de la pila de nodos, entero que es el valor del nodo origen, entero valor distancia
Salida: Sin salida
Proceso: guarda los nodos y la distancia que se van formando en las iterraciones

int propPila (pilaNodoE *auxPilaNodoE);
Entrada: estructura de la pila
Salida: valor entero
Proceso: Guarda todos los nodos, sacando los de menor costo en cada iteracción
void dijkstra (nodoEstructura *nodo, int nodoOrigen, int nodoDestino);

Entrada: estructura del nodo, nodo origen con valor int, nodo destino con valor int
Salida: Ninguno, solo el archivo de ruteo
Proceso: Esta función nos va a permitir ir sacando las posibles rutas que tiene un nodo origen
    al nodo destino, esto nos permite sacar la tabla de ruteo y guardarlo en el archivo ruteo.txt,
    también guardar todos los nodos para después sacar la ruta más corta
*/
//Ruteo por Juan Pablo

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
    FILE *archivoRuteo;    /*Abrimos o se crea el archivo ruteo.txt para ir guardando los nodos generados */
    archivoRuteo=fopen("ruteo.txt","wt");
    fprintf(archivoRuteo,"\t\t\t\t%s%s%s%s%s\n","Tabla"," ","de"," ","ruteo");
    fprintf(archivoRuteo,"%s%s%s%s%s\n","NodoOrigen"," ","NodoDestino"," ","Distancia");
    char concatenaArchivoRuteo;
    /* Tanto nodo origen y destino se les resta 'a' para tener un rango de 0 a n en valor entero*/
    nodoOrigen = nodoOrigen - 'a';
    nodoDestino = nodoDestino - 'a';
    for (i = 0; i < nodo->longitudVertices; i++) {
        verticeE *auxVerti = nodo->vertices[i];
        auxVerti->distancia = INT_MAX;
        auxVerti->nodoPrevio = 0;
        auxVerti->nodoVisitado = 0;
    }
    /* Recorre los nodos partiendo del nodo Origen */
    verticeE *auxVerti = nodo->vertices[nodoOrigen];
    auxVerti->distancia = 0;
    pilaNodoE *auxPilaNodoE = creaPila(nodo->longitudVertices); //Crea la pila de nodos dependiendo la longitud de los vertices
    //printf("---> LONG %d ---> NODO ORIGEN %d ---> DISTANCIA %d \n",auxPilaNodoE->longitudNodo,nodoOrigen, auxVerti->distancia);
    guardaPilaNodos(auxPilaNodoE, nodoOrigen, auxVerti->distancia); // Va guardando los nodos partiendo del nodo origen, destino y su distancia
    while (auxPilaNodoE->longitudNodo) {//Recorre los numeros de nodos y cuando llega su longitud se sale
        i = propPila(auxPilaNodoE);//guarda el valor del nodo
        if (i == nodoDestino)//si el valor del nodo es igual al destino, se sale
            break;
        auxVerti = nodo->vertices[i]; //sino recorre todos los nodos
        auxVerti->nodoVisitado = 1;
        for (j = 0; j < auxVerti->longitudAristas; j++) {//ahora recorremos cuantas aristas se forman
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
