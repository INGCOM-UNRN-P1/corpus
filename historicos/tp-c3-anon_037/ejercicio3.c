

#include <stdio.h>

typedef struct tiempo{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;

tiempo_t crear_tiempo();
void mostrar_tiempo(tiempo_t tiempo);
void agregar_horas(tiempo_t *tiempo);
void agregar_minutos(tiempo_t *tiempo);
void agregar_segundos(tiempo_t *tiempo);
tiempo_t suma_tiempos(tiempo_t tiempo1, tiempo_t tiempo2);


int main()
{
    tiempo_t tiempoo1;
    tiempo_t tiempoo2;
    tiempo_t tiempo_sumado;
    
    
    printf("<>Cree un tiempo<>\n\n");
    tiempoo1 = crear_tiempo();
    mostrar_tiempo(tiempoo1);
    
    
    printf("\n\n\n<>Cree otro tiempo<>\n\n");
    tiempoo2 = crear_tiempo();
    mostrar_tiempo(tiempoo2);
    
    
    printf("\n\n\nLa suma de ambos tiempos es:");
    tiempo_sumado = suma_tiempos(tiempoo1, tiempoo2);
    mostrar_tiempo(tiempo_sumado);
    
    
    agregar_horas(&tiempo_sumado);
    mostrar_tiempo(tiempo_sumado);
    
    
    agregar_minutos(&tiempo_sumado);
    mostrar_tiempo(tiempo_sumado);
    
    
    agregar_segundos(&tiempo_sumado);
    mostrar_tiempo(tiempo_sumado);
}

tiempo_t crear_tiempo()
{
    tiempo_t time;
    
    printf("Ingrese horas -> ");
    scanf("%d", &time.horas);
    fflush(stdin);

    printf("Ingrese minutos -> ");
    scanf("%d", &time.minutos);
    fflush(stdin);

    printf("Ingrese segundos -> ");
    scanf("%d", &time.segundos);
    fflush(stdin);

    while (time.minutos >= 60)
    {
        time.minutos = time.minutos - 60;
        time.horas = time.horas + 1;
    }

    while (time.segundos >= 60)
    {
        time.segundos = time.segundos - 60;
        time.minutos = time.minutos + 1;
    }
    
    return time;
}

void mostrar_tiempo(tiempo_t tiempo)
{
    printf("\n%d horas, %d minutos, %d segundos.", tiempo.horas, tiempo.minutos, tiempo.segundos);
}

void agregar_horas(tiempo_t *tiempo)
{
    int horas_asumar;

    printf("\n\n\nIngrese la cantidad de horas que desea agregar -> ");
    scanf("%d", &horas_asumar);
    fflush(stdin);
    
    tiempo->horas = tiempo->horas + horas_asumar;
}

void agregar_minutos(tiempo_t *tiempo)
{
    int minutos_asumar;

    printf("\n\n\nIngrese la cantidad de minutos que desea agregar -> ");
    scanf("%d", &minutos_asumar);
    fflush(stdin);
    
    tiempo->minutos = tiempo->minutos + minutos_asumar;

    while (tiempo->minutos >= 60)
    {
        tiempo->minutos = tiempo->minutos - 60;
        tiempo->horas = tiempo->horas + 1;
    }
}

void agregar_segundos(tiempo_t *tiempo)
{
    int segundos_asumar;

    printf("\n\n\nIngrese la cantidad de segundos que desea agregar -> ");
    scanf("%d", &segundos_asumar);
    fflush(stdin);
    
    tiempo->segundos = tiempo->segundos + segundos_asumar;

    while (tiempo->segundos >= 60)
    {
        tiempo->segundos = tiempo->segundos - 60;
        tiempo->minutos = tiempo->minutos + 1;
    }
}

tiempo_t suma_tiempos(tiempo_t tiempo1, tiempo_t tiempo2)
{
    tiempo_t time;

    time.horas = tiempo1.horas + tiempo2.horas;
    time.minutos = tiempo1.minutos + tiempo2.minutos;
    time.segundos = tiempo1.segundos + tiempo2.segundos;

    while (time.minutos >= 60)
    {
        time.minutos = time.minutos - 60;
        time.horas = time.horas + 1;
    }

    while (time.segundos >= 60)
    {
        time.segundos = time.segundos - 60;
        time.minutos = time.minutos + 1;
    }
    
    return time;
}