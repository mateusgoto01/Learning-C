#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

table* graph_creat(int size){
    table* table = malloc(sizeof(node));
    table->head = calloc(size, sizeof(node*));

    table->mark = malloc(size * sizeof(int));
    table->dist = malloc(size * sizeof(int));

    return table;
}

void graph_insert(table* p, int arest1, int arest2){
    node* n = malloc(sizeof(node));
    if(n == NULL)
        return;
    //Primeira inserção
    n->data = arest2;
    n->next = p->head[arest1-1];
    p->head[arest1 -1] = n;

    // não é mais necessario
    /*//Segunda inserção
    node* m = malloc(sizeof(node));
    if(m == NULL)
        return;

    m->data = arest1;
    m->next = p->head[arest2-1];
    p->head[arest2 -1] = m;*/
}

void graph_print(int ver, table* p){
    for(int i = 0; i < ver; i++){
        node* n = p->head[i];
        printf("posi: %d -- ", i+1);
        while(n != NULL){
            printf("%d ",  n->data);
            n = n->next;
        }
        printf("\n");
    }
}

queue* queue_creat(int size){
    queue* q = malloc(sizeof(queue));
    q->itens = calloc(size, sizeof(node*));

    q->front = -1;
    q->rear = -1; 

    return q;
}

void queue_enqueue(queue* q, table* p, int posi){
    if(q->front == -1) // se tiver vazio
        q->front = 0;
    q->rear++; //botar na posição 0 e assim em diante
    q->itens[q->rear] = posi-1;
}

int queue_dequeue(queue* q){
    int n;
    if(q->rear == -1) // se estiver vazia
        return 0; // faça nada
    else{
        n = q->itens[q->front];
        q->front++;
        if(q->front > q->rear){ // Se o front ficar maior é que já passamos por todos elementos da lista
        q->front = -1;
        q->rear = -1;
        }
    }
    return n;
}   

void graph_BFS(table* p, int size, int ori){
    queue* queue = queue_creat(size);
    for(int i = 0; i < size; i++){
        p->mark[i] = 0;
        p->dist[i] = -1;
        //printf("%d %d\n", p->mark[i], p->dist[i]);
    }
    p->mark[ori-1] = 1;
    p->dist[ori-1] = 0;
    queue_enqueue(queue, p, ori);
    while(queue->rear != -1){
        int v = queue_dequeue(queue);
        //printf("valor de v  = %d\n", v);
        printf("%d %d\n", v+1, p->dist[v]);
        node* n = p->head[v];
        while(n != NULL){
            if(p->mark[n->data-1] == 0){
                //printf("vertices = %d, esta na posi = %d\n", n->data, n->data-1);
                p->dist[n->data-1] = p->dist[v] +1;
                p->mark[n->data-1] = 1;
                queue_enqueue(queue, p, n->data);
            }
            n = n->next;
        }
    }
    queue_free(queue);
}
void graph_free(table* p){
    free(p->mark);
    free(p->dist);
    free(p->head);
    free(p);
}

void queue_free(queue* q){
    free(q->itens);
    free(q);
}