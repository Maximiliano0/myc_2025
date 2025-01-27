/************************************************************************************************
 * Ejercicio 1 - 2025                                                                           *
 * Escriba un programa que solicite 5 número enteros por teclado e imprima su valor medio.      *
 * Los 5 números deben estar separados por comas y ser signados hasta con 3 dígitos y su        *
 * ingreso realizarse en batch con la tecla enter. El programa debe imprimir en pantalla        *
 * los errores de ingreso cometidos por el usuario.                                             *
 ************************************************************************************************/

// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Macros
#define _DEBUG_ 1
#define _Buff_Size ((uint8_t) 128)
#define _Cant_Numeros ((uint8_t) 5)
#define _Digitos ((uint8_t) 3)

// Prototipos de funciones


// Función principal
int main (void){
    // Variables locales
    char teclado[_Buff_Size] = {0}, numero[_Digitos+2] = {0};
    int  data[_Cant_Numeros] = {0}, sum;
    uint8_t i,k,j, dummy;
    
    // Solicitar los números
    dummy = _Cant_Numeros;
    printf("Ingrese %u numeros enteros separados por comas: \n", dummy);
    fflush(stdin); // Limpio el buffer de entrada
    fgets(teclado, _Buff_Size, stdin); // Ingreso de datos
    
    // Parseo los datos
    for(j=0, i=0; i<_Buff_Size; i++){

        // Verifico si es un número ',' o '-'
        if((teclado[i]<='9' && teclado[i]>='0') || teclado[i]=='-' || teclado[i]==','){
            // Tomo números del teclado
            for(k=0;(k<_Digitos+1) && (teclado[i]!=',') && (teclado[i]!='\n'); k++, i++) numero[k] = teclado[i];
    
            // Verifico si el número no tiene ms digitos de los permitidos
            if(k>_Digitos){
                printf("Error: Numero con mas de %u digitos\n", _Digitos);
                break;
            }

            // Completo el string
            numero[k+1]='\0';
            // Lo guardo como entero
            data[j++] = atoi(numero);

            // Verifico si llego a un enter
            if(teclado[i]=='\n') break;
        } 
        else{
            printf("Error: Caracter no valido: %c \n", teclado[i]);
            printf("%d\n", i);
            break;
        }

        // Verifico si se ingresaron mas números de los permitidos
        if(j>_Cant_Numeros){
            printf("Error: Ingreso mas de %u numeros\n", _Cant_Numeros);
            break;
        }  

    }
    
    // Muestro los datos
    for(i=0; i<_Cant_Numeros; i++){
        printf("Numero %u: %d\n", i, data[i]);
    }

    // Calculo el promedio
    for(i=0, sum=0; i<j; i++) sum += data[i];
    printf("Promedio: %f\n", (float)(dummy/i));

}