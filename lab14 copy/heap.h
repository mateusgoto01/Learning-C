#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


struct heap
{
    int* key;
    int* cost;
    int size;
    int capacity;
};

typedef struct heap heap;

// Inicializar o heap
heap* heap_creat(int cap);


//Funções auxiliares
//Encontrar o indice filho esq
int heap_left(int index);
//Encontrar o indice filho dir
int heap_right(int index);
//Encontrar o indice de um pai
int heap_parent(int index);

//Função auxiliar de inserição e remoção

//anda desde uma folha da arvore até a raiz se precisar, para trocar os valores e manter a arvore balanceada
void heapfy_up(heap* p,int index, int track[]);

//anda desde uma raiz até a folha se precisar, para trocar os valores e manter a arvore balanceada
void heapfy_bottom(heap* p, int index, int track[]);

// troca os valores de dois nós. Pode fazer trocas invalidas, mas delimito as trocas nas outras funções ** pode dar problema.
void heap_swap(heap* p, int parent, int index, int track[]);

//Busca as posições em que certa chave se encontra usando o vetor auxiliar
int heap_search(int key, int track[]);

//Função de inserção, o heap deve inserir o custo acompanhado de sua chave. Se a chave já existe em algum lugar, não faça nada
void heap_insert(heap* p, int key, int cost, int track[]);

//Função que remove o mínimo de toda a arvore. Se a arvore estiver fazia, printe "arvore vazia"
void heap_remove(heap* p, int track[]);

// função de trocar o cost de uma função. Se ela for menor que a anterior ela precisa subir na arvore.
void heap_down(heap* p, int track[], int key, int newkey);

//Free em toda alocação feita

void heap_free(heap* p);
