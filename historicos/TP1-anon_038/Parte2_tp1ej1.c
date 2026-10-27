
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero;
	
	printf("Ingrese un numero del 1 al 7 para traducirlo a un dia de la semana \n");
	scanf("%d", &numero);
	
	switch(numero)
	{
	case 1:
	{
	printf("El dia de la semana es Lunes \n");
	break;
	}
	case 2:
	{
	printf("El dia de la semana es Martes \n");
	break;
	}
	case 3:
	{
	printf("El dia de la semana es Miercoles \n");
	break;
	}
	case 4:
	{
	printf("El dia de la semana es Jueves \n");
	break;
	}
	case 5:
	{
	printf("El dia de la semana es Viernes \n");
	break;
	}
	case 6:
	{
	printf("El dia de la semana es Sabado \n");
	break;
	}
	case 7:
	{
	printf("El dia de la semana es Domingo \n");
	break;
	}
	default:
	{
	printf("El numero ingresado esta fuera del rango \n");
	}
	
	}
	
	return 0;
	
}

