



#include <stdio.h> 

float convertir_a_celsius(fahrenheit){
    return (fahrenheit -32)/1.8;
}

float convertir_a_fahrenheit(celsius){
    return (celsius*1.8) + 32;
}


int main(){
    float fahrenheit = 0;
    float celsius=0;
    float resultado=0;
    int opcion= 0;
    printf("Elija una opcion,1 para convertir de F a C, o 2 para convertir de C a F: \n");
    scanf("%d", &opcion);
    if (opcion == 1)
        {
        printf("Ingrese la temperatura en Fahrenheit: \n");
        scanf("%f", &fahrenheit);
        resultado = convertir_a_celsius(fahrenheit);
        printf("La temperatura convertida de Fahrenheit a Celsius es: %.2f C\n", resultado);
        }
         else if(opcion == 2)
         {
            printf("Ingrese la temperatura en Celsius: \n");
            scanf("%f", &celsius);
            resultado = convertir_a_fahrenheit(celsius);
            printf("La temperatura convertida de Celsius a Fahrenheit es: %.2f F\n ", resultado);
            }
    return 0;
}
    


