/*************************************************************
 *  Nombre: tablero.c                                        *
 *  Descripcion: Definición de Tablero para el juego         *
*************************************************************/

// Librerias
#include "tablero.h"

// Macros

// Variables globales
unsigned int last_id = 0; // ID del ultimo tablero

/*  Funciones locales   */
// Pasa nombres a coordenadas
static int nombre_a_fc(char *nombre, unsigned int *fila, unsigned int *columna){
    *fila = nombre[0] - 'a'; // Carga la fila
    *columna = nombre[1] - '0'; // Carga la columna
    return 1; // Devuelve el nombre del casillero
} // Devuelve el nombre del casillero

// Pasa coordenadas a nombres
static char* fc_a_nombre(unsigned int fila, unsigned int columna){
    static char nombre[3]; // Nombre del casillero
    nombre[0] = 'a' + fila; // Carga la fila
    nombre[1] = '0' + columna; // Carga la columna
    nombre[2] = '\0'; // Carga el terminador de cadena
    return nombre; // Devuelve el nombre del casillero
} // Devuelve el nombre del casillero

// Limpiar
static int tablero_limpiar(tablero_t *tablero){ 
    unsigned int i, j; // Variables de control
    for (i = 0; i < _MAX_FILAS; i++) { // Recorre las filas
        for (j = 0; j < _MAX_COLUMNAS; j++) { // Recorre las columnas
            tablero->matriz[i][j] = casillero_cargar(fc_a_nombre(i, j), VACIO, pieza_cargar(SIN_FORMA, SIN_COLOR)); // Carga el casillero vacio
            // NO HACER tablero->matriz[i][j] = VACIO;
            /* MAL
                tablero->matriz[i][j].nombre = "vacio"
                tablero->matriz[i][j].estado = VACIO;
                tablero->matriz[i][j].contenido = UNA PIEZA;
            */
        } // Fin del for de columnas
    } // Fin del for de filas
    return 1; // Devuelve 1 si se destruyo el tablero correctamente
} 

/*  Funciones globales */

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
int tablero_poner(tablero_t *tablero, casillero_t a_insertar){
    unsigned int fila, columna; // Variables de control
    nombre_a_fc(a_insertar.nombre, &fila, &columna); // Convierte el nombre a coordenadas
    if (tablero->matriz[fila][columna].estado == OCUPADO) { // Si el casillero esta ocupado
        return 0; // Devuelve 0 si no se puede insertar la pieza
    } // Fin del if
    tablero->matriz[fila][columna] = a_insertar; // Inserta la pieza en el tablero
    
    tablero->matriz[fila][columna].estado = OCUPADO; // Cambia el estado del casillero a ocupado //  Dudoso
    
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

// Crea el tablero
int tablero_crear(tablero_t *p){
   
    (*p).id = last_id; // Carga el ID del tablero
    last_id++; // Incrementa el ID del tablero

    tablero_limpiar(p); // Limpia el tablero

    return 0; 
}

