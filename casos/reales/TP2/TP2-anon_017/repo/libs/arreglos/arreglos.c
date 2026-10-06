/**
 * @file arreglos.c
 * @brief Esqueleto de implementación para la biblioteca libarreglos.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    (void)arreglo;
    (void)cantidad;
    
    long long suma_total = 0;
    if(cantidad > 0)
    {
        for(size_t i = 0; i < cantidad; i++)
        {
            suma_total = suma_total + arreglo[i];
        }
    }
    return suma_total;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    (void)arreglo;
    (void)cantidad;
    (void)buscado;
    
    int indice = -1;
    size_t contador = 0;
    int lugares_indice = 0;
    bool parar = false;

    if(cantidad > 0)
    {
        while((contador < cantidad) && (parar == false))
        {
            if(arreglo[contador] == buscado)
            {
                indice = lugares_indice;
                parar = true;
            }
            contador = contador + 1;
            lugares_indice = lugares_indice + 1;
        }
    }

    return indice;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    (void)arreglo;
    (void)cantidad;
    
    if(cantidad > 1)
    {
        int contador_fin = cantidad - 1;
        int contador_inicio = 0;
        int auxiliar = 0;

        while(contador_inicio <= contador_fin)
        {
            auxiliar = arreglo[contador_fin];
            arreglo[contador_fin] = arreglo[contador_inicio];
            arreglo[contador_inicio] = auxiliar;

            contador_inicio = contador_inicio + 1;
            contador_fin = contador_fin - 1;
        }
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    (void)arreglo;
    (void)cantidad;
    
    bool estado_arreglo = true;
    bool detener = false;
    size_t contador = 0;
    if(arreglo == NULL) 
    {
        estado_arreglo = false;
    }
    else if(cantidad >= 0 && cantidad <= 1)
    {
        estado_arreglo = true;
    }
    else
    {
        size_t finalizar = cantidad - 1;
        while((contador < finalizar) && (detener == false))
        {
            if(arreglo[contador] > arreglo[contador + 1])
            {
                detener = true;
                estado_arreglo = false;
            } 
            contador = contador + 1;
        }
    }

    return estado_arreglo;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    (void)arreglo;
    (void)cantidad;
    (void)buscado;
    
    int veces_digito = 0;

    if(arreglo == NULL)
    {
        veces_digito = 0;
    }
    else if(cantidad > 0)
    {
        for(size_t i = 0; i < cantidad; i++)
        {
            if(buscado == arreglo[i])
            {
                veces_digito = veces_digito + 1;
            }
        }
    }
    return veces_digito;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    int nuevo_tamano = 0;
    if((arreglo == NULL) || (cantidad < 2))
    {
        nuevo_tamano = 0;
    }
    else
    {
        int existe_el_numero = arreglo_buscar(arreglo, cantidad, valor);
        if(existe_el_numero != -1)
        {
            size_t veces_repetido = arreglo_contar(arreglo, cantidad, valor);
            size_t eliminar_repetido = 0;

            while((eliminar_repetido < veces_repetido) && (veces_repetido != cantidad))
            {
                int intercambiar_valor = 0;
                int posicion_eliminar = arreglo_buscar(arreglo, cantidad, valor);
                int terminar_antes = cantidad - 1;

                for(int i = posicion_eliminar; i < terminar_antes; i++)
                {
                    intercambiar_valor = arreglo[i];
                    arreglo[i] = arreglo[i+1];
                    arreglo[i+1] = intercambiar_valor;
                }
                eliminar_repetido = eliminar_repetido + 1;
                nuevo_tamano = cantidad - eliminar_repetido;
            }
        }
    }
    return nuevo_tamano;

}

size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t cantidad)
{
    size_t total_volcados = 0;

    if((primero == NULL) || (segundo == NULL) || (destino == NULL) ) 
    {
        total_volcados = 0;
    }
    else
    {
        size_t contador_primero = 0;
        size_t contador_segundo = 0;
        size_t contador = 0;

        while((contador < cantidad) && (contador_primero < cantidad_uno) && (contador_segundo < cantidad_dos))
        {
            if(primero[contador_primero] <= segundo[contador_segundo])
            {
                destino[contador] = primero[contador_primero];
                contador_primero = contador_primero + 1;
            }
            else
            {
                destino[contador] = segundo[contador_segundo];
                contador_segundo = contador_segundo + 1;
            }
            contador = contador + 1;
        }

        while((contador < cantidad) && (contador_primero < cantidad_uno))
        {
            destino[contador] = primero[contador_primero];
            contador = contador + 1;
            contador_primero = contador_primero + 1;
        }

        while((contador < cantidad) && (contador_segundo < cantidad_dos))
        {
            destino[contador] = segundo[contador_segundo];
            contador = contador + 1;
            contador_segundo = contador_segundo + 1;
        }

        total_volcados = contador;
    }
    return total_volcados;
}

