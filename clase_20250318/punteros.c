#include "stdio.h"
#include "stdlib.h"

int main (void){
    int a = 2;
    int b = 257;
    int *p; 
    char *pc;

    // Muestro direcciones y contenido de las variables
    printf("Contenido de a: %d\n", a);
    printf("Contenido de b: %d\n", b);

    printf("Direccion de a: %X\n", &a);
    printf("Direccion de b: %X\n", &b);

    printf("\n");

    // Muestro puntero desbocado
    printf("Contenido de p sin inicializar: %X\n", p);

    // Muestro punteros asignados correctamente
    p = &a;
    printf("Contenido de p: %X\n", p);
    printf("Direccion de p: %X\n", &p);
    *p = 3;
    printf("Contenido de a: %d\n", a);
    
    printf("\n");
 
    // Casteo de punteros
    pc = (char*) (&b);
    printf("Contenido de pc: %X\n", pc);
    printf("Contenido de pc: %X\n", *pc);
    
    printf("\n");

    // Aritmetica de punteros
    pc++;
    printf("Contenido de pc: %X\n", pc);
    printf("Contenido de pc: %X\n", *pc);

    pc+=3;
    printf("Contenido de pc: %X\n", pc);
    printf("Contenido de pc: %X\n", *pc);

    p--;
    printf("Contenido de p: %X\n", p);
    printf("Contenido de p: %d\n", *p);

    return(0); 
}