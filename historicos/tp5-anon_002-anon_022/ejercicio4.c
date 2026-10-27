#include <stdio.h>
#define MENOR -1
#define IGUAL 0
#define MAYOR 1




typedef struct
{
    int horas;      // Representa las horas.
    int minutos;    // Representa los minutos.
    int segundos;   // Representa los segundos
} tiempo_t;



/**
 * Esta funcion imprime por pantalla el tiempo, mostrando horas, minutos y segundos.
 * @param tiempo Parametro de tipo tiempo_t que recibe de la funcion principal las h, m y s
 * @pre El tiempo tienen que ser numeros validos 
 * @post Mostrar correctamente el tiempo 
*/

void mostrar_tiempo(tiempo_t tiempo)
{
    printf("%ih:%im:%is\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    return;
}


/**
 * Funcion de tipo tiempo_t que sumando horas, minutos y segundos de tiempo1 con los de tiempo2.
 * @param tiempo. Es el tiempo numero 1 que se recibe como parametro para la suma 
 * @param tiempo2. Es el tiempo numero 2 que se recibe como parametro para completar la suma con el primero
 * @return tiempo_total. Es la suma de ambos tiempos ingresados anteriormente.
 * @pre Los tiempos recibidos por parametros tienen que ser numeros validos 
 * @post Tiempo total, de estructura tipo tiempo_t debe retornar correctamente la suma de ambos tiempos.
 * 
*/

tiempo_t sumar_tiempo(tiempo_t tiempo, tiempo_t sumar)
{
    tiempo_t tiempo_total;
    tiempo_total.segundos = tiempo.segundos + sumar.segundos;
    tiempo_total.minutos = tiempo.minutos + sumar.minutos;
    tiempo_total.horas = tiempo.horas + sumar.horas;
    tiempo_total.minutos = tiempo_total.minutos + (tiempo_total.segundos / 60);
    tiempo_total.segundos = tiempo_total.segundos % 60;
    tiempo_total.horas = tiempo_total.horas + (tiempo_total.minutos / 60);
    tiempo_total.minutos = tiempo_total.minutos % 60;
    return tiempo_total;
}


/**
 * Esta funcion compara tiempo1 y tiempo2, verificando cual de los dos es mayor, o es igual.
 * @param tiempo. Es el tiempo numero 1 a comparar.
 * @param tiempo2. Es el tiempo numero 2 a comparar.
 * @returns MENOR: El tiempo numero 1 es menor al tiempo 2
 *          IGUAL: El tiempo 1 es igual al tiempo 2.
 *          MAYOR: El tiempo 1 es mayor al tiempo 2.
 * @pre Los tiempos que se reciben por parametros deben ser numeros validos.
 * @post La comparacion de tiempos al retornar debe ser la correcta.
*/

int compara(tiempo_t tiempo, tiempo_t tiempo2)
{
    int resultado;
    if (tiempo.horas < tiempo2.horas)
    {
        resultado = MENOR;
    }
    else if (tiempo.horas > tiempo2.horas)
    {
        resultado = MAYOR;
    }
    else if (tiempo.minutos < tiempo2.minutos)
    {
        resultado = MENOR;
    }
    else if (tiempo.minutos > tiempo2.minutos)
    {
        resultado = MAYOR;
    }
    else if (tiempo.segundos < tiempo2.segundos)
    {
        resultado = MENOR;
    }
    else if (tiempo.segundos > tiempo2.segundos)
    {
        resultado = MAYOR;
    }
    else
    {
        resultado = IGUAL;
    }
    return resultado;
}
int main()
{
    tiempo_t tiempo, tiempo2, tiempos_sumados;
    int resultado;
    printf("Ingrese el tiempo en horas, minutos y segundos:\n");
    printf("h:");
    scanf("%i", &tiempo.horas);
    printf("m:");
    scanf("%i", &tiempo.minutos);
    printf("s:");
    scanf("%i", &tiempo.segundos);
    printf("Tiempo: ");
    mostrar_tiempo(tiempo);
    printf("Ingrese el tiempo 2 en horas, minutos y segundos para comparar y sumar con tiempo 1:\n");
    printf("h:");
    scanf("%i", &tiempo2.horas);
    printf("m:");
    scanf("%i", &tiempo2.minutos);
    printf("s:");
    scanf("%i", &tiempo2.segundos);
    resultado = compara(tiempo, tiempo2);
    printf("Comparacion de los dos tiempos: \n");
    if (resultado == MENOR)
    {
        printf("El tiempo 1 es menor\n");
    }
    else if (resultado == MAYOR)
    {
        printf("El tiempo 1 es mayor\n");
    }
    else
    {
        printf("los dos tiempso son iguales\n");
    }
    tiempos_sumados = sumar_tiempo(tiempo, tiempo2);
    printf("El resultado de sumar tiempo 1 y tiempo 2 es: ");
    mostrar_tiempo(tiempos_sumados);
    return 0;
}
