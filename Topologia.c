#include "funcionesGenerales.h"

void topologia()
{

FILE *topologia;
int valida=0, c, i,a;
char renglon[200];
char *or;
char ori[255];
char *de;
int costo,d=0;
DATOS *inicio, *auxiliar, *nodo;
char separador[]=":";
char *cadena;
char *arregloCadena[max];
int contador=0;
char nulo='\0';
char busca[25];


char *costoc;


system("clear");
printf("\t\t\tRealizado por: Diana Laura Aviles Elizalde\n\n");
printf("lee topoligia archivo\n");

topologia=fopen("topologia.txt","rt");




//Validar si existe el archivo
if(topologia==NULL)
  {
    valida=2;
    validationError(valida);
    getchar();
  }
  else
  {
    while(fscanf(topologia,"%s",renglon)==1)
    {
      or=strtok(renglon,":");
      de=strtok(NULL,":");
      costoc=strtok(NULL,":");
      costo=atoi(costoc);
    }

  }

//
getchar();
getchar();
}//fin main
