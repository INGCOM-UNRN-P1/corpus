
#include <stdio.h>


int main(int argc, char *argv[])
{
	int num1; 
	int num2;

	printf("Ingrese un numero entero:\t");
	scanf("%d", &num1);	
	
	do
	{
		printf("Ingrese un numero entero mayor a %d:\t",num1);
		scanf("%d", &num2);
	}
	while(num2 <= num1);
	
	for (int i=num1; i<(num2+1); i+=1)
	{

		printf("%d \n",i);

	}
	
}



