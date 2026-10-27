

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n_int;
    int cont;
    int cont2;
    double n_double;
    double n_double2;

    printf("Ingrese un valor numerico: \n");
    do
    {
        scanf("%d", &n_int);
    } while (n_int < 0);
    

    n_double = (double)n_int;
    n_double2 = n_double;
    cont = n_int;
    cont2 = n_int-1;

    for (cont; cont > 0; cont--)
    {
        cont2 = cont-1;

        for (cont2; cont2 > 0; cont2--)
        {
            
            n_double2 = n_double2 * cont2;
            
        }

        printf("El factorial de %d! es: %.0lf \n", cont, n_double2);
        
        n_double = n_double - 1;
        n_double2 = n_double;

    }

    return 0;

}