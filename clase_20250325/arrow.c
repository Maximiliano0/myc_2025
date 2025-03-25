#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

// Macros
#define _MaxChar 50
#define _MaxNotas 4
#define _MaxAlumnos 4

// Tipo de datos
typedef enum {ING_MECANICA = ((unsigned int) 0),
              ING_ELECTRONICA = ((unsigned int) 1),
              ING_BIOMEDICINA = ((unsigned int) 2)    
             } tipo_carrera;

typedef struct estructura_alumno{
    char nombre[_MaxChar]; 
    char apellido[_MaxChar];
    tipo_carrera carrera; 
    int legajo;
    unsigned int edad;
    float *historico; 
}tipo_alumno;

// Variables globales
float buffer_notas[_MaxNotas]={4, 6, 10, 2};
char buffer_nombres[_MaxAlumnos][_MaxChar] = {"Lautaro", "Ramiro", "Magdalena", "Juan"};
tipo_carrera buffer_carreras[_MaxAlumnos] = {ING_MECANICA, ING_MECANICA, ING_BIOMEDICINA, ING_BIOMEDICINA};

// Función Main
int main(void){
    // Variables
    int index;
    tipo_alumno mis_alumnos[4];

    // Inicializacion A fuerza bruta
    for(index=0; index<_MaxAlumnos; index++){
        strcpy(mis_alumnos[index].nombre, buffer_nombres[index]);
        mis_alumnos[index].carrera = buffer_carreras[index];
    }

    // Imprimir
    for(index=0; index<_MaxAlumnos; index++){
        printf("Nombre: %s\n", mis_alumnos[index].nombre);
        printf("Carrera: %d\n", mis_alumnos[index].carrera);
        printf("\n");
    }

    // Filtro
    printf("Alumnos de Ingenieria Mecanica:\n");
    for(index=0; index<_MaxAlumnos; index++){
        if( (*(mis_alumnos+index)).carrera == ING_MECANICA){
            printf("Nombre: %s\n", (mis_alumnos+index)->nombre);
            printf("Carrera: %d\n", mis_alumnos[index].carrera);
            printf("\n");
        }
    }

    // Acceso a buffer_notas
    mis_alumnos[0].historico = buffer_notas;  

    for(index=0; index<_MaxNotas; index++){
        printf("Nota %d es : %2.f \n", index, (mis_alumnos[0]).historico[index]);
        printf("Nota %d es : %2.f \n", index, mis_alumnos -> historico[index]);
        printf("Nota %d es : %2.f \n", index, (*mis_alumnos).historico[index]);  
        printf("Nota %d es : %2.f \n", index, mis_alumnos -> historico + index);    
    }

    return 0;
}
