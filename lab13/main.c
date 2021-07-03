#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
// n 41
// chave reservada -1 para timestamp

#include "has.h"

int main(void){
    char cmd;
    char str[251];
    int timestamp = 0;
    hash* table = hash_creat();

    while(1){
        scanf(" %c", &cmd);
        if(cmd == 'i'){
            scanf("%[^\n]s", str);
            strcpy(str, str + 1 ); //remove o blank entre "i" e a "string"
            //printf("[%s]\n", str);
            node* check = hash_search(table, str, 0);
            if(check != NULL){
                printf("[%s] ja esta na tabela\n", str);
            }
            else{
                hash_insert(table, str, 0, timestamp);
                printf("[%s] foi inserida\n", str);
                timestamp++;
            }
        }
        if(cmd == 'b'){
            scanf("%[^\n]s", str);
            strcpy(str, str + 1 ); //remove o blank entre "i" e a "string"
            node* search = hash_search(table, str, 0);
            if(search == NULL)
                printf("[%s] nao esta na tabela\n", str);
            else
                printf("[%s] esta na tabela, timestamp %d\n", search->str, search->timestamp);
        }
        if(cmd == 'r'){
            scanf("%[^\n]s", str);
            strcpy(str, str + 1 ); //remove o blank entre "i" e a "string"
            hash_remove(table, str, 0);
        }
        if(cmd == 'f'){
            hash_free(table);
            return 0;
        }
    } 

    return 0;
}