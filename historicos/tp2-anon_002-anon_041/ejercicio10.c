

#include <stdio.h>



float conversion_litros_galones(float numero, int tipo)
{
    float litro_a_galon = 0.264172;
    float galon_a_litro = 3.78541;
    float resultado = 0;

    if(tipo == 1)
    {
        if(numero < 1)
        {
            resultado = litro_a_galon;
        }
        else
        {
            resultado = litro_a_galon * numero;
        }
    }
    else if(tipo == 2)
    {
        if(numero < 1)
        {
            resultado = galon_a_litro;
        }
        else
        {
            resultado = galon_a_litro * numero;
        }
    }

    return resultado;
}



float conversion_millas_kilometros(int numero, int tipo)
{
    float kilometro_a_milla = 0.621371;
    float milla_a_kilometro = 1.60934;
    float resultado = 0;

    if(tipo == 3)
    {
        if(numero < 1)
        {
            resultado = kilometro_a_milla;
        }
        else
        {
            resultado = kilometro_a_milla * numero;
        }
    }
    else if(tipo == 4)
    {
        if(numero < 1)
        {
            resultado = milla_a_kilometro;
        }
        else
        {
            resultado = milla_a_kilometro * numero;
        }
    }

    return resultado;
}

int main()
{
    float numero;
    int tipo;
    float resultado;

    printf("Que desea convertir?\n1: Litros a galones.\n2: Galones a litros.\n3: Kilometros a millas.\n4: Millas a kilometros.\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &tipo);

    switch (tipo)
    {
        case 1:
            printf("Ingrese el numero a convertir: ");
            scanf("%f", &numero);
            resultado = conversion_litros_galones(numero, tipo);
            break;

        case 2:
            printf("Ingrese el numero a convertir: ");
            scanf("%f", &numero);
            resultado = conversion_litros_galones(numero, tipo);
            break;

        case 3:
            printf("Ingrese el numero a convertir: ");
            scanf("%f", &numero);
            resultado = conversion_millas_kilometros(numero, tipo);
            break;

        case 4:
            printf("Ingrese el numero a convertir: ");
            scanf("%f", &numero);
            resultado = conversion_millas_kilometros(numero, tipo);
            break;
    }

    printf("El resultado de la conversion es %f.", resultado);

    return 0;
}