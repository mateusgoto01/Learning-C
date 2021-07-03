#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "has.h"
// string "alo" e "xy" tem a mesma key
hash* hash_creat(){
    hash* table = calloc(1,sizeof(node));
    table->head = calloc(6250, sizeof(node*));

    return table;
}

unsigned long djb2(unsigned char *str) {
  unsigned long hash = 5381;
  int c;
  
  while ((c = *str++))
    hash = ((hash << 5) + hash) ^ c; // hash * 33 XOR c
  
  return hash;
}

unsigned long h1(unsigned long key){
    return key % 6250;
}

unsigned long h2(unsigned long key){
    return 1 + (key % 37);
}

void hash_insert(hash* table, char* data, int count, int timestamp2){
    //printf("count = %d\n", count);
    unsigned long key = djb2((unsigned char *) data); // convertendo string em inteiros

    unsigned long posi = (h1(key) + count*h2(key)) % 6250;
    //printf("posicao e %lu\n", posi);

    if(table->head[posi] == NULL || table->head[posi]->timestamp == -1){
        node* n = malloc(sizeof(node));
        if (n == NULL)
        return;

        n->timestamp = timestamp2;
        strcpy(n->str, data);
        n->next = table->head[posi];
        table->head[posi] = n;
    }
    else{
        hash_insert(table, data, count + 1, timestamp2);
    }
}

node* hash_search(hash* table, char* data, int count){
    unsigned long key = djb2((unsigned char *) data);

    unsigned long posi = (h1(key) + count*h2(key)) % 6250;
    // Se a chave estiver nula, então seu elemento não está aqui.
    if(table->head[posi] == NULL)
        return NULL;
    else if(table->head[posi] != NULL){
        node* p = table->head[posi];
        while(p != NULL){
            if(strcmp(p->str, data) == 0)
                return p;
            p = p->next;
        }
    }
    // se o elemento não estiver na chave procure denovo com o incremento de hashing duplo
    return hash_search(table, data, count +1);
}

void hash_remove(hash* table, char* data, int count){
    node* remove = hash_search(table, data, 0);
    if(remove == NULL){
        printf("[%s] nao esta na tabela\n", data);
    }
    else{
        printf("[%s] foi removida\n", remove->str);
        strcpy(remove->str, "removed");
        remove->timestamp = -1; 
    }
}

void hash_free(hash* table){
    for(int i = 0; i < 6250; i++){
        node* p = table->head[i];
        node* next; // aux para fazer o free
        // nesse while eu dou free em todos os nós da lista
        while (p != NULL){
            next = p->next;
            free(p);
            p = next;
        }
        //free(head); // free na propria lista
    }
    free(table); // free na tabela
}