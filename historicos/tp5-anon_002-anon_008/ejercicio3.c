/*
Ejercicio 3 - Fracciones
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>

typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion_t;

void mostrar_fraccion(fraccion_t fraccion);
fraccion_t suma_fracciones(fraccion_t fraccion1, fraccion_t fraccion2);
fraccion_t multiplicacion_fracciones(fraccion_t fraccion1, fraccion_t fraccion2);
fraccion_t suma_num_entero (fraccion_t fraccion1);

int main(){
	fraccion_t fraccion1,fraccion2,resultado;
	
	printf("Introduce el numerador de la primera fraccion: ");
	scanf("%d",&fraccion1.numerador);
	printf("Introduce el denominador de la primera fraccion: ");
	scanf("%d",&fraccion1.denominador);
	
	printf("\nIntroduce el numerador de la segunda fraccion: ");
	scanf("%d",&fraccion2.numerador);
	printf("Introduce el denominador de la segunda fraccion: ");
	scanf("%d",&fraccion2.denominador);
	
	printf("Fraccion 1:\n");
    mostrar_fraccion(fraccion1);
    
    printf("\nFraccion 2:\n");
    mostrar_fraccion(fraccion2);
    
    resultado = suma_fracciones(fraccion1, fraccion2);
    printf("\nSuma de fracciones:\n");
    mostrar_fraccion(resultado);
    
    resultado = multiplicacion_fracciones(fraccion1, fraccion2);
    printf("\nMultiplicacion de fracciones:\n");
    mostrar_fraccion(resultado);
    
    resultado = suma_num_entero (fraccion1);
    printf("\nSuma con numero entero:\n");
    mostrar_fraccion(resultado);
    
	
	return 0;
}

void mostrar_fraccion(fraccion_t fraccion) {
    printf(" %d\n", fraccion.numerador);
    printf("---\n");
    printf(" %d\n",fraccion.denominador);
    
}

fraccion_t suma_fracciones(fraccion_t fraccion1,fraccion_t fraccion2){
	int denominador, numerador, aux1, aux2;
	fraccion_t resultado;
	resultado.denominador = fraccion1.denominador * fraccion2.denominador;
	
	aux1 = fraccion1.numerador * fraccion2.denominador;
	aux2 = fraccion2.numerador * fraccion1.denominador;
	resultado.numerador = aux1 + aux2;
	
	return resultado;
}

fraccion_t multiplicacion_fracciones(fraccion_t fraccion1, fraccion_t fraccion2){
	fraccion_t resultado;
	
	resultado.numerador = fraccion1.numerador * fraccion2.numerador;
	resultado.denominador = fraccion1.denominador * fraccion2.denominador;
	
	return resultado;
}

fraccion_t suma_num_entero(fraccion_t fraccion1) {
    int num;
    printf("\nEscriba el numero entero a sumar (Se sumara a la primera fraccion): ");
    scanf("%d", &num);

    fraccion_t numero_entero;
    numero_entero.numerador = num;
    numero_entero.denominador = 1;

    return suma_fracciones(fraccion1, numero_entero);
}

//Precondiciones:
//Se espera que el usuario ingrese dos fracciones válidas en el formato de numerador y denominador para la primera y la segunda fracción.
//El denominador de ambas fracciones no debe ser cero.
//Se espera que el usuario ingrese un número entero para la suma con número entero.
//El programa se ejecuta sin errores o fallas en la lectura de entrada.

//Postcondiciones:
//Después de la ejecución, el programa muestra la primera fracción ingresada por el usuario.
//Luego, muestra la segunda fracción ingresada por el usuario.
//Calcula la suma de las dos fracciones ingresadas y muestra el resultado.
//Calcula la multiplicación de las dos fracciones ingresadas y muestra el resultado.
//Solicita al usuario ingresar un número entero y luego calcula la suma de ese número entero con la primera fracción y muestra el resultado.
//El programa finaliza sin errores.


