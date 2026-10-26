

#include <stdio.h>

   

int suma_lenta(int num1, int num2);
   
   
int main()
{
	int suma, num1, num2;
	printf("Ingrese un número: \n");
	scanf("%d",&num1);
	printf("Ingrese un segundo número: \n");
	scanf("%d",&num2);
	suma = suma_lenta(num1, num2);
	printf("Total suma: %d\n", suma);
	return 0;	   
}

int suma_lenta(int numero1, int numero2)

{
	int i;
	int resultado;
	
	for (i=0; i<=numero2; i++) {
		resultado=numero1 + i;
		}
	return resultado;
}