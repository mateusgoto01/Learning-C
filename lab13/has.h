#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

struct node {
  char str[251]; // guarda o dado
  int timestamp; // guarda quantas vezes foi chamado
  struct node* next;
};

typedef struct node node;

struct hash{
    node** head;
};

typedef struct hash hash;

hash* hash_creat();
//função para transformar cadeias de caracteres em inteiros com um bom espaçamento
unsigned long djb2(unsigned char *str);


//funções de hash, como é resolvido colisão pro incremento de hashing duplo, precisamos de duas funções
unsigned long h1(unsigned long key);
unsigned long h2(unsigned long key);

// função de inserção usando incrimento por hashing duplo, a inserção é feita de forma padrão para uma lista encadeada
void hash_insert(hash* table, char* data, int count, int timestamp2);

//Função de busca
node* hash_search(hash* table, char* data, int count);

//Função de remover: Preciso achar a key onde esta o item que quero remover. Eu não o removo, eu só troco o timestamp para -1, assim evitando que a função de busca pare. E para isso preciso modificar a função de inserição para que se ele encontrar um ponto não nulo e com timestamp -1, ele pode inserir no local
void hash_remove(hash* table, char* data, int count);

// Press f to pay respect. Função de finalização do programa, preciso dar free em todos os nós de lista, a lista e a tabela que contem essas listas
void hash_free(hash* table);