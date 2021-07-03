/*
Neste trabalho você deve fazer um programa que mantém uma coleção de contatos de pessoas.
Seu programa deve ser capaz de organizar até 1.000 contatos. Ele deve inserir, remover e recuperar contatos da coleção.

Cada contato tem nome, endereço, telefone e data de aniversário. O nome tem até 50 caracteres, o endereço até 100, o telefone até 12 dígitos e a data de aniversário tem o formato dd/mm/aa.

Cada operação sobre a coleção é especificada por um caractere que indica qual é a operação e é seguido de linhas específicas para a operação.

As operações podem ser:

i para inserção. As quatro linhas seguintes conterão nome, endereço, telefone e data de aniversário. Depois de inserir o contato seu programa deve imprimir uma mensagem como exemplificada abaixo. Se a coleção já tiver 1.000 contatos então esse novo contato não deve ser inserido e o programa deve imprimir
O contato nao foi inserido.
em uma linha e mais uma linha em branco.
r para remoção. A linha seguinte tem um nome. Seu programa deve remover todos os registros que tenham nome exatamente igual ao que foi dado. O programa deve imprimir o número de registros removidos.
b para busca. A linha seguinte tem um nome. Seu programa deve imprimir todos os registros que tenham nome contendo alguma parte que é igual ao nome digitado, um por linha com campos separados por tabulação, na ordem em que foram inseridos. O formato está exemplificado abaixo.
p para impressão. Seu programa deve imprimir todos os registros na coleção, um por linha com campos separados por tabulação, na ordem em que foram inseridos.
f para finalizar o programa.

by Goto

i
Fulano
Rua A, 1 - Centro
11212134512
31/11/31
i
Fulana
Rua B, 2 - Centro
11212134512
01/01/50
i
Fulano
Rua A, 1 - Centro
11212134512
31/11/31
i
Fulana
Rua B, 2 - Centro
11212134512
01/01/50
i
Fulano
Rua A, 1 - Centro
11212134512
31/11/31
i
Fulana
Rua B, 2 - Centro
11212134512
01/01/50
i
Fulano
Rua A, 1 - Centro
11212134512
31/11/31
i
Fulana
Rua B, 2 - Centro
11212134512
01/01/50
i
Fulano
Rua A, 1 - Centro
11212134512
31/11/31
i
Fulana
Rua B, 2 - Centro
11212134512
01/01/50
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[51];
    char address[101];
    char cell[13];
    char birth[9];
}contatos;

void insert(contatos* agenda,int count){
    char data[101]; // irá amazenar os dados
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
    else if(count> 999){
        scanf(" %[^\n]s", data);
        scanf(" %[^\n]s", data);
        scanf(" %[^\n]s", data);
        scanf(" %[^\n]s", data);
        printf("O contato nao foi inserido.\n\n");
    }
    
}

void list_contact(contatos* agenda, int count){
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
 
void search_contact(contatos* agenda, int count){
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

int remove_contact(contatos* agenda,int count){
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
                    //troco de posição
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
    return removed; // garantir que a variavel contadora volte a contar no lugar certo
}

int main(void){
    contatos agenda[1000];
    char in; // entrada dos comandos
    int count = 0;
    
    int decreased; // variavel para armazenar quantas casas o count tem que voltar 
    do {
        scanf("%c", &in);
        if(count > 1000) count = 1000;
        //printf("count %d\n", count);
        if( in == 'i') insert(agenda, count++);
        else if(in == 'r') {
           decreased = remove_contact(agenda, count);
           count -= decreased; 
        }    
        else if(in == 'b') search_contact(agenda, count);
        else if(in == 'p') list_contact(agenda, count);

    }while(in != 'f');
    return 0;
}