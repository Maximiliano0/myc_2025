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
typedef struct tablero
{
    casillero_t matriz[_MAX_FILAS] [_MAX_COLUMNAS]; // Matriz del tablero
    unsigned int id; // ID del tablero    
} tablero_t;

/* Funciones Globales   */
unsigned char tablero_inicializar(tablero_t *tablero, unsigned int id); // Inicializa el tablero
unsigned char tablero_destruir(tablero_t *tablero); // Destruye el tablero

void tablero_imprimir(tablero_t *tablero); // Imprime el tablero

unsigned char tablero_insertar(tablero_t *tablero, void *contenido, unsigned int fila, unsigned int columna); // Inserta una pieza en el tablero
void* tablero_sacar(tablero_t *tablero, unsigned int fila, unsigned int columna); // Inserta una pieza en el tablero

#endif