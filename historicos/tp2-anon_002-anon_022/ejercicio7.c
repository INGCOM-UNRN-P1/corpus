




#include <stdio.h>




int suma_sucesiva (int numero1, int numero2) 
{
    int resultado = 0;
    int i;
    for ( i = 0;i < numero2;i++)
    {
        resultado = resultado + numero1;
    }
    return resultado;
}



int potencia_lenta (int base, int exponente) //realiza la potencia utilizando la suma sucesiva en vez de la multiplicacion
{
    int resultado = 1;
    int i = 0;
    if (exponente >= 0)
    {
        for (i; i < exponente; i++)
        {
            resultado = suma_sucesiva(resultado,base);
        }
    }
    return resultado;
}

int main()
{
   int base;
   int exponente;
   int resultado; 
   printf("Ingrese la base: \n");
   scanf("%d",&base);
   printf("Ingrese el exponente: \n");
   scanf("%d",&exponente);
   resultado = potencia_lenta(base, exponente);
   printf("El resultado de %d elevado a %d es %d\n",base,exponente,resultado);
   return 0;
}