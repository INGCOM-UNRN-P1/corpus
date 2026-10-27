
#include <stdio.h>

int multiplo();
int resto();



int main()
{
    int numero1;
    int numero2;
    int respuesta;
    
    printf("ingrese el primer numero: ");
    scanf("%d",&numero1);
    
    printf("ingrese el segundo numero: ");
    scanf("%d",&numero2);
    
    respuesta = multiplo(numero1, numero2); 
    if (respuesta == 1)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    
    
    
}
 

int multiplo(int numero1, int numero2)
{
    float resultado;
    int auxiliar;
    int true = 0;
    int false = 0;
    
    if (numero1 < numero2)
    {
        auxiliar = numero1;
        numero1 = numero2;
        numero2= auxiliar;
    }
    resultado = resto(numero1,numero2);
    if (resultado ==0)
    {
        true = 1;
        return true; 
    }
    else
    {
        false = 0;
        return false; 
    }
}




int resto(int dividendo, int divisor) 
{
    int rtdoresto;
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		
	}
    rtdoresto = dividendo;
	return rtdoresto;
 
}
