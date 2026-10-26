# TP1 C1

En este TP, vamos a reutilizar las consignas del TP-1 de Python que usamos el cuatrimestre anterior.

El objetivo de esta practica es que comienzen a programar en C, aprovechando que tienen resueltos estos ejercicios.

## Forma de entrega

* Cada punto debe ser entregado en un archivo independiente
* El nombre de cada archivo debe ser ser `ejercicio` seguido 
del numero de ejercicio mas `.c` (el primer ejercicio sera entonces `ejercicio1.c`
* Cada archivo debe seguir la estructura indicada dentro de `anon_060.c`, la cual debe
estar completa con su nombre y usuario de GitHub. 
* En ningún caso se aceptara el uso de variables globales. Toda la información 
necesaria para el funcionamiento de las funciones a desarrollar tienen que ser
pasado como argumentos de las mismas.
* Se provee el prototipo en Python de la funcion a implementar en todos los ejercicios, 
pero pueden crear mas funciones aparte de la pedida.
* Indiquen las pre y poscondiciones de su algoritmo.
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"

## Ejercicios

### 1. Hola Mundo

Desarrollar un programa que muestre por STDOUT el mensaje "Hola Mundo".

Indicar en un comentario la instrucción de compilación con GCC por linea de comandos.

### 2. Conversión de temperaturas

Se quiere transformar temperaturas en grados fahrenheit a grados centígrados y viceversa.

Escribir las funciones para convertir la temperatura en grados centigrados en fahrenheit como 
un número decimal, utilice esta formula para calcular los grados centígrados y retorne el 
resultado obtenido. Y viceversa.

``` python
def convertir_a_fahrrenheit(centigrados):
def convertir_a_centigrados(fahrenheit):
```
### 3. Números positivos y negativos

Escribir una función que reciba un número e indique si el mismo es positivo, negativo o cero con un numero entero y utilizando operaciones de suma y resta.

``` python
def signo(numero):
```

### 4. Comparación de números

Escribir una función que utilizando sumas y restas, reciba dos valores y retorne:
 * Retornar `-1` si el primero es menor que el segundo
 * Retornar `0` si son iguales
 * Retornar `1` si el primero es mayor que el segundo
 
``` python
def compara(numero, otro_numero):
```

### 5. Suma lenta

Escribir una función que haga la suma entre dos números enteros sin hacer la operación de 
manera directa. Esto quiere decir que para hacer la suma entre 4 y 3, las operaciones 
resultantes deberán ser 4+1+1+1.

La funcion debe ser capaz de sumar cualquier numero entero positivo y negativo.

``` python
def suma_lenta(numero, otro_numero):
```

### 6. Divisiones
Escribir una función que mediante restas sucesivas, obtenga el valor del 
cociente y el resto de dos números enteros.

``` python
def division_lenta(dividendo, divisor):

def cociente_lento(dividendo, divisor):
```


### 7. Números primos
Escribir una función que indique con `True` si un numero indicado es Primo.

``` python
def es_primo(numero):
```

### 8. Palíndromo
Escribir una función que indique con True si una palabra o frase ingresada se trata de un palindromo.
Palíndromo, es si se lee igual de derecha a izquierda que de izquierda a derecha.

``` python
def es_palindromo(texto):
```

### 9. Multiplos de
Escribir una función que indique con `True` si un número entero es multiplo de otro, utilizando sumas y restas.

``` python
def es_multiplo(numero, multiplo):
```

### 10. Factorial

Desarrollar un programa obtenga el factorial de un número entero.

``` python
def factorial(numero, ):
```