#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void main(int argc, char const *argv[]) {

     if (argc == 3) {

          FILE *entrada;
          entrada = fopen (argv[1],"r");

          if (entrada != NULL){

               int num_vertices, num_arestas, vertice1, vertice2, aresta;

               fscanf(entrada, "%d %d", &num_vertices, &num_arestas);
               Grafo grafo;
               DefineTamanhoGrafo(&grafo, num_vertices);

               for (int i = 0; i < num_arestas; i++) {
                    fscanf(entrada, "%d %d %d", &vertice1, &vertice2, &aresta);
                    InsereVerticeGrafo(&grafo, vertice1, vertice2, aresta);
               }
               fclose (entrada);

               GeraGrafoMinimo(&grafo);
               OrdenaGrafo(&grafo);
               printf("\n");
               ImprimeGrafo(&grafo);
               printf("\n");

          FILE *saida;
          saida = fopen (argv[2],"w");

               if (saida != NULL){

                    ImprimeGrafoArquivo(&grafo, saida);
                    fclose (saida);
               }
               else {
                    printf("\nFalha ao abrir arquivo para escrita!!!\nCertifique-se de passar o nome corretamente\n\n");
                    return ;
               }
          }
          else {
               printf("\nFalha ao abrir arquivo para leitura!!!\nCertifique-se de passar o nome corretamente\n\n");
               return ;
          }
     }
     else{
          printf("\nERRO!!!\nCertifique-se de ter todos os parametros de entrada no formato: \nLinux: $ ./executavel.exe entrada.txt saida.txt\nWindows: executavel.exe entrada.txt saida.txt\n\n");
          return;
     }
}
