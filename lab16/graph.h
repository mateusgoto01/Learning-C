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

//Criando a queue para fazer o BFS(Breadth first search). ainda tenho trauma do lab08 professor, mas vamos tentar fazer a queue

struct queue{
    int* itens;

    int front;
    int rear;
};

typedef struct queue queue;

// Criar a queue
queue* queue_creat(int size);

//Inserir na queue
void queue_enqueue(queue* q, table* p, int posi);

//Remover da queue
int queue_dequeue(queue* q);

//Com a queue feita, podemos criar a função BFS. A busca por largura e printar todos os vertices percorridos e distancia
void graph_BFS(table* p, int size, int ori);

//Função para dar free em tudo galera.
void graph_free(table* p);
void queue_free(queue* q);