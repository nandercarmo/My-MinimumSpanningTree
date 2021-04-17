#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc, char const *argv[]) {

	if(argc == 3) {

		FILE * input;
		input = fopen (argv[1],"r");

		if(input != NULL) {

			int num_vertices, num_arestas, vertice1, vertice2, aresta;

			fscanf(input, "%d %d", &num_vertices, &num_arestas);
			Grafo grafo;
			DefineTamanhoGrafo(&grafo, num_vertices);

			for(int i = 0; i < num_arestas; i++) {
				fscanf(input, "%d %d %d", &vertice1, &vertice2, &aresta);
				InsereVerticeGrafo(&grafo, vertice1, vertice2, aresta);
			}
			fclose (input);

			GeraGrafoMinimo(&grafo);
			OrdenaGrafo(&grafo);
			printf("\n");
			ImprimeGrafo(&grafo);
			printf("\n");

		FILE * output;
		output = fopen (argv[2],"w");

			if(output != NULL) {

				ImprimeGrafoArquivo(&grafo, output);
				fclose(output);
			
			} else {

				printf("Error on opening 'output.txt' file!\n");
				return -1;
			}
		
		} else {
			
			printf("Error on opening 'input.txt' file!\n");
			return -1;
		}
	
	} else {

		printf("Error! Input parameters are incorrects!");
		return -1;
	}

	return 0;
}
