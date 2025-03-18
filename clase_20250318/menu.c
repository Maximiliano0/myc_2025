#include "stdio.h"
#include "stdlib.h"

// Prototipo de las fuciones
int fun_1 (void);
int fun_2 (void);
int fun_3 (void);


int main (void){
    int opcion_int;
    char opcion_caracter[2]={'0'};
    int (*fp)(void); // Declaracion de un puntero a funcion

    // Bucle infinito
    while(1){
    // Menu de opciones
    printf("1.- Funcion 1\n");
    printf("2.- Funcion 2\n");  
    printf("3.- Funcion 3\n");
    printf("4.- Salir\n");

    // Tomar la opción del teclado
    fflush(stdin);
    fgets(opcion_caracter, 2,  stdin);

    // Ejecuto la opcion
    switch(opcion_caracter[0]){
        case '1':
            fp = fun_1;
            break;
        case '2':
            fp = fun_2;
            break;
        case '3':
            fp = fun_3;
            break;
        case '4':
            exit(0);
            break;
        default:
            printf("Opcion no valida\n");
            break; 
        }

    // Ejecuto la funcion
    opcion_int = fp();

    }
    return 0;
}

// Definicion de las funciones
int fun_1 (void){
    printf("Hola soy la funcion 1\n");
    return 1;
}

int fun_2 (void){
    printf("Hola soy la funcion 2\n");
    return 2;
}

int fun_3 (void){
    printf("Hola soy la funcion 3\n");
    return 3;
}