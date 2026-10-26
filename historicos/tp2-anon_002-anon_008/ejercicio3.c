/*
3. Tabla de multiplicar
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

void tabla(int numero){
	int otro_numero;
	int contador;
	
	otro_numero = numero;
	contador = 1;
	
	while(contador <= 10){
		numero  = otro_numero * contador;
		printf("%d por %d es igual a %d \n", otro_numero, contador, numero);
		contador++;
	}

}

int main(){
	int numero;
	printf("Escriba un numero: ");
	scanf("%d",&numero);
	tabla(numero);
	
	return 0;
}

//precondicion: Se pide al usuario poner un numero el cual debe ser entero.
//poscondicion: El programa mostrará por pantalla la tabla de multiplicar de ese numero del 1 al 10.
