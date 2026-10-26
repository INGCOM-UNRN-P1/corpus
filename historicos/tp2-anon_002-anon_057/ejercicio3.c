

#include <stdio.h>





void tabla_de_multiplicar(unsigned int numero)
{
    int i = 0;
    for (i = 0; i < 10 ; i++)
    {
        printf("%dx%d=%d\t", i, numero, i*numero);
    }
    printf("\n");
}


// Mucho sentido no tiene que se pueda ingresar un valor
// por lo que se arma la tabla completa para los digitos
// de siempre.
int main()
{
    for (int i = 0; i < 10 ; i++)
    {
        tabla_de_multiplicar(i);
    }
    return 0;
}
