

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n_int;
    int cont;
    double n_double;
    double result;

    printf("Ingrese un valor numerico: \n");
    scanf("%d", &n_int);

    n_double = (double)n_int;
    cont = n_int-1;

    for (cont; cont > 0; cont--)
    {

        n_double = n_double * cont;
        
    }
    
    printf("El factorial de %d!: %.0lf \n", n_int, n_double);
    return 0;
}