/**
 * @file vector.h
 * @brief Biblioteca libvector: manejo de bloques contiguos de enteros en heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica con malloc/calloc/realloc debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - No se emplean estructuras (structs); la gestión se realiza mediante punteros directos
 *   (int*), dobles punteros (int**) y tamaños pasados por parámetro.
 * 
 * 
 * 
 * 
 * @brief crear_bloque_enteros
 *        funcion que utiliza calloc para generar un bloque de memoria
 *          inicializada en 0.
 * @param cantidad de numeros enteros a alojar en el puntero
 * @return NULL si fallo el calloc o si cantidad ==0
 * @return puntero de memoria asignada
 * 
 * [!]se debe librerar memoria con free luego de su uso.[!]
 * 
 * 
 * 
 * 
 * ----------------------------------------------------------------------
 * @brief liberar_bloque_enteros
 *        Libera memoria de un puntero y aplica null al mismo/
 * @param puntero_bloque puntero a librerar y nulificar.
 * @return no retorna nada, solo realiza la operacoin./
 * 
 * ----------------------------------------------------------------------
 * @brief redimensionar_bloque_enteros
 *        utiliza realloc para modificar el tama;o del boque asignado
 *        bajo nueva_cantidad.
 * @param bloque puntero a realocar
 * @param nueva_cantidad para el punterop nuevo.
 * @return NULL SI: nueva cantidad =0
 *                  realloc falla.
 * @return bloque_realloc si la relocacion es ok.
 * 
 * 
 * _------------------------------------------------------------------------
 * 
 * @brief fusionar_bloques_enteros
 *        fusiona dos bloque sde datos de enteros, en uno nuevo en heap..
 *        reserva usando malloc la totalidad de cant_primero + cant_segundo
 *        y posteriormente concantena
 * 
 * @param primero puntero a primer bloque de data
 * @param cant_primero size_t de primero
 * @param segundo puntero al segundo bloque de data.\
 * @param cant_segundo size_t de segundo
 * 
 * @return Puntero al nuevo bloque de info.
 * @return null si: Primero o segundo = NULL
 *         cant total que es la suma de cant_primero y cant_segundo  es 0
 *         falla malloc.
 *        
 * -----------------------------------------------------------------------
 * @brief agregar_al_bloque_enteros
 *        agrega un entero a unloque en memoria dinamica
 *        
 * @param puntero_bloque direccion del puntero 
 * @param cantidad puntero de variable de cantidad
 * @param valor que se inserta al final
 * 
 * @return true si asigno ok
 * @return false si alguno es null, o fallo realloc. 
 * 
 * 
 * 
 * 
 * 
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>


int *crear_bloque_enteros(size_t cantidad);


void liberar_bloque_enteros(int **puntero_bloque);


int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);


int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);

 bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
