//REferencias Manuel perez, Isuky
#include "funcionesGenerales.h"


void topologia()
{

  FILE *topologia;
  int valida=0, c, i,a;
  char renglon[200];
  char or[255];
  char ori[255];
  char de[255];
  int costo,d=0;
  DATOS *inicio, *auxiliar, *nodo;
  char separador[]=":";
  char *cadena;
  char *arregloCadena[max];
  int contador=0;
char nulo='\0';
char busca[25];

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
      //leer renglon por renglon
      while (fgets(renglon,maxNumCaracToRead,topologia)!=NULL)
	{
	  cadena= strtok(renglon,separador);
	  while (cadena != NULL)
	    {
	      printf("%s ",cadena);
	      cadena = strtok(NULL,separador);
	    }
	  //Guardar datos del renglo origen:Destino:Costo
	  if(scanf(cadena,"%s%*c%s%*c%d",or,de,&costo)==3) //valida que tenga 3 valores
	    {

	      nodo=malloc(sizeof(DATOS));
	      if(nodo==NULL)
		{
		  valida=3;
		  validationError(valida);
		  //limpiamos el nodo
		  if (inicio == NULL)
		    {
		      nodo = inicio;
		      while (nodo != NULL)
			{
			  inicio = nodo->siguiente;
			  free(nodo);
			  nodo = inicio;
			  exit(0);
			}
		    }
		}
	      nodo->origen=(char*)malloc(strlen(or));
	      strcpy(nodo->origen,or);
	      nodo->destino=(char*)malloc(strlen(de));
	      strcpy(nodo->destino,de);
	      nodo->costo=costo;
	      nodo->siguiente=NULL;

        printf("%s\n",nodo->origen);
        printf("%s\n",nodo->destino);
        printf("%d\n",nodo->costo);

	      if (inicio == NULL)
		{
		  inicio=nodo;
		}
	      else
		{
		  auxiliar->siguiente=nodo;
		}
auxiliar=nodo;
	    }

	}
      fclose(topologia);
      //apartir de aqui , comparamos los cadenas para determinar cuantos nodos son
      //inicializamos el arreglo de cadenas

      if (auxiliar == NULL)
      {
        printf("\nNo hay DATOS en el programa\n\n");
     }
      else
       {
   printf("\nsi hay\n\n");
 }


//vamos a buscar en la lista

printf("buscar: ");
scanf("%s",busca);
printf("%s",busca);

auxiliar=inicio;
while(auxiliar!=NULL)
  {
    if(strcmp(busca,auxiliar->origen)==0)
    {
    printf("%s\n",auxiliar->origen);
    contador=1;
  }
    auxiliar=auxiliar->siguiente;
  }
  if(contador==0)
  {
    printf(" no existe");
  }

//
 }
//
    getchar();
    getchar();
    //

}
