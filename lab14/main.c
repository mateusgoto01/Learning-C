#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "heap.h"

int main(void){
    int cap = 0;
    int cost;
    int key;
    char cmd;
    scanf(" %d", &cap);

    int track[cap]; // responsavel por encontrar as chaves
    heap* p = heap_creat(cap);

    while(1){
        scanf(" %c", &cmd);
        if(cmd == 'i'){
            scanf(" %d %d\n", &key, &cost);
            heap_insert(p, key, cost, track);
        }
        else if(cmd == 'm'){
            heap_remove(p, track);
        }
        else if(cmd == 'd'){
            scanf(" %d %d\n", &key, &cost);
            heap_down(p, track, key, cost);
        }
        else if(cmd == 't'){
            heap_free(p);
            return 0;
        }
    }
    return 0;
}