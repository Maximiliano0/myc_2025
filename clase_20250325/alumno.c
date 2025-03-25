#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

// Macros
#define _MaxChar 50
#define _MaxNotas 40

// Tipo de datos
typedef enum {ING_MECANICA = 0,
              ING_ELECTRONICA = 1,
              ING_BIOMEDICINA = 2    
             } tipo_carrera;

typedef struct estructura_alumno{
    char nombre[_MaxChar]; 
    char apellido[_MaxChar];
    tipo_carrera carrera; 
    int legajo;
    unsigned int edad;
    float *historico; 
}tipo_alumno;

// Prototipos de funciones

// Variables globales
float buffer_notas[_MaxNotas];

// Función Main
int main(void){
    // Variables
    int index;
    tipo_alumno maxi, malena;
    struct estructura_alumno matias;

    // Inicializacion
    strcpy(maxi.nombre, "Maximiliano");
    strcpy(maxi.apellido, "Vega");
    maxi.carrera = ING_ELECTRONICA;
    maxi.legajo = 12345;
    maxi.edad = 33;
    maxi.historico = buffer_notas;

    printf("Nombre: %s\n", maxi.nombre);
    printf("Apellido: %s\n", maxi.apellido);
    printf("Carrera: %d\n", maxi.carrera);
    printf("Legajo: %d\n", maxi.legajo);
    printf("Edad: %d\n", maxi.edad);
    printf("\n");
    
    strcpy(malena.nombre, "Malena");
    strcpy(malena.apellido, "Gimenez");
    malena.carrera = ING_MECANICA;
    malena.legajo = 1984;
    malena.edad = 42;
    malena.historico = buffer_notas;
    
    printf("Nombre: %s\n", malena.nombre);
    printf("Apellido: %s\n", malena.apellido);
    printf("Carrera: %d\n", malena.carrera);
    printf("Legajo: %d\n", malena.legajo);
    printf("Edad: %d\n", malena.edad);
    printf("\n");

    // Tamaño del struct
    printf("Tamano de la estructura tipo_alumno: %d\n", sizeof(tipo_alumno));

    return 0;
}

