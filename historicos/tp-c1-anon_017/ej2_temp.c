/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>       

double convertir_a_fahrrenheit(); 
double convertir_a_centigrados();


int main()
{
    int seleccion;
    double temperatura;
    double respuesta;
    double resultado;
    printf("ingrese 1 si desea pasar de farenheit a centigrados o 2 si desea pasar de centigrados a farenheit: \n"); 
    scanf("%d",&seleccion); 
    
    if (seleccion == 1)
    {
        printf("ingrese la temperatura en F° para convertir a C°: ");
        scanf("%lf",&temperatura); 
        
        
        respuesta = convertir_a_centigrados(temperatura);  
        printf("el resultado es: %f C°. \n ",respuesta); 
    } 
    else if (seleccion == 2)
    {
        printf("ingrese la temperatura en C° para convertir a F°: ");
        scanf("%lf",&temperatura); 
        
        respuesta = convertir_a_fahrrenheit(temperatura);  
        printf("el resultado es : %f F°. \n",respuesta); 
    }
    else
    {
        printf("El numero %d no corresponde a ninguna opcion.\n", seleccion); 
    }
}


double convertir_a_fahrrenheit(double temperatura)
{
    double respuesta = 0;
    respuesta= (temperatura * 9/5) + 32; 
    return respuesta;  
}


double convertir_a_centigrados(double temperatura)
{
    double respuesta = 0;
    respuesta=(temperatura - 32) * 5/9; 
    return respuesta; 
    
}