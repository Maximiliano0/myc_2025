#include "stdio.h"
#include "stdlib.h"

int main (void){
    int array[5] = {1, 2, 3, 4, 5};
    int *p;
    char *pc;

    // Apunto al Array
    p = array;
    pc = (char *) array;

    // Equivalencia de array y puntero
    printf("array[0] = %d\n", array[0]);
    printf("puntero = %d\n", *p);

    printf("\n");

    // Incremento de puntero
    p++;
    printf("array[1] = %d\n", array[1]);
    printf("puntero = %d\n", *p);
    printf(" array ?? = %d\n", *(array+1));

    printf("\n");

    // Incremento de puntero char
    printf("array[0] = %d\n", array[0]);
    printf("puntero = %d\n", *pc);

    printf("\n");

    pc++;
    printf("array[0] = %d\n", array[0]);
    printf("puntero = %d\n", *pc);

    printf("\n");

    pc+=3;
    printf("array[3] = %d\n", array[3]);
    printf("puntero = %d\n", *pc);

    return 0; 
}