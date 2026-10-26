
#include <stdio.h>

float litros_a_galones(float litros);
float galones_a_litros(float galones);
float kilometros_a_millas(float kilometros);
float millas_a_kilometros(float millas);

//pre: se necesita un numero entero
//post: se opera con el numero entero e imprime el resultado de la operacion

int main()
{
    int numero = 0;
    int opcion = 0;
    float respuesta = 0;
    
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("                      Freedom units                      \n");
    printf("---------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese 1 para pasar de litros a galones\n");
    printf("Ingrese 2 para pasar de galones a litros\n");
    printf("Ingrese 3 para pasar de kilometors a millas\n");
    printf("Ingrese 4 para pasar de millas a kilometors\n");
    
    printf("Opcion: ");
    scanf("%d",&opcion);
    
    printf("Ingrese el valor que quiere convertir: ");
    scanf("%d",&numero);
    
    if(opcion == 1)
    {
        respuesta = litros_a_galones(numero);
        printf("La conversion de litros a galones fue de: %f galones",respuesta);
    }
    else if (opcion == 2)
    {
        respuesta = galones_a_litros(numero);
        printf("La conversion de galones a litros fue de: %f litros",respuesta);
    }
    else if (opcion == 3)
    {
        respuesta = kilometros_a_millas(numero);
        printf("La conversion de kilometros a millas fue de: %f millas",respuesta);
    }
    else if (opcion == 4)
    {
        respuesta = millas_a_kilometros(numero);
        printf("La conversion de millas a kilometros fue de: %f kilometros",respuesta);
    }
    else
    {
        printf("No es una opcion!!");
    }
}



float litros_a_galones(float litros)
{
    float total = 0;
    
    total = litros / 3.785;//para obtener un resultado aproximado, divide el valor de volumen entre 3.785
    
    return total;
}



float galones_a_litros(float galones)
{
    float total = 0;
    
    total = galones * 3.785;//para obtener un resultado aproximado, multiplica el valor de volumen por 3.785
    
    return total;
}



float kilometros_a_millas(float kilometros)
{
    float total = 0;
    
    total = kilometros / 1.609;//para obtener un resultado aproximado, divide el valor de longitud entre 1.609

    return total;
}




float millas_a_kilometros(float millas)
{
    float total = 0;
    
    total = millas * 1.609;//para obtener un resultado aproximado, multiplica el valor de longitud entre 1.609

    return total;
}
