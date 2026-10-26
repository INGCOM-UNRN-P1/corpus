

#include <stdio.h>

typedef struct {
   int horas;
   int minutos;
   int segundos;
}tiempo_t;


void mostrar_tiempo(tiempo_t tiempo){
   printf("%ih:%im:%is\n", tiempo.horas,tiempo.minutos,tiempo.segundos);
   return;
}


tiempo_t sumar_tiempo(tiempo_t tiempo, tiempo_t sumar){
   tiempo_t tiempo_total;
   tiempo_total.segundos = tiempo.segundos + sumar.segundos;
   tiempo_total.minutos = tiempo.minutos + sumar.minutos;
   tiempo_total.horas = tiempo.horas + sumar.horas;
   tiempo_total.minutos = tiempo_total.minutos + (tiempo_total.segundos/60);
   tiempo_total.segundos = tiempo_total.segundos%60;
   tiempo_total.horas = tiempo_total.horas + (tiempo_total.minutos/60);
   tiempo_total.minutos = tiempo_total.minutos%60;
   return tiempo_total;
}


int main()
{
   tiempo_t tiempo, sumar,tiempo2,tiempos_sumados;
   printf("Ingrese el tiempo en horas, minutos y segundos:\n");
   scanf("%i", &tiempo.horas);
   scanf("%i", &tiempo.minutos);
   scanf("%i", &tiempo.segundos);
   printf("Tiempo: ");
   mostrar_tiempo(tiempo);
   printf("Ingrese el segundo a sumar: ");
   scanf("%i", &sumar.segundos);
   printf("Ingrese el minuto a sumar: ");
   scanf("%i", &sumar.minutos);
   printf("Ingrese la hora a sumar: ");
   scanf("%i", &sumar.horas);
   sumar = sumar_tiempo(tiempo,sumar); 
   mostrar_tiempo(sumar);
   printf("Ingrese el tiempo 2 en horas, minutos y segundos para sumar con tiempo1:\n");
   scanf("%i", &tiempo2.horas);
   scanf("%i", &tiempo2.minutos);
   scanf("%i", &tiempo2.segundos);
   tiempos_sumados = sumar_tiempo(sumar, tiempo2);
   printf("El resultado de sumar tiempo 1 y tiempo 2 es: ");
   mostrar_tiempo(tiempos_sumados);
   return 0;
}