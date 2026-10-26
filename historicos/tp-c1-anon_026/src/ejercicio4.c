

#include <stdio.h>

   

int compara(int num1, int num2);
   
int main()
{
	int comparacion;
	comparacion = compara(4,4);
	printf("Comparación: %d\n", comparacion);
	return 0;	   
}



int compara(int num1, int num2)   

{
	int suma;
	int resta;
	printf("Ingrese un número: \n");
	scanf("%d", &num1);
	printf("Ingrese otro número: \n");
	scanf("%d", &num2);
	suma = num1 + num2;
	resta = num1 - num2;
	
	if (((suma >0) && (resta >0)) || ((suma <0) && (resta >0))) {
		return 1;
		}
		else if (((suma > 0) && (resta <0)) || ((suma <0) && (resta <0))) {
			return -1;
		} 
		else {
			return 0;
		}	
	
	return 0;
}
	
