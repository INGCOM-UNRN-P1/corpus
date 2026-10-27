
#include <stdio.h>
#include <stdlib.h>

int raiz(int num);

int main(int argc, char *argv[])
{
    int num1;
    int num2;
    printf("Ingrese la raiz a calcular: \n");
    scanf("%d",&num1);
    printf("Ingrese la segunda raiz a calcular: \n");
    scanf("%d",&num2);
    int res_uno = raiz(num1);
    int res_dos = raiz (num2);
    printf("La parte entera de la raiz de %d es %d.\n", num1, res_uno);
    printf("La parte entera de la raiz de %d es %d.\n", num2, res_dos);
    return 0;
}

int raiz(int num)
{
    int resultado = 0;
    int lim = num*1000;
    if (num >0)
    {
        for(int i =1; i<=lim; i++)
            {
                int potencia = i*i;
                if (num == potencia)
                {
                    resultado = i;
                    break;
                }
                else if(num < potencia)
                {
                    resultado = i-1;
                    break;
                }
            }
    }
    else
    {
        printf("El numero ingresado no es valido");
    }
    return resultado;
}