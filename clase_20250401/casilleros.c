/*************************************************************
 *  Nombre: casilleros.c                                     *
 *  Descripcion: Definición de Casilleros del tablero        *
*************************************************************/

// Librerias
#include "casilleros.h"

// Macros

// Variables globales

// Funciones globales

casillero_t casillero_cargar(char *nombre, estado_t estado, pieza_t contenido){
    casillero_t casillero; // Definición del casillero
    strcpy(casillero.nombre, nombre); // Carga el nombre del casillero
    casillero.estado = estado; // Carga el estado del casillero
    casillero.contenido = contenido; // Carga el contenido del casillero
    return casillero; // Devuelve el casillero cargado
} 

void casillero_imprimir(casillero_t *casillero){
    pieza_imprimir(&(casillero->contenido)); // Imprime el contenido del casillero
}

// Funciones locales