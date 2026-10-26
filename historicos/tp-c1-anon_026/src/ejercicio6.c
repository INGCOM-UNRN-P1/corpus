

#include <stdio.h>


int division_lenta(int numero1, int numero2);
int cociente_lento(int numero1, int numero2);
   
int main()
{
	int num1;
	int num2;
	int cociente;
	int resto;
 	printf("Ingrese el dividendo: \n");
	scanf("%d", &num1);
	printf("Ingrese el divisor: \n");
	scanf("%d", &num2);
	cociente=cociente_lento(num1,num2);
	printf("El cociente es: %d\n", cociente);
	resto=division_lenta(num1,num2);
	printf("El resto es: %d\n", resto);
	return 0;
}


   

int division_lenta(int numero1, int numero2)
{
	int resto;
	resto = numero1;
	while (resto >= numero2){
		resto= resto - numero2;
	}		
	return resto;
		
}

  


int cociente_lento(int numero1, int numero2)
{
	int cociente;
	while (numero1 >= numero2){
		numero1= numero1 - numero2;
		cociente= cociente +1;
		
	}		
	return cociente;
	
}