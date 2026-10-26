# TP C3

En este TP, vamos a trabajar con estructuras.

## Forma de entrega

* Cada archivo debe seguir la estructura indicada dentro de `anon_060.c`, la cual debe
estar completa con su nombre y usuario de GitHub.
* La prolijidad cuenta.
* No mezclen tabuladores y espacios en la indentación.
* En ningún caso se aceptara el uso de variables globales. Toda la información 
  necesaria para el funcionamiento de las funciones a desarrollar tienen que ser
  pasado como argumentos de las mismas.
* Cada funcion implementada debe contar con un comentario sobre su prototipo que describa:
  * Las pre y poscondiciones de cada funcion implementada de forma coloquial
  * La descripción de los arguementos que recibe
  * La descripción de los valores que retorna.  
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"

# Fecha de entrega

La fecha de entrega de este TP es el dia viernes 16 de septiembre a las 17 horas. (16/09/anon_001)

## Ejercicios


### 1. Fracciones

Desarrollar las funciones necesarias para operar con fracciones de números enteros.

```C
typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion_t;
```
Operaciones a implementar:
 * Mostrar una fraccion por consola.
 * Suma entre fracciones
 * Multiplicacion entre fracciones
 * Suma con un número entero.
 
El `main` para este ejercicio debe utilizar todas estas operaciones.

Este ejercicio no requiere de la utilización de punteros.

### 2. División Lenta II

Unificar las funciones de división lenta del TP1 de forma que la funcion retorne una estructura
representando los valores posibles.

Crear las funciones de soporte necesarias.

### 3. Gestionando el `tiempo_t`

Desarrollar una estructura y funciones que permitan realizar las siguientes operaciones con 
tiempo expresado en horas, minutos y segundos.

 * Crear `tiempo_t`
 * Mostrar `tiempo_t`
 * Sumar segundos
 * Sumar minutos
 * Sumar horas
 * Sumar dos `tiempo_t`
 
