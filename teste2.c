#include <stdio.h>
#include <string.h>

struct contatos
{
    char name[51];
    char address[101];
    char cell[13];
    char birth[9];
}agenda[1000];

void insert(int count){
    char data[101]; // irÃ¡ amazenar os dados
    if(count <= 999){
    scanf(" %[^\n]s", data);
    strcpy(agenda[count].name, data);

    scanf(" %[^\n]s", data);
    strcpy(agenda[count].address, data);

    scanf(" %[^\n]s", data);
    strcpy(agenda[count].cell, data);

    scanf(" %[^\n]s", data);
    strcpy(agenda[count].birth, data);

    printf("Contato para %s inserido.\n\n", agenda[count].name);
    }
    else{
        scanf(" %[^\n]s", data);
        scanf(" %[^\n]s", data);
        scanf(" %[^\n]s", data);
        scanf(" %[^\n]s", data);
        printf("O contato nao foi inserido.\n\n");
    }
    
}

void list_contact(int count){
    printf("Listagem:\n");
    int list = 0;
    for(int i = 0; i < count; i++){
        if(agenda[i].name[0] == '\0') continue;
        printf("(%d) %s\t%s\t%s\t%s\n", i+1 ,agenda[i].name, agenda[i].address, agenda[i].cell, agenda[i].birth);
        list = 1;
    }
    if(list == 0) printf("Nenhum contato.\n");
    printf("\n");
}
 
void search_contact(int count){
    char data[51];
    int search = 0;
    scanf(" %[^\n]s", data);

    printf("Resultado da busca:\n");

    for(int i = 0; i < count; i++){
        if( strstr(agenda[i].name, data) != 0) {
            printf("(%d) %s\t%s\t%s\t%s\n", i+1 ,agenda[i].name, agenda[i].address, agenda[i].cell, agenda[i].birth);
            search = 1;
        }    
    }
    if(search == 0) printf("Nenhum contato.\n\n");
    else printf("\n");
}

void remove_contact(int count){
    char data[51];
    int removed = 0;
    scanf(" %[^\n]s", data);
    for(int i = 0; i <= count; i++){
        if( strcmp(agenda[i].name, data) == 0) {
            agenda[i].name[0] = '\0';
            removed += 1;
        }    
    }
    for(int i = 0; i <= count; i++){
        for(int j = i + 1; j <= count; j++){
            //printf("%d %d\n", i, j);
            if(agenda[i].name[0] == '\0'){
                if(agenda[j].name[0] != '\0'){
                    //printf("entrei nesse loop\n");
                    //printf("posicoes que entrei no loop %d %d\n", i, j);
                    //troco de posiÃ§Ã£o
                    strcpy(agenda[i].name, agenda[j].name);
                    strcpy(agenda[i].address, agenda[j].address);
                    strcpy(agenda[i].cell, agenda[j].cell);
                    strcpy(agenda[i].birth, agenda[j].birth);
                    //apago o que restou no outro struct
                    agenda[j].name[0] = '\0';
                    agenda[j].address[0] = '\0';
                    agenda[j].cell[0] = '\0';
                    agenda[j].birth[0] = '\0';
                }
            }
        }
    }
    printf("Contatos de %s removidos: %d.\n\n", data, removed);
}

int main(void){
    char in; // entrada dos comandos
    int count = 0;
    do {
        scanf("%c", &in);

        if( in == 'i') insert(count++);
        else if(in == 'r') remove_contact(count--);
        else if(in == 'b') search_contact(count);
        else if(in == 'p') list_contact(count);

    }while(in != 'f');
    return 0;
}