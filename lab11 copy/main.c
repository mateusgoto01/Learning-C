#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "tree.h"

int main(void){

    char cmd[13];
    int data;
    tree* t = NULL;
    int check = 0;
    while(1){ 
        scanf(" %s", cmd);
        if(strcmp(cmd, "criar") == 0){
            if(check == 0){
                t = tree_creat();
                check = 1;
            }       
            else{
                if(t->root != NULL){
                    tree_free_node(t->root);
                    free(t);
                    t = tree_creat();
                }
            }     
        }
        else if(strcmp(cmd, "inserir") == 0){
            scanf(" %d", &data);

            int check2 = tree_insert(t, data);
            if(check2 == 0)
                printf("memoria insuficiente\n");
        }
        else if(strcmp(cmd, "buscar") == 0){
            scanf(" %d", &data);
            node* search = tree_search(t->root, data);
            if(search == NULL){
                printf("%d nao esta na arvore\n", data);
            }
            else printf("%d esta na arvore\n", search->key);
        }
        else if(strcmp(cmd, "pre-ordem") == 0){
            if(t->root == NULL)
                printf("arvore vazia\n");
            else{
                printf("pre-ordem: ");
                tree_pre_ordem(t->root);
                printf("\n");
            }
        }
        else if(strcmp(cmd, "em-ordem") == 0){
            if(t->root == NULL)
                printf("arvore vazia\n");
            else{
                printf("em-ordem: ");
                tree_em_ordem(t->root);
                printf("\n");
            }
        }
        else if(strcmp(cmd, "pos-ordem") == 0){
            if(t->root == NULL)
                printf("arvore vazia\n");
            else{
                printf("pos-ordem: ");
                tree_pos_ordem(t->root);
                printf("\n");
            }
        }
        else if(strcmp(cmd, "sucessor") == 0){
            scanf(" %d", &data);
            node* suc = tree_sucessor(data, t->root);
            if(suc == NULL)
                printf("nao ha sucessor de %d\n", data);
            else
                printf("sucessor de %d: %d\n", data, suc->key);
        }
        else if(strcmp(cmd, "predecessor") == 0){
            scanf(" %d", &data);
            node* pre = tree_predecessor(data, t->root);
            if(pre == NULL)
                printf("nao ha predecessor de %d\n", data);
            else
                printf("predecessor de %d: %d\n", data, pre->key);
        }
        else if(strcmp(cmd, "remover") == 0){
            scanf(" %d", &data);
            node* remove = tree_search(t->root, data);
            if(remove != NULL){
                tree_remove(remove, t);
            }
            
        }
        else if(strcmp(cmd, "terminar") == 0){
            if(check == 1){
                tree_free_node(t->root);
                free(t);
            }
           else free(t);
           return 0;
        }

    }
    
    return 0;
}