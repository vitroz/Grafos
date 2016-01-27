#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main(){
	Grafo *cria_grafo(int nro_vertices, int grau_max, int eh_ponderado);

	Grafo *gro;
	gro = cria_grafo(10, 7, 0);
	insereAresta(gr, 0, 1, 0, 0);
	insereAresta(gr, 1, 3, 0, 0);
	removeAresta(gr, 0, 1 ,0);	

	int eh_digrafo = 1;
	Grafo* gr = cria_grafo(5, 5, 0);
	insereAresta(gr, 0, 1, eh_digrafo, 0);
	insereAresta(gr, 1, 3, eh_digrafo, 0);
	insereAresta(gr, 1, 2, eh_digrafo, 0);
	insereAresta(gr, 2, 4, eh_digrafo, 0);
	insereAresta(gr, 3, 0, eh_digrafo, 0);
	insereAresta(gr, 3, 4, eh_digrafo, 0);
	insereAresta(gr, 4, 1, eh_digrafo, 0);

	int vis[5];

	buscaProfundidade_Grafo(gr, 0, vis);

	libera_Grafo(gr);

	return 0;
}