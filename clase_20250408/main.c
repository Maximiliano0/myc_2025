// Librerias
#include "encuestas.h"
#include "string.h"

// Macros y Defines

// Variables globales
encuesta_t vector_encuestas[7]; // Vector de encuestas

// Funciones Locales

// Funcion principal
int main(void){
    // Variables
    char nombre_ingresado [_LENGHT_NOMBRE] = "Maxi"; // Nombre ingresado por el usuario
    char docente[_LENGHT_NOMBRE]; // Variable para guardar el nombre del docente
    char mayus[_LENGHT_MATERIA]; // Variable para guardar el nombre de la materia en mayusculas
    encuesta_t encuesta_aux, encuestas_copy[sizeof(vector_encuestas)/sizeof(encuesta_t)];
    int index, i, k, cant_encuestas, cant_matches; // Cantidad de encuestas
    float promedio_docente; // Variable para guardar el puntaje promedio del docente

    /* Armar aqui el llenado ficticio de las encuestas para probar el codigo hecho */
    // Practicar Aqui

    cant_encuestas = sizeof(vector_encuestas)/sizeof(encuesta_t); // Cantidad de encuestas} 
    // Filtrar las encuestas por Materia
    // Faltaria pasar nombre_ingresado a mayusculas
    for(index = 0; index < cant_encuestas; index++){
        get_materia(&vector_encuestas[index], mayus); // Llamo a la funcion para pasar a mayusculas
        if(strcmp(nombre_ingresado, mayus) == 0){
            print_encuesta(&vector_encuestas[index]);
        }
    }

    // Ordenar por Puntaje de Materia
    // Deberia crearse un vector auxiliar para no modificar el original
    for(index = 0; index < cant_encuestas; index++){
        encuestas_copy[index] = vector_encuestas[index]; // Copia el vector original al auxiliar
    }
    for(i = 0; i < cant_encuestas - 1; i++){
        for(k = 0; k < cant_encuestas - i - 1; k++){
            if(encuestas_copy[k].puntaje_materia > encuestas_copy[k + 1].puntaje_materia){
                // Intercambiar las encuestas
                encuesta_aux = encuestas_copy[k];
                encuestas_copy[k] = encuestas_copy[k + 1];
                encuestas_copy[k + 1] = encuesta_aux;
            }
        }
    }
    // Imprimir el vector ordenado por puntaje de materia
    for(index = 0; index < cant_encuestas; index++){
        print_encuesta(&encuestas_copy[index]);
    }

    // Obtener el puntaje promedio del docente
    promedio_docente = 0;
    cant_matches = 0; // Cantidad de matches
    for(index=0; index < cant_encuestas; index++){
        get_nombre_docente(&vector_encuestas[index], docente);
        if(sctrcmp(nombre_ingresado, docente) == 0){
            cant_matches++; // Aumento la cantidad de matches
            promedio_docente += get_puntaje_docente(&vector_encuestas[index]); // Sumo el puntaje del docente
        }
    }
    // Opcion 1 de promedio
    promedio_docente = promedio_docente / cant_encuestas; // Promedio de los puntajes del docente
    // OPcion 2 de promedio
    //promedio_docente = promedio_docente / cant_matches; // Promedio de los puntajes del docente

    return 0;
}

