#ifndef _PIEZAS_H
#define _PIEZAS_H

/*  Librerias   */
#include "piezas.h"

/*  Macros      */

/*  Tipos de Datos  */
typedef enum
{
    CIRCULO = ((unsigned char) 0), // Forma circulo
    CUADRADO = ((unsigned char) 1), // Forma cuadrado
    TRIANGULO = ((unsigned char) 2), // Forma triangulo
    ESTRELLA = ((unsigned char) 3) // Forma estrella
} forma_t; // Definición de las formas

typedef enum
{
    ROJO = ((unsigned char) 0), // Color rojo
    VERDE = ((unsigned char) 1), // Color verde
    AZUL = ((unsigned char) 2), // Color azul
    AMARILLO = ((unsigned char) 3) // Color amarillo
} color_t; // Definición de los colores

typedef struct piezas
{
    forma_t forma; // Forma de la pieza
    color_t color; // Color de la pieza
} piezas_t;

/* Funciones Globales   */
void piezas_inicializar(piezas_t *pieza, forma_t forma, color_t color); // Inicializa la pieza

#endif