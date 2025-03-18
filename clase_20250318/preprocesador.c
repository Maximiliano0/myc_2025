#include "stdio.h"
#include "stdlib.h"

// Macro
#define _Buffer_Size ((unsigned int) 10) 
#define _Mi_Macro(x) (x++);
#define _Si_Par(x) ((x%2)? 0:1)
#define _Multiplico(x,y) (x*y)


int main(void){
    int aux=0;

    // Define
    printf("Buffer size: %u\n", _Buffer_Size);
    printf("Buffer size: %u\n", ((unsigned int) 10 ));
    // NNo se puede
    // _Buffer_Size = 10;
    // ((unsigned int) 10 ) = 10;

    // Macro
    _Mi_Macro(aux)
    // Compila como (aux++);
    printf("Aux: %d\n", aux);

    // Ejemplo de una macro util
    aux = 2;
    if(_Si_Par(aux) == 1){
        printf("Es par\n");
    }else{
        printf("Es impar\n");
    }

    // Imprimo
    printf("Multiplico: %d\n", _Multiplico(2,3));

    return 0;
}