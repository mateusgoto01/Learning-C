#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

//struct dos nos
struct node {

  int key;

  struct node* left;
  struct node* right;
  struct node* parent;

};

typedef struct node node;

//struct da raiz da arvore
struct tree {

  node* root;
};

typedef struct tree tree;


tree* tree_creat();

//Função de inserção para a arvore binaria
int tree_insert(tree* t, int data);

//Função de busca na arvore binaria
node* tree_search(node* p, int key);
//Funções de busca na arvore binaria em profundidade
int tree_pre_ordem(node* p);
int tree_em_ordem(node* p);
int tree_pos_ordem(node* p);

//funções auxilares para sucessor e predecessor. Acha o maximo e minimo de uma arvore
node* minimum(node* p);
node* maximum(node* p);

//Funções que acha o sucessor ou predecessor de um nó. Se não tiverem, imprima que não possuem.
node* tree_sucessor(int data, node* t);
node* tree_predecessor(int data, node* t);

//Função remoção. Caso simples quando o nó não tem nenhum filho, para quanto tem um filho e para quando tem dois filhos.
void tree_remove(node* p, tree* t);

//Função de desfazer os nós
void tree_free_node(node* p);

//Funções para descobrir nó, folhas e altura
int tree_count_nodes(node* p);

int tree_count_leafs(node* p);

int tree_avl_check(node* p);

int tree_height(node* p);

//Função que procura o caminho mais longo entre a raiz e uma folha


// irei fazer o percurso em largura, porém só quero gravar o ultimo nó que é o nó que dara o caminho mais longo
void tree_long(node* p);