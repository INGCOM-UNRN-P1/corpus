#include <stdio.h>


typedef struct tiempo
{
    int hora;
    int minuto;
    int segundo;
} tiempo_t;

/**
 * Crea una estructura de tiempo a partir de la cantidad total de segundos.
 *
 * @param segundos  La cantidad total de segundos.
 *
 * @returns Una estructura de tiempo representando la hora, los minutos y los
 * segundos.
 *
 * @pre El valor de 'segundos' debe ser un número entero no negativo.
 *
 * @post La función devuelve una estructura de tiempo válida.
 */
tiempo_t crear_desde_segundos(int segundos)
{
    tiempo_t tiempo;
    tiempo.hora = segundos / 3600;
    tiempo.minuto = (segundos % 3600) / 60;
    tiempo.segundo = segundos % 60;
    return tiempo;
}

/**
 * Crea una estructura de tiempo a partir de horas, minutos y segundos.
 *
 * @param hora     Las horas.
 * @param minutos  Los minutos.
 * @param segundos Los segundos.
 *
 * @returns Una estructura de tiempo representando la hora, los minutos y los
 * segundos.
 *
 * @pre Los valores de 'hora', 'minutos' y 'segundos' deben ser números enteros
 * válidos.
 *
 * @post La función devuelve una estructura de tiempo válida.
 */
tiempo_t crear(int hora, int minutos, int segundos)
{
    tiempo_t tiempo = {.hora = hora, .minuto = minutos, .segundo = segundos};
    tiempo_t cero = {.hora = 0, .minuto = 0, .segundo = 0};
    tiempo = sumar_tiempo(tiempo, cero);
    return tiempo;
}

/**
 * Muestra una estructura de tiempo en el formato HH:MM:SS.
 *
 * @param tiempo  La estructura de tiempo que se mostrará.
 *
 * @pre El valor de 'tiempo' debe ser una estructura de tiempo válida.
 *
 * @post La función muestra la hora en el formato HH:MM:SS en la consola.
 */
void mostrar_tiempo(tiempo_t tiempo)
{
    printf("%02d:%02d:%02d\n", tiempo.hora, tiempo.minuto, tiempo.segundo);
}

/**
 * Realiza la suma de dos estructuras de tiempo.
 *
 * @param sumando  La primera estructura de tiempo que se sumará.
 * @param sumador  La segunda estructura de tiempo que se sumará.
 *
 * @returns Una estructura de tiempo representando la suma de las dos
 * estructuras de tiempo.
 *
 * @pre Los valores de 'sumando' y 'sumador' deben ser estructuras de tiempo
 * válidas.
 *
 * @post La función devuelve una estructura de tiempo válida que representa la
 * suma.
 */
tiempo_t sumar_tiempo(tiempo_t sumando, tiempo_t sumador)
{
    tiempo_t resultado;
    resultado.hora = sumando.hora + sumador.hora;
    resultado.minuto = sumando.minuto + sumador.minuto;
    resultado.segundo = sumando.segundo + sumador.segundo;

    if (resultado.segundo >= 60)
    {
        resultado.minuto += resultado.segundo / 60;
        resultado.segundo %= 60;
    }
    if (resultado.minuto >= 60)
    {
        resultado.hora += resultado.minuto / 60;
        resultado.minuto %= 60;
    }

    return resultado;
}

/**
 * Convierte una estructura de tiempo en la cantidad total de segundos.
 *
 * @param tiempo  La estructura de tiempo que se convertirá en segundos.
 *
 * @returns La cantidad total de segundos representada por la estructura de
 * tiempo.
 *
 * @pre El valor de 'tiempo' debe ser una estructura de tiempo válida con
 * valores de hora, minutos y segundos válidos.
 *
 * @post La función devuelve la cantidad total de segundos equivalente a la
 * estructura de tiempo proporcionada.
 */
int a_segundos(tiempo_t tiempo)
{
    return tiempo.hora * 3600 + tiempo.minuto * 60 + tiempo.segundo;
}

/**
 * Compara dos estructuras de tiempo para determinar cuál es mayor.
 *
 * @param inicio  La primera estructura de tiempo.
 * @param fin     La segunda estructura de tiempo.
 *
 * @returns Un -1 si 'inicio' es menor que 'fin', 0 si son iguales y 1 si
 * 'inicio' es mayor que 'fin'.
 *
 * @pre Los valores de 'inicio' y 'fin' deben ser estructuras de tiempo válidas.
 *
 * @post La función devuelve un entero que indica la relación entre las dos
 * estructuras de tiempo.
 */
int comparar_tiempo(tiempo_t inicio, tiempo_t fin)
{
    int diferencia = a_segundos(inicio) - a_segundos(fin);
    int resultado;
    if (diferencia > 0)
    {
        resultado = 1;
    }
    else if (diferencia < 0)
    {
        resultado = -1;
    }
    else
    {
        resultado = 0;
    }
    return resultado;
}

int main()
{
    tiempo_t tiempo1 = crear(12, 30, 45);
    tiempo_t tiempo2 = crear(10, 15, 30);

    mostrar_tiempo(tiempo1);
    mostrar_tiempo(tiempo2);

    tiempo_t resultado_suma = sumar_tiempo(tiempo1, tiempo2);
    mostrar_tiempo(resultado_suma);

    int comparacion = comparar_tiempo(tiempo1, tiempo2);
    if (comparacion < 0)
    {
        printf("El tiempo 1 es menor que el tiempo 2.\n");
    }
    else if (comparacion > 0)
    {
        printf("El tiempo 1 es mayor que el tiempo 2.\n");
    }
    else
    {
        printf("El tiempo 1 es igual al tiempo 2.\n");
    }

    return 0;
}
