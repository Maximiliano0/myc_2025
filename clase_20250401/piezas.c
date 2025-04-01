/************************************************************
 *  Nombre: piezas.c                                        *
 * Descripcion: Definición de las piezas del juego          *
 ***********************************************************/

// Librerias
#include "piezas.h"

// Macros

// Variables globales

// Funciones globales
pieza_t pieza_cargar(forma_t forma, color_t color){
    pieza_t pieza; // Definición de la pieza
    
    if(forma!=SIN_FORMA) pieza.forma = forma; // Carga la forma de la pieza
    else pieza.forma = SIN_FORMA; // Si no tiene forma, carga SIN_FORMA
    
    pieza.color = color; // Carga el color de la pieza
    return pieza; // Devuelve la pieza cargada
}

void pieza_imprimir(pieza_t *pieza){
    // Imprime la forma de la pieza
    switch (pieza->forma) {
        case CIRCULO:
            printf("C");
            break;
        case TRIANGULO:
            printf("T");
            break;
        default:
            printf("X");
            break;
    }
}

// Funciones locales