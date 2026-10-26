

#include <stdio.h>



int mayor_entre_tres(int numero, int segundo_numero, int tercer_numero)
{
    int mayor;

    if(numero > segundo_numero && numero > tercer_numero)
    {
        mayor = numero;
    }

    else if(segundo_numero > numero && segundo_numero > tercer_numero)
    {
        mayor = segundo_numero;
    }

    else
    {
        mayor = tercer_numero;
    }

    return mayor;
}

int main()
{
    int numero;
    int segundo_numero;
    int tercer_numero;
    int resultado;

    printf("Ingrese tres numeros enteros para saber cual es el mayor entre ellos:\n");
    printf("Primer numero: ");
    scanf("%d", &numero);
    printf("Segundo numero: ");
    scanf("%d", &segundo_numero);
    printf("Tercer numero: ");
    scanf("%d", &tercer_numero);

    resultado = mayor_entre_tres(numero, segundo_numero, tercer_numero);

    if(resultado == numero)
    {
        printf("El mayor es el primer numero ingresado.");
    }

    else if(resultado == segundo_numero)
    {
        printf("El mayor es el segundo numero ingresado.");
    }

    else
    {
        printf("El mayor es el tercer numero ingresado.");
    }
    
    return 0;
}