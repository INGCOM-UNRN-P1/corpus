
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int es_perfecto(int numero);

//pre: se necesita un numero entero
//post: se devuelve si un numero es perfecto o no

int main()
{
    int numero = 0;
    int retorno = 0;
    
    
    printf("\n");
    printf("-------------------------------------------------------------\n");
    printf("                      Números perfectos                      \n");
    printf("-------------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero para ver si es perfecto: ");
    scanf("%d",&numero);
    
    retorno = es_perfecto(numero);
    
    if(retorno == TRUE)
    {
        printf("El numero %d, es PERFECTO.",numero);
    }
    else
    {
        printf("El numero %d, es no es perfecto.",numero);
    }
    
}



int es_perfecto(int numero)
{
    int contador = 1;
    int suma = 0;
    int retorno = 0;
    
    while(contador < numero)
    {
        if ((numero % contador) == 0)
        {
            suma = suma + contador;//Aca sumo los divisores.
        }
        contador++;
    }
    
    if (suma == numero)
    {
        retorno = TRUE;
    }
    else
    {
        retorno = FALSE;
    }
    
    return retorno;   
}