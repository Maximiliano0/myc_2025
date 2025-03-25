// Lirerias
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// Defines & Macros
#define _N 10

// Tipos de Datos
struct my_complex {
    int a;
    int b;
    //double modulo: 
    double (*modulo) (int a , int b );
};

// Prototipos de Funciones
double calc_modulo (int a, int b);

// Programa principal
int main (void){
    
    struct my_complex x;
    // Cargo el Numero
    x.a = 2;
    x.b = 2;
    x.modulo = calc_modulo; // asigno al puntero a función el código donde calcula el modulo

    // Imprimo el Numero
    printf("Numero Complejo: %d + %dj\n", x.a, x.b);

    // Calculo el Modulo
    //x.modulo = sqrt(pow(x.a, 2) + x.b * x.b);
    //printf("Modulo: %f\n", x.modulo);
    printf("Modulo: %f\n", x.modulo(x.a, x.b));

    return 0;
}

// Funciones
double calc_modulo (int a, int b){
    return sqrt(pow(a, 2) + b * b);
    //return sqrt(a * a + b * b);
}