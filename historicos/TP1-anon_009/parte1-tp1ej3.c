/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{   
    int A; //almacena el primer número entero
    int B; //almacena el segundo número entero
   
    //Input del primer número
    printf("Ingresa un número entero: A = ");
    scanf("%d", &A);


    //Input del segundo número
    printf("Ingresa otro número entero: B = ");
    scanf("%d", &B);

    printf("Operador multiplicación: A*B = %i\n", (A*B));

    float C = (float) A;//Crea una variable float C con la int A para poder hacer las divisiones más precisas
    printf("Operador división: A/B = %.2f\n", (C/B));
    
    printf("Operador resto: A%cB = %i\n", '%', (A % B));
    
    return 0;
}