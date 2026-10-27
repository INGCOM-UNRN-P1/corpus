

#include <stdio.h>



int main()
{
int n;
printf("Ingrese un numero n:  ");
scanf("%d", &n);

while(n<100)
	{
	printf("El numero es menor a 100 \n"); 
	printf("Ingrese otro número: \n");
	scanf("%d", &n);
	}
	return 0;
	}

