/*************************************************************
 *  Nombre: casilleros.h                                     *
 * Descripcion: Definición de Casilleros del tabllero        *
 *************************************************************/
#ifndef _CASILLEROS_H
#define _CASILLEROS_H

/*  Librerias   */
#include "piezas.h"
#include "string.h"

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
// Casilleros ubica segun coordenaas ["a1", "b2", "c3", "d4"]
typedef struct casilleros
{
    char nombre[3]; // Nombre del casillero
    pieza_t contenido; // Contenido del casillero 
    estado_t estado; // Estado del casillero (0: vacio, 1: ocupado)
} casillero_t;

/* Funciones Globales   */
casillero_t casillero_cargar(char *nombre, estado_t estado, pieza_t contenido); // Carga el casillero
void casillero_imprimir(casillero_t *casillero); // Imprime el casillero

#endif