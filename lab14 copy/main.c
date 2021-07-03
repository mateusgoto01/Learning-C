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

    int track[cap+1];
    for(int i = 0; i<cap+1; i++)
        track[i] = -1;
    heap* p = heap_creat(cap);

    while(1){
        scanf(" %c", &cmd);
        if(cmd == 'i'){
            scanf(" %d %d", &key, &cost);
            heap_insert(p, key, cost, track);
        }
        else if(cmd == 'm'){
            heap_remove(p, track);
        }
        else if(cmd == 'd'){
            scanf(" %d %d", &key, &cost);
            heap_down(p, track, key, cost);
        }
        else if(cmd == 't'){
            heap_free(p);
            return 0;
        }
    }
    return 0;
}