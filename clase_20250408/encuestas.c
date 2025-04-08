// Librerias 
#include "encuestas.h"

// Variables Globales

// Funciones Globales

void print_encuesta(encuesta_t *p){
    // Imprime la encuesta en pantalla
    printf("Materia: %s\n", (*p).materia); // Exactamente igual a printf("Materia: %s\n", p->materia);
    printf("Puntaje Materia: %d\n", p->puntaje_materia);
    printf("Nombre Docente: %s\n", p->nombre_docente);
    printf("Puntaje Docente: %d\n", p->putaje_docente);
    printf("Nombre Ayudante: %s\n", p->nombre_ayudante);
    printf("Puntaje Ayudante: %d\n", p->putaje_ayudante);
    printf("Comentario: %s\n", p->comentario);

    return; 
}

void get_materia(encuesta_t *p, char *mayus){
    int index; 
   
    for(index = 0; index < _LENGHT_MATERIA; index++){
        if(p->materia[index] <= 'z' && p->materia[index] >= 'a'){
            mayus[index] = (p->materia[index]) + ('a' - 'A'); // Convierto a Mayuscula
        } 
    }
    return; // si era return(p->materia) funcionaba pero no podia volverlos mayusculas
}

int  get_puntaje_materia(encuesta_t *p){
    return(p->puntaje_materia); // Devuelve el puntaje de la materia
}

void get_nombre_docente(encuesta_t *p, char *nombre){
    int index;

    for(index = 0; index < _LENGHT_NOMBRE; index++){
        nombre[index] = min2Mayus(nombre[index]);
        // Igual a 
        // nombre[index] = (nombre[index] >= 'a' && nombre[index] <= 'z')? (nombre[index] + ('a' - 'A')) : nombre[index];
    }

    return; 
}

int  get_puntaje_docente(encuesta_t *p){
    return(p->putaje_docente); // Devuelve el puntaje del docente
}