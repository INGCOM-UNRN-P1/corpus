
#include <stdio.h>

int semana(int dia);
int main(int argc, char *argv[])
{
	int dia;
	int resultado;
	printf("Ingrese un dia de la semana en numero entero: \n");
	scanf("%d", &dia);
	resultado= semana(dia);
	return resultado;
}

int semana(int dia)
{
	switch(dia)
	{
		case 1: printf("El dia %d es Lunes", dia);
		break;
		case 2: printf("El dia %d es Martes", dia);
		break;
		case 3: printf("El dia %d es Miercoles", dia);
		break;
		case 4: printf("El dia %d es Jueves", dia);
		break;
		case 5: printf("El dia %d es Viernes", dia);
		break;
		case 6: printf("El dia %d es Sabado", dia);
		break;
		case 7: printf("El dia %d es Domingo", dia);
		break;
		default: printf("El numero ingresado no corresponde a un dia, ingrese otro numero", dia);
	}
}


