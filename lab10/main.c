#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "org.h"

int main(void){
    int n = 0;
    int r = 0;

    int cost = 0;
    int total = 0;
    aut* list = aut_alloc();
    if (list == NULL)
        exit(errno);
    // descobre qual é a sequencia da lista inicial
    scanf(" %d", &n);
    for(int i = n; i >= 1; i--){
        int check = aut_insert(list, i, 0);
        if(check == 0) exit(errno);
    }
    scanf(" %d", &r);
    int R[r];
    for(int i = 0; i < r; i++){
        scanf("%d", &R[i]);
    }
    for(int i = 0; i < r; i++){
        cost = aut_MTF(list, R[i]);
        total += cost;
        printf("search: %d, cost: %d -- ", R[i], cost);
        aut_print(list);
        printf("\n");
    }
    //libero a lista criada e a remonto novamente para que eu consiga efetuar a proxima testagem
    aut_redo(list, n);

    printf("MTF: %d\n", total);
    total = 0;

    for(int i = 0; i < r; i++){
        cost = aut_transpose(list, R[i]);
        total += cost;
        /*printf("search: %d, cost: %d -- ", R[i], cost);
        aut_print(list);
        printf("\n");*/
    }
    printf("Transpose: %d\n", total);

    total = 0;
    aut_redo(list, n);
    for(int i = 0; i < r; i++){
        cost = aut_count(list, R[i]);
        total += cost;
        /*printf("search: %d, cost: %d -- ", R[i], cost);
        aut_print(list);
        aut_print_count(list);
        printf("\n");*/
    }
    printf("Count: %d\n", total);
    free(list);
    return 0;
}