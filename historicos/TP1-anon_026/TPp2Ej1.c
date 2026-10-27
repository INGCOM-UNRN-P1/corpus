

#include <stdio.h>

int main()
{
	int numero;
	printf("Ingrese un numero entre el 1 y 7 \n");
	scanf("%d", &numero);
	switch(numero){
		case 1: printf("Lunes"); break;
		case 2: printf("Martes"); break;
		case 3: printf("Miércoles"); break;
		case 4: printf("Jueves"); break;
		case 5: printf("Viernes"); break;
		case 6: printf("Sábado"); break;
		case 7: printf("Domingo"); break;
		default: printf("El numero no corresponde a un dia de la semana");
	}
	return 0;
}
