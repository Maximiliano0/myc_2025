// Librerías
#include <stdio.h>
#include <stdlib.h>

// Macros
#define _Buff_Size ((int) 128) // Tamaño del buffer de teclado
#define _Cant_Numeros ((int) 5) // Cantidad de números a ingresar

// Teclas
#define _NOK_ ((int) 0)
#define _OK_ ((int) 1)

// Prototipos de funciones
int validate_digit(char digit);
int char_to_int(char digit);

// Función principal
int main (void){
    // Variables locales
    char teclado[_Buff_Size] = {0};
    int  buffer[_Cant_Numeros] = {0};
    int i,k,j;
    
    // Solicitar los números
    printf("Ingrese %u numeros enteros: \n", _Cant_Numeros);
    fflush(stdin); // Limpio el buffer de entrada
    fgets(teclado, _Buff_Size, stdin); // Ingreso de datos
    
    // Parseo los datos
    for(i=0; (i<_Buff_Size) && (teclado[i]!='\n'); i++){

        // Verifico si es un número válido
        if(validate_digit(teclado[i])==_OK_) buffer[i] = char_to_int(teclado[i]);
        else{
            printf("Error: Caracter no valido: %c \n", teclado[i]);
            break;
        }
    }

    for(i=0; i<_Cant_Numeros; i++) printf("buffer[%u]: %d\n", i, buffer[i]);

    return 0;
}

// Función para validar un dígito
int validate_digit(char digit){
    
    // Verifico si es un número
    if(digit<='9' && digit>='0') return _OK_;

    else return _NOK_;
}

// Función para convertir un caracter a entero
int char_to_int(char digit){
    return ((int) (digit - '0'));
}