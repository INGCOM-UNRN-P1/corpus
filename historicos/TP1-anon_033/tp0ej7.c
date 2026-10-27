
#include <stdio.h>

int main(int argc, char *argv[])
{
    int num,cont;
	unsigned long long factorial = 1;

	printf("Ingrese su numero entero: ");
	scanf("%d",&num);
	cont=num;
	while(num >= 1)
    {
        cont=num;
		while(cont>=1)
        {
            factorial=factorial*cont;
			cont--;
			}
			printf("El factorial de %d! es: %llu.\n",num,factorial);
			num--;
			factorial = 1;
	}
	return 0;
}
