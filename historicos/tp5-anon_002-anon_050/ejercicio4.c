

#include <stdio.h>

typedef struct tiempo
{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;

/**
 * La función crea la hora dados los valores necesarios.
 * @param horas, de la hora.
 * @pre int válido mayor a cero.
 * @param minutos, de la hora.
 * @pre int válido mayor o igual a cero.
 * @param segundos, de la hora.
 * @pre int válido mayor o igual a cero.
 * @return tiempo, la hora.
 * @post int válido, mayor o igual a cero para minutos y segundos, mayor a cero para hora. 
*/
tiempo_t laHora(int horas, int minutos, int segundos)
{
    tiempo_t tiempo;

    tiempo.horas = horas;
    tiempo.minutos = minutos;
    tiempo.segundos = segundos;
    
    return tiempo;
}

/**
 * La función formatea la hora y la muestra en pantalla.
 * @param tiempo, a formatear y mostrar.
 * @pre int válido, mayor o igual a cero para minutos y segundos, mayor a cero para hora.
*/
void mostrarHora(tiempo_t tiempo)
{
    printf("%02d:%02d:%02d\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
}

/**
 * La función suma dos horas.
 * @param tiempo1, a sumar.
 * @pre int válido, mayor o igual a cero para minutos y segundos, mayor a cero para hora.
 * @param tiempo2, a sumar.
 * @pre int válido, mayor o igual a cero para minutos y segundos, mayor a cero para hora.
 * @return resultado, de la suma.
 * @post int válido, mayor o igual a cero para minutos y segundos, mayor a cero para hora.
*/
tiempo_t sumarHora(tiempo_t tiempo1, tiempo_t tiempo2)
{
    tiempo_t resultado;

    resultado.segundos = tiempo1.segundos + tiempo2.segundos;
    resultado.minutos = tiempo1.minutos + tiempo2.minutos +resultado.segundos / 60;
    resultado.horas = tiempo1.horas + tiempo2.horas + resultado.minutos / 60;

    resultado.minutos %= 60;
    resultado.segundos %= 60;

    return resultado;
}

/**
 * La función compara dos tiempos.
 * @param tiempo1, a comparar.
 * @pre int válido, mayor o igual a cero para minutos y segundos, mayor a cero para hora.
 * @param tiempo2, a comparar.
 * @pre int válido, mayor o igual a cero para minutos y segundos, mayor a cero para hora.
 * @return, -1 si tiempo1 es menor, 0 si es igual, 1 si es mayor a tiempo2.
 * @post int entre -1 y 1
*/
int compararHoras(tiempo_t tiempo1, tiempo_t tiempo2)
{
    int ret = 0;
    
    if (tiempo1.horas < tiempo2.horas)
    {
        ret = -1;
    }
    else if (tiempo1.horas > tiempo2.horas)
    {
        ret = 1;
    }
    else if (tiempo1.minutos < tiempo2.minutos)
    {
        ret = -1;
    }
    else if (tiempo1.minutos > tiempo2.minutos)
    {
        ret = 1;
    }
    else if (tiempo1.segundos < tiempo2.segundos)
    {
        ret = -1;
    }
    else if (tiempo1.segundos > tiempo2.segundos)
    {
        ret = 1;
    }

    return ret;
}

int main()
{
    tiempo_t tiempo1 = laHora(13, 45, 50);
    tiempo_t tiempo2 = laHora(5, 15, 20);
    tiempo_t suma;
    int comparar;

    printf("La primer hora es: ");
    mostrarHora(tiempo1);

    printf("La segunda hora es: ");
    mostrarHora(tiempo2);

    suma = sumarHora(tiempo1, tiempo2);
    printf("La suma de horas da: ");
    mostrarHora(suma);

    comparar = compararHoras(tiempo1, tiempo2);
    if (comparar == -1)
    {
        printf("El primer tiempo es menor al segundo.\n");
    }
    else if (comparar == 1)
    {
        printf("El primer tiempo es mayor al segundo.\n");
    }
    else
    {
        printf("Ambos tiempos son iguales.\n");
    }

    return 0;
}