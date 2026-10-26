/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>


int main(int argc, char *argv[])
{
    int numero, factorial=1;// asigno las variables a usar, la variable factorial tiene asignado el valor 1 en caso de que se ingrese 0
    printf("Ingrese un numero para calcular su factorial:\t");
    scanf("%d", &numero);//input del numero al cual se le calculara el factorial

    //calculo de factorial
    for(int i = 1; i <= numero; i++)
        factorial *= i;

    printf("El factorial de %d es: %d! = %d\n", numero, numero, factorial);
    return 1;
}
