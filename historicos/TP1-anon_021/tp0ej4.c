
#include <stdio.h>
 
int main(int argc, char *argv[])
{

int numero,resta,clon;

printf("\n Ingrese un numero entero mayor a 100:\n      ");

scanf("%d",&numero);

while(numero <= 100)
{
	
	printf(" repito, el valor deve ser mayor a 100:\n       ");
	
	scanf("%d",&numero);
	
}

clon = numero;

resta = 2;

while (resta <= 6)
{
	
	clon = clon - resta;
	
	if (clon == 0)
	{
		
		printf("\n %d Multiplo de %d : SI\n",resta,numero);

		clon = numero;
		
		resta = resta + 1;
		
	}
	else if(clon < 0)
	{
		
		printf("\n %d Multiple de %d : NO\n",resta,numero);
		
		clon = numero;
		
		resta = resta + 1;
		
	}
	
}	
	
return 0;
}
