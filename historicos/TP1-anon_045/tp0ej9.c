
#include <stdio.h>


int main(int argc, char *argv[])
{

	int num1;

	printf("Ingrese un numero n:\t");
	scanf("%d", &num1);	
		
	do
	{
		printf("El numero es menor a 100. \n \n");
		printf("Ingrese un numero n:\t");
		scanf("%d", &num1);	
	}
	while(num1<100);
	
	
}


