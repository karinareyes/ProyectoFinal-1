default: Dijkstra.o funcionesGenerales.o 	funcionesTopologia.o funcionesRuteo.o funcionesDireccionamiento.o
	gcc Dijkstra.o funcionesGenerales.o funcionesTopologia.o funcionesRuteo.o funcionesDireccionamiento.o -o Dijkstra -lm
Dijkstra.o:Dijkstra.c
	gcc -c Dijkstra.c
funcionesGenerales.o:funcionesGenerales.c
		gcc -c funcionesGenerales.c
funcionesTopologia.o: funcionesTopologia.c
		gcc -c funcionesTopologia.c
funcionesRuteo.o:funcionesRuteo.c
		gcc -c funcionesRuteo.c
funcionesDireccionamiento.o:funcionesDireccionamiento.c
				gcc -c funcionesDireccionamiento.c
todo:
	gcc Dijkstra.c funcionesGenerales.c funcionesTopologia.c funcionesRuteo.c funcionesDireccionamiento.c -o Dijkstra
clear:
	rm*.o
