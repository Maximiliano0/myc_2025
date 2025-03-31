/*************************************************************
 *  Nombre: tablero.c                                        *
 *  Descripcion: Definición de Tablero para el juego         *
*************************************************************/

// Librerias
#include "tablero.h"

// Macros

// Variables globales

// Funciones globales

/*  Funciones locales   */
static char* tablero_nombre(unsigned int fila, unsigned int columna){
    static char nombre[3]; // Nombre del casillero
    nombre[0] = 'a' + fila; // Carga la fila
    nombre[1] = '1' + columna; // Carga la columna
    nombre[2] = '\0'; // Termina la cadena
    return nombre; // Devuelve el nombre del casillero
} // Devuelve el nombre del casillero

// Destruye el tablero
int tablero_limpiar(tablero_t *tablero){ 
    unsigned int i, j; // Variables de control
    for (i = 0; i < _MAX_FILAS; i++) { // Recorre las filas
        for (j = 0; j < _MAX_COLUMNAS; j++) { // Recorre las columnas
            tablero->matriz[i][j] = casillero_cargar(tablero_nombre(i, j), VACIO, pieza_cargar(SIN_FORMA, SIN_COLOR)); // Carga el casillero vacio
        } // Fin del for de columnas
    } // Fin del for de filas
    return 1; // Devuelve 1 si se destruyo el tablero correctamente
} 

// Imprime el tablero
void tablero_imprimir(tablero_t *tablero){ 
    unsigned int i, j; // Variables de control
    printf("Tablero: %d\n", tablero->id); // Imprime el ID del tablero
    for (i = 0; i < _MAX_FILAS; i++) { // Recorre las filas
        for (j = 0; j < _MAX_COLUMNAS; j++) { // Recorre las columnas
            casillero_imprimir(&(tablero->matriz[i][j])); // Imprime el casillero
            printf(" "); // Imprime un espacio
        } // Fin del for de columnas
        printf("\n"); // Imprime un salto de linea
    } // Fin del for de filas
} 

// Inserta una pieza en el tablero
int tablero_poner(tablero_t *tablero, casillero_t *a_insertar, unsigned int fila, unsigned int columna){
    if (tablero->matriz[fila][columna].estado == OCUPADO) { // Si el casillero esta ocupado
        return 0; // Devuelve 0 si no se puede insertar la pieza
    } // Fin del if
    tablero->matriz[fila][columna] = *a_insertar; // Inserta la pieza en el tablero
    tablero->matriz[fila][columna].estado = OCUPADO; // Cambia el estado del casillero a ocupado
    return 1; // Devuelve 1 si se inserto la pieza correctamente
} 

// Inserta una pieza en el tablero
int tablero_sacar(tablero_t *tablero, casillero_t *a_vaciar, unsigned int fila, unsigned int columna){
    if (tablero->matriz[fila][columna].estado == VACIO) { // Si el casillero esta vacio
        return 0; // Devuelve 0 si no se puede sacar la pieza
    } // Fin del if
    tablero->matriz[fila][columna] = *a_vaciar; // Saca la pieza del tablero
    tablero->matriz[fila][columna].estado = VACIO; // Cambia el estado del casillero a vacio
    return 1; // Devuelve 1 si se saco la pieza correctamente
}

