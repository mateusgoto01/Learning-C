#include "darray.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
//#include <malloc.h>
/*
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
push Mas um dia
inject desses   
push eu vou fugir de casa e
inject  nao
inject bora
inject ultima
inject penultima
inject teste
inject  nao
inject bora
inject ultima
inject penultima
inject teste



pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop
pop

pop
eject
pop
eject

mudar os realloc para malloc mais free
violação de memoria = talvez eu esteja tentando acessar um lugar que não existe
não preciso free nos for de realocamento
teste 6 : 10 inject e 10 eject até ficar vazio 
teste 10: varios push e varios inject depois varios eject e pop
IMPORTANTE: tanto no reduzir como aumentar, vc precisa reorganizar o array para copiar, se não buga
*/

darray* da_alloc(int capacity){
    struct darray *deck = (struct darray *) malloc(capacity);
    //deck->data = (char**) calloc(capacity, sizeof(char*));
    //struct darray *deck;
    deck->data = (char**) calloc(capacity, sizeof(char*));
    //deck->data = (char**) malloc(capacity);
    //("%d\n", sizeof(char *));
    //("%d\n", _msize(deck->data));
        if (!deck) {
        return NULL;
    }
        (deck)->first = -1; // The index of the first element in the sequence.
        (deck)->size = -1;  // The sequence size
        (deck)->capacity = capacity; // The array size.
        (deck)->min_cap = capacity;  // The minimum array size.

    return deck;
}

void da_free(darray* A){
    char* clear;
    while(!da_is_empty(A)){
        clear = da_pop(A);
        free(clear);
    }  
    free(A->data);
    free(A);
    //("finalizacao do programa terminada\n");
}
int da_push(darray* A, char* string){
    //("%d %d\n", A->first, A->size);
    if(da_is_empty(A)){
        A->first = 0;
        A->size = 0;
        A->data[A->size] = strdup(string);
        //("primeira string %s coloca do em %d\n", A->data[A->size], A->size);
        return 1;
    }
    if(A->size == A->capacity-1){
        //("alterando tamanho\n");

        char** RA = (char**) calloc(2*A->capacity, sizeof(char*));

        if(RA != NULL){
            for(int i = A->first; i < A->capacity; i++){
                RA[i - A->first] = A->data[i];
            }
            int place = A->capacity - A->first;
            for(int j = 0; j < A->first; j++){
                RA[j + place] = A->data[j];
            }
            free(A->data);
            A->data = RA;
            A->first = 0;
            A->capacity += A->capacity;
        } 
        else return 0;
    }
    if( A->size < A->capacity){
        A->size += 1;
        int place = A->first + A->size; 
        //("place e %d\n", place);
        if(place > A->capacity - 1){
            place -= A->capacity;       
        }
        A->data[place] = strdup(string);
        //("a string foi alocada %s na posicao %d\n", A->data[place], place);
    }
    return 1;
}
char* da_pop(darray* A){
    int out = (A->capacity)*(0.25) -1;
    //("size e %d aguardando\n", A->size);
    //("Capacity/2 %d e min_cap %d\n", A->capacity/2, A->min_cap);
    if(A->size == out && A->capacity/2 >= A->min_cap)
    {   
        //("entrei nessa condicao god have mercy on me\n");
        int range = A->capacity - A->first;
        //("O range e %d\n", range);
        if(A->first == 0){
            A->capacity = 0.5*A->capacity;
            char** RA= (char**) calloc(A->capacity, sizeof(char*));
            if(A->data != NULL){
            for(int i = 0; i <= A->size; i++){
                RA[i] = A->data[i];
            }
            free(A->data);
            A->data = RA;
            }
            else return 0;
        }
        else{
            for(int i = 0; i < (A->size - range); i++){
                A->data[i + range] = A->data[i];
                //("a posicao inicial %d agora foi para %d\n", i, i +range);
            }
            for(int j = 0; j < range; j++){
                A->data[j] = A->data[A->first + j];
                //("a posicao final %d agora foi para %d\n", A->first + j, j);
            }
            A->capacity = 0.5*A->capacity;
            A->first = 0;
            char** RA= (char**) calloc(A->capacity, sizeof(char*));
            if(A->data != NULL){
            for(int i = 0; i <= A->size; i++){
                RA[i] = A->data[i];
                //("a string %s esta na posicao %d\n", A->data[i], i);
            }
            free(A->data);
            A->data = RA;
            }
            else return 0;
        }
        
    }

    int place = A->first + A->size; 
    //("place %d\n", place);
    if(place > A->capacity-1){
        place -= A->capacity;       
    }
    A->size -= 1;
    if(A->size == -1){
        char* last = A->data[place];
        A->first = -1;
        A->size = -1;
        //("estou retirando a string %s\n", last);
        return last;
    }
    //("estou retirando a string %s na posicao %d\n", A->data[place], place);
    return A->data[place];

}

int da_inject(darray* A, char* string){
    if(da_is_empty(A)){
        A->first = A->capacity -1;
        A->size = 0;
        A->data[A->first] = strdup(string);
        //("primeira string %s coloca do em %d\n", A->data[A->first], A->first);
        return 1;
    }
    if(A->size == A->capacity-1){
        //("alterando tamanho\n");

        char** RA = (char**) calloc(2*A->capacity, sizeof(char*));

        if(RA != NULL){
            for(int i = A->first; i < A->capacity; i++){
                RA[i - A->first] = A->data[i];
            }
            int place = A->capacity - A->first;
            for(int j = 0; j < A->first; j++){
                RA[j + place] = A->data[j];
            }
            free(A->data);
            A->data = RA;
            A->first = 0;
            A->capacity += A->capacity;
        } 
        else return 0;
    }

    A->first -= 1;
    A->size += 1;
    if(A->first < 0) A->first = A->capacity -1;
    A->data[A->first] = strdup(string);
    //("A string %s foi alocada na posicao %d\n",A->data[A->first], A->first);
    return 1;
}

char* da_eject(darray* A){
    int out = (A->capacity)*(0.25)-1;
    if(A->size == out && A->capacity/2 >= A->min_cap)
    {   
        //("entrei nessa condicao god have mercy on me\n");
        int range = A->capacity - A->first;
        //("O range e %d\n", range);
        if(A->first == 0){
            A->capacity = 0.5*A->capacity;
            char** RA= (char**) calloc(A->capacity, sizeof(char*));
            if(A->data != NULL){
            for(int i = 0; i <= A->size; i++){
                RA[i] = A->data[i];
            }
            free(A->data);
            A->data = RA;
            }
            else return 0;
        }
        else{
            for(int i = 0; i < (A->size - range); i++){
                A->data[i + range] = A->data[i];
                //("a posicao inicial %d agora foi para %d\n", i, i +range);
            }
            for(int j = 0; j < range; j++){
                A->data[j] = A->data[A->first + j];
                //("a posicao final %d agora foi para %d\n", A->first + j, j);
            }
            A->capacity = 0.5*A->capacity;
            A->first = 0;
            char** RA= (char**) calloc(A->capacity, sizeof(char*));
            if(A->data != NULL){
            for(int i = 0; i <= A->size; i++){
                RA[i] = A->data[i];
                //("a string %s esta na posicao %d\n", A->data[i], i);
                //("a string %s está na posição %d", RA[i], i);
            }
            free(A->data);
            A->data = RA;
            }
            else return 0;
        }
        
    }
    if(A->first > A->capacity-1) A->first -= A->capacity;
    A->size -= 1;
    A->first += 1;
    if(A->size == -1){
        char* last = A->data[A->first-1];
        A->first = -1;
        A->size = -1;
        //("estou retirando a string %s\n", last);
        return last;
    }
    //("first e %d\n", A->first);
    //("size e %d", A->size);
    
    //("estou retirando a string %s na posicao %d\n", A->data[A->first-1], A->first-1);
    return A->data[A->first-1];

}
char* da_first(darray* A){
    char* first = A->data[A->first];
    //("posição %d\n",A->data[A->first]);
    return first;
}
char* da_last(darray* A){
    char* last;
    int place = A->size + A->first;
    //("place %d e capacity e %d\n", place, A->capacity);
    if(place > A->capacity -1) place -= A->capacity;
    //("place %d\n", place);
    last = A->data[place];
    return last;
}

int da_is_empty(darray* A){
    //("%d e %d\n",A->size==-1, A->first == -1);
    if(A->size == -1 && A->first == -1) return 1;
    else return 0;
}
