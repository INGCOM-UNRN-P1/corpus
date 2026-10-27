
#include <stdio.h>
#include <stdlib.h>

int producto(int num1, int num2);
int potencia(int num1, int num2);

int main(int argc, char *argv[])
{
    int numero_uno;
    int numero_dos;
    printf("Ingrese primer numero mayor a 0: \n");
    scanf("%d",&numero_uno);
    printf("Ingrese segundo numero mayor a 0: \n");
    scanf("%d",&numero_dos);
    int res_producto = producto(numero_uno, numero_dos);
    int res_potencia = potencia(numero_uno, numero_dos);
    printf("El producto de %d y %d es: %d.\n", numero_uno,numero_dos, res_producto);
    printf("La potencia de %d y %d es: %d.\n", numero_uno,numero_dos, res_potencia);
    return 0;
}

int producto(int num1, int num2)
{
    int resultado = 0;
    if ((num1 > 0)&&(num2 > 0))
    {
        resultado = num1*num2;
    }
    else
    {
        printf("El numero ingresado no es valido \n");
    }
    return resultado;
}

int potencia(int num1, int num2)
{
    int i = 1;
    int resultado = num1;
    if ((num1 > 0)&&(num2 > 0))
    {
        while(i < num2)
        {
            resultado = resultado * num1;
            i++;
        }
    }
    else
    {
        printf("El numero ingresado no es valido \n");
    }
    return resultado;
}