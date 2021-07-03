#include "darray.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
//#include <malloc.h>

darray* da_alloc(int capacity){
    struct darray *deck = (struct darray *) malloc(capacity);
    //deck->data = (char**) calloc(capacity, sizeof(char*));
    //struct darray *deck;
    deck->data = (char**) calloc(capacity, sizeof(char*));
    //deck->data = (char**) malloc(capacity);
    //printf("%d\n", sizeof(char *));
    //printf("%d\n", _msize(deck->data));
        if (!deck) {
        return NULL;
    }
        (deck)->first = 0; // The index of the first element in the sequence.
        (deck)->size = 0;  // The sequence size
        (deck)->capacity = capacity; // The array size.
        (deck)->min_cap = capacity;  // The minimum array size.

    return deck;
}

void da_free(darray* A){
    char* x;
    char* y; 
    while(!da_is_empty){
        x = da_pop(A);
        y = da_eject(A);
        free(x);
        free(y);
    }
    free(A->data);
    free(A);
}
int da_push(darray* A, char* string){

    if(A->size - A->first == A->capacity-1){
        //printf("alterando tamanho\n");
        A->capacity += A->capacity;
        A->data = (char**) realloc(A->data, A->capacity* sizeof(char*));
        if(A == NULL) {
            return 0;
       }
    }

    //printf("Conferindo deck: size %d e first %d \n", A->size, A->first);
        A->data[A->size] = strdup(string);
        //printf("a string foi alocada %s\n", A->data[A->size]);
        A->size += 1;

    return 1;
}
char* da_pop(darray* A){
    int out = (A->capacity)*(0.25);
    if(A->size - A->first == out && A->capacity/2 > A->min_cap + (A->min_cap/2))
    {
        A->capacity = 0.5*A->capacity;
        A->data = (char**) realloc(A->data, A->capacity* sizeof(char*));
        if(A != NULL) {
        }
        else return NULL;
    }

    A->size -= 1;
    printf("size e %d", A->data[A->size]);
    return A->data[A->size];

}

int da_inject(darray* A, char* string){
    if(A->size - A->first == A->capacity-1){
        printf("alterando tamanho quando cheguei na posição %d\n", A->first);
        A->capacity += A->capacity;
       A->data = (char**) realloc(A->data, A->capacity* sizeof(char*));
       if(A == NULL) {
           return 0;
       }
    }
    if(A->size - A->first <  A->capacity){
        A->first -= 1;
        A->data[A->first] = strdup(string);
        printf("A string foi alocada na posição %d\n", A->first);
    }
     return 1;
}

char* da_eject(darray* A){
    int out = (A->capacity)*(0.25);
    if(da_is_empty(A)) return NULL;
    else if(A->size - A->first == out && A->capacity/2 > A->min_cap + (A->min_cap/2))
    {
        A->capacity = 0.5*A->capacity;
        A->data = (char**) realloc(A->data, A->capacity* sizeof(char*));
        if(A == NULL) {
           return NULL;
        }
    }
    A->first += 1;
    return A->data[A->first - 1];

}
char* da_first(darray* A){
    char* first = A->data[A->first];
    printf("posição %d\n",A->data[A->first]);
    return first;
}
char* da_last(darray* A){
    char* last;
    last = A->data[+A->size-1];
    printf("posição %d\n",A->data[+A->size-1]);
    return last;
}

int da_is_empty(darray* A){
    //printf("%d e %d\n",A->size, A->first == 0);
    if(A->size - A->first == 0) return 1;
    else return 0;
}
