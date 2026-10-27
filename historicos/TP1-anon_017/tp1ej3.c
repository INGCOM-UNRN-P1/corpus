

#include <stdio.h>

int main()
{
	int numero1=0;
	int numero2=0;	
	int resultadomultiplicacion;
	float resultadodivision;
	int restodivision;
	{
	printf("ingrese el primer numero:");
	scanf("%d", &numero1);
	
	printf("ingrese el segundo numero:");
	scanf ("%d", &numero2);
    
	resultadomultiplicacion= (numero1*numero2);
	printf("el resultado de la multiplicacion es: %d \n", resultadomultiplicacion);
	
	resultadodivision=((float)numero1)/numero2;
	printf("el resultado de la division es %f \n", resultadodivision);
	
	restodivision=(numero1%numero2);
	printf("y el resto de la division es %d", restodivision);
		
	}
 
}
 
 