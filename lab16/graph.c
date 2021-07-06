#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

table* graph_creat(int size){
    table* table = malloc(sizeof(node));
    table->head = calloc(size, sizeof(node*));

    table->mark = malloc(size * sizeof(int));
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
    free(p->mark);
    free(p->color);
    free(p->timestamp);
    free(p->timestamp_final);
    free(p->head);
    free(p);
}
