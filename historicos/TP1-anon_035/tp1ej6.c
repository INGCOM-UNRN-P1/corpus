/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int compara_fechas(char primera, char segunda)
{
	int valor;
	
	if(primera == segunda)
	{
		valor = 0;
		
	}
	
	return valor;
}



int main()
{
	
    char  cadena1, cadena2;
	int resultado;
	
	printf("Ingrese primera fecha formato dia/mes/anio \n");
	
	scanf("%c" , &cadena1);
	
	printf("Ingrese segunda fecha formato dia/mes/anio \n");
	
	scanf("%c" , &cadena2);
	
	resultado = compara_fechas(cadena1, cadena2);
	
	printf("El retorno es: %d", resultado);
	
    return 0;
}