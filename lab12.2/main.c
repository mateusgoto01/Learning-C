#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct node {

  char key;

  struct node* left;
  struct node* right;
};

typedef struct node node;

struct tree {

  node* root;
};

typedef struct tree tree;

node* tree_insert(char key){
    node* new_node = calloc(1, sizeof(node));
    new_node->key = key;
    return new_node;
}

int find_in(char in[], char data, int start, int end){
  for(int i= start; i <= end; i++){
      if(in[i] == data)
        return (i);
    }
}

node* tree_reconstruct(char pre[], char in[], int start, int end){
    node* t = calloc(1, sizeof(node));
    printf("start = %d e end = %d\n", start, end);
    static int aux = 0;
    if(start > end)
      return;
    t = tree_insert(pre[aux++]);
    //printf("pre start = %c\n", pre[start]);
    printf("valor de t = %c\n", t->key);
    
    int index = find_in(in, t->key, start, end);
    printf("index = %d\n", index);
    printf("arvore esquerda \n");
    t->left = tree_reconstruct(pre, in, start, index-1);
    printf("arvore direita \n");
    t->right = tree_reconstruct(pre, in, index+1, end);
    return t;
}


void tree_pos_ordem(node* p){
    if(p == NULL)
        return printf("arvore vazia\n");

    tree_pos_ordem(p->left);
    tree_pos_ordem(p->right);
    printf("%c", p->key);
}
// abdghceif bgdhaeicf
int main(void){
  char pre[63];
  char in[63];

  scanf(" %s %s", pre, in);
  int len = strlen(pre);
  printf("len %d\n", len);
  tree* t = calloc(1, sizeof(tree));
  t->root = tree_reconstruct( pre, in, 0, len-1);
  printf("consegui montar a arvore\n");
  tree_pos_ordem(t->root);
  printf("consegui printar\n");

  return 0;
}