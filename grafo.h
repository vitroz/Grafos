#define Lin 20
#define Col 40


typedef struct grafo Grafo;


struct grafo
{
	int nro_vertices;
	int grau_max;
	int** arestas;
	int** percusso;
	int* grau;

};

Grafo *gr;
char labirinto[Lin][Col];
int x, y, fim;

Grafo* cria_grafo(int nro_vertices, int grau_max){

	Grafo *gr=(Grafo*) malloc(sizeof(struct grafo));

	if(gr != NULL)
	{
		int i;
		gr->nro_vertices = nro_vertices;
		gr->grau_max = grau_max;		
		gr->grau=(int*)calloc(nro_vertices,sizeof(int));
		gr->arestas=(int**)malloc(nro_vertices*sizeof(int*));
		gr->percusso=(int**)malloc(nro_vertices*sizeof(int*));

		for(i = 0; i<nro_vertices; i++)
			gr->arestas[i]=(int*)malloc(nro_vertices*sizeof(int*));
		for(i = 0; i<nro_vertices; i++)
			gr->percusso[i]=(int*)malloc(nro_vertices*sizeof(int*));				
	}
		return gr;
}

void libera_Grafo(Grafo* gr)
{
	if(gr != NULL){
		int i;
		for(i=0; i<gr->nro_vertices; i++)
			free(gr->arestas[i]);
		free(gr->arestas);
		
		free(gr->grau);
		free(gr);
	}
}

int insereAresta(Grafo* gr, int orig, int dest){
	if(gr == NULL)
		return 0;
	if(orig < 0 || orig >= gr->nro_vertices)
		return 0;
	if(dest < 0 || dest >= gr->nro_vertices)
		return 0;

/*	gr->arestas[orig][gr->grau[orig]] = dest;	Percurso*/ 
	gr->percusso[orig][gr->grau[orig]] = dest;
	gr->arestas[orig][gr->grau[orig]] = 1;
	gr->grau[orig]++;

}

int removeAresta(Grafo* gr, int orig, int dest){
	if(gr == NULL)
		return 0;
	if(orig < 0 || orig >= gr->nro_vertices)
		return 0;
	if(dest < 0 || dest >= gr->nro_vertices)
		return 0;

	int i = 0;
	while(i<gr->grau[orig] && gr->arestas[orig][i]!=dest)
		i++;
	if(i == gr->grau[orig])
		return 0;
	gr->grau[orig]--;
	gr->arestas[orig][i]=gr->arestas[orig][gr->grau[orig]];	

}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
	int i;
	visitado[ini] = cont;
	printf("%d\n",ini);
	for(i=0; i<gr->grau[ini]; i++){
		if(!visitado[gr->arestas[ini][i]])
			buscaProfundidade(gr,gr->arestas[ini][i],visitado,cont+1);
	}
	for(i=0; i<gr->grau[ini]; i++){
		if(!visitado[gr->percusso[ini][i]])
			buscaProfundidade(gr,gr->percusso[ini][i],visitado,cont+1);
	}
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
	int i, cont = 1;
	for(i = 0; i<gr->nro_vertices; i++)
		visitado[i] = 0;
	buscaProfundidade(gr, ini, visitado, cont);
}


void print_grafo(Grafo* g) {
  int i, j;

  printf("  ");
  for (i = 0 ; i < g->nro_vertices ; i++) 
  	printf(" %d ", i);
  for (i = 0 ; i < g->nro_vertices ; i++) {
	 printf("\n");
    printf("%d ", i);
    for (j = 0 ; j < g->nro_vertices ; j++) {
      printf("[%d]", g->arestas[i][j-1]);
    }
  }
  printf("\n\n");
}

