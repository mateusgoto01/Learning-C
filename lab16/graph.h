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

    int* color; // 1 = white 2 = gray 3 = black
    int* timestamp; // guarda tempo de descoberta
    int* timestamp_final; // guarda tempo de finalização

    node** head;
};

typedef struct table table;

//cria a tabela para as listas de adjacências 
table* graph_creat();

//insere as arestas
void graph_insert(table* p, int arest1, int arest2);
//Função para conferir se a inserção está certa
void graph_print(int ver, table* p);
void graph_print_DFS(int ver, table* p);
//Free nas alocações feitas
void graph_free(table* p);

//Parte do codigo para DFS
void graph_DTS(table* p, int size);

int graph_DTS_visit(table* p, int vertex, int time);
