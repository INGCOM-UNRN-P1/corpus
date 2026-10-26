
#include <stdio.h>

int producto(int num1, int num2);
int potencia(int num1, int num2);


int main(int argc, char *argv[])
{
	int num1;
	int num2;
	int resultado_producto;
	int resultado_potencia;
	
	
	printf("Ingrese un número: ");
	scanf("%d", &num1);
	
	printf("Ingrese otro número: ");
	scanf("%d", &num2);
	
	resultado_producto = producto(num1, num2);
	resultado_potencia = potencia(num1, num2);
	
	printf("\n Producto: %d",resultado_producto);
	printf("\n Potencia: %d",resultado_potencia);
	
}

int producto(int num1, int num2)
{
	int resultado = 0;
	
	for (int i = 0; i< num2; i++)
	{
		resultado += num1;
	}
	
	return resultado;
}

int potencia(int num1, int num2)
{
	int resultado = num1;
	
	for (int i = 1; i< num2; i++)
	{
		resultado = producto(resultado, num1);
	}
	
	return resultado;
}
