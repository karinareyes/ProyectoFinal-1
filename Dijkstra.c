/*----------------------------------------------------------------------------------------------------
  P R O Y E C T O    F I N A L     <TALLER DESARROLLO DE APLICACIONES
  ---------------------------------------------------------------------------------------------------*/
#include "funcionesGenerales.h"


int main(int argc, char const *argv[])
{

FILE *propiedadesTxt; //leer el archivo de propiedades
FILE *topologiaTxt; //lee el archivo de topologia

int i=0,j=0;
int nodoEntrada=0;
int contadorNodosEntrada=0;
int contadorNodosSalida=0;
int contadorLongitud=0;
int res;
char nodoEntradaAscii;
char nodoDestinoAscii;
char archivoTopologia[]= "topologia.txt";
char archivoPropiedades[]= "properties.txt";
char letraComparar[20];
char edificio[20];

//variables para el menú
char opcion[15];
int opcionMenu=0;
int valida=0;
int contadori=0;
//declaracion de la estructura almacenando un espacio en la memoria
struct arrChar aux;
nodoEstructura *nodo = calloc(1, sizeof (nodoEstructura));


  do {
    do{
      system ("clear");
      printf("\n\n\t\t\t\t\tPROGRAMA  DE  CAMINOS  CORTOS \n\n");
      printf("\t\t\t\t     M e n u      d e      O p c  i o n e s \n\n");
      printf("\t\t\t\t  --------------------------------------------\n");
      printf("\t\t\t\t\t\tDesarrollado por:\n\n");
      printf(" \t\t\t\t\tDiana Laura Aviles Elizalde\n" );
      printf(" \t\t\t\t\tDiego Patricio Gutierrez Lopez Cano\n" );
      printf(" \t\t\t\t\tJuan Pablo Velasco Medina\n" );
      printf("\t\t\t\t  --------------------------------------------\n");
      printf("\t\t |                                                                             |\n");
      printf("\t\t |  1.  Ayuda                                                                  |\n");
      printf("\t\t |  2.  Generar topología                                                      |\n");
      printf("\t\t |  3.  Mostrar la lista de nodos de la red                                    |\n");
      printf("\t\t |  4.  Salir                                                                  |\n");
      printf("\t\t |                                                                             |\n");
      printf("\t\t\t\t  --------------------------------------------\n\n");
      printf("\t\t\t\tIngresar opcion: ");
      scanf("%s",opcion);

      if (sscanf(opcion, "%d", &opcionMenu) != 1) // Se valida que sea un numero entero.
	{
	  valida=1;
	  validationError(valida);
	  getchar();
	  getchar();
	}
    } while(sscanf(opcion, "%d", &opcionMenu) != 1);  //2 hasta ingresarlo bien se repetira


    switch (opcionMenu) {
    case 1:
      menuHelp();
      getchar();
      break;

    case 2:
    topologiaTxt=fopen(archivoTopologia,"r");
    if(topologiaTxt==NULL)
    {
     printf("NO existe el archivo\n");
   }
   else
   {
     while (fscanf(topologiaTxt,"%s %s %s",aux.nodosEntrada,aux.nodoSalida,aux.longitud) != EOF)
     {
         j++;
       int auxEntero= aux.longitud[0] - '0';
       agregarArista(nodo,toascii(aux.nodosEntrada[0]), toascii(aux.nodoSalida[0]), auxEntero);

     }
   }
     fclose (topologiaTxt);

    propiedadesTxt=fopen(archivoPropiedades,"r");
     printf("\n\n\t\tReferencia\n\n");
     while (fscanf(topologiaTxt,"%s\t%s \n",letraComparar,edificio) != EOF){
       j++;
       for(int contadori = 0; letraComparar[contadori]; contadori++) {
         printf("\t\t%c\t%s\n", letraComparar[contadori],edificio);
       }

     }
     fclose (propiedadesTxt);

     getchar();
     getchar();
      break;

    case 3:
    system("clear");
    printf("Escribe el nodo origen:");
scanf("%c",&nodoEntradaAscii);
int enteroNodoEntradaAscii=  (int)nodoEntradaAscii;
if(enteroNodoEntradaAscii>122 || enteroNodoEntradaAscii<97){
  printf("\n\n\t\t\t\n ERROR escribe una letra en minuscula de la a a la z \n");
  exit(0);
}
printf("\n");
getchar();
printf("Escribe el nodo destino:");
scanf("%c",&nodoDestinoAscii);
int enteroNodoDestinoAscii=  (int)nodoDestinoAscii;
if(enteroNodoDestinoAscii>122 || enteroNodoDestinoAscii<97){
  printf("\n\n\t\t\t\n ERROR escribe una letra en minuscula de la a a la z \n");
  exit(0);
}
//printf("\n\n\n\n\n\n Nodo salida %d",enteroNodoEntradaAscii);
printf("\n\t\t\t *********Tabla de Ruteo ************\n\n\n");
printf("\t Nodo Origen \t Nodo Destino \t Distancia\n");
printf("\n\t\t %c \t\t %c \t\t %d \n",nodoEntradaAscii,nodoEntradaAscii,0);
dijkstra(nodo, enteroNodoEntradaAscii,enteroNodoDestinoAscii);
funcionDireccionamiento(nodo, enteroNodoDestinoAscii);

      break;

    case 4:
      printf("HASTA LUEGO VUELVA PRONTO\n");
      exit(0);
      break;

    default:
      system("clear");
      printf("INGRESE UNA OPCION CORRECTA\n");
    }

  } while(opcionMenu<=5);

  return 0;
}
