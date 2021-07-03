/*
By Mateus Goto
De volta para o passado / lab03
Vender ações ao voltar no passado, sonho
*/ 
#include <stdio.h>

int max_profit(int n, int k, double q, double acoes[]){
    double lucro_max = -100.0; 
    double lucro;
    int compras, compra_dia, venda_dia, acao_dia; // armazena a quant de ações, dia de compra, dia de venda, quantas ações comprou naquele dia
    //Esses laços está servindo para calcular o lucro de todas as possibilidades e armazena o maior lucro
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){

            if( i + j <= n - 1){
                compras = q / acoes[i];
                lucro = compras * (acoes[i+j] - acoes[i]);

                if(lucro > lucro_max){
                    lucro_max = lucro;
                    compra_dia = i ;
                    venda_dia = i + j; 
                    acao_dia = compras;
                }
            }
        }
    }
    // print das saidas
    printf("Dia da compra: %d\n", compra_dia + 1);
    printf("Valor de compra: R$ %.2lf\n", acoes[compra_dia]);
    printf("Dia da venda: %d\n", venda_dia + 1);
    printf("Valor de venda: R$ %.2lf\n", acoes[venda_dia]);
    printf("Quantidade de acoes compradas: %d\n", acao_dia);
    printf("Lucro: R$ %.2lf\n", lucro_max);

    return 1;
}

int main(void){
    int N, K; // Quantidade de dias, numero máximo de dias permitido para venda
    double Q; // teu dinheiro
    
    scanf("%d", &N);
    double acoes[N]; //define o tamanho do array do tamanho de N
    //coletando o resto das informações do enunciado
    for(int i = 0; i < N; i++){ 
        scanf("%lf", &acoes[i]);

    }
    
    scanf("%d", &K);
    scanf("%lf", &Q);
    // função responsável por calcular o maximo lucro e fazer os devidos prints
    max_profit(N, K, Q, acoes);

    return 0;
}