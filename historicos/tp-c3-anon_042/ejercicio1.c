
#include <stdio.h>
typedef struct fraccion{ 
    int numerador;
    int denominador;
} fraccion_t;
void mostrar_fraccion(fraccion_t fraccion1) 
{
	
	int frac_int;
	if(fraccion1.numerador % fraccion1.denominador== 0){
		frac_int = fraccion1.numerador / fraccion1.denominador;
		printf("%d\n", frac_int);
	}
	else{
		printf("%d/%d\n",fraccion1.numerador, fraccion1.denominador);
	}
}
fraccion_t suma(fraccion_t fraccion1, fraccion_t fraccion2){ 
	
	fraccion_t resultado_s;
	resultado_s.denominador = fraccion1.denominador * fraccion2.denominador;
	resultado_s.numerador = (resultado_s.denominador / fraccion1.denominador) * fraccion1.numerador + (resultado_s.denominador / fraccion2.denominador) * fraccion2.numerador;
	return resultado_s;
}
fraccion_t multiplicacion(fraccion_t fraccion1, fraccion_t fraccion2){ 
	
	fraccion_t resultado_m;
	resultado_m.numerador = fraccion1.numerador * fraccion2.numerador;
	resultado_m.denominador = fraccion1.denominador * fraccion2.denominador;
	return resultado_m;
}
fraccion_t suma_entero(fraccion_t fraccion1, int numero){ 
	
	fraccion_t resultado_sn;
	resultado_sn.denominador = fraccion1.denominador;
	resultado_sn.numerador = fraccion1.numerador + (fraccion1.denominador * numero);
	return resultado_sn;
}
int main()
{	
	fraccion_t resultado_suma;
	fraccion_t resultado_multiplicacion;
	fraccion_t resultado_sumaentero;
	fraccion_t fraccion1;
	fraccion_t fraccion2;
	int numero;
	printf("Ingrese numerador: \n");
	scanf("%d", &fraccion1.numerador);
	printf("Ingrese denominador: \n");
	scanf("%d", &fraccion1.denominador);
	printf("\n");

	printf("Ingrese numerador 2: \n");
	scanf("%d", &fraccion2.numerador);
	printf("Ingrese denominador 2: \n");
	scanf("%d", &fraccion2.denominador);
	printf("Ingrese numero entero: \n");
	scanf("%d", &numero);
	printf("\n");
	
	printf("---Funcion para mostrar fraccion---\n");
	mostrar_fraccion(fraccion1);
	resultado_suma= suma(fraccion1, fraccion2);
	printf("---Funcion para mostrar el resultado de la suma---\n");
	mostrar_fraccion(resultado_suma);
	resultado_multiplicacion= multiplicacion(fraccion1, fraccion2);
	printf("---Funcion para mostrar el resultado de la multiplicacion---\n");
	mostrar_fraccion(resultado_multiplicacion);
	resultado_sumaentero= suma_entero(fraccion1, numero);
	printf("---Funcion para mostrar el resultado de la suma con entero---\n");
	mostrar_fraccion(resultado_sumaentero);
	return 0;
}