/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>

int factorial(unsigned int n);

int main(int argc, char *argv[])
{
    unsigned int n = 0;
    while(n < 1) //chequea que el numero n sea natural
    {
        printf("Ingrese un numero n que sea natural: ");
        scanf("%d", &n);
    };

    printf("El fractorial de %i! %0.d\n", n, factorial(n));
    
    


}

int factorial(unsigned int n)
{

 double num = n;//Almacena el numero fractorial.

    for (int i = n - 1; i > 0; i--)//Loop entre todos los numeros desde n hasta 0, multiplicandolos entre si.
    {
        num = num * i;
    }
    
    return num;



}