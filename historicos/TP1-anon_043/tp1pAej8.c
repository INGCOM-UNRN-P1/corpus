

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 3, n;

    // Inicializacion del primero, segundo y tercer termino.
    int t1 = 0, t2 = 1;
    int siguiente = t1 + t2;

    // Pide un numero y verifica que sea mayor a 10.
    printf("Ingrese un valor numerico mayor a 10: ");
    do
    {
        scanf("%d", &n);
        if (n < 10)
        {
            printf("El numero no es mayor a 10, intente de nuevo.");
        }

    } while (n < 10);
    
    // Se imprimen los primeros dos terminos pre definidos.
    printf("Los numeros de la sucesion de fibonacci menor a %d son: %d, %d, ", n, t1, t2);

    // Se imprimen el resto de los terminosa a partir del tercero.
    while (siguiente < n)
    {
        printf("%d, ", siguiente);
        t1 = t2;
        t2 = siguiente;
        siguiente = t1 + t2;
    }

    return 0;

}