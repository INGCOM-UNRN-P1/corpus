
#include <stdio.h>
#include <stdlib.h>

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
    unsigned long long int resultado = combinatoria(n,m);
    printf("Combinatoria (%d,%d): %llu\n", n, m, resultado);
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
    else
    {
        res = 0;
    }

    return res;
}

unsigned long long combinatoria(int num1, int num2)
{
    int resta = num1 - num2;
    unsigned long long fact_n;
    unsigned long long fact_m;
    unsigned long long fact_resta;
    unsigned long long combinatoria = 0;
    if ((num1 > 0)&&(num2 > 0))
    {
        if (num2 <= num1)
        {
            fact_n = factorial(num1);
            fact_m = factorial(num2);
            fact_resta = factorial(resta);
            combinatoria = (fact_n /(fact_m*fact_resta));
        }
        else
        {
            printf("Error. El numero m es mayor a n \n");
        }
    }
    else
    {
        if(num1 <=0)
        {
            printf("Error: n no valido. n es menor a l \n");
        }
        else
        {
            printf("Error: m no valido. m es menor a 1 \n");	
        }
    }
    return combinatoria;
}