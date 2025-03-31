/************************************************************
 *  Nombre: piezas.h                                        *
 * Descripcion: Definición de las piezas del juego          *
 ************************************************************/
#ifndef _PIEZAS_H
#define _PIEZAS_H

/*  Librerias   */
#include "stdio.h"
#include "stdlib.h"

/*  Macros      */

/*  Tipos de Datos  */
typedef enum
{
    SIN_FORMA = ((unsigned char) 0), // Sin forma
    CIRCULO = ((unsigned char) 1), // Forma cuadrado
    TRIANGULO = ((unsigned char) 2) // Forma triangulo
} forma_t; // Definición de las formas

typedef enum
{
    SIN_COLOR = ((unsigned char) 0), // Sin color
    VERDE = ((unsigned char) 1), // Color verde
    AZUL = ((unsigned char) 2), // Color azul
    AMARILLO = ((unsigned char) 3) // Color amarillo
} color_t; // Definición de los colores

typedef struct piezas
{
    forma_t forma; // Forma de la pieza
    color_t color; // Color de la pieza
} pieza_t;

/* Funciones Globales   */
void pieza_imprimir(pieza_t *pieza); // Imprime la pieza
pieza_t pieza_cargar(forma_t forma, color_t color); // Carga la pieza

#endif