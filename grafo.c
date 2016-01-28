#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define Lin 20
#define Col 40



int main(){
	char labirinto[Lin][Col];
	int s;
	int x, y;
	Grafo *cria_grafo(int nro_vertices, int grau_max);
	Grafo *gro;
	
	gro = cria_grafo(10, 7);
	insereAresta(gr, 0, 1);
	insereAresta(gr, 1, 3);
	removeAresta(gr, 0, 1);	

	Grafo* gr = cria_grafo(5, 5);
	insereAresta(gr, 0, 1);
	insereAresta(gr, 1, 3);
	insereAresta(gr, 1, 2);
	insereAresta(gr, 2, 4);
	insereAresta(gr, 3, 0);
	insereAresta(gr, 3, 4);
	insereAresta(gr, 4, 1);

	int vis[5];

/*	CriarLabirinto();
	s = 1+rand() % Lin-2;
	Rota(s, 1);
	labirinto[s][1] = 'T'; //inicio do caminho

	Imprimir();
	x=s;
	y=1;*/

	print_grafo(gr);

	buscaProfundidade_Grafo(gr, 0, vis);

	libera_Grafo(gr);

	return 0;
}