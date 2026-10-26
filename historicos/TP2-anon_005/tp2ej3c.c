/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 3 - Parte 3: Mostrar cada termino combinatorio
*************************/
#include <stdio.h>
#include <stdlib.h>

unsigned long long int mostrar_combinatoria(int num, int m);
unsigned long long int combinatoria(int num1, int num2);
unsigned long long int factorial(int num);

int main(int argc, char *argv[])
{
    int n;
    int m;
    printf("Ingrese valor de n (mayor a 0): \n");
    scanf("%d",&n);
    printf("Ingrese valor de m (mayor a 0): \n");
    scanf("%d",&m);
    printf("n: %d\n", n);
    printf("m: %d\n", m);
    mostrar_combinatoria(n,m);

    return 0;
}

unsigned long long int factorial(int num)
{
    int i;
    unsigned long long int res=1;
    if (num >= 1)
    {
        for (i = 1; i < num+1; i++)
        {
            res = res*i;
        }
    }
    return res;
}

unsigned long long int combinatoria(int num1, int num2)
{
    int resta = num1 - num2;
    unsigned long long int fact_n;
    unsigned long long int fact_m;
    unsigned long long int fact_resta;
    unsigned long long int combinatoria = 0;

    if ((num1 > 0)&&(num2 > 0))
    {
        if (num2 <= num1)
        {
            fact_n = factorial(num1);
            fact_m = factorial(num2);
            fact_resta = factorial(resta);
            combinatoria = (fact_n /(fact_m*fact_resta));
        }
    }
    
    return combinatoria;
}

unsigned long long int mostrar_combinatoria(int num, int m)
{
    unsigned long long int termino;
    if(num<=0)
    {
        printf("Error: n no valido. n es menor a l \n");
    }
    else if(m<=0)
    {
        printf("Error: m no valido. m es menor a l \n");
    }
    else if(m>num)
    {
        printf("Error. El numero m es mayor a n \n");
    }
    else
    {
        for(int i =1; i<=m; i++)
        {
            termino = combinatoria(num, i);
            printf("(%d,%d)!= %llu\n", num, i, termino);	
        }
    }
    return termino;
}