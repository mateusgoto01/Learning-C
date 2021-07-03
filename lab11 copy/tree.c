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

void tree_remove(node* p, tree* t){
    if(p->left == NULL && p->right == NULL){
        node* fat = p->parent; //nó do pai
        if(fat == NULL){// p é a raiz
            t->root = NULL;
            free(p);
        }
        else{
            if(fat->key > p->key)
                fat->left = NULL;
            else
                fat->right = NULL;
            free(p);
        }
    }       
    else if(p->left == NULL){
        node* fat = p->parent; //nó do pai
        node* temp = p->right;
        if(fat == NULL){
            temp->parent = NULL;
            t->root = temp;
            free(p);
            return;
        }
        else{
            temp->parent = p->parent;
            if(fat->key > temp->key)
                fat->left = temp;
            else
                fat->right = temp;
            free(p);
        }     
    }
    else if(p->right == NULL){
        node* fat = p->parent; //nó do pai
        node* temp = p->left;
        if(fat == NULL){
            temp->parent = NULL;
            t->root = temp;
            free(p);
            return;
        }
        else{
            temp->parent = p->parent;
            if(fat->key > temp->key)
                fat->left = temp;
            else
                fat->right = temp;
            free(p);
        }
        
    }
    else if(p->left != NULL && p->right != NULL){
        node* temp = minimum(p->right); // o minimo do lado direito do nó sempre é o sucessor de p
        p->key = temp->key;
        tree_remove(temp, t);
    }
}

void tree_free_node(node* p){
  if(p == NULL)
    return;
  tree_free_node(p->left);
  tree_free_node(p->right);
  free(p);
}