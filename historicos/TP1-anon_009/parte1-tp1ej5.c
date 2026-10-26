/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int A; //almacena el primer número
    int B; // almacena el segundo número

    //Input del priemer número
    printf("Primer número: ");
    scanf("%d", &A);

    //Input del segundo número
    printf("Segundo número: ");
    scanf("%d", &B);

    if (A > B) //Si el primer numero es mayor, hace un loop empezando desde el segundo y sumandole 1
    {
        for (int i = B; i <= A; i++)
        {
            printf("%i\n", i);
        }
    }
     else if (A < B) //Si el segundo numero es mayor, hace un loop empezando por el primero y sumandole 1
    {
        for (int i = A; i <= B; i++)
        {
            printf("%i\n", i);
        }
    } 
    else //Si los dos numeros son iguales lo imprime una vez
    {
        printf("%i\n", A);
    }

    return 0;

}