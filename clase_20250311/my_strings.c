#include "my_strings.h"

int main (void){
    char letra1 ='a';
    int  letra2 = 'a';
    const int my_constante = 10;
    char buffer[buffer_length]="a b";

    // Caracteres ASCII
    printf("Letra1: %d\n", letra1);
    printf("Letra2: %c\n", letra2);

    // Palabras
    printf("Buffer: %s\n", buffer);

    // Inclusion de .h
    printf("Maximum length of a string: %d\n", buffer_length);

    // Constantes
    printf("Constante: %d\n", my_constante);
    //my_constante = 20; --> read-only !!!
    // printf("Constante: %d\n", my_constante);
    //buffer_length = 200; --> Imposible
    
    // Acceso de Array
    buffer[0] = '1';
    buffer[1] = '2';
    printf("Buffer: %s\n", buffer);

    // Como lo rompo
    buffer[10] = 'z';
    printf("Buffer Roto: %s\n", buffer);

    return 0;
}