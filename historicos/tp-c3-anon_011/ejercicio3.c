


#include <stdio.h>
#include <string.h>

typedef struct tiempo{
    int horas;
    int minutos;
	int segundos;
} tiempo_t;

tiempo_t crear_tiempo() {
	
	int horas, minutos, segundos;
	tiempo_t resultado;
	
	
	do
	{
		printf("ingrese la cantidad de sengundos: ");
		scanf("%d", &segundos);
		if(segundos < 0) {
			printf("no pueden ser segundos con valor negativo");
		}
	} while(segundos < 0);
	
	do
	{
		printf("ingrese la cantidad de minutos: ");
		scanf("%d", &minutos);
		if(minutos < 0) {
			printf("no pueden ser minutos con valor negativo");
		}
	} while(minutos < 0);
	
	do
	{
		printf("ingrese la cantidad de horas: ");
		scanf("%d", &horas);
		if(horas < 0) {
			printf("no pueden ser horas con valor negativo");
		}
	} while(horas < 0);
	
	
	do
	{
		if(segundos >= 60) {
			segundos -= 60;
			minutos+=1;
		} else
			;
		if(minutos > 60) {
			minutos -= 60;
			horas+=1;
		} else 
			;
	} while(segundos >= 60 || minutos >= 60);
	
	
	resultado.segundos = segundos;
	resultado.minutos = minutos;
	resultado.horas = horas;
	
	return resultado;
}

void mostrar_tiempo(tiempo_t tiempo) {
	
	printf("%d:%d:%d", tiempo.horas, tiempo.minutos, tiempo.segundos);
}	

tiempo_t sumar_segundos(tiempo_t tiempo) {
	
	int mas_segundos;
	
	printf("ingrese los segundos que desea sumar: ");
	scanf("%d", &mas_segundos);
	
	tiempo.segundos = tiempo.segundos + mas_segundos;
	
	do
	{
		if(tiempo.segundos >= 60) {
			tiempo.segundos -= 60;
			tiempo.minutos+=1;
		} else
			;
		if(tiempo.minutos > 60) {
			tiempo.minutos -= 60;
			tiempo.horas+=1;
		} else 
			;
	} while(tiempo.segundos >= 60 || tiempo.minutos >= 60);
	
	return tiempo;
}

tiempo_t sumar_minutos(tiempo_t tiempo) {
	
	int mas_minutos;
	
	printf("ingrese los segundos que desea sumar: ");
	scanf("%d", &mas_minutos);
	
	tiempo.minutos = tiempo.minutos + mas_minutos;
	
	do
	{
		if(tiempo.minutos > 60) {
			tiempo.minutos -= 60;
			tiempo.horas+=1;
		} else 
			;
	} while(tiempo.minutos >= 60);
	
	return tiempo;
}

tiempo_t sumar_horas(tiempo_t tiempo) {
	
	int mas_horas;
	
	printf("ingrese los segundos que desea sumar: ");
	scanf("%d", &mas_horas);
	
	tiempo.horas = tiempo.horas + mas_horas;
		
	return tiempo;
}

tiempo_t suma_tiempos(tiempo_t tiempo1, tiempo_t tiempo2) {
	
	tiempo_t resultado;
	
	resultado.segundos = tiempo1.segundos + tiempo2.segundos;
	resultado.minutos = tiempo1.minutos + tiempo2.minutos;
	resultado.horas = tiempo1.horas + tiempo2.horas;
	
	do
	{
		if(resultado.segundos >= 60) {
			resultado.segundos -= 60;
			resultado.minutos+=1;
		} else
			;
		if(resultado.minutos > 60) {
			resultado.minutos -= 60;
			resultado.horas+=1;
		} else 
			;
	} while(resultado.segundos >= 60 || resultado.minutos >= 60);
	
	return resultado;
}	
int main()
{
	tiempo_t t1, t2, t3;
	
	
	t1 = crear_tiempo();
	printf("\n");
	
	
	mostrar_tiempo(t1);
	printf("\n");
	printf("\n");
	
	
	t1 = sumar_segundos(t1);
	mostrar_tiempo(t1);
	printf("\n");
	
	
	t1 = sumar_minutos(t1);
	mostrar_tiempo(t1);
	printf("\n");
	
	
	t1 = sumar_horas(t1);
	mostrar_tiempo(t1);
	printf("\n");
	
	
	printf("creamos el 2do tiempo\n");
	t2 = crear_tiempo();
	printf("sumando los 2 tiempos...\n");
	t3 = suma_tiempos(t1, t2);
	mostrar_tiempo(t3);
	
	return 0;
}