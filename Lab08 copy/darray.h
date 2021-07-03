/**
  darray.h
  Declarations for a sequence of strings stored in an array that swells and
  shrinks by a factor of 2 as needed.
**/


#ifndef DARRAY_H
#define DARRAY_H


typedef struct darray {

  char** data; // The array of pointers to char, that is, the array of string.

  int first; // The index of the first element in the sequence.
  int size;  // The sequence size.

  int capacity; // The array size.
  int min_cap;  // The minimum array size.

} darray;



/**
   Allocate a darray and the array of pointers to strings with
   initial capacity.  Set the initial state of the darray properly.

   capacity is the initial array size.  It is also the minimum array size.

   It returns the address of a new darray.  On failure it returns NULL.
**/
darray* da_alloc(int capacity);
void insert_string(darray* deck);
void da_free(darray* A);
int da_push(darray* A, char* string);
char* da_pop(darray* A);
int da_inject(darray* A, char* string);
char* da_eject(darray* A);
char* da_first(darray* A);
char* da_last(darray* A);
int da_is_empty(darray* A);
#endif