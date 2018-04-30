#include "funcionesGenerales.h"


void topologia()
{

  FILE *topologia;
  int valida=0, c, i,a;
  char renglon[200];
  char or[255];
  char de[255];
  int costo;
  DATOS *inicio, *auxiliar, *nodo;
  char separador[]=":";
  char *cadena;
  const char *arregloCadena[max];
  int contador=0;

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
	      printf("%s\n",nodo->origen);
	      nodo->destino=(char*)malloc(strlen(de));
	      strcpy(nodo->destino,de);
	      printf("%s\n",nodo->destino);
	      nodo->costo=costo;
	      printf("%d\n",nodo->costo);

	      nodo->siguiente=NULL;

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
      //inicializamos el arreglo de cadenas.
      for (a=0; a<max; a++)
	{
	  arregloCadena[a]="0";
	  printf("%s\n",arregloCadena[a]);
	}

      auxiliar = inicio;
      while (auxiliar != NULL)
        {
          contador=0;
          for (a=0; a<max; a++)
          {
              if(strstr(arregloCadena[a],"0")!=NULL)
              {
                if (strcasecmp(arregloCadena[a],auxiliar->origen)==0)
                  {
                    contador = 1;
                  }
              }
          }
          if(contador==0)
          {
            arregloCadena[a]=auxiliar->origen;
          }

          contador=0;
          for (a=0; a<max; a++)
          {
              if(strstr(arregloCadena[a],"0")!=NULL)
              {
                if (strcasecmp(arregloCadena[a],auxiliar->origen)==0)
                  {
                    contador = 1;
                  }
              }
          }
          if(contador==0)
          {
            arregloCadena[a]=auxiliar->destino;
          }
           auxiliar = auxiliar->siguiente;
	      }
  for(a=0;a<max;a++)
  {
    printf("%s",arregloCadena[a]);
  }
      getchar();
      getchar();
    }
}
