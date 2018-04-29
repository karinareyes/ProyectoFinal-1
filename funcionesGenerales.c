#include "funcionesGenerales.h"

void menuHelp()
{
  system("clear");
  printf("\n\t\t\t\t\t\t\t A Y U D A \n");
  printf("\t\t\t\t\t\t----------------------------\n\n");
  printf("\t\t   Este programa ayuda a encontrar la ruta más corta para llegar de un punto X  a un punto Y  \n");
  printf("\t\ten este caso se esta basando en la topología de la universidad Iberoamericana usando el famoso\n");
  printf("\t\tAlgoritmo de Dijkstra , ya que; es un algoritmo que determina el camino más corto dado un nodo\n");
  printf("\t\tun nodo destino y un costo. Como resultado indicara los puntos a seguir para llegar al destino.\n\n");
  printf("\t\t\t\t\t\t       Desarrollado por:\n\n");
  printf(" \t\t\t\t\t\t   Diana Laura Aviles Elizalde\n" );
  printf(" \t\t\t\t\t\tDiego Patricio Gutierrez Lopez Cano\n" );
  printf(" \t\t\t\t\t\t   Juan Pablo Velasco Medina\n\n\n" );
  printf("\t\t\t\t\t\tPresiona Enter para continuar [  ]\n");
  getchar();

}



int validationError(int valida)
{
  switch (valida)
  {
    case 1:
      system("clear"); //validacion de argumentos
      printf("\n\n\tIngreso mal su opcion,intentelo de nuevo\n");
      printf("\t\t\t\t\t\tPresiona Enter para continuar [  ]\n");
    break;

    case 2:
      system("clear"); //validacion de argumentos
      printf("\n\n\t\t\t\t\t\t     No existe el archivo\n");
        printf("\t\t\t\t\t\tPresiona Enter para continuar [  ]\n");
    break;

    case 3:
      system("clear"); //validacion de argumentos
      printf("\n\n\t\t\t\t\t\t  YA NO HAY MEMORIA\n");
        printf("\t\t\t\t\t\tPresiona Enter para continuar [  ]\n");
    break;


  default:
    printf("ERROR\n");
  }
}
