#include "lib_string.h"

void my_lib_printf(char *my_string, int cantidad){

    int index; //Local a la funcion

    // Imprimir buffer completo
    for(index = 0; index < cantidad ; index++){
        printf("%c", my_string[index]);
    }
    printf("\n");

    cantidad = 2;
    printf("Cantidad: %d\n", cantidad);

    return; 
}