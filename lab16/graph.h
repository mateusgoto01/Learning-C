#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


struct node
{
    int data; //guarda o vertice
    struct node* next;
};

typedef struct node node;

struct table{
    int* mark; // guar se o vertice foi marcado ou não
    int* dist; // guarda a distancia do vertice de origem
    node** head;
};

typedef struct table table;

//cria a tabela para as listas de adjacências 
table* graph_creat();

//insere as arestas
void graph_insert(table* p, int arest1, int arest2);
//Função para conferir se a inserção está certa
void graph_print(int ver, table* p);

//Free nas alocações feitas
void graph_free(table* p);

//Parte do codigo para DFS

