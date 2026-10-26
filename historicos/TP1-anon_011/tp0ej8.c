/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){
	
	int num_ingresado, primer_num, segundo_num, resultado;
	
	do
	{
		printf("ingrese un numero mayor a 10: ");
		scanf("%d", &num_ingresado);
		if(num_ingresado < 10){
			printf("recuerde ingresar un numero mayor a 10\n");
		}
	}
	while(num_ingresado < 10);	
	
	
	primer_num = 0;
	segundo_num = 1;
	resultado = 0;
	
	printf("%d, %d", primer_num, segundo_num);
	
	while(resultado <= num_ingresado) {
		resultado = primer_num + segundo_num;
		primer_num = segundo_num;
		segundo_num = resultado;
		if (resultado <= num_ingresado) {
			printf(", %d", resultado);
		}
	}
	return 0;
}