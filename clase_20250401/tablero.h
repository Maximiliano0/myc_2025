/*************************************************************
 *  Nombre: tablero.h                                        *
 *  Descripcion: Definición de Tablero para el juego         *
 *************************************************************/
#ifndef _TABLERO_H
#define _TABLERO_H

/*  Librerias   */
#include "casilleros.h"

/*  Macros      */
#define _MAX_FILAS 4 // Cantidad maxima de filas del tablero
#define _MAX_COLUMNAS 4// Cantidad maxima de columnas del tablero

/*  Tipos de Datos  */
// Definición de la estructura del tablero
// Tablero ubica segun coordenadas (fila, columna)
typedef struct tablero
{
    unsigned int id; // ID del tablero    
    casillero_t matriz[_MAX_FILAS] [_MAX_COLUMNAS]; // Matriz del tablero
} tablero_t;

/* Funciones Globales   */
void tablero_imprimir(tablero_t *tablero); // Imprime el tablero

int tablero_poner(tablero_t *tablero, casillero_t a_insertar); // Inserta una pieza en el tablero
int tablero_sacar(tablero_t *tablero, casillero_t *a_vaciar, unsigned int fila, unsigned int columna); // Inserta una pieza en el tablero

int tablero_crear(tablero_t *tablero); // Crea el tablero


/*  Funciones locales   */
//char* tablero_nombre(unsigned int fila, unsigned int columna); // Devuelve el nombre del casillero
// Tratar de acceder a pieza_t desde tablero_t

#endif