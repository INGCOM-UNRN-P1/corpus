

#include <stdio.h>

typedef struct tiempo
{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;


void crear_tiempo(tiempo_t *tiempo);

void mostrar_tiempo(tiempo_t *tiempo);

void sumar_segundos(tiempo_t *tiempo);

void sumar_minutos(tiempo_t *tiempo);

void sumar_horas(tiempo_t *tiempo);

tiempo_t sumar_2_tiempos(tiempo_t *tiempo, tiempo_t *tiempo2);

void mostrar_menu();

int main()
{
    tiempo_t tiempo;
    tiempo_t tiempo2;
    tiempo_t tiempo3_resultado_suma;
    int opcion_elegida;

    crear_tiempo(&tiempo);
    printf("\n");
    mostrar_menu();
    printf("Seleccione las operaciones: ");
    scanf("%d", &opcion_elegida);
    printf("\n");

    switch (opcion_elegida)
    {
    case 1:
        mostrar_tiempo(&tiempo);
        break;
    case 2:
        sumar_segundos(&tiempo);
        mostrar_tiempo(&tiempo);
        break;
    case 3:
        sumar_minutos(&tiempo);
        mostrar_tiempo(&tiempo);
        break;
    case 4:
        sumar_horas(&tiempo);
        mostrar_tiempo(&tiempo);
        break;
    case 5:
        printf("TIEMPO 2\n");
        crear_tiempo(&tiempo2);
        tiempo3_resultado_suma = sumar_2_tiempos(&tiempo, &tiempo2);
        printf("\n");
        printf("La suma de los 2 tiempos es: \n");
        mostrar_tiempo(&tiempo3_resultado_suma);
        break;

    default:
        printf("Opcion invalida\n");
        break;
    }

    return 0;
}

void crear_tiempo(tiempo_t *tiempo)
{
    do
    {
        if (tiempo->horas < 0)
        {
            printf("Formato invalido, reingrese la cantidad de horas: ");
            scanf("%d", &tiempo->horas);
        }
        else
        {
            printf("Digite las horas(mayor o igual a 0): ");
            scanf("%d", &tiempo->horas);
        }
    } while (tiempo->horas < 0);

    do
    {
        if (tiempo->minutos > 59 || tiempo->minutos < 0)
        {
            printf("Formato invalido, reingrese la cantidad de minutos: ");
            scanf("%d", &tiempo->minutos);
        }
        else
        {
            printf("Digite los minutos en formato hora(de 0 hasta 59 mins): ");
            scanf("%d", &tiempo->minutos);
        }
    } while (tiempo->minutos > 59 || tiempo->minutos < 0);

    do
    {
        if (tiempo->segundos > 59 || tiempo->segundos < 0)
        {
            printf("Formato invalido, reingrese la cantidad de segundos: ");
            scanf("%d", &tiempo->segundos);
        }
        else
        {
            printf("Digite los segundos en formato hora(de 0 hasta 59 segs): ");
            scanf("%d", &tiempo->segundos);
        }
    } while (tiempo->segundos > 59 || tiempo->segundos < 0);
}

void mostrar_tiempo(tiempo_t *tiempo)
{
    printf("Horas: %d\n", tiempo->horas);
    printf("Minutos: %d\n", tiempo->minutos);
    printf("Segundos: %d\n", tiempo->segundos);
}

void sumar_segundos(tiempo_t *tiempo)
{
    int segundos = 0;
    printf("Digite los segundos que quiera sumarle a su tiempo: ");
    scanf("%d", &segundos);

    tiempo->segundos = tiempo->segundos + segundos;
    if (tiempo->segundos > 59)
    {
        tiempo->minutos = tiempo->minutos + 1;
        tiempo->segundos = 0;
    }

    if (tiempo->minutos > 59)
    {
        tiempo->horas = tiempo->horas + 1;
        tiempo->minutos = 0;
    }
}

void sumar_minutos(tiempo_t *tiempo)
{
    int minutos = 0;
    printf("Digite los minutos que quiera sumarle a su tiempo: ");
    scanf("%d", &minutos);

    tiempo->minutos = tiempo->minutos + minutos;

    if (tiempo->minutos > 59)
    {
        tiempo->horas = tiempo->horas + 1;
        tiempo->minutos = 0;
    }
}

void sumar_horas(tiempo_t *tiempo)
{
    int horas = 0;
    printf("Digite las horas que quiera sumarle a su tiempo: ");
    scanf("%d", &horas);

    tiempo->horas = tiempo->segundos + horas;
}

void mostrar_menu()
{
    printf("Opcion 1: Mostrar tiempo\n");
    printf("Opcion 2: Sumar segundos\n");
    printf("Opcion 3: Sumar minutos\n");
    printf("Opcion 4: Sumar horas\n");
    printf("Opcion 5: Sumar 2 tiempos\n");
    printf("\n");
}

tiempo_t sumar_2_tiempos(tiempo_t *tiempo, tiempo_t *tiempo2)
{
    tiempo_t tiempo3_resultado_suma;

    tiempo3_resultado_suma.horas = (tiempo->horas + tiempo2->horas);
    tiempo3_resultado_suma.minutos = (tiempo->minutos + tiempo2->minutos);
    tiempo3_resultado_suma.segundos = (tiempo->segundos + tiempo2->segundos);

    if (tiempo3_resultado_suma.segundos > 59)
    {
        tiempo3_resultado_suma.minutos = tiempo3_resultado_suma.minutos + 1;
        tiempo3_resultado_suma.segundos = 0;
    }

    if (tiempo3_resultado_suma.minutos > 59)
    {
        tiempo3_resultado_suma.horas = tiempo3_resultado_suma.horas + 1;
        tiempo3_resultado_suma.minutos = 0;
    }
    return tiempo3_resultado_suma;
}