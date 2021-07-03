#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "tree.h"
/*
criar
inserir 30
inserir 50
inserir 40
inserir 10
inserir 20
caminho-mais-longo
*/
tree* tree_creat(){
    return calloc(1, sizeof(tree));
}

int tree_insert(tree* t, int data){
  if(tree_search(t->root, data) != NULL){
      return 1;
  }
    
  node* knot = calloc(1,sizeof(node));

  if (!knot)
    return 0;

  knot->key = data;


  node* p = t->root; // filho
  node* pp = NULL; // pai

  while (p != NULL) {
    pp = p; // 
    if (p->key > data)
      p = p->left;
    else
      p = p->right;
  }
  if (t->root == NULL) {
    t->root = knot;
    return 1;
  }
  if (pp->key > data){
      pp->left = knot;
      pp->left->parent = pp;
  }
  else{
      pp->right = knot;
      pp->right->parent = pp;
  }   
  return 1;
}

node* tree_search(node* p, int key){
    if(p == NULL)
        return NULL;
    if(p->key == key)
        return p;
    if(p->key < key)
        return tree_search(p->right, key);
    else
        return tree_search(p->left, key);
}

int tree_pre_ordem(node* p){
    if(p == NULL)
        return 0;
    else{
        printf("%d ", p->key);
        tree_pre_ordem(p->left);
        tree_pre_ordem(p->right);
        return 1;
    }
    return 1;
}

int tree_em_ordem(node* p){
    if(p == NULL)
        return 0;
    else{
        tree_em_ordem(p->left);
        printf("%d ", p->key);
        tree_em_ordem(p->right);
        return 1;
    }
    return 1;
}

int tree_pos_ordem(node* p){
    if(p == NULL)
        return 0;
    else if(p != NULL){ 
        tree_pos_ordem(p->left);
        tree_pos_ordem(p->right);
        printf("%d ", p->key);
        return 1;
    }
    return 1;
}
// o menor numero de uma arvore binario esta presente no ultimo filho a esquerda
node* minimum(node* p){
    if(p == NULL)
        return 0;

    while(p->left != NULL){
        p = p->left;
    }
    return p;
}

node* maximum(node* p){
    if(p == NULL)
        return 0;

    while(p->right != NULL){
        p = p->right;
    }
    return p;

}

node* tree_sucessor(int data, node* t){
    if(t == NULL)
        return NULL;
    node* knot = tree_search(t, data);
    if(knot == NULL){
        return NULL;
    }
    if(knot->right != NULL)
        return minimum(knot->right);
    
    node* suc = knot->parent;
    
    while(suc != NULL && knot == suc->right){
        knot = suc;
        suc = suc->parent;     
    }
    return suc;
}
node* tree_predecessor(int data, node* t){
    if(t == NULL)
        return NULL;
    node* knot = tree_search(t, data);
    if(knot == NULL){
        return NULL;
    }
    if(knot->left != NULL)
        return maximum(knot->left);

    node* pre = knot->parent;
    
    while(pre != NULL && knot == pre->left){
        knot = pre;
        pre = pre->parent;     
    }
    return pre;
}

void tree_replace(tree* t, node* u, node* v){
    if(u->parent == NULL)
        t->root = v;
    else if( u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if( v != NULL)
        v->parent = u->parent;
}


void tree_remove(tree* t, node* z){
    if(z->left == NULL){
        tree_replace(t, z, z->right);
        free(z);
    }
    else if (z->right == NULL){
        tree_replace(t, z, z->left);
        free(z);
    } 
    else{
        node* y = minimum(z->right);
        if(y->parent != z){
            tree_replace(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;  
        }
        tree_replace(t, z, y);
        y->left = z->left;
        y->left->parent = y;
        free(z);
    }

}

void tree_free_node(node* p){
  if(p == NULL)
    return;
  tree_free_node(p->left);
  tree_free_node(p->right);
  free(p);
}

int tree_count_nodes(node* p){
    if(p == NULL)
        return 0;
    return (1 + tree_count_nodes(p->left) + tree_count_nodes(p->right));
}

int tree_count_leafs(node* p){

    if(p == NULL)
        return 0;
    else if(p->left == NULL && p->right == NULL)
        return 1;
    return tree_count_leafs(p->left) + tree_count_leafs(p->right);
}

int tree_avl_check(node* p){
            if(p == NULL){
                return 1;
            }
            int height_left = tree_height(p->left); // tamanho da subarovre da raiz esquerda
            int height_right = tree_height(p->right); // tamanho da subarovre da raiz direita
            
            int check = height_left - height_right;
            if(check < 0)
                check = -check;
            //printf("lado esq %d lado direito %d\n", height_left, height_right);
            if(check <= 1 && tree_avl_check(p->left) && tree_avl_check(p->right)){
                return 1;
            }
            return 0;
            
}
int max(int a, int b){
    return (a>=b) ? a : b;
}
int tree_height(node* p){
    if(p == NULL)
        return 0; // se a arvore for vazia retorne 0
    return 1 + max(tree_height(p->left), tree_height(p->right));
        
}
// nota para mim : tente por largura, talvez dê
/*
criar
inserir 30
inserir 50
inserir 40
inserir 10
inserir 20
caminho-mais-longo
*/

void tree_long(node* p){
    if(p == NULL)
        return;
    printf("%d ", p->key);
    int height_left = tree_height(p->left); // tamanho da subarovre da raiz esquerda
    int height_right = tree_height(p->right); // tamanho da subarovre da raiz direita
    
    if(height_right >= height_left){
            tree_long(p->right);
    }
    else{       
            tree_long(p->left);
    }
    return;
}