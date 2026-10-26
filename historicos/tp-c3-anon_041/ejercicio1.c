

#include <stdio.h>

typedef struct {
	int numerador;
	int denominador;
}fraccion_t;

void mostrar_fraccion(fraccion_t mostrar);
fraccion_t sumar_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2);
fraccion_t multiplicar_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2);
fraccion_t suma_con_entero(fraccion_t fraccion, int entero);

void mostrar_fraccion(fraccion_t mostrar)
{
	printf("%d/%d \n", mostrar.numerador, mostrar.denominador);
	return;
}

fraccion_t sumar_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2)
{
	fraccion_t suma;
	if (fraccion_1.denominador == fraccion_2.denominador)
	{
		suma.numerador = fraccion_1.numerador + fraccion_2.numerador;
		suma.denominador = fraccion_1.denominador;
	}
	else
	{
		suma.numerador = fraccion_1.numerador * fraccion_2.denominador + fraccion_2.numerador * fraccion_1.denominador;
		suma.denominador = fraccion_1.denominador * fraccion_2.denominador;
	}
	return suma;
}

fraccion_t multiplicar_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2)
{
	fraccion_t resultado;
	resultado.numerador = fraccion_1.numerador * fraccion_2.numerador;
	resultado.denominador = fraccion_1.denominador * fraccion_2.denominador;
	return resultado;
}

fraccion_t suma_con_entero(fraccion_t fraccion, int entero)
{
	fraccion_t suma_entero;
	suma_entero.numerador = fraccion.denominador * entero + fraccion.numerador;
	suma_entero.denominador = fraccion.denominador;
	return suma_entero;
}

int main()
{
	fraccion_t fraccion_1;
	fraccion_t fraccion_2;
	fraccion_t suma;
	fraccion_t multiplicacion;
	fraccion_t con_entero;
	int entero;
	int eleccion;
	
	printf("Para trabajar ingrese el numerador y denominador de la fraccion\n");
	printf("Numerador de la fracción:\n");
	scanf("%d", &fraccion_1.numerador);
	printf("Denominador de la fracción:\n");
	scanf("%d", &fraccion_1.denominador);
	printf("Primer fracción:\n");
	mostrar_fraccion(fraccion_1);
	printf("Ingrese la segunda fracción para hacer la suma o multiplicación:\n");
	printf("Numerador de segunda fracción:\n");
	scanf("%d", &fraccion_2.numerador);
	printf("Denominador de segunda fracción:\n");
	scanf("%d", &fraccion_2.denominador);
	printf("Segunda fracción:\n");
	mostrar_fraccion(fraccion_2);
	
	while (eleccion < 3)
	{
		printf("\n-----¿Cual operación desea realizar?-----\n(ingrese un numero mayor a 2 para que termine el programa)\n0.Suma de fracciones.\n1.Multiplicación de fracciones\n2.Sumar con un número entero\n:");
		scanf("%d", &eleccion);
		
		if(eleccion == 0)
		{
			suma = sumar_fracciones(fraccion_1, fraccion_2);
			printf("\nLa suma de fracciones es:\n");
			mostrar_fraccion(suma);
		}
	
		if (eleccion == 1)
		{
			multiplicacion = multiplicar_fracciones(fraccion_1, fraccion_2);
			printf("\nLa multiplicación de las fracciones es:\n");
			mostrar_fraccion(multiplicacion);
		}
	
		if (eleccion == 2)
		{
			printf("\nIngrese un número entero para sumarle a la primer fracción:\n");
			scanf("%d", &entero);
			con_entero = suma_con_entero(fraccion_1, entero);
			printf("\nLa suma con un número entero es:\n");
			mostrar_fraccion(con_entero);
		}
	}
	
	return 0;
}