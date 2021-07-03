/* 
By Goto
Lab 4
Submatrizes: o programa tem o objetivo de quebrar uma matriz em partes menores e dessas partes achar
a maior soma dos elementos dessa submatrizes
*/

#include <stdio.h>

int reduced_matriz(int n, int m,int matriz[n][m], int r, int s){
    int soma = 0;
    int soma_max = 0;
    int y = 1;
    for(int i = 0; i <= n - r; i ++){
        for(int j = 0; j <= m - s ; j++){
            for( int k = 0; k < r; k++){
                for(int l = 0; l < s; l++){
                        //printf("i = %d k = %d j = %d l = %d\n-----------------\n", i, k, j, l);
                        printf("o valor e %d \n", matriz[i+k][j+l]);
                        soma = matriz[i+k][j+l] + soma;
                        printf("soma e %d\n", soma);
                        //printf("(%d)[%d] e [%d]\n--------------\n", y, i + k, j + l);
                        
                        if( y % (r*s) == 0){
                            //printf("2soma é %d\n", soma);
                            if(soma > soma_max){
                                soma_max = soma;   
                            }
                            soma = 0;
                            y = 0;
                        }
                        y++;
                    
                }
                
            }
        }
    }
    printf("%d\n", soma_max);
    return 1;
}

int main(void){
    int n, m, r, s; // linhas, colunas, linha da submatriz, coluna da submatriz
    scanf(" %d %d %d %d", &n, &m, &r, &s);
    int matriz[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m ; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    /*for(int i = 0; i < n; i ++){
        for(int j = 0; j < m ; j++){
            printf("%d ", matriz[i][j]);
            if(j == m - 1){
                printf("\n");
            }
        }
    }*/
    //reduced_matriz( n, m, matriz[n][m], r, s);
    int soma = 0;
    int soma_max = 0;
    int y = 1;
    for(int i = 0; i <= n - r; i ++){
        for(int j = 0; j <= m - s ; j++ ){
            for( int k = 0; k < r; k++){
                for(int l = 0; l < s; l++){
                        //printf("i = %d k = %d j = %d l = %d\n-----------------\n", i, k, j, l);
                        //printf("o valor e %d \n", matriz[i+k][j+l]);
                        soma = matriz[i+k][j+l] + soma;
                        //printf("soma e %d\n", soma);
                        //printf("(%d)[%d] e [%d]\n--------------\n", y, i + k, j + l);
                        
                        if( y % (r*s) == 0){
                            //printf("2soma é %d\n", soma);
                            if(soma > soma_max){
                                soma_max = soma;   
                            }
                            soma = 0;
                            y = 0;
                        }
                        y++;
                    
                }
                
            }
        }
    }
    printf("%d\n", soma_max);


    return 0;
}