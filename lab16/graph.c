#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

table* graph_creat(int size){
    table* table = malloc(sizeof(node));
    table->head = calloc(size, sizeof(node*));

    table->color = malloc(size * sizeof(int));
    table->timestamp = malloc(size * sizeof(int));
    table->timestamp_final = malloc(size * sizeof(int));

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

void graph_print_DFS(int ver, table* p){
    for(int i = 0; i < ver; i++){
        printf("%d [%d,%d]\n", i+1, p->timestamp[i], p->timestamp_final[i]);   
    }
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

void graph_free(table* p){
    free(p->color);
    free(p->timestamp);
    free(p->timestamp_final);
    free(p->head);
    free(p);
}

void graph_DTS(table* p, int size){
    for(int i = 0; i<size; i++){
        p->color[i] = 1;
        p->timestamp[i] = 0;
        p->timestamp_final[i] = 0;
    }
    int time = 0;
    for(int i = 0; i <size; i++){
        if(p->color[i] == 1)// se o vertex estiver branco
        {
            //printf("fui pro vertice %d\n", i);
            time = graph_DTS_visit(p, i, time);
        }
            
    }
}

int graph_DTS_visit(table* p, int vertex, int time){
    time += 1;
    //printf("Valor de time %d\n", time);
    p->timestamp[vertex] = time;
    p->color[vertex] = 2; // color cinza
    node* n = p->head[vertex];
    while(n != NULL){
        //printf("estou olhando os vizinhos de %d\n", n->data -1);
        if(p->color[n->data - 1] == 1){
            //printf("estou nas arestas de %d\n", n->data -1);
            time = graph_DTS_visit(p, n->data - 1, time);
        }
        n = n->next;
    }
    p->color[vertex] = 3; // color black
    time += 1;
    p->timestamp_final[vertex] = time;
    return time;
}
