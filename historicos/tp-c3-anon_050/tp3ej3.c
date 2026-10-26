

#include <stdio.h>

typedef struct tiempo_t
{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;

/**
 * @brief crea el tiempo.
 * @pre horas, todo natural♣.
 * @pre minutos, todo natural♣.
 * @pre segundos, todo natural♣.
 * @post horas, todo natural♣.
 * @post minutos, todo natural♣.
 * @post segundos, todo natural♣.
 * @param horas las horas del tiempo.
 * @param minutos los minutos del tiempo.
 * @param segundos los segundos del tiempo.
 * @result la hora
 */
tiempo_t crear(int horas, int minutos, int segundos)
{
    tiempo_t resultado;
    resultado.horas = horas;
    resultado.minutos = minutos;
    resultado.segundos = segundos;

    return resultado;
}

/**
 * @brief muestra el tiempo.
 * @pre tiempo.horas todo natural♣.
 * @pre tiempo.minutos todo natural♣ menor a 60.
 * @pre tiempo.segundos todo natural♣ menor a 60.
 * @post tiempo.horas todo natural♣.
 * @post tiempo.minutos todo natural♣ menor a 60.
 * @post tiempo.segundos todo natural♣ menor a 60.
 * @param tiempo el tiempo solicitado.
 */
void mostrar(tiempo_t tiempo)
{
    printf("%02d:%02d:%02d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
}

/**
 * @brief suma segundos al tiempo.
 * @pre tiempo.horas todo natural♣.
 * @pre tiempo.minutos todo natural♣ menor a 60.
 * @pre tiempo.segundos todo natural♣ menor a 60.
 * @post tiempo.horas todo natural♣.
 * @post tiempo.minutos todo natural♣ menor a 60.
 * @post tiempo.segundos todo natural♣ menor a 60.
 * @param tiempo el tiempo solicitado.
 * @param segundos segundos a sumar a tiempo.
 */
tiempo_t sumar_segundos(tiempo_t tiempo, int segundos)
{
    tiempo.segundos += segundos;
    while (tiempo.segundos >= 60)
    {
        tiempo.segundos -= 60;
        tiempo.minutos++;
    }
    while (tiempo.minutos >= 60)
    {
        tiempo.minutos -= 60;
        tiempo.horas++;
    }
    return tiempo;
}

/**
 * @brief suma minutos al tiempo.
 * @pre tiempo.horas todo natural♣.
 * @pre tiempo.minutos todo natural♣ menor a 60.
 * @post tiempo.horas todo natural♣.
 * @post tiempo.minutos todo natural♣ menor a 60.
 * @param tiempo el tiempo solicitado.
 * @param minutos minutos a sumar a tiempo.
 */
tiempo_t sumar_minutos(tiempo_t tiempo, int minutos)
{
    tiempo.minutos += minutos;
    while (tiempo.minutos >= 60)
    {
        tiempo.minutos -= 60;
        tiempo.horas++;
    }
    return tiempo;
}

/**
 * @brief suma horas al tiempo.
 * @pre tiempo.horas todo natural♣.
 * @post tiempo.horas todo natural♣.
 * @param tiempo el tiempo solicitado.
 * @param horas horas a sumar a tiempo.
 */
tiempo_t sumar_horas(tiempo_t tiempo, int horas)
{
    tiempo.horas += horas;
    return tiempo;
}

/**
 * @brief suma dos tiempos.
 * @pre horas todo natural♣.
 * @pre minutos todo natural♣ menor a 60.
 * @pre segundos todo natural♣ menor a 60.
 * @post horas todo natural♣.
 * @post minutos todo natural♣ menor a 60.
 * @post segundos todo natural♣ menor a 60.
 * @param a el primer tiempo a sumar.
 * @param b el segundo tiempo a sumar.
 */
tiempo_t sumar_tiempos(tiempo_t a, tiempo_t b)
{
    a = sumar_segundos(a, b.segundos);
    a = sumar_minutos(a, b.minutos);
    a = sumar_horas(a, b.horas);
    return a;
}

int main()
{
    tiempo_t t0;
    tiempo_t t1;
    tiempo_t tsuma;
    t0 = crear(1, 2, 8);
    t1 = crear(7, 59, 59);
    printf("El tiempo 1 es: ");
    mostrar(t0);
    printf("El tiempo 2 es: ");
    mostrar(t1);
    tsuma = sumar_tiempos(t0, t1);
    printf("La suma de tiempos es: ");
    mostrar(tsuma);
    return 0;
}