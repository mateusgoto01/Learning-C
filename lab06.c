/*
lab06
Cifra de Et bilu
Consiste em uma cifra de cesar, porém a quantidade de símbolos deslocado é inferido pela letra de maior repetição no codigo
Se a letra for a --> a = a 
Se for a letra z --> z = z

notas:
se maior de 122 então é igual a 122 + chave -26
teste particular:
zz abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz zz
abcdefghijklmnopqrstuvwxyaz zz
abcdefghijklmnopqrstuvwxyz aa
acdefghijklmnopqrstuvwxyzb aa
bcdefghijklmnopqrstuvwxaz zz
bcdefghijklmnopqrstuvwxaz zz
acdefghijklmnopqrstuvwxyzb aa
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char codigo[10001];
    char alfa[27] = "abcdefghijklmnopqrstuvwxyz";
    int count[26]; // contadores para todas as letras do alfabeto
    int max = 0; // quantidade de vezes que a maior letra repetiu
    char letra = 0; // armazena qual carac é a mais repetida
    int key;// chave de decodificação
    scanf("%[^\n]s", codigo);

    for(int i = 0; i < (int)strlen(codigo); i++){
        for(int j = 0; j < strlen(alfa); j++){
            if(codigo[i] == alfa[j]){
                count[j] += 1;
                if(count[j] > max){
                    max = count[j];
                    letra = alfa[j];
                }
            }
        }
    }
    

    key = letra - alfa[0];
    //printf("a chave e %d\n", key);
    if(key == 0){  
        for(int i = 0; i < (int)strlen(codigo); i++){
            if(codigo[i] >= 97 && codigo[i] <= 122 ){
                if(codigo[i] == letra) codigo[i] = codigo[i];
                else if(codigo[i] == 98) codigo[i] = 122;
                else codigo[i] -= 1;
                if(codigo[i] < 97)  codigo[i] += 26;
                if(codigo[i] > 122) codigo[i] -= 26;
            }
        }
    }
    if(key == 25){  
        for(int i = 0; i < (int)strlen(codigo); i++){
            if(codigo[i] >= 97 && codigo[i] <= 122 ){
                //printf("%d %d\n", codigo[i], 1 + codigo[i]);
                if(codigo[i] == letra) codigo[i] = codigo[i];
                else if(codigo[i] == 97) codigo[i] = 121;
                else codigo[i] -= 1;
                if(codigo[i] < 97)  codigo[i] += 26;
                if(codigo[i] > 122) codigo[i] -= 26;
            }
        }
    }
    else {
        for(int i = 0; i < (int)strlen(codigo); i++){
            if(codigo[i] >= 97 && codigo[i] <= 122 ){
                // se for a letra da chave, não faça nada se for qualquer outra diminua a chave
                if(codigo[i] == letra) codigo[i] = codigo[i];
                else {
                    for(int j = 0; j < key; j++){
                        codigo[i]--;
                        if(codigo[i] < 97)  codigo[i] += 26;
                        if(codigo[i] == letra) j--;
                    }
                }
                // se sair do intervalo do alfabeto minusculo, traz de volta
                /*if(codigo[i] < 97)  codigo[i] += 26;
                else if(codigo[i] > 122) codigo[i] -= 26;
                // se durante a descodificação passar pela letra, adicione +1
                if(letra <= last && letra > codigo[i]) codigo[i]--;*/
            }
        }
    }       
    printf("%s\n", codigo);
    return 0;
}