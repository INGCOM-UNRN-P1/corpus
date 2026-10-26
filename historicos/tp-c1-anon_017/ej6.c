/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int cociente();
int resto();


int main()
{
    int dividendo;
    int divisor;
    int rtdocociente;
    int rtdoresto;
    
    printf("ingrese el dividendo: ");
    scanf("%d",&dividendo);
    
    printf("ingrese el divisor: ");
    scanf("%d",&divisor);
    
    rtdocociente = cociente(dividendo, divisor);
    printf("\n El cociente es: %d \n", rtdocociente);
    
    rtdoresto = resto(dividendo, divisor);
    printf(" El resto  es: %d", rtdoresto);
}


int cociente(int dividendo, int divisor)
{
	int rtdocociente;
    if (divisor ==0)
    {
        return 0;
    }
    else
    {
        while (dividendo >= divisor)
        {
		dividendo = dividendo - divisor;
		rtdocociente = rtdocociente + 1;
        }
        return rtdocociente;
    }
	
}


int resto(int dividendo, int divisor)
{
    int rtdoresto;
    if (divisor ==0)
    {
        return 0;
    }
    else
    {
       while (dividendo >= divisor)
        {
		dividendo = dividendo - divisor;
		
        }
        rtdoresto = dividendo;
        return rtdoresto;
    }
	
}
