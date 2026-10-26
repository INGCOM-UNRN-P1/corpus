/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>
 
unsigned int raiz_entero(int numero);

int main(int argc, char *argv[])
{
    int numero = 0;
    int resultado_n = 0;
    int resultado_m = 0;
    
    printf("Ingrese un numero (n) para calcular el resultado de una raiz (solo la parte entera): ");
    scanf("%d", &numero);
    
    resultado_n = raiz_entero(numero);
    printf("La raiz cuadrada de n es = %d\n", resultado_n);
    
    printf("Ingrese un numero (m) ");
    scanf("%d", &numero);
    
    resultado_m = raiz_entero(numero);
    printf("La raiz cuadrada de n es = %d\nLa raiz cuadrada de m es = %d", resultado_n, resultado_m);
    
    return 0;
}

unsigned int raiz_entero(int numero)
{
    int resultado = 0;
    int i = 0;
    
    while (resultado < numero)
    {
        i++;
        resultado = i*i;
    }
    
    if (resultado > numero)
    {
        i--;
    }
    return i;
}