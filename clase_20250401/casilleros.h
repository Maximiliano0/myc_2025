/*************************************************************
 *  Nombre: casilleros.h                                     *
 * Descripcion: Definición de Casilleros del tabllero        *
 *************************************************************/
#ifndef _CASILLEROS_H
#define _CASILLEROS_H

/*  Librerias   */
#include "piezas.h"

/*  Macros      */

/*  Tipos de Datos  */

// Definición de los estados de los casilleros
// 0: vacio, 1: ocupado
typedef enum
{
    VACIO = ((unsigned char ) 0), // Casillero vacio
    OCUPADO = ((unsigned char) 1) // Casillero ocupado
} estado_t;

// Definición de la estructura de un casillero
typedef struct casilleros
{
    unsigned int fila; // Fila del casillero
    unsigned int columna; // Columna del casillero
    piezas_t contenido; // Contenido del casillero 
    estado_t estado; // Estado del casillero (0: vacio, 1: ocupado)
} casillero_t;

/* Funciones Globales   */
void casillero_imprimir(tablero_t *tablero); // Imprime el tablero

unsigned char tablero_insertar(tablero_t *tablero, piezas_t pieza, unsigned int fila, unsigned int columna); // Inserta una pieza en el tablero
piezas_t tablero_sacar(tablero_t *tablero, unsigned int fila, unsigned int columna); // Inserta una pieza en el tablero

#endif