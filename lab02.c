#include <stdio.h>



int ascii_art(int num, int freq, char carac){

    printf("%*d |",(int)sizeof(num), num);
    for(int i = 0; i < freq; i++){
        printf("%c", carac);
    }
    printf(" %d\n", freq);
    return 1;
}

int main(void){
    int n = 0;
    scanf("%d", &n);
    int num[n];
    int freq[n];
    char carac[n];


    for(int i = 0; i < n; i++){
        scanf(" (%d,%d,%c)", &num[i], &freq[i], &carac[i]);
        ascii_art(num[i], freq[i], carac[i]);
    }

        
    return 0;
}