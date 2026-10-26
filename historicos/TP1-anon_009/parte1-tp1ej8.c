/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{   
    
    int n;//almacena el numero del usuario
    
    //chequea que el numero del usuario sea mayor que 10. si no lo es se produce un loop hasta que lo sea.
    while (n < 10)
    {
    printf("Ingrese un número entero mayor a 100: n = ");
    scanf("%d", &n);
    }

    int num1 = 0;
    int num2 = 1;
    
    printf("Los números de la sucesión de Fibonacci menor a %i son: ", n);

    do //loop que suma dos numeros con el resultado de la suma de los mismos.
    {
       printf("%i, %i, ", num1, num2); 
       num1 = num1 + num2;
       num2 = num2 + num1;
    } while (num1 < n && num2 < n);

    printf("\n");

    return 0;
}