
#include <stdio.h>

int multiplicacion(int num1, int num2);
int division(int num1, int num2);
int resto(int num1, int num2);

int main(int argc, char *argv[])
{
	int num1; 
	int num2;
	int mult;
	int div;
	int res;
	
	printf("Ingrese un numero:\t");
    scanf("%d", &num1);
	
	printf("Ingrese otro numero:\t");
	scanf("%d", &num2);
	
	printf("El primer numero es: %d \n",num1);
	printf("El segundo numero es: %d \n",num2);
	
	mult = multiplicacion(num1,num2);
	div = division(num1,num2);
	res = resto(num1,num2);
	
	printf("Multiplicacion: %d \n",mult);
	printf("Division: %d \n",div);
	printf("Resto: %d \n",res);
	
}

int multiplicacion(int num1, int num2)
{
	int resultado = 0;
	
	resultado = num1 * num2;
	
	return resultado;
}

int division(int num1, int num2)
{
	int resultado = 0;
	
	resultado = num1 / num2;
	
	return resultado;
}

int resto(int num1, int num2)
{
	int resultado = 0;
	
	resultado = num1 % num2;
	
	return resultado;
}
