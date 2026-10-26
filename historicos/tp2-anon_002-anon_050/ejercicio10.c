

#include <stdio.h>


double litros_a_galones(double litros)
{
    return litros * 0.264172;
}


double galones_a_litros(double galones)
{
    return galones * 3.78541;
}


double millas_a_kilometros(double millas)
{
    return millas * 1.60934;
}


double kilometros_a_millas(double kilometros)
{
    return kilometros * 0.621371;
}

int main()
{
    double valor;

    printf("Ingrese el valor a comprobar: \n");
    scanf("%lf", &valor);

    printf("%.2f litros son %.2f galones US.\n", valor, litros_a_galones(valor));

    printf("%.2f galones US son %.2f litros.\n", valor, galones_a_litros(valor));

    printf("%.2f millas son %.2f kilómetros.\n", valor, millas_a_kilometros(valor));

    printf("%.2f kilómetros son %.2f millas.\n", valor, kilometros_a_millas(valor));
    
    return 0;
}
