

#include <stdio.h>
#define SIZE 60

typedef struct {
	int horas;
	int minutos;
	int segundos;
}tiempo_t;

tiempo_t crear_tiempo(tiempo_t nuevo_tiempo);
void mostrar_tiempo(tiempo_t tiempo_actual);
tiempo_t sumar_segundos(tiempo_t tiempo, int segundos);
tiempo_t sumar_minutos(tiempo_t tiempo, int minutos);
tiempo_t sumar_horas(tiempo_t tiempo, int horas);
tiempo_t sumar_dos_tiempos(tiempo_t tiempo_1, tiempo_t tiempo_2);

tiempo_t crear_tiempo(tiempo_t nuevo_tiempo)
{
	int minutos_sumar = 0;
	int horas_sumar = 0;
	printf("Horas:\n");
	scanf("%d", &nuevo_tiempo.horas);
	printf("Minutos:\n");
	scanf("%d", &nuevo_tiempo.minutos);
	printf("Segundos:\n");
	scanf("%d", &nuevo_tiempo.segundos);
	
	while(nuevo_tiempo.segundos >= SIZE)
	{
		nuevo_tiempo.segundos = nuevo_tiempo.segundos - SIZE;
		minutos_sumar++;
	}
	
	nuevo_tiempo.minutos = nuevo_tiempo.minutos + minutos_sumar;
	
	while(nuevo_tiempo.minutos >= SIZE)
	{	
		nuevo_tiempo.minutos = nuevo_tiempo.minutos - SIZE;
		horas_sumar++;
	}
	
	nuevo_tiempo.horas = nuevo_tiempo.horas + horas_sumar;
	
	return nuevo_tiempo;
}

void mostrar_tiempo_t(tiempo_t tiempo_actual)
{
	printf("%dh %dm %ds\n", tiempo_actual.horas, tiempo_actual.minutos, tiempo_actual.segundos);
	return;
}

tiempo_t sumar_segundos(tiempo_t tiempo, int segundos)
{
	int minutos_sumar = 0;
	int horas_sumar = 0;
	tiempo.segundos = tiempo.segundos + segundos;
	
	while(tiempo.segundos >= SIZE)
	{
		tiempo.segundos = tiempo.segundos - SIZE;
		minutos_sumar++;
	}
	
	tiempo.minutos = tiempo.minutos + minutos_sumar;
	
	while(tiempo.minutos >= SIZE)
	{	
		tiempo.minutos = tiempo.minutos - SIZE;
		horas_sumar++;
	}
	
	tiempo.horas = tiempo.horas + horas_sumar;
	
	return tiempo;
}

tiempo_t sumar_minutos(tiempo_t tiempo, int minutos)
{
	int horas_sumar = 0;
	tiempo.minutos = tiempo.minutos + minutos;
	
	while(tiempo.minutos >= SIZE)
	{	
		tiempo.minutos = tiempo.minutos - SIZE;
		horas_sumar++;
	}
	
	tiempo.horas = tiempo.horas + horas_sumar;
	
	return tiempo;
}

tiempo_t sumar_horas(tiempo_t tiempo, int horas)
{
	tiempo.horas = tiempo.horas + horas;
	
	return tiempo;
}

tiempo_t sumar_dos_tiempos(tiempo_t tiempo_1, tiempo_t tiempo_2)
{
	int segundos = tiempo_2.segundos;
	int minutos = tiempo_2.minutos;
	int horas = tiempo_2.horas;
	
	tiempo_1 = sumar_segundos(tiempo_1, segundos);
	tiempo_1 = sumar_minutos(tiempo_1, minutos);
	tiempo_1 = sumar_horas(tiempo_1, horas);
	
	return tiempo_1;
}

int main()
{
	tiempo_t tiempo;
	tiempo_t resultado_segundos;
	tiempo_t resultado_minutos;
	tiempo_t resultado_horas;
	tiempo_t segundo_tiempo;
	tiempo_t sumados;
	int segundos;
	int minutos;
	int horas;
	int eleccion;
	
	printf("Ingrese el tiempo en segundos, minutos y horas:\n");
	tiempo = crear_tiempo(tiempo);
	printf("\nSu tiempo:\n");
	mostrar_tiempo_t(tiempo);
	
	
	while (eleccion < 4)
	{
		printf("\n-----¿Cual operación desea realizar?-----\n(ingrese un numero mayor a 3 para que termine el programa)\n0.Sumarle segundos al tiempo.\n1.Sumarle minutos al tiempo.\n2.Sumarle horas al tiempo.\n3.Sumar con otro tiempo.\n:");
		scanf("%d", &eleccion);
		
		if(eleccion == 0)
		{
			printf("\nIngrese los segundos para sumar a su tiempo:\n");
			scanf("%d", &segundos);
			tiempo = sumar_segundos(tiempo, segundos);
			mostrar_tiempo_t(tiempo);
		}
		
		if(eleccion == 1)
		{
			printf("\nIngrese los minutos para sumar a su tiempo:\n");
			scanf("%d", &minutos);
			tiempo = sumar_minutos(tiempo, minutos);
			mostrar_tiempo_t(tiempo);
		}
		
		if(eleccion == 2)
		{
			printf("\nIngrese las horas para sumar a su tiempo:\n");
			scanf("%d", &horas);
			tiempo = sumar_horas(tiempo, horas);
			mostrar_tiempo_t(tiempo);
		}
		
		if(eleccion == 3)
		{
			printf("\nIngrese otro tiempo para sumar al primer tiempo ingresado:\n");
			segundo_tiempo = crear_tiempo(segundo_tiempo);
			printf("\nSu segundo tiempo:\n");
			mostrar_tiempo_t(segundo_tiempo);
			sumados = sumar_dos_tiempos(tiempo, segundo_tiempo);
			printf("\nLos dos tiempos sumados son:\n");
			mostrar_tiempo_t(sumados);
		}
	}
	
	return 0;
}