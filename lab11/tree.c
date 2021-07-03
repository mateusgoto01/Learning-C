#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "tree.h"

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

node* tree_remove(int data, node* t){
    if(t == NULL)
        return t;

    if (data < t->key)
        t->left = tree_remove(data, t->left);
    else if (data> t->key)
        t->right = tree_remove(data, t->right);
    else{
        // se não tiver nenhum filho
        if(t->left == NULL && t->right == NULL){

            free(t);
            return NULL;
        }
        // se tiver um filho
        else if(t->left == NULL){
            node* temp = t;
            t = t->right;
            t->parent = temp->parent;
            //printf("o pai é nulo logo raiz %d\n", temp->parent == NULL);
            //printf("1removi %d\n", temp->key);
            free(temp);
        }
        else if(t->right == NULL){
            node* temp = t;
            t = t->left;
            t->parent = temp->parent;
            //printf("o pai é nulo logo raiz %d\n", temp->parent == NULL);
            //printf("2removi %d\n", temp->key);
            free(temp);
        }
        // se tiver dois filhos
        else {
            node* temp = minimum(t->right);
            t->key = temp->key;
            t->right = tree_remove(temp->key, t->right);
        }
    }
    return t;
    
}

void tree_free_node(node* p){
  if(p == NULL)
    return;
  tree_free_node(p->left);
  tree_free_node(p->right);
  free(p);
}