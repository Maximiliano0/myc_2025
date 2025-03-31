// Libreria de funciones para el juego
#include "tablero.h"

// Variables Globales

// Programa Principal
int main(void){
    tablero_t tablero1; // Definición del tablero 1
    tablero1.id = 1; // Carga el ID del tablero 1

    tablero_limpiar(&tablero1); // Limpia el tablero 1
    tablero_imprimir(&tablero1); // Imprime el tablero 1

    // Carga las piezas
    pieza_t pieza1 = pieza_cargar(CIRCULO, VERDE); // Carga la pieza 1
    pieza_t pieza2 = pieza_cargar(TRIANGULO, AZUL); // Carga la pieza 2
    pieza_t pieza3 = pieza_cargar(CIRCULO, AMARILLO); // Carga la pieza 3
    pieza_t pieza4 = pieza_cargar(TRIANGULO, VERDE); // Carga la pieza 4

    // Carga los casilleros
    casillero_t casillero1 = casillero_cargar("a1", OCUPADO, pieza1); // Carga el casillero 1
    casillero_t casillero2 = casillero_cargar("b2", OCUPADO, pieza2); // Carga el casillero 2
    casillero_t casillero3 = casillero_cargar("c3", OCUPADO, pieza3); // Carga el casillero 3
    casillero_t casillero4 = casillero_cargar("d4", OCUPADO, pieza4); // Carga el casillero 4

    // Inserta los casilleros en el tablero
    tablero_poner(&tablero1, &casillero1, 0, 0); // Inserta el casillero 1 en el tablero 1
    tablero_poner(&tablero1, &casillero2, 1, 1); // Inserta el casillero 2 en el tablero 1
    tablero_poner(&tablero1, &casillero3, 2, 2); // Inserta el casillero 3 en el tablero 1
    tablero_poner(&tablero1, &casillero4, 3, 3); // Inserta el casillero 3 en el tablero 1

    tablero_imprimir(&tablero1); // Imprime el tablero 1
    
    return 0; 
}