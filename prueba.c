#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct arrChar{
char leerCaracter[256];
char auxEntrada[256];
char nodosEntrada[256];
char nodoSalida[256];
char longitud[256];
};

typedef struct {
    int vertice;
    int peso;
} aristaE;

typedef struct {
    aristaE **aristas;
    int longitudAristas;
    int tamanioArista;
    int distancia;
    int nodoPrevio;
    int nodoVisitado;
} verticeE;
 
typedef struct {
    verticeE **vertices;
    int longitudVertices;
    int tamanioVertice;
} nodoEstructura;
 
typedef struct {
    int *datosAlmacenados;
    int *auxNodo;
    int *indice;
    int longitudNodo;
    int tamanioNodo;
} pilaNodoE;
 
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
 
void agregarArista (nodoEstructura *nodo, int nodoOrigen, int nodoDestino, int costoArista) {
    //printf("NODO ORIGEN %d\n\n",nodoOrigen);
    nodoOrigen = nodoOrigen - 'a';
    //printf("NODO DESTINO %d\n\n",nodoDestino);
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
 
pilaNodoE *creaPila (int nodoss) {
    pilaNodoE *auxiliarPila = calloc(1, sizeof (pilaNodoE));
    auxiliarPila->datosAlmacenados = calloc(nodoss + 1, sizeof (int));
    auxiliarPila->auxNodo = calloc(nodoss + 1, sizeof (int));
    auxiliarPila->indice = calloc(nodoss, sizeof (int));
    return auxiliarPila;

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
 
int sacaMenor (pilaNodoE *h, int longNodo2, int z, int y) {
    int m = longNodo2;
    if (z <= h->longitudNodo && h->auxNodo[z] < h->auxNodo[m])
        m = z;
    if (y <= h->longitudNodo && h->auxNodo[y] < h->auxNodo[m])
        m = y;
    return m;
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
                printf("---> LONG %d ---> VERTICE %d ---> DISTANCIA %d \n",auxPilaNodoE->longitudNodo,auxAristaE->vertice, auxVerticeE->distancia);
                guardaPilaNodos(auxPilaNodoE, auxAristaE->vertice, auxVerticeE->distancia);
            }
        }
    }
}
 
void muestraRuta (nodoEstructura *nodo, int i) {
    int n, j;
    verticeE *auxVerti, *auxVerticeE;
    i = i - 'a';
    auxVerti = nodo->vertices[i];
    if (auxVerti->distancia == INT_MAX) {
        printf("No hay RUta\n");
        return;
    }
    for (n = 1, auxVerticeE = auxVerti; auxVerticeE->distancia; auxVerticeE = nodo->vertices[auxVerticeE->nodoPrevio], n++);
    char *rutaFinal = malloc(n);
    rutaFinal[n - 1] = 'a' + i;
	printf("La ruta es: \n\n");
    for (j = 0, auxVerticeE = auxVerti; auxVerticeE->distancia; auxVerticeE = nodo->vertices[auxVerticeE->nodoPrevio], j++)
        rutaFinal[n - j - 2] = 'a' + auxVerticeE->nodoPrevio;
    printf("%d %.*s\n", auxVerti->distancia, n, rutaFinal);
}
 
int main () {
    nodoEstructura *nodo = calloc(1, sizeof (nodoEstructura)); 
    int nodoEntradaMain=0; 
      char archivoTopo[]= "topologia.txt";
  //~ char ofilename[]= "salida.txt";
  struct arrChar aux;int i=0,j=0,res; 
  int contadorNodosEntrada=0,contadorNodosSalida=0,contadorLongitud=0;
  
  FILE *ifp;
  ifp=fopen(archivoTopo,"r");
  while (fscanf(ifp,"%s %s %s",aux.nodosEntrada,aux.nodoSalida,aux.longitud) != EOF){
      j++;

  // for(int contadori = 0; aux.nodosEntrada[contadori]; contadori++) {
      //printf("%c, = alt + %d\n", aux.nodosEntrada[contadori], toascii(aux.nodosEntrada[contadori]));
      int auxEntero= aux.longitud[0] - '0';
      agregarArista(nodo,toascii(aux.nodosEntrada[0]), toascii(aux.nodoSalida[0]), auxEntero);
   //}
  }
fclose (ifp);
    //char caracterA= 'a';
    //int convierteA=  (int)caracterA;
    //agregarArista(nodo, convierteA, 'b', 7);
    //agregarArista(nodo, 'a', 'c', 9);
    //agregarArista(nodo, 'a', 'f', 14);
    //agregarArista(nodo, 'b', 'c', 10);
    //agregarArista(nodo, 'b', 'd', 15);
    //agregarArista(nodo, 'c', 'd', 11);
    //agregarArista(nodo, 'c', 'f', 2);
    //agregarArista(nodo, 'd', 'e', 6);
    //agregarArista(nodo, 'e', 'f', 9);
    //dijkstra(nodo, 'a', 'e');
    //muestraRuta(nodo, 'e');
   printf("\n\t\t\t *********Tabla de Ruteo ************\n\n\n");
   printf("\n\t Escribe nodo origen: \n");
   scanf("%d",
   printf("\n\t Escribe nodo destino: \n");
   dijkstra(nodo, 'a', 'e');
   muestraRuta(nodo, 'e');
    return 0;
}