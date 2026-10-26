#include<stdio.h>
#include<stdlib.h>

int suma_lenta(int numero, int otro_numero)
{
    int resultado = numero + otro_numero;//
    printf("%d\n", numero);
    while(numero < resultado)//condicion donde el numero tiene que ser menor al resultado    
    {
        int i = 1;        
        printf("+%d\n", i);
        numero = numero + 1;//a numero se le suma 1 en cada vuelta hasta llegar al valor del resultado
    }
    return resultado;
    
}

int resta_lenta(int numero, int otro_numero) 
{
    int resultado = numero - otro_numero;
    printf("%d\n", numero);
    
    while (numero > resultado) 
    { // La condición debe ser numero > resultado
        int i = 1;
        printf("-%d\n", i);
        numero = numero - 1; // Deberías estar incrementando numero, no decrementándolo
    }
    
    return resultado;
}

int multiplica_lenta(int factor1, int factor2) 
{
    int resultado = 0;
    
    while (factor2 >= 1) 
    {
        resultado  = resultado + factor1;
        printf("%d\n", resultado);
        factor2 --;
    }
    
    return resultado;
}

int division_lenta(int dividendo, int divisor) {
    int resto = dividendo;
    printf("Division lenta: %d\n", dividendo);
    
    while (resto >= divisor) {
        resto = resto - divisor;
        printf("%d\n", resto);
    }
    
    return resto;
}