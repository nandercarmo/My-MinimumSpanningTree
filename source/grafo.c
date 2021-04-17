#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

     int TestaListaVazia(Lista *lista) {

          if(lista->primeiro == lista->ultimo)
               return 1;

          return 0;
     }

     void FazListaVazia(Lista *lista){

          lista->primeiro = (Apontador) malloc(sizeof(Celula));
          lista->ultimo = lista->primeiro;
          lista->primeiro->prox = NULL;
     }

     void InsereLista(Celula *celula, Grafo *grafo, int i){

          grafo->vetor[i].ultimo->prox = celula;
          grafo->vetor[i].ultimo = grafo->vetor[i].ultimo->prox;
          grafo->vetor[i].ultimo->prox = NULL;
     }

     void RetiraLista(Apontador p, Apontador q, Lista *lista){

          p->prox = q->prox;
          if (p->prox == NULL)
          lista->ultimo = p;
          free(q);
     }

     void ImprimeLista(Lista *lista){

          Apontador aux;
          aux = lista->primeiro->prox;
          while(aux != NULL){
               printf("%i %i %i\n", lista->vertice, aux->item.vertice, aux->item.aresta);
               aux = aux->prox;
          }
     }

     void MontaLista(Lista *lista, TipoItem item){

          lista->ultimo->prox = (Apontador) malloc(sizeof(Celula));
          lista->ultimo = lista->ultimo->prox;
          lista->ultimo->item = item;
          lista->ultimo->prox = NULL;
     }

     Lista OrdenaLista(Lista *lista){

          Apontador aux, aux2, copia;
          Lista lista_aux;
          FazListaVazia(&lista_aux);

          lista_aux.vertice = lista->vertice;

          while (!TestaListaVazia(lista)) {

               aux = lista->primeiro;
               aux2 = aux;
               copia = aux->prox;

               while (aux->prox != NULL) {
                    if(aux->prox->item.vertice < copia->item.vertice){
                         copia = aux->prox;
                         aux2 = aux;
                    }
                    aux = aux->prox;
               }

               MontaLista(&lista_aux, copia->item);
               RetiraLista(aux2, copia, lista);
          }
          return lista_aux;
     }

     void ImprimeListaArquivo(Lista *lista, FILE *file){

          Apontador aux;
          aux = lista->primeiro->prox;
          while(aux != NULL){
               fprintf(file, "%i %i %i\n", lista->vertice, aux->item.vertice, aux->item.aresta);
               aux = aux->prox;
          }
     }

//--------------------------------------------------------------------------------

     void DefineTamanhoGrafo(Grafo *grf, int numero_vertices){

          grf->num_vertices = numero_vertices;
          grf->num_arestas = 0;

          grf->vetor = (Lista *) malloc(numero_vertices*sizeof(Lista));

          for (int i = 0; i < grf->num_vertices; i++) {
               FazListaVazia(&grf->vetor[i]);
          }

          for (int i = 0; i < grf->num_vertices; i++){
               grf->vetor[i].vertice = -1;
          }
     }

     int TestaGrafoVazio(Grafo *grf){
          for (int i = 0; i < grf->num_vertices; i++) {

               if(grf->vetor[i].primeiro->prox != NULL){
                   return 0;
               }
          }
          return 1;
     }

     void InsereVerticeGrafo(Grafo *grf, int vertice_inicial, int vertice_final, int aresta){
          int i=0;

          Celula *aux;
          aux = (Celula *) malloc(sizeof(Celula));
          aux->item.vertice = vertice_final;
          aux->item.aresta = aresta;

          if(!TestaGrafoVazio(grf)){

               for (i = 0; i < grf->num_vertices; i++) {

                    if (grf->vetor[i].vertice == -1) break;
                    if (grf->vetor[i].vertice == vertice_inicial) {

                         InsereLista(aux, grf, i);
                         grf->num_arestas++;
                         return ;
                    }
               }

               grf->vetor[i].vertice = vertice_inicial;
               InsereLista(aux, grf, i);
               grf->num_arestas++;
               return ;
          }

          grf->vetor->vertice = vertice_inicial;
          InsereLista(aux, grf, i);
          grf->num_arestas++;
          return ;
     }

     void RetiraVerticeGrafo(Grafo *grafo, int vertice1, int vertice2, int aresta){

          Apontador q, p;
          p = grafo->vetor[vertice1].primeiro;
          q = grafo->vetor[vertice1].primeiro->prox;

          while ((q->item.aresta != aresta) && (q->item.vertice != vertice2) && (q != NULL)) {
               p = q;
               q = q->prox;
          }
          RetiraLista(p, q, &grafo->vetor[vertice1]);
          grafo->num_arestas--;
     }

     void ImprimeGrafo(Grafo *grf) {

          printf("%i %i\n", grf->num_vertices, grf->num_arestas);

          for (int i = 0; i < grf->num_vertices && grf->vetor[i].vertice != -1; i++){
               ImprimeLista(&grf->vetor[i]);
          }
     }

     int VerificaGrafo(Grafo *grafo, int vertice1, int vertice2){

          int v1=0, v2=0;
          Apontador aux;

          for (int i = 0; i < grafo->num_vertices; i++) {

               if((v1 == 0) && (vertice1 == grafo->vetor[i].vertice)) v1 =1;
               if((v2 == 0) && (vertice2 == grafo->vetor[i].vertice)) v2 =1;
          }
               for (int i = 0; i < grafo->num_vertices; i++){

                    aux = grafo->vetor[i].primeiro->prox;
                    while (aux != NULL) {
                         if((v1 == 0) && (vertice1 == aux->item.vertice)) v1 =1;
                         if((v2 == 0) && (vertice2 == aux->item.vertice)) v2 =1;

                         aux = aux->prox;
                    }
               }

          if((v1*v2 == 0) && (v1+v2 ==1)){
               return 1;
          } else return 0;
     }

     void GeraGrafoMinimo(Grafo *grafo){

          Grafo grf;
          DefineTamanhoGrafo(&grf, grafo->num_vertices);

          Apontador aux;
          int menor[]={-1, -1, -1};
          int aresta = -1, vertice;

          grf.vetor->vertice = grafo->vetor->vertice;
          grf.num_vertices = 1;

          while (grf.num_vertices < grafo->num_vertices) {

               for (int i = 0; (i < grafo->num_vertices) && (grafo->vetor[i].vertice != -1); i++) {

                    aux = grafo->vetor[i].primeiro->prox;
                    while (aux != NULL) {

                         if ((aresta == -1 || aux->item.aresta < aresta) && VerificaGrafo(&grf, grafo->vetor[i].vertice, aux->item.vertice)) {
                              aresta = aux->item.aresta;
                              vertice = aux->item.vertice;
                         }
                         if(aux->prox == NULL) break;
                         aux = aux->prox;
                    }

                    if((aresta < menor[2]) || (menor[2] == -1)){

                         menor[0] = grafo->vetor[i].vertice;
                         menor[1]= vertice;
                         menor[2] = aresta;
                    }
               }

               InsereVerticeGrafo(&grf, menor[0], menor[1], menor[2]);
               grf.num_vertices++;

               for (int i = 0; i < grafo->num_vertices; i++) {
                    if (grafo->vetor[i].vertice == menor[0]){
                         menor[0] = i;
                         break;
                    }
               }
               RetiraVerticeGrafo(grafo, menor[0], menor[1], menor[2]);
               aresta = -1;
               menor[2] = -1;
          }
          *grafo = grf;
     }

     void OrdenaGrafo(Grafo *grafo){

          for (int i = 0; (i < grafo->num_vertices) && (grafo->vetor[i].vertice != -1); i++) {
               grafo->vetor[i] = OrdenaLista(&grafo->vetor[i]);
          }

          int j=0;
          Lista aux;

          for (int i = 1; (i < grafo->num_vertices) && grafo->vetor[i].vertice != -1; i++) {

               aux = grafo->vetor[i];
               j = i - 1;

               while ((j >= 0) && (aux.vertice < grafo->vetor[j].vertice)) {

                    grafo->vetor[j + 1] = grafo->vetor[j];
                    j--;
               }
               grafo->vetor[j + 1] = aux;
          }
     }

     void ImprimeGrafoArquivo(Grafo *grafo, FILE *file){

          fprintf(file, "%i %i\n", grafo->num_vertices, grafo->num_arestas);
          for (int i = 0; i < grafo->num_vertices && grafo->vetor[i].vertice != -1; i++){
               ImprimeListaArquivo(&grafo->vetor[i], file);
          }
     }
