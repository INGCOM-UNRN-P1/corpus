
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int ingreso;
	printf("Ingrese un numero entero entre el 1 y el 7 para saber que dia de la semana le corresponde: ");
	scanf("%d", &ingreso);
	switch(ingreso)
	{
		case 1 : printf("Lunes!");break;
		case 2 : printf("Martes!");break;
		case 3 : printf("Miercoles!");break;
		case 4 : printf("Jueves!");break;
		case 5 : printf("Viernes!");break;
		case 6 : printf("Sabado!");break;
		case 7 : printf("Domingo!");break;
		default : printf("El numero ingresado esta fuera de rango!");
	}
	
	return 0;
}