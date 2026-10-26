# TP C5

Memoria dinámica y archivos

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
  * La descripción de los argumentos que recibe
  * La descripción de los valores que retorna.  
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"
* Para que sea mas facil de trabajar, cada punto debiera estar en un archivo separado.

# Fecha de entrega

La fecha de entrega de este TP es el dia viernes 14 de octubre a las 17 horas. (14/10/anon_001)

# Ejercicios

## Preparativos

Con el objetivo de analizar el tiempo de ejecución de los algoritmos que implementaran en el practico siguiente y reducir la interferencia de partes del programa que no son específicamente parte de la búsqueda, vamos a implementar un conjunto de programas independientes.

### ¿Cómo son los archivos?

La idea es trabajar con archivos que contengan números enteros, uno por línea, en donde el primer número, es la cantidad de números que contiene el archivo.

La idea es trabajar con archivos que contengan números enteros, uno por línea, en donde el primer número, es la cantidad de números que contiene el archivo.

```shell
$> cat archivo_numeros.txt
5
3
-5
3
6
3
```

Usen esta forma de guardar números así podemos intercambiar algoritmos más adelante.

### esta_ordenado?

Implementar la función `esta_ordenado` que dado un conjunto de números, indique: 

- Sí está o no ordenado y

- En qué sentido lo está (ascendente o descendente).

El programa que hace uso de esta función debe de aceptar el nombre de archivo por línea de comandos y mostrar por pantalla (y retornar el código de salida)

```shell
$> ./esta_ordenado archivo_numeros.txt
Si - ascendente
$> echo $? 1
```

Utilizen como código de retorno, `-1` descendente,`0`  no ordenado y `1` como ordenado de forma ascendente.

### ordena

Aprovechando la funció de ordenamiento del TP2, construyan un programa que permita cargar y ordenar un archivo con números.

```
$> ./esta_ordenado archivo_numeros.txt
No
$> ./ordena archivo_numeros.txt asc archivo_ordenado.txt
$> ./esta_ordenado archivo_ordenado.txt
Si - ascendente
```

Este es un ejemplo, en el que primero va el archivo de entrada, luego va el sentido en el que se ordenará y finalmente donde será guardado el resultado.

### generador_lineal

El objetivo de este programa es la generación de archivos con números enteros consecutivos, en donde el programa debe recibir la cantidad de números a generar junto al valor inicial y paso.

```shell
$> ./generador_lineal archivo_numeros.txt 10000 -100 2
Generando archivo_numeros.txt
Con 10000 numeros desde -100 aumentando de a 2
```

En este ejemplo, se creará el archivo `archivo_numeros.txt` con `10000` números a partir de `-100` de forma ascendente

El signo de este argumento indica la dirección en la que se generan los números.

### generador_aleatorio

El objetivo de este programa es la generación de archivos con números enteros al azar, en donde debemos indicar la cantidad de números a generar junto a su rango (mínimo y máximo)

```shell
$> ./generador_aleatorio archivo_numeros.txt 10000 -100 100
Generando archivo_numeros.txt
Con 10000 numeros entre -100 y 100
```

En este ejemplo, se creará el archivo archivo_numeros.txt con 10000 números entre -100 y 100.
