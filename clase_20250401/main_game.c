// Libreria de funciones para el juego
#include "tablero.h"

// Variables Globales

// Programa Principal
int main(void){
    tablero_t tablero1; // Definición del tablero 1
    tablero_t tablero2; // Definición del tablero 2  

    tablero_crear(&tablero1); // Crea el tablero 1
    tablero_crear(&tablero2); // Crea el tablero 2

    tablero_imprimir(&tablero1); // Imprime el tablero 1
    tablero_imprimir(&tablero2); // Imprime el tablero 2

    // Carga las piezas DIDACTICA
    // DEBERIA HACERSE EN UNA FUNCIÓN DE tablero.c O BIEN casilleros.c
    // Ejemplo TABLERO_JUEGO_CARGAR(*tablero1, "AJEDREZ")
    // CONCEPTO !!! NO DEBERIA LLAMAR A pieza_cargar() NI casillero_cargar() DESDE MAIN_GAME.c
    // Inserta los casilleros en el tablero
    tablero_poner(&tablero1, casillero_cargar("a0", OCUPADO, pieza_cargar(CIRCULO, VERDE))); // Inserta el casillero 1 en el tablero 1
    tablero_poner(&tablero1, casillero_cargar("b1", OCUPADO, pieza_cargar(TRIANGULO, AZUL))); // Inserta el casillero 2 en el tablero 1
    tablero_poner(&tablero1, casillero_cargar("c2", OCUPADO, pieza_cargar(CIRCULO, AMARILLO))); // Inserta el casillero 3 en el tablero 1
    tablero_poner(&tablero1, casillero_cargar("d1", OCUPADO, pieza_cargar(CIRCULO, AMARILLO))); // Inserta el casillero 3 en el tablero 1

    printf("\n\n"); // Imprime un salto de linea
    tablero_imprimir(&tablero1); // Imprime el tablero 1
    
    return 0; 
}