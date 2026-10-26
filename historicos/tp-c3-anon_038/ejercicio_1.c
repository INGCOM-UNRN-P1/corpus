


#include <stdio.h>


typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion_t;




void imprimir_fraccion(fraccion_t frac_1, fraccion_t frac_2)
{
	int eleccion_2=0;
	
	printf("Si desea imprimir la primera fraccion ingrese 1, si desea imprimir la segunda ingrese 2 \n");
	scanf("%d", &eleccion_2);
	
	if (eleccion_2 == 1)
	{
		printf("%d / %d \n", frac_1.numerador, frac_1.denominador);
	}
	else if (eleccion_2 == 2)
	{
		printf("%d / %d \n", frac_2.numerador, frac_2.denominador);
	}
	else
	{
		printf("Ingreso un valor no valido \n");
	}
}


fraccion_t suma_fracciones(fraccion_t frac_1, fraccion_t frac_2)
{
	int numerador_1 = 0;
	int numerador_2 = 0;
	
	fraccion_t resultado_suma;
	
	numerador_1 = frac_1.numerador * frac_2.denominador;
	numerador_2 = frac_2.numerador * frac_1.denominador;
	
	resultado_suma.numerador = numerador_1 + numerador_2;
	resultado_suma.denominador = frac_1.denominador * frac_2.denominador;
	
	return resultado_suma; 
}



fraccion_t multiplicacion_fracciones(fraccion_t frac_1, fraccion_t frac_2)
{
	fraccion_t resultado_multiplicacion;
	
	resultado_multiplicacion.numerador = frac_1.numerador * frac_2.numerador;
	resultado_multiplicacion.denominador = frac_1.denominador * frac_2.denominador;
	
	return resultado_multiplicacion; 
}


int main()
{
	int eleccion_1 = 0;
	int eleccion_2 = 0;
	int eleccion_3 = 0;
	int eleccion_4 = 0;
	int eleccion_5 = 0;
	
	fraccion_t frac_1;
	fraccion_t frac_2;
	fraccion_t frac_entero = {.numerador=0, .denominador=1};
	fraccion_t resultado_suma;
	fraccion_t resultado_multiplicacion;
	fraccion_t resultado_suma_entero;
	
	frac_1.numerador = 0;
	frac_1.denominador = 0;
	
	frac_2.numerador = 0;
	frac_2.denominador = 0;

	printf("Ingrese el numerador de la primera fraccion \n");
	scanf("%d", &frac_1.numerador);
	
	printf("Ingrese el denominador de la primera fraccion \n");
	scanf("%d", &frac_1.denominador);
	
	printf("Ingrese el numerador de la segunda fraccion \n");
	scanf("%d", &frac_2.numerador);
	
	printf("Ingrese el denominador de la segunda fraccion \n");
	scanf("%d", &frac_2.denominador);
	
	
	
	printf("Si desea imprimir una fraccion en pantalla ingrese 1, sino ingrese 0 \n");
	scanf("%d", &eleccion_1);
	
	if (eleccion_1 == 1)
	{
		imprimir_fraccion (frac_1, frac_2);
	}
	else if(eleccion_1 == 0)
	{
		printf("No se ejecuta la IMPRESION \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
	}
	
	
	
	printf("Si desea realizar una suma entre fracciones, en pantalla ingrese 1, sino ingrese 0 \n");
	scanf("%d", &eleccion_2);
	
	if (eleccion_2 == 1)
	{
		resultado_suma = suma_fracciones(frac_1, frac_2);
		printf("Su suma de fracciones da %d / %d", resultado_suma.numerador, resultado_suma.denominador);
	}
	else if(eleccion_2 == 0)
	{
		printf("No se ejecuta la SUMA \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
	}

	
	
	printf("Si desea realizar una MULTIPLICACION entre fracciones, en pantalla ingrese 1, sino ingrese 0 \n");
	scanf("%d", &eleccion_3);
	
	if (eleccion_3 == 1)
	{
		resultado_multiplicacion = multiplicacion_fracciones(frac_1, frac_2);
		printf("Su multiplicacion de fracciones da %d / %d", resultado_multiplicacion.numerador, resultado_multiplicacion.denominador);
	}
	else if(eleccion_3 == 0)
	{
		printf("No se ejecuta la MULTIPLICACION \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
	}

	
	
	printf("Si desea realizar una SUMA entre una FRACCION y un numero ENTERO, en pantalla ingrese 1, sino ingrese 0 \n");
	scanf("%d", &eleccion_4);
	
	if (eleccion_4 == 1)
	{	
		printf("Que numero ENTERO desea sumar? \n");
		scanf("%d", &frac_entero.numerador);
		
		printf("Si desea SUMAR este numero ENTERO a la fraccion numero 1 (%d / %d), ingrese 1, pero si desea hacer la SUMA con la fraccion 2 (%d / %d), ingrese 2 \n", frac_1.numerador, frac_1.denominador, frac_2.numerador, frac_2.denominador);
		scanf("%d", &eleccion_5);
	
		if (eleccion_5 == 1)
		{
		resultado_suma_entero = suma_fracciones(frac_1, frac_entero);
		printf("Su SUMA da %d / %d \n", resultado_suma_entero.numerador, resultado_suma_entero.denominador);
		}
		else if(eleccion_5 == 2)
		{
			resultado_suma_entero = suma_fracciones(frac_2, frac_entero);
			printf("Su SUMA da %d / %d \n", resultado_suma_entero.numerador, resultado_suma_entero.denominador);
		}
		else
		{
			printf("Ingreso un valor no valido \n");
		}
	
	}
	else if(eleccion_4 == 0)
	{
		printf("No se ejecuta la SUMA \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
	}
}