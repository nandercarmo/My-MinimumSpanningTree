#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

//Definicao do TAD GRAFO
typedef struct Item TipoItem;
typedef struct Celula_str *Apontador;
typedef struct Celula_str Celula;
typedef struct ListaAD Lista;
typedef struct Grafo_str Grafo;

    struct Item {
        int aresta;
        int vertice;
    };

    struct Celula_str {
        Apontador prox;
        TipoItem item;
    };

    struct ListaAD {
        Apontador primeiro;
        Apontador ultimo;
        int vertice;
    };

    struct Grafo_str {
         Lista *vetor;
         int num_arestas;
         int num_vertices;
    };

void FazListaVazia(Lista*);
int TestaListaVazia(Lista*);
void InsereLista(Celula*, Grafo*, int);
void MontaLista (Lista*, TipoItem);
void RetiraLista(Apontador, Apontador, Lista*);
void ImprimeLista(Lista*);
Lista OrdenaLista(Lista*);
void ImprimeListaArquivo(Lista*, FILE*);

//---------------------------------------------------------------------------------

void DefineTamanhoGrafo(Grafo*, int);
int TestaGrafoVazio(Grafo *grf);
void InsereVerticeGrafo(Grafo*, int, int, int);
void RetiraVerticeGrafo(Grafo*, int, int, int);
void ImprimeGrafo(Grafo*);
int VerificaGrafo(Grafo*, int, int);
void GeraGrafoMinimo(Grafo*);
void OrdenaGrafo(Grafo*);
void ImprimeGrafoArquivo(Grafo*, FILE*);

#endif
