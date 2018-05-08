default: Dijkstra.o funcionesGenerales.o 	funcionesTopologia.o Ruteo.o Direccionamiento.o
	gcc Dijkstra.o funcionesGenerales.o funcionesTopologia.o Ruteo.o Direccionamiento.o -o Dijkstra -lm
Dijkstra.o:Dijkstra.c
	gcc -c Dijkstra.c
funcionesGenerales.o:funcionesGenerales.c
		gcc -c funcionesGenerales.c
funcionesTopologia.o: funcionesTopologia.c
		gcc -c funcionesTopologia.c
Ruteo.o:Ruteo.c
		gcc -c Ruteo.c

todo:
	gcc Dijkstra.c funcionesGenerales.c funcionesTopologia.c Ruteo.c Direccionamiento.c -o Dijkstra
clear:
	rm*.o
