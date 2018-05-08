#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
#include <ctype.h>

/*#define  maxNumCaracToRead 200
#define max 10 //nodos diferenetes max que puede llegar a leer*/



//Estructutras finales para el proyecto final

//Estructura para la lectura de archivo
struct arrChar{
char leerCaracter[256];
char auxEntrada[256];
char nodosEntrada[256];
char nodoSalida[256];
char longitud[256];
};

//estructura de la arista del grafo
typedef struct {
    int vertice;
    int peso;
} aristaE;

//Estructura del vertice del grafo
typedef struct {
    aristaE **aristas;
    int longitudAristas;
    int tamanioArista;
    int distancia;
    int nodoPrevio;
    int nodoVisitado;
} verticeE;

//Estructura del grafo
typedef struct {
    verticeE **vertices;
    int longitudVertices;
    int tamanioVertice;
} nodoEstructura;

//Estructura para la crear la topologia
typedef struct {
    int *datosAlmacenados;
    int *auxNodo;
    int *indice;
    int longitudNodo;
    int tamanioNodo;
} pilaNodoE;


//Menu de Ayudaa
void menuHelp();

//imprime los errores
int validationError(int valida);

/*funciones topología*/
extern void agregarArista (nodoEstructura *nodo, int nodoOrigen, int nodoDestino, int costoArista);
extern void agregaVertice (nodoEstructura *nodo, int i);

/*funciones ruteo*/
void ruteo();

/*funciones  direccionamiento*/
void direccionamiento();



/*Estructura para leer el archivo de topologia.txt
typedef struct topologiatxt{
  char *origen;
  char *destino;
  char *auxiliar;
  int costo;
  struct topologiatxt *siguiente;
}DATOS;
*/
