/* 
A program that takes a large number os values in one single input and than calculate de avarege of this values.
Create by Goto
*/
/*OBSERVATION: i made this code to take the arquive send by the professor, but the arquive is to much big that one copy and past will
work in a single input, so if you WANNA TRY THIS CODE copy a part of the arquive(half of it), later input the rest of the numbers, will work
I didnt think a more cleaver way to do this */
#include <stdio.h>

int number_of_value = 1000; // the number of who many number we a working with

int main(void){

    int info[number_of_value]; // a int array to hold all the data
    double sum = 0.0; // will get the sum of all the data
    printf("Insert values\n"); // print the message

    for(int i = 0; i < number_of_value; i++){ // the for lace will scan every entry in your input
        scanf("%4d", &info[i]); // the scan f is taking 4 in 4 numbers, avoiding to record any blank or just a part of the number
    }
    // uncomment this if you wanna see all the values
    /*for(int i = 0; i < number_of_value; i++){
        printf("\nthe number %d is locate in %d in the array", info[i], i);
    }*/

    // this will sum all the value to calculate de avarege
    for(int j = 0; j < number_of_value; j++){
        sum = sum + info[j];
    }
    printf("The avarege is %.2f\n\n", sum/number_of_value); // print the avarege 

    return 0;
}