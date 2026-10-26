/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{   
    //Input de un numero y lo almacena en n
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    double num = n;//Almacena el numero fractorial de n.

    for (int i = n - 1; i > 0; i--)//Loop entre todos los numeros desde n hasta 0, multiplicandolos entre si.
    {
        num = num * i;
    }


    for(int i = n; i > 0; i--)//Loop entre todos los numeros, dividiendo al fractorial de n por todos los numeros de 0 a n.
    {
        printf("El fractorial de %i: %0.f\n", i, num);
        num = num / i;
    }
    
    
    
    return 0;
}