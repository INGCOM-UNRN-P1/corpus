

#include <stdio.h>



int numero_deficiente(int numero)
{
    int i;
    int suma = 0;
    int verificacion;

    for(i = 1;i < numero; i++)
    {
        if(numero % i == 0)
        {
            suma = suma + i;
        }
    }
    
    if(suma < numero)
    {
        verificacion = 1;
    }
    else
    {
        verificacion = 0;
    }

    return verificacion;
}

int main()
{
    int numero;
    int resultado;

    printf("Ingrese un numero para verificar si es deficiente o no: \n");
    scanf("%d", &numero);

    resultado = numero_deficiente(numero);
    
    if(resultado == 1)
    {
        printf("El numero ingresado es deficiente.");
    }
    else
    {
        printf("El numero ingresado no es deficiente.");
    }

    return 0;
}