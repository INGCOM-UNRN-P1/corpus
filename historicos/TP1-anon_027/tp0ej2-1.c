#include <stdio.h>
#include <locale.h>

int main()
{
	
	setlocale(LC_ALL, "spanish");
	
	int dia;
	printf("Ingrese número de dia (1-7):\n");
	scanf("%d", &dia);
	
	switch(dia)	
	{
		case 1: printf("Lunes");
			break;
		case 2: printf("Martes");
			break;
		case 3: printf("Miercoles");
			break;
		case 4: printf("Jueves");
			break;
		case 5: printf("Viernes");
			break;
		case 6: printf("Sabado");
			break;
		case 7: printf("Domingo");
			break;
		default: printf("Número incorrecto");
				
	}
	
	return 0;
}


