
#include <stdio.h>


int main(int argc, char *argv[])
{
	int a = 1; 
	int b = 0;
	int num1;

	do
	{
		printf("Ingrese un numero entero mayor a 10:\t");
		scanf("%d", &num1);	
	}
	while(num1<10);

	printf("Los numeros de la sucesion de fibonacci menor a %d son: ",num1);

	while((b <= num1) || (a <= num1))
	{
		printf("%d ,",b);
		printf("%d ,",a);
		b = b + a;
		a = a + b;
	}
	
	
}


