/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
 
unsigned multiplicacion(unsigned numero, unsigned otronumero);

unsigned potencia(unsigned numero, unsigned otronumero);
 
int main(int argc, char *argv[])
{
	
    unsigned numero,otronumero, resultado;

    printf("\nIngrese1 valor entero :  ");

    scanf("%d",&numero);

    printf("\nIngrese1 otro valor entero :  ");

    scanf("%d",&otronumero);

    resultado = multiplicacion(numero, otronumero);

    printf("\n\n %d x %d = %d | ",numero,otronumero, resultado);

    resultado = potencia(numero, otronumero);

    printf("%d^%d = %d \n\n ",numero,otronumero, resultado);

    return 0;
}

unsigned multiplicacion(unsigned numero, unsigned otronumero){
	
    unsigned contador, resultado;

    resultado = 0;

    contador = 0;
	
    while (contador < otronumero){
	
        contador += 1;
	
        resultado = resultado + numero;
    }	

    return resultado;
}

unsigned potencia(unsigned numero, unsigned otronumero){

    unsigned contador, resultado,contadorpotencia, cantidad;

    resultado = 0;

    contador = 1;
	
    cantidad = numero;

    while (contador < otronumero){
	
        contador += 1;
	
        contadorpotencia = 0;
	
        while (contadorpotencia < cantidad){
		
            contadorpotencia += 1;
		
            resultado = resultado + numero;
		
        }

        cantidad = resultado;
	
        if(contador < otronumero){
		
            resultado = 0;
		
        }
    }	

    return resultado;
}