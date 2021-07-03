#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "li.h"


li* li_alloc() {
  return calloc(1,sizeof(li));
}



void li_free(li* L) {

  node* p = L->head;
  node* n = NULL;

  while (p != NULL) {
    n = p->next;
    free(p);
    p = n;
  }

  free(L);
}



int li_insert(li* L, int data) {

  node* n = malloc(sizeof(node));
  if (n == NULL)
    return 0;

  n->data = data;
  n->next = L->head;
  L->head = n;

  return 1;
}



void li_print(li* L) {

  node* p = L->head;
  printf("{");

  while (p != NULL && p->next != NULL) {
    printf("%d, ",p->data);
    p = p->next;
  }

  if (p != NULL) printf("%d",p->data);

  printf("}");
}

li* li_union(li* A, li* B){
  li* uni = li_alloc(); //criando a lista da união

  int i = 0;
  for (node* p = B->head; p != NULL; p = p->next) {
    for (node* q = A->head; q != NULL; q = q->next){
      if(p->data == q->data){
        i++;
      }
    }
    if(i == 0) li_insert(uni, p->data);
    else i = 0;
  }
  for (node* p = A->head; p != NULL; p = p->next) {
    for (node* q = B->head; q != NULL; q = q->next){
      if(p->data == q->data){
        i++;
      }
    }
    if(i == 0) li_insert(uni, p->data);
    else i = 0;
  }
  for (node* p = A->head; p != NULL; p = p->next) {
    for (node* q = B->head; q != NULL; q = q->next){
      if(p->data == q->data){
        li_insert(uni, q->data);
      }
    }
  }
  return uni;
}

li* li_intersection(li* A, li* B){
  li* inter = li_alloc(); //criando a lista da união
  for (node* p = A->head; p != NULL; p = p->next) {
    for (node* q = B->head; q != NULL; q = q->next){
      if(p->data == q->data){
        li_insert(inter, q->data);
      }
    }
  }
  return inter;
}
li* li_difference(li* A, li* B){
  li* diff = li_alloc(); //criando a lista da união
  int i = 0;
  for (node* p = A->head; p != NULL; p = p->next) {
    for (node* q = B->head; q != NULL; q = q->next){
      if(p->data == q->data){
        i++;
      }
    }
    if(i == 0) li_insert(diff, p->data);
    else i = 0;
  }
  return diff;
}

