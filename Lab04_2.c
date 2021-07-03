/* 
By Goto
Lab 4
Submatrizes: o programa tem o objetivo de quebrar uma matriz em partes menores e dessas partes achar
a maior soma dos elementos dessa submatrizes
*/

#include <stdio.h>

int main(void){
    int n, m, r, s; // linhas, colunas, linha da submatriz, coluna da submatriz
    scanf(" %d %d %d %d", &n, &m, &r, &s);
    int matriz[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m ; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma = 0;
    int sub =0;
    int adi = 0;
    int soma_max = 0;
    int y = 1;
    for(int i = 0; i <= n - r; i++){
            for( int k = 0; k < r; k++){
                for(int l = 0; l < s; l++){
                    printf("i + k = [%d] e l = [%d] = %d, k = %d\n--------------\n", i + k, l, matriz[i+k][l], k);
                    soma = matriz[i+k][l] + soma;
                        //printf("i = %d k = %d l = %d\n==========\n", i, k, l);
                        printf("soma original %d\n", soma);
                        if(soma > soma_max){
                            soma_max = soma;
                        }
                        for(int x = 1; x <= m -s; x++){
                            for(int w = 0; w < r; w++){
                                if(i + w < n){
                                    //printf("linha %d e coluna %d\n", (i  +w), x - 1);
                                    sub = matriz[(i +w)][x - 1] + sub;
                                    adi = adi + matriz[(i +w)][x + s -1];
                                    //printf("sub = %d e adi = %d\n", sub, adi);
                            }
                            }
                            soma = soma - sub + adi;
                            if(soma > soma_max){
                            soma_max = soma;
                        }
                            //printf("pos soma %d\n", soma);
                            adi = 0;
                            sub = 0;
                        }
                        
                    
                    y++;
                }
            }
    }
                        
    printf("%d\n", soma_max);
    return 0;
}