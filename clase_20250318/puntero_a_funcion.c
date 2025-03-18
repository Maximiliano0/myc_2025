#include "stdio.h"
#include "stdlib.h"

// Prototipo de las fuciones
int fun_1 (void);
int fun_2 (void);
char fun_3 (void);


int main (void){
    int aux;
    int (*fp)(void); // Declaracion de un puntero a funcion

    // Ejecuto funciones
    fp = fun_1; 
    //aux = fp(); equivale a aux = fun_1();
    aux = fun_1();
    printf("Ejecuto y veo: %d \n", aux);

    // Ejecuto funciones
    fp =  fun_3; 
    aux = fp(); 
    printf("Ejecuto y veo: %d \n", aux);
    
    return 0;
}

// Definicion de las funciones
int fun_1 (void){
    printf("Hola soy la funcion 1\n");
    return 0;
}

int fun_2 (void){
    printf("Hola soy la funcion 2\n");
    return 0;
}

char fun_3 (void){
    printf("Hola soy la funcion 3\n");
    return 'a';
}