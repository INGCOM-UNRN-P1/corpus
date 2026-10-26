


#include <stdio.h>
#define ERROR -1 





int suma_digitos(int numero) //recibe un numero y suma sus digitos
{
    int suma = 0;
    if (numero == 0) 
    {
        return -1;
    }
    while ( numero > 0)
    {
        suma = suma + numero % 10;
        numero = numero / 10;
    }
    return suma;
}
int main()
{
    int numero;
    int evaluar;
    printf("Ingrese el numero: \n");
    scanf("%d", &numero);
    if (numero < 0)
    {
        printf("Tiene que ingresar un numero entero positivo");
    }
    else 
    {
        evaluar = suma_digitos(numero);
        printf("La suma de los digitos del numero %d es %d",numero,evaluar);
    }    
    return 0;
}
