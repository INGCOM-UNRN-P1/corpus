
#include <stdio.h>
 
int main(int argc, char *argv[])
{   
    //Input de un numero y lo almacena en n
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    double num = n;//Almacena el numero fractorial.

    for (int i = n - 1; i > 0; i--)//Loop entre todos los numeros desde n hasta 0, multiplicandolos entre si.
    {
    num = num * i;
    }

    printf("El fractorial de %i! %0.f\n", n, num);
    
    return 0;
}