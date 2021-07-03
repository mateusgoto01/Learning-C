#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "heap.h"

heap* heap_creat(int cap){
    heap* min_heap = calloc(1, sizeof(heap));
    min_heap->item = calloc(cap, sizeof(item*));
    for(int i = 0; i < cap; i++){
        min_heap->item[i]->key = -1;
    }
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
    if(heap_search(key, p, track) == -2){
        if( p->size == p->capacity)
            return;
        else{
            //printf("fui inserido\n");
            p->size++;
            p->item[p->size-1]->key = key;
            p->item[p->size-1]->cost = cost;
            track[p->size-1] = key;
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
        if(p->item[parent]->cost> p->item[index]->cost){
            //printf("fui trocado\n");
            heap_swap(p, parent, index, track);
            heapfy_up(p, parent, track);
        }
        else
            return;
    }
}
void heapfy_bottom(heap* p, int index, int track[]){
    if(index > p->capacity)
        return;
    else{
        int left = heap_left(index);
        int right = heap_right(index);
        int small;
        if(p->item[left]->key == -1 && p->item[right]->key == -1)
            return;
        else if(p->item[left]->key == -1)
            small = right;
        else if(p->item[right]->key == -1)
            small = left;
        else{
            if(p->item[left]->cost <= p->item[right]->cost)
                small = left;
            else
                small = right;
        }
        if(small < p->size && p->item[small]->cost < p->item[index]->cost){
            //printf("trocando %d por %d\n", p->item[index]->cost, p->cost[small]);
            heap_swap(p, small, index, track);
            heapfy_bottom(p, small, track);
        }
        else
            return;     
    }
}

void heap_remove(heap* p, int track[]){
    if(p->item[0]->key == -1)
        printf("heap vazio\n");
    else{
        printf("minimo {%d,%d}\n", p->item[0]->key, p->item[0]->cost);
    p->item[0]->key = p->item[p->size-1]->key;
    p->item[0]->cost = p->item[p->size-1]->cost;

    p->item[p->size-1]->key = -1;
    //p->cost[p->size-1] = -1;
    p->size--;
    heapfy_bottom(p, 0, track);
    }
   
}

void heap_swap(heap* p, int parent, int index,int track[]){
    int temp1 = p->item[parent]->key;
    int temp2 = p->item[parent]->cost;

    p->item[parent]->key = p->item[index]->key;
    track[parent] = p->item[index]->key;
    p->item[parent]->cost = p->item[index]->cost;

    p->item[index]->key = temp1;
    track[index] = temp1;
    p->item[index]->cost = temp2;

}

int heap_search(int key, heap*p, int track[]){
    for(int i = 0; i< p->size; i++){
        if(track[i] == key)
            return i;
    }
    return -2;
}

void heap_down(heap* p, int track[], int key, int cost){
    int search = heap_search(key, p, track);
    if(search == -2)
        return;
    else{
        //printf("a chave %d esta em %d\n",p->key[search], search);
        p->item[search]->cost = cost;
        heapfy_up(p, search, track);
    }
}

void heap_free(heap* p){
    
    free(p->item);
    free(p);
}