#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "org.h"


aut* aut_alloc(){
    return calloc(1,sizeof(aut));
}

int aut_insert(aut* L, int data, int count) {

  node2* n = malloc(sizeof(node2));
  if (n == NULL)
    return 0;

  n->data = data;
  n->call = count;
  n->next = L->head;
  L->head = n;

  return 1;
}

int aut_insert_at(aut* L, int data, int at, int count){
    node2* n = malloc(sizeof(node2));
    if (n == NULL)
    return 0;

    node2* p = L->head;
    if(at == 1) 
        return aut_insert(L, data, count);

    for(int i = 0; i < at-2; i ++) 
        p = p->next;

    n->data = data;
    n->call = count;
    n->next = p->next;
    p->next = n;

    return 1;
}

void aut_remove(aut* L, int at){
    node2* p = L->head;
    for(int i = 0; i < at-1; i ++) p = p->next;
    node2* r = p->next;
    p->next = r->next;

}

void aut_print(aut* list){
    node2* p = list->head;
    printf("(");
    
    while (p != NULL &&  p->next != NULL) {
        printf("%d, ",p->data);
        p = p->next;
    }
    if (p != NULL) printf("%d",p->data);
    printf(")");
}

void aut_print_count(aut* list){
    node2* p = list->head;
        printf("(");
    while (p != NULL &&  p->next != NULL) {
        printf("%d, ",p->call);
        p = p->next;
    }
    if (p != NULL) printf("%d",p->call);
    printf(")");
}
int aut_MTF(aut* L, int search){
    int cost = 0;
    for(node2* p = L->head; p != NULL; p = p->next){
        cost++;
        if(p->data == search){
            aut_insert(L, p->data, 0);
            aut_remove(L, cost);
            return cost;
        }
    }
    return 0;
}

int aut_transpose(aut* L, int search){
    int cost = 0;

    for(node2* p = L->head; p != NULL; p = p->next){
        cost++;
        if(p->data == search){
            if(cost == 1) return cost;
            int check = aut_insert_at(L, search, cost-1, 0);
                if(check == 0) exit(errno);
            aut_remove(L, cost);
            return cost;
        }
    }
    return 0;
}

int aut_count(aut* L, int search){
    int cost = 0;
    int posi = 0; // guarda posicao
    for(node2* p = L->head; p != NULL; p = p->next){
        cost++;
        if(p->data == search){
            p->call++;
            if(cost == 1){
                return cost;
            }
            else {
                for(node2* q = L->head; q != NULL; q = q->next){
                    posi++;
                    if(p->call >= q->call){
                        int check = aut_insert_at(L, search, posi, p->call);
                        if(check == 0) exit(errno);
                        aut_remove(L, cost);
                        return cost;  
                    }
                }
            }
        }
    }
    return 0;
}

void aut_redo(aut* L, int n){
    node2* p = L->head;

    for(int i = 1; i <= n; i++){
        p->data = i;
        p = p->next;
    }
}