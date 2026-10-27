
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int A = 0; //almacena el número que da el usuario

    //chequea que el numero del usuario sea mayor que 100. si no lo es se produce un loop hasta que lo sea.
    while (A < 100)
    {
    printf("Ingrese un número entero mayor a 100: A = ");
    scanf("%d", &A);
    }

    for (int i = 2; i <= 6; i++) //Chequea mediante el loop que el numero sea multiplo de 2, 3, 4, 5 y 6.
    {
        if (A % i == 0)
        {
            printf("Es multiplo de %i: SI\n", i);
        } else
        {
            printf("Es multiplo de %i: NO\n", i);
        }
    }
    
    return 0;

}