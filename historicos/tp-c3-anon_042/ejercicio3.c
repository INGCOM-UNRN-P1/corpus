
#include <stdio.h>
typedef struct tiempo{ 
    int horas;
    int minutos;
	int segundos;
} tiempo_t;
void mostrar_tiempo(tiempo_t tiempo1){ 
	while (tiempo1.segundos >= 60){
		tiempo1.minutos = tiempo1.minutos + 1;
		tiempo1.segundos = tiempo1.segundos - 60;
	}
	while (tiempo1.minutos >= 60){
		tiempo1.horas= tiempo1.horas + 1;
		tiempo1.minutos = tiempo1.minutos - 60;
	}
	printf("%dhs %dmins %ds\n", tiempo1.horas, tiempo1.minutos, tiempo1.segundos);
}
tiempo_t sumar_segundos(tiempo_t tiempo1, int segundos){ 
	
	tiempo1.segundos = tiempo1.segundos + segundos;
	return tiempo1;
}
tiempo_t sumar_minutos(tiempo_t tiempo1, int minutos){ 
	
	tiempo1.minutos = tiempo1.minutos + minutos;
	return tiempo1;
}
tiempo_t sumar_horas(tiempo_t tiempo1, int horas){ 
	
	tiempo1.horas = tiempo1.horas + horas;
	return tiempo1;
}
tiempo_t sumar_tiempos(tiempo_t tiempo1, tiempo_t tiempo2){ 
	
	tiempo2.segundos = tiempo2.segundos + tiempo1.segundos;
	tiempo2.minutos = tiempo2.minutos + tiempo1.minutos;
	tiempo2.horas = tiempo2.horas + tiempo1.horas;
	return tiempo2;
}
int main()
{	
	tiempo_t tiempo1;
	int segundos;
	tiempo_t resultado_sumasegs;
	int minutos;
	tiempo_t resultado_sumamins;
	int horas;
	tiempo_t resultado_sumahoras;
	tiempo_t tiempo2;
	tiempo_t resultado_sumatiempos;
	
	printf("Ingrese horas: \n");
	scanf("%d", &tiempo1.horas);
	printf("Ingrese minutos: \n");
	scanf("%d", &tiempo1.minutos);
	printf("Ingrese segundos: \n");
	scanf("%d", &tiempo1.segundos);
	printf("\n");
	printf("Ingrese horas para tiempo 2: \n");
	scanf("%d", &tiempo2.horas);
	printf("Ingrese minutos para tiempo 2: \n");
	scanf("%d", &tiempo2.minutos);
	printf("Ingrese segundos para tiempo 2: \n");
	scanf("%d", &tiempo2.segundos);
	printf("\n");

	printf("Ingrese los segundos a sumar: \n");
	scanf("%d", &segundos);
	printf("Ingrese los minutos a sumar: \n");
	scanf("%d", &minutos);
	printf("Ingrese las horas a sumar: \n");
	scanf("%d", &horas);

	printf("---Funcion para mostrar el tiempo ingresado---\n");
	mostrar_tiempo(tiempo1);
	resultado_sumasegs = sumar_segundos(tiempo1, segundos);
	printf("---Funcion para mostrar el resultado de suma segundos---\n");
	mostrar_tiempo(resultado_sumasegs);
	resultado_sumamins = sumar_minutos(tiempo1, minutos);
	printf("---Funcion para mostrar el resultado de suma minutos---\n");
	mostrar_tiempo(resultado_sumamins);
	resultado_sumahoras = sumar_horas(tiempo1, horas);
	printf("---Funcion para mostrar el resultado de suma horas---\n");
	mostrar_tiempo(resultado_sumahoras);
	resultado_sumatiempos = sumar_tiempos(tiempo1, tiempo2);
	printf("---Funcion para mostrar el resultado de la suma de los dos tiempos---\n");
	mostrar_tiempo(resultado_sumatiempos);
	return 0;
}