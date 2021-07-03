/*
Lab05 - identificar se uma(password é boa
by Goto
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//função para achar vogal, o codigo para quando acha o primeiro
int search_vogal(char password[]){
    int test = 0;
    char vogais[11] = "aeiouAEIOU";
    for(int i = 0; i < (int)strlen(password); i++) {
        for(int j = 0; j <11; j++){
            if(password[i] == vogais[j]){
                return test = 1;
            }
        }
    }
    return test = 0;
}
//função para achar numeros, para quando encontrar o primeiro
int search_num(char password[]){
    int test = 0;
    char num[11] = "0123456789";
    for(int i = 0; i < (int)strlen(password); i++) {
        for(int j = 0; j <11; j++){
            if(password[i] == num[j]){
                return test = 1;
            }
        }
    }
    return test =0;
}
//função para achar pelo menos uma letra maiscula e minuscula
int is_lowerupper(char password[]){
    int test = 0;
    int ma = 0; // achou maisculo vai para 1
    int mi = 0; // achou minusculo vai para 1
    for(int i = 0; i < (int)strlen(password); i++){
        if(isalpha(password[i])){
            if(islower(password[i])){
                mi = 1;
            }
            if(isupper(password[i])){
                ma = 1;
            }
            if( ma == 1 && mi == 1) return test = 1;
        }
    }
    return test = 0;
}
// função para verificar se não há 3 vogais consecutivas
int not_vogal(char password[]){
    int test = 0;
    char vogal[11] = "aeiouAEIOU";
    for(int i = 0; i < strlen(password)-2; i++){
        for(int j = 0; j < 11; j++){      
            if(password[i] == vogal[j]){
                for(int k = 0; k < 11; k++){
                    if(password[i+1] == vogal[k]){
                        for(int l = 0; l < 11; l++){
                            if(password[i+2] == vogal[l]){
                                return test = 0;
                            }
                        }        
                    }
                }    
            }
        }
    }
  

    return test = 1;
}
//função que verifica se há consoantes seguidas
int yes_cons(char password[]){
    int test = 0;
    for(int i = 0; i < strlen(password)-2; i++){    
        if(isalpha(password[i]) && password[i] != 'a' && password[i] != 'e' && password[i] != 'i' && password[i] != 'o' && password[i] != 'u' && password[i] != 'A' && password[i] != 'E' && password[i] != 'I' && password[i] != 'O' && password[i] != 'U'){
            if(isalpha(password[i+1]) && password[i+1] != 'a' && password[i+1] != 'e' && password[i+1] != 'i' && password[i+1] != 'o' && password[i+1] != 'u' && password[i+1] != 'A' && password[i+1] != 'E' && password[i+1] != 'I' && password[i+1] != 'O' && password[i+1] != 'U'){
                if(isalpha(password[i+2]) && password[i+2] != 'a' && password[i+2] != 'e' && password[i+2] != 'i' && password[i+2] != 'o' && password[i+2] != 'u' && password[i+2] != 'A' && password[i+2] != 'E' && password[i+2] != 'I' && password[i+2] != 'O' && password[i+2] != 'U'){
                    return test = 1;
                }
                               
            }
   
        }
        
    }
  
    return test = 0;
}
int main(void){

    char chr[21];

    do{
        scanf("%s", chr);
        if(strcmp(chr, "fim") != 0){
            if(strlen(chr) < 8 ){
            printf("[%s] e' inaceitavel.\n", chr);
            }
            
            else if(search_vogal(chr) != 1) printf("[%s] e' inaceitavel.\n", chr);
            else if(search_num(chr) != 1) printf("[%s] e' inaceitavel.\n", chr);
            else if(is_lowerupper(chr) != 1) printf("[%s] e' inaceitavel.\n", chr);
            else if(not_vogal(chr) != 1) printf("[%s] e' inaceitavel.\n", chr);
            else if(yes_cons(chr) != 1) printf("[%s] e' inaceitavel.\n", chr);
            else printf("[%s] e' aceitavel.\n", chr);
            }
        //else;

    } while(strcmp(chr, "fim") != 0);
    return 0;
}
        