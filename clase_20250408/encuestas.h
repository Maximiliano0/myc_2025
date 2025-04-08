// Librerias
#include "stdio.h"

// Macros y Defines
#define _LENGHT_MATERIA 20
#define _LENGHT_NOMBRE 20 // El nombre de Docente mas largo tiene 19 caracteres
#define _LENGHT_COMENTARIO 11
#define _NA 0

#define min2Mayus(x) ((x) >= 'a' && (x) <= 'z')? ((x) + ('a' - 'A')) : x // Macro para convertir a mayusculas

// Tipos de Datos
typedef struct encuestas
{
   char materia[_LENGHT_MATERIA]; // El nombre de Materia mas largo tiene 19 caracteres
   int puntaje_materia; // Es obligatorio puede ser 1,2,3,4 o 5
   char nombre_docente[_LENGHT_NOMBRE]; // El nombre de Docente mas largo tiene 19 caracteres
   int putaje_docente; // Es obligatorio puede ser _NA, 1,2,3,4 o 5
   char nombre_ayudante[_LENGHT_NOMBRE]; // El nombre de Docente mas largo tiene 19 caracteres
   int putaje_ayudante; // Es obligatorio puede ser _NA, 1,2,3,4 o 5
   char comentario[_LENGHT_COMENTARIO]; // Comentario opcional de 10 caracteres
}encuesta_t;

// Funciones Globales
void print_encuesta(encuesta_t *p); // Imprime la encuesta en pantalla

void get_materia(encuesta_t *p, char *mayus); // Pide el nombre de la materia y lo devuelve
int  get_puntaje_materia(encuesta_t *p); // Pide el puntaje de la materia y lo devuelve  

void get_nombre_docente(encuesta_t *p, char *nombre); // Pide el nombre del docente y lo devuelve
int  get_puntaje_docente(encuesta_t *p); // Pide el puntaje del docente y lo devuelve

// Funciones Locales