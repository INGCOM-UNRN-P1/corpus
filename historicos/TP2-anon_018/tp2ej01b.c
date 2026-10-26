/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>
int calcular_raiz(); 

int main(int argc, char *argv[])
{
	unsigned int numero, raiz = 1;
	printf("El siguiente programa calculara la raiz cuadrada de dos numeros ingresados.\n");
	printf("Ingrese un numero natural:");
	scanf("%d", &numero);
	raiz = calcular_raiz(numero);
	printf("La raiz cuadrada de %d es: %d\n", numero, raiz);
	printf("Ingrese otro numero natural:");
	scanf("%d", &numero);
	raiz = calcular_raiz(numero);
	printf("La raiz cuadrada de %d es: %d\n", numero, raiz);
	return 0;
}

int calcular_raiz(unsigned int numero)
{//esta funcion busca el numero que, elevado al cuadrado sea mas cercano
 //al numero ingresado
	int i, resultado, cuadrado = 1;
	if (numero < 2)
	{
		resultado = numero;
		return resultado;
	}
	for (i=1;cuadrado<numero;i++)
	{
		cuadrado = i * i;
		resultado = i;
	}//este for termina cuando el el valor del cuadrado es
	 //igual o mayor al numero ingresado
	if (cuadrado > numero)
	{
		resultado--;
	}
	//si el cuadrado es mayor al numero ingresado se le resta 1 al
	// resultado para llegar a la parte entera de la raiz
	return resultado;
}