


#include <stdio.h>
#include <string.h>

typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion_t;

void mostrar_fracciones(fraccion_t frac) {
	
	printf("fracción: %d/%d\n", frac.numerador, frac.denominador);
}

fraccion_t suma_fracciones(fraccion_t fracc1, fraccion_t fracc2) {
	
	fraccion_t resultado;
	int hay_multiplo, i, multiplo, menor;
	
	if (fracc1.denominador == fracc2.denominador) {
		resultado.numerador = fracc1.numerador + fracc2.numerador;
		resultado.denominador = fracc1.denominador + fracc2.denominador;
	} else 
		resultado.numerador = (fracc1.numerador * fracc2.denominador) + (fracc2.numerador * fracc1.denominador);
		resultado.denominador = fracc1.denominador * fracc2.denominador;
	
	do
	{
		if(resultado.numerador < resultado.denominador) {
			menor = resultado.numerador;
		} else
			menor = resultado.denominador;

		i = 2;
		hay_multiplo = 0;
		while(i <= menor && hay_multiplo == 0) {
			if(resultado.numerador % i == 0 && resultado.denominador % i == 0) {
				multiplo = i;
				hay_multiplo = 1;
			}
			i++;
		}
		if(hay_multiplo == 1) {
			resultado.numerador = resultado.numerador/multiplo;
			resultado.denominador = resultado.denominador/multiplo;
		}
	} while(hay_multiplo == 1);
	
	return resultado;
}	

fraccion_t suma_fracciones_con_entero(fraccion_t fracc1, int num_entero) {
	
	fraccion_t resultado;
	int hay_multiplo, i, multiplo, menor;
	
	resultado.numerador = fracc1.numerador + (num_entero * fracc1.denominador);
	resultado.denominador = fracc1.denominador;
	
	do
	{
		if(resultado.numerador < resultado.denominador) {
			menor = resultado.numerador;
		} else
			menor = resultado.denominador;

		i = 2;
		hay_multiplo = 0;
		while(i <= menor && hay_multiplo == 0) {
			if(resultado.numerador % i == 0 && resultado.denominador % i == 0) {
				multiplo = i;
				hay_multiplo = 1;
			}
			i++;
		}
		if(hay_multiplo == 1) {
			resultado.numerador = resultado.numerador/multiplo;
			resultado.denominador = resultado.denominador/multiplo;
		}
	} while(hay_multiplo == 1);
	
	return resultado;
}	

fraccion_t multiplicacion_fracciones(fraccion_t fracc1, fraccion_t fracc2) {
	
	fraccion_t resultado;
	int hay_multiplo, i, multiplo, menor;
	
	resultado.numerador = fracc1.numerador * fracc2.numerador;
	resultado.denominador = fracc1.denominador * fracc2.denominador;
	
	if(resultado.numerador < 0 && resultado.denominador < 0) {
		resultado.numerador = resultado.numerador * -1;
		resultado.denominador = resultado.denominador * -1;
	} else if(resultado.denominador < 0) {
		resultado.numerador = resultado.numerador * -1;
		resultado.denominador = resultado.denominador * -1;
	} else
		;
	
	
	do
	{
		if(resultado.numerador < resultado.denominador) {
			menor = resultado.numerador;
		} else
			menor = resultado.denominador;

		i = 2;
		hay_multiplo = 0;
		while(i <= menor && hay_multiplo == 0) {
			if(resultado.numerador % i == 0 && resultado.denominador % i == 0) {
				multiplo = i;
				hay_multiplo = 1;
			}
			i++;
		}
		if(hay_multiplo == 1) {
			resultado.numerador = resultado.numerador/multiplo;
			resultado.denominador = resultado.denominador/multiplo;
		}
	} while(hay_multiplo == 1);
	
	return resultado;
}

int main()
{
	fraccion_t f1, f2, resultado;
	int entero;
	
	
	
	f1.numerador = 4;
	f1.denominador = 2;
	
	
	f2.numerador = 4;
	f2.denominador = 5;
	
	
	mostrar_fracciones(f1);
	
	mostrar_fracciones(f2);
	printf("\n");
	
	
	resultado = suma_fracciones(f1, f2);
	mostrar_fracciones(resultado);
	printf("\n");
	
	
	resultado = multiplicacion_fracciones(f1, f2);
	mostrar_fracciones(resultado);
	printf("\n");
	
	
	entero = 3;
	resultado = suma_fracciones_con_entero(f1, entero);
	mostrar_fracciones(resultado);
	
	return 0;
}
