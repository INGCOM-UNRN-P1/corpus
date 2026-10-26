

#include <stdio.h>



int menor_entre_tres(int numero, int segundo_numero, int tercer_numero)
{
    int menor;

    if(numero < segundo_numero && numero < tercer_numero)
    {
        menor = numero;
    }

    else if(segundo_numero < numero && segundo_numero < tercer_numero)
    {
        menor = segundo_numero;
    }

    else
    {
        menor = tercer_numero;
    }

    return menor;
}

int main()
{
    int numero;
    int segundo_numero;
    int tercer_numero;
    int resultado;

    printf("Ingrese tres numeros enteros para saber cual es el menor entre ellos:\n");
    printf("Primer numero: ");
    scanf("%d", &numero);
    printf("Segundo numero: ");
    scanf("%d", &segundo_numero);
    printf("Tercer numero: ");
    scanf("%d", &tercer_numero);

    resultado = menor_entre_tres(numero, segundo_numero, tercer_numero);

    if(resultado == numero)
    {
        printf("El menor es el primer numero ingresado.");
    }

    else if(resultado == segundo_numero)
    {
        printf("El menor es el segundo numero ingresado.");
    }

    else
    {
        printf("El menor es el tercer numero ingresado.");
    }
    
    return 0;
}