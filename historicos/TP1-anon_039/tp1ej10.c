
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int dia = 0;
	
	printf("Ingrese el numero del dia: ");
	scanf("%d", &dia);
	
	switch (dia)
	{
		case 1: printf(" 1 --> Lunes");
		break;
		case 2: printf(" 2 --> Martes");
		break;
		case 3: printf(" 3 --> Miercoles");
		break;
		case 4: printf(" 4 --> Jueves");
		break;
		case 5: printf(" 5 --> Viernes");
		break;
		case 6: printf(" 6 --> Sabado");
		break;
		case 7: printf(" 7 --> Domingo");
		break;
		default: printf("El numero %d no corresponde a ningun dia", dia);
	}
	return 0;
}