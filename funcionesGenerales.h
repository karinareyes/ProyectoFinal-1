#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define  maxNumCaracToRead 200
#define max 10 //nodos diferenetes max que puede llegar a leer

/*Estructura para leer el archivo de topologia.txt*/
typedef struct topologiatxt{
  char *origen;
  char *destino;
  char *auxiliar;
  int costo;
  struct topologiatxt *siguiente;
}DATOS;

//Estructutras finales TDA
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


//Menu de Ayudaa
void menuHelp();

//imprime los errores
int validationError(int valida);

/*funciones topología*/
void topologia();

/*funciones ruteo*/
void ruteo();

/*funciones  direccionamiento*/
void direccionamiento();
