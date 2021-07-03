#include <stdio.h>

int relogio(int entrada){
    // variaveis globais
    int dias = 0;
    int horas = 0 ;
    int minutos = 0;
    int segundos = 0;
    // variaveis para quebrar
    int dias_horas = 0;
    int horas_minutos = 0;
    // para dias
    dias = entrada / (24 * 3600);
    dias_horas = entrada % (24 * 3600);
    // para horas
    horas = dias_horas / 3600;
    horas_minutos = entrada % 3600;
    // para minutos
    minutos = horas_minutos / 60;
    // para segundos
    segundos = entrada % 60;

    
    return printf("%d dia(s), %d hora(s), %d minuto(s) e %d segundo(s).\n", dias, horas, minutos, segundos);
}

int main(void){

    int valor = 0;
    scanf("%d", &valor);
    relogio(valor);

    return 0;
}
