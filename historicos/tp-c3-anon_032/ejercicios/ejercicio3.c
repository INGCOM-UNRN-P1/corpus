

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct tiempo
{
    int horas, minutos, segundos;
} tiempo_t;

tiempo_t normalizar_tiempo(tiempo_t tiempo)
// Precondiciones: El valor de entrada "tiempo" tiene que ser de tipo tiempo_t
// Postcondiciones: Devuelve una estructura tiempo_t con los valores correspondientes a la normalización
// de los valores de acuerdo al sistema horario de 24 horas
// Argumentos: Recibe el argumento "tiempo" el cual es una estructura que contiene 3 valores enteros:
// "horas", "minutos" y "segundos".
// Retorno: Devuelve una estructura del tipo tiempo_t
{
    tiempo_t tiempo_final = {.horas = tiempo.horas, .minutos = tiempo.minutos, .segundos = tiempo.segundos};
    if (tiempo_final.segundos >= 60)
    {
        tiempo_final.minutos = tiempo_final.minutos + floor(tiempo_final.segundos / 60);
        tiempo_final.segundos = tiempo_final.segundos % 60;
    }
    if (tiempo_final.minutos >= 60)
    {
        tiempo_final.horas = tiempo_final.horas + floor(tiempo_final.minutos / 60);
        tiempo_final.minutos = tiempo_final.minutos % 60;
    }
    if (tiempo_final.horas >= 24)
    {
        tiempo_final.horas = tiempo_final.horas % 24;
    }
    return tiempo_final;
}

tiempo_t crear_tiempo(int horas, int minutos, int segundos)
// Precondiciones: Los valores de entradas "horas", "minutos" y "segundos" deben ser números enteros
// Postcondiciones: Devuelve un una estructura del tipo tiempo_t con los valores pasados por parámetros
// Argumentos: Recibe los argumentos "horas", "minutos" y "segundos" de tipo número entero
// Retorno: Devuelve una estructura del tipo tiempo_t
{
    tiempo_t tiempo = {.horas = horas, .minutos = minutos, .segundos = segundos};
    return tiempo;
}

void mostrar_tiempo(tiempo_t tiempo)
// Precondiciones: El valor de entrada "tiempo" tiene que ser de tipo tiempo_t de número enteros
// Postcondiciones: No devuelve ningún valor, imprime por consola el contenido del tiempo
// Argumentos: Recibe el argumento "tiempo" el cual es una estructura que contiene 3 valores enteros:
// "horas", "minutos" y "segundos". Esta estructura esta nombrada por el alias tiempo_t
// Retorno: No devuelve ningún valor, imprime por consola el contenido del tiempo
{
    if (tiempo.horas < 10 && tiempo.minutos < 10 && tiempo.segundos < 10)
    {
        printf("0%d:0%d:0%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
    else if (tiempo.horas < 10 && tiempo.minutos < 10 && tiempo.segundos >= 10)
    {
        printf("0%d:0%d:%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
    else if (tiempo.horas < 10 && tiempo.minutos >= 10 && tiempo.segundos < 10)
    {
        printf("0%d:%d:0%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
    else if (tiempo.horas < 10 && tiempo.minutos >= 10 && tiempo.segundos >= 10)
    {
        printf("0%d:%d:%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
    else if (tiempo.horas >= 10 && tiempo.minutos < 10 && tiempo.segundos < 10)
    {
        printf("%d:0%d:0%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
    else if (tiempo.horas >= 10 && tiempo.minutos < 10 && tiempo.segundos >= 10)
    {
        printf("%d:0%d:%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
    else if (tiempo.horas >= 10 && tiempo.minutos >= 10 && tiempo.segundos < 10)
    {
        printf("%d:%d:0%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
    else if (tiempo.horas >= 10 && tiempo.minutos >= 10 && tiempo.segundos >= 10)
    {
        printf("%d:%d:%d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    }
}

tiempo_t suma_segundos(tiempo_t tiempo, int segundos)
// Precondiciones: El valor de entrada "tiempo" tiene que ser de tipo tiempo_t y el valor de "segundos"
// tiene que ser de tipo entero
// Postcondiciones: Devuelve una estructura tiempo_t con los valores correspondientes a la suma entre la
// estructura "tiempo" y el entero "segundos" ingresados por parámetros
// Argumentos: Recibe el argumento "tiempo" el cual es una estructura que contiene 3 valores enteros:
// "horas", "minutos" y "segundos". Tambien recibe "segundos" que es un número de tipo entero
// Retorno: Devuelve una estructura del tipo tiempo_t
{
    tiempo_t tiempo_final = {.horas = tiempo.horas, .minutos = tiempo.minutos, .segundos = tiempo.segundos + segundos};
    tiempo_final = normalizar_tiempo(tiempo_final);
    return tiempo_final;
}

tiempo_t suma_minutos(tiempo_t tiempo, int minutos)
// Precondiciones: El valor de entrada "tiempo" tiene que ser de tipo tiempo_t y el valor de "minutos"
// tiene que ser de tipo entero
// Postcondiciones: Devuelve una estructura tiempo_t con los valores correspondientes a la suma entre la
// estructura "tiempo" y el entero "minutos" ingresados por parámetros
// Argumentos: Recibe el argumento "tiempo" el cual es una estructura que contiene 3 valores enteros:
// "horas", "minutos" y "segundos". Tambien recibe "minutos" que es un número de tipo entero
// Retorno: Devuelve una estructura del tipo tiempo_t
{
    tiempo_t tiempo_final = {.horas = tiempo.horas, .minutos = tiempo.minutos + minutos, .segundos = tiempo.segundos};
    tiempo_final = normalizar_tiempo(tiempo_final);
    return tiempo_final;
}

tiempo_t suma_horas(tiempo_t tiempo, int horas)
// Precondiciones: El valor de entrada "tiempo" tiene que ser de tipo tiempo_t y el valor de "horas"
// tiene que ser de tipo entero
// Postcondiciones: Devuelve una estructura tiempo_t con los valores correspondientes a la suma entre la
// estructura "tiempo" y el entero "horas" ingresados por parámetros
// Argumentos: Recibe el argumento "tiempo" el cual es una estructura que contiene 3 valores enteros:
// "horas", "minutos" y "segundos". Tambien recibe "horas" que es un número de tipo entero
// Retorno: Devuelve una estructura del tipo tiempo_t
{
    tiempo_t tiempo_final = {.horas = tiempo.horas + horas, .minutos = tiempo.minutos, .segundos = tiempo.segundos};
    tiempo_final = normalizar_tiempo(tiempo_final);
    return tiempo_final;
}

tiempo_t suma_tiempos(tiempo_t tiempo, tiempo_t otro_tiempo)
// Precondiciones: El valor de entrada "tiempo" y "otro_tiempo" tienen que ser de tipo tiempo_t
// Postcondiciones: Devuelve una estructura tiempo_t con los valores correspondientes a la suma entre las
// estructuras "tiempo" y "otro_tiempo" ingresados por parámetros
// Argumentos: Recibe los argumentos "tiempo" y "otro_tiempo" los cuales son una estructura que contiene 3 valores
// enteros: "horas", "minutos" y "segundos".
// Retorno: Devuelve una estructura del tipo tiempo_t
{
    tiempo_t tiempo_final = {
        .horas = tiempo.horas + otro_tiempo.horas,
        .minutos = tiempo.minutos + otro_tiempo.minutos,
        .segundos = tiempo.segundos + otro_tiempo.segundos};
    tiempo_final = normalizar_tiempo(tiempo_final);
    return tiempo_final;
}

int main()
{
    int horasScanf = 0;
    float horasScanfFloat = 0.0;
    int minutosScanf = 0;
    float minutosScanfFloat = 0.0;
    int segundosScanf = 0;
    float segundosScanfFloat = 0.0;
    tiempo_t tiempo = {.horas = 0, .minutos = 0, .segundos = 0};
    tiempo_t otro_tiempo = {.horas = 0, .minutos = 0, .segundos = 0};
    int segundosSuma = 0;
    float segundosSumaFloat = 0;
    tiempo_t suma_de_segundos = {.horas = 0, .minutos = 0, .segundos = 0};
    int minutosSuma = 0;
    float minutosSumaFloat = 0;
    tiempo_t suma_de_minutos = {.horas = 0, .minutos = 0, .segundos = 0};
    int horasSuma = 0;
    float horasSumaFloat = 0;
    tiempo_t suma_de_horas = {.horas = 0, .minutos = 0, .segundos = 0};
    tiempo_t suma_de_tiempos = {.horas = 0, .minutos = 0, .segundos = 0};
    printf("Ejercicio 3: Gestionando el tiempo_t\n");
    printf("Mediante el ingreso de un tiempo en formato HH:MM:SS, realizar diferentes operaciones\n\n");
    printf("Creación del tiempo\n");
    printf("Introduzca las horas: ");
    fflush(stdout);
    scanf("%f", &horasScanfFloat);
    horasScanf = horasScanfFloat;
    if (horasScanfFloat - horasScanf)
    {
        printf("Error! Debes ingresar un número entero\n");
    }
    else
    {
        printf("Introduzca los minutos: ");
        fflush(stdout);
        scanf("%f", &minutosScanfFloat);
        minutosScanf = minutosScanfFloat;
        if (minutosScanfFloat - minutosScanf)
        {
            printf("Error! Debes ingresar un número entero\n");
        }
        else
        {
            printf("Introduzca los segundos: ");
            fflush(stdout);
            scanf("%f", &segundosScanfFloat);
            segundosScanf = segundosScanfFloat;
            if (segundosScanfFloat - segundosScanf)
            {
                printf("Error! Debes ingresar un número entero\n");
            }
            else
            {
                tiempo = crear_tiempo(horasScanf, minutosScanf, segundosScanf);
                printf("\nMostrar tiempo\n");
                mostrar_tiempo(tiempo);
                printf("\nSuma de segundos\n");
                printf("Introduzca los segundos para sumar: ");
                fflush(stdout);
                scanf("%f", &segundosSumaFloat);
                segundosSuma = segundosSumaFloat;
                if (segundosSumaFloat - segundosSuma)
                {
                    printf("Error! Debes ingresar un número entero\n");
                }
                else
                {
                    suma_de_segundos = suma_segundos(tiempo, segundosSuma);
                    mostrar_tiempo(suma_de_segundos);
                    printf("\nSuma de minutos\n");
                    printf("Introduzca los minutos para sumar: ");
                    fflush(stdout);
                    scanf("%f", &minutosSumaFloat);
                    minutosSuma = minutosSumaFloat;
                    if (minutosSumaFloat - minutosSuma)
                    {
                        printf("Error! Debes ingresar un número entero\n");
                    }
                    else
                    {
                        suma_de_minutos = suma_minutos(tiempo, minutosSuma);
                        mostrar_tiempo(suma_de_minutos);
                        printf("\nSuma de horas\n");
                        printf("Introduzca los horas para sumar: ");
                        fflush(stdout);
                        scanf("%f", &horasSumaFloat);
                        horasSuma = horasSumaFloat;
                        if (horasSumaFloat - horasSuma)
                        {
                            printf("Error! Debes ingresar un número entero\n");
                        }
                        else
                        {
                            suma_de_horas = suma_horas(tiempo, horasSuma);
                            mostrar_tiempo(suma_de_horas);
                            printf("\nSuma de tiempos\n");
                            printf("Creación de otro tiempo\n");
                            printf("Introduzca las horas: ");
                            fflush(stdout);
                            scanf("%f", &horasScanfFloat);
                            horasScanf = horasScanfFloat;
                            if (horasScanfFloat - horasScanf)
                            {
                                printf("Error! Debes ingresar un número entero\n");
                            }
                            else
                            {
                                printf("Introduzca los minutos: ");
                                fflush(stdout);
                                scanf("%f", &minutosScanfFloat);
                                minutosScanf = minutosScanfFloat;
                                if (minutosScanfFloat - minutosScanf)
                                {
                                    printf("Error! Debes ingresar un número entero\n");
                                }
                                else
                                {
                                    printf("Introduzca los segundos: ");
                                    fflush(stdout);
                                    scanf("%f", &segundosScanfFloat);
                                    segundosScanf = segundosScanfFloat;
                                    if (segundosScanfFloat - segundosScanf)
                                    {
                                        printf("Error! Debes ingresar un número entero\n");
                                    }
                                    else
                                    {
                                        otro_tiempo = crear_tiempo(horasScanf, minutosScanf, segundosScanf);
                                        suma_de_tiempos = suma_tiempos(tiempo, otro_tiempo);
                                        mostrar_tiempo(suma_de_tiempos);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}