#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct node2 {
  int data; // guarda o dado
  int call; // guarda quantas vezes foi chamado
  struct node2* next;
};

typedef struct node2 node2;


struct aut {
  node2* head; // guarda a cabeça da lista
};

typedef struct aut aut;

/*
  Allocate an empty list of ints.  Return a pointer to the new list or NULL if
  memory allocation fails.
*/
aut* aut_alloc();

/*
    Insert the int number at the head.
*/
int aut_insert(aut* L, int data, int count);

/*
    Insert the int number at a specific position;
*/
int aut_insert_at(aut* L, int data, int at, int count);

/*
    Remove a node in a determinted location
*/
void aut_remove(aut* L, int at);

// help me see
void aut_print(aut* list);
void aut_print_count(aut* list);

/*
    Implement the Move-to-front, when a element is search, this function need to return the value of cost.
    At the end need to swap places between the head and the element.
*/
int aut_MTF(aut* L, int search);

/*
    Implement the transpose permutation. When a element is required, they swap places with the last element before this one. If the element requireded is the first one do nothing.
*/
int aut_transpose(aut* L, int search);

/*
    Implement the count permutation. This function need to count how many time the elemente was required and reorganize the list in a decrease order. If the elemente required is the first one, increases de count and return cost.
*/
int aut_count(aut* L, int search);

/*
  Reorganize the list for the next test.
*/
void aut_redo(aut* L, int n);