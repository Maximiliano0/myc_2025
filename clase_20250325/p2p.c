#include "stdio.h"
#include "stdlib.h"

# define _MaxAlumnos 4

int main (void){
    int columna, fila;
    char buffer_nombres[][12] = {"Lautaro", "Ramiro", "Magdalena", "Juan"};

    // Imprimo
    for(columna=0; columna<_MaxAlumnos; columna++){
        printf("Nombre: %s\n", buffer_nombres[columna]);
    }
    printf("\n");

    for(columna=0; columna<_MaxAlumnos; columna++){
        for(fila=0; buffer_nombres[columna][fila] != '\0'; fila++){
            printf("%c", buffer_nombres[columna][fila]);
        }
        printf("\n");
    }

    for(columna=0; columna<_MaxAlumnos; columna++){
        for(fila=0; (*(buffer_nombres + columna))[fila] != '\0'; fila++){
            printf("%c", *((*(buffer_nombres + columna)) + fila) );
        }
        printf("\n");
    }

    return 0;
}