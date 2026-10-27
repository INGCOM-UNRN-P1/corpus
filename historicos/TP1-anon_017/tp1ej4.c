

#include <stdio.h>

int main()

{ 
	int numero=0;
	int contador=6;
	int auxiliar;
	printf("ingrese un numero entero mayor a 100: ");
	scanf("%d", &numero);
  
	if(numero>100)
	{
		while(contador<=6)
		{
		auxiliar=numero%contador;
			if(auxiliar==0)	
			{
			printf("es multiplo de %d\n",contador);
		
			}	
			else
			{
			printf("no es multiplo de %d\n",contador);
		
			}	
		contador = contador-1;
		}
	}
	else 
	{
	 printf("Tiene que ser un numero entero mayor a 100!!");
	}
}