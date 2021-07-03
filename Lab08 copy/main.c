
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "darray.h"

int main(void) {
  char* del;
  char in[50] = "Eu odeio esse lab";
  darray* D = da_alloc(64);
  if(da_is_empty(D)){
    printf("-yes\n");
  }
  else printf("-nope\n");

  da_push(D, in); 
  char in2[50] = "Serio mesmo";
  da_push(D, in2);
  char in3[50] = "Namoral qual a necessidade?";
  da_push(D, in3);
  char in4[50] = "To com fome e com dor";
  da_push(D, in4);
  char in5[50] = "E esse lab me ajuda a esquecer disso pela raiva";
  da_push(D, in5);
  char in6[50] = "prologo";
  da_inject(D, in6);
  char in7[50] = "O que nao faco para ter dentes bons";
  da_push(D, in7);

  for(int i = D->first; i < D->size; i++){
    printf("Conferindo deck: data %s %d\n", (D+i)->data, i);
  }
  del = da_pop(D);
  free(del);
  del = da_eject(D);
  free(del);

  printf("\na primeira frase e %s\n", da_first(D));
  printf("\na ultima frase e %s\n", da_last(D));

  da_free(D);
  return 0;
}