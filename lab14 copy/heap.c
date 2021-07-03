#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "heap.h"

heap* heap_creat(int cap){
    heap* min_heap = calloc(1, sizeof(heap));
    min_heap->cost = calloc(cap, sizeof(int));
    min_heap->key = calloc(cap, sizeof(int));
    min_heap->size = 0;
    min_heap->capacity = cap;

    return min_heap;
}

int heap_left(int index){
    return 2*index + 1;
}

int heap_right(int index){
    return 2*index + 2;
}

int heap_parent(int index){
    return (index - 1) / 2;
}

void heap_insert(heap* p, int key, int cost, int track[]){
    if(heap_search(key, track) ==-1){
        if( p->size == p->capacity)
            return;
        else{
            //printf("fui inserido\n");
            p->size++;
            p->key[p->size-1] = key;
            p->cost[p->size-1] = cost;
            track[key] = p->size-1;
            //printf("rank = %d e chave %d\n", p->size -1, key);
            //printf("valor = %d\n", track[key]);
            heapfy_up(p, p->size-1, track);
        }
    }
    else
        return;  
}

void heapfy_up(heap* p, int index, int track[]){
    if(index == 0)
        return;
    else{
        int parent = heap_parent(index);
        //printf("parente = %d\n", parent);
        if(p->cost[parent] > p->cost[index]){
            //printf("fui trocado\n");
            heap_swap(p, parent, index, track);
            heapfy_up(p, parent, track);
        }
        else
            return;
    }
}
void heapfy_bottom(heap* p, int index, int track[]){
    if(index > p->size)
        return;
    else{
        int left = heap_left(index);
        int right = heap_right(index);
        int small;
        if(p->key[left] == -1 && p->key[right]== -1)
            return;
        else if(p->key[left] == -1)
            small = right;
        else if(p->key[right] == -1)
            small = left;

        else if(p->cost[left] <= p->cost[right])
            small = left;
        else if(p->cost[right] < p->cost[left])
            small = right;


        if(small < p->size && p->cost[small] < p->cost[index]){
            //printf("trocando %d por %d\n", p->cost[index], p->cost[small]);
            heap_swap(p, small, index, track);
            heapfy_bottom(p, small, track);
        }
        else
            return;     
    }
}

void heap_remove(heap* p, int track[]){
    if(heap_search(p->key[0], track) == -1 || p->key[0] == -1 )
        printf("heap vazio\n");
    else{
        printf("minimo {%d,%d}\n", p->key[0], p->cost[0]);
        //printf("key subida e %d\n", p->key[p->size-1]);
    track[p->key[0]] = -1;
    p->key[0] = p->key[p->size-1];
    p->cost[0] = p->cost[p->size-1];
    p->key[p->size-1] = -1;
    
    p->size--;
    heapfy_bottom(p, 0, track);
    }
   
}

void heap_swap(heap* p, int parent, int index,int track[]){
    int temp1 = p->key[parent];
    int temp2 = p->cost[parent];

    p->key[parent] = p->key[index];
    track[p->key[index]] = parent;
    p->cost[parent] = p->cost[index];

    p->key[index] = temp1;
    track[temp1] = index;
    p->cost[index] = temp2;

}

int heap_search(int key, int track[]){
    int search = track[key];
    //printf("search = %d\n", search);
    return search;
}

void heap_down(heap* p, int track[], int key, int cost){
    int search = heap_search(key, track);
    //printf("search = %d\n", search);
    if(search == -2)
        return;
    else{
        //printf("a chave %d esta em %d\n",p->key[search], search);
        p->cost[search] = cost;
        heapfy_up(p, search, track);
    }
}

void heap_free(heap* p){
    
    free(p->cost);
    free(p->key);
    free(p);
}