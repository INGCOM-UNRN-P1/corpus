


#include <stdio.h>

typedef struct {
    int horas;
    int minutos;
    int segundos;
} tiempo_t;

tiempo_t suma_segundos(tiempo_t tiempo1, tiempo_t tiempo2);
tiempo_t crear_tiempo(int horas, int minutos, int segundos) ;
void mostrar_tiempo_t(tiempo_t time);
int compara_tiempo(tiempo_t tiempo1, tiempo_t tiempo2);

int main() 
{
    tiempo_t tiempo1 = crear_tiempo(3, 45, 30); // variable de primera fracción
    tiempo_t tiempo2 = crear_tiempo(2, 30, 15); // variable segunda fracción
    
    printf("tiempo 1: ");
    mostrar_tiempo_t(tiempo1);
    printf("Tiempo 2: ");
    mostrar_tiempo_t(tiempo2);


    tiempo_t suma = suma_segundos(tiempo1, tiempo2);
    printf("La suma de segundos es: \n");
    mostrar_tiempo_t(suma);

    int resultado = compara_tiempo(tiempo1, tiempo2);
    if (resultado == -1) 
    {
        printf("Tiempo 1 es mas chico que Tiempo 2\n");
    } 
    else if (resultado == 1) 
    {
        printf("Tiempo 1 es mas grande que Tiempo 2\n");
    }
    else 
    {
        printf("Tiempo 1 y Tiempo 2 son iguales\n");
    }

    return 0;
}


tiempo_t crear_tiempo(int horas, int minutos, int segundos) 
{
    tiempo_t tiempo;
    tiempo.horas = horas;
    tiempo.minutos = minutos;
    tiempo.segundos = segundos;
    return tiempo;
}


void mostrar_tiempo_t(tiempo_t time) 
{
    printf("%02d horas:%02d minutos:%02d segundos\n", time.horas, time.minutos, time.segundos);
}


tiempo_t suma_segundos(tiempo_t tiempo1, tiempo_t tiempo2) 
{
    tiempo_t suma;
    suma.horas = tiempo1.horas + tiempo2.horas;
    suma.minutos = tiempo1.minutos + tiempo2.minutos;
    suma.segundos = tiempo1.segundos + tiempo2.segundos;

    // Ajustar los segundos si es mayor o igual a 60
    if (suma.segundos >= 60) 
    {
        suma.minutos += suma.segundos / 60;
        suma.segundos %= 60;
    }

    // Ajustar los minutos si es mayor o igual a 60
    if (suma.minutos >= 60) 
    {
        suma.horas += suma.minutos / 60;
        suma.minutos %= 60;
    }

    return suma;
}


int compara_tiempo(tiempo_t tiempo1, tiempo_t tiempo2)
{
    int comparacion = 0;
    if (tiempo1.horas < tiempo2.horas)
    {
        comparacion = -1;
    }
    else if(tiempo1.horas > tiempo2.horas)
    {
        comparacion = 1;
    }
    else
    {
        comparacion;
    }

    if (tiempo1.minutos < tiempo2.minutos)
    {
        comparacion = -1;
    }
    else if(tiempo1.minutos > tiempo2.minutos)
    {
        comparacion = 1;
    }
    else 
    {
        comparacion;
    }

        if (tiempo1.segundos < tiempo2.segundos)
    {
        comparacion = -1;
    }
    else if(tiempo1.segundos > tiempo2.segundos)
    {
        comparacion = 1;
    }
    else
    {
        comparacion;
    }

    return comparacion;
}
