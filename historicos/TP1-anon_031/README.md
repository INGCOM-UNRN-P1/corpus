# Trabajo Práctico 1
## Programación en C

Bienvenidos a Programación 1.

Ingeniería en Computación - Sede Andina - Universidad Nacional de Rio Negro


## Condiciones generales de la entrega
Lo dejo numerado para que sea más fácil referenciarlo en las correcciones.

1. Usen nombres descriptivos siempre.
2. No estamos practicando *Code Golf*, no ahorren en líneas o caracteres 
   y sean lo más descriptivos posible.
4. Lo primordial es la legibilidad de los programas desarrollados, 
   no su eficiencia o rendimiento percibido.
4. Cada punto debe ser entregado en un archivo independiente.
5. El nombre de cada archivo debe ser `tp0ej` seguido del 
   número de ejercicio más `.c` por lo que el primer ejercicio será entonces `tp0ej1.c`
6. Dentro de lo posible y la consigna, mantengan separada la interacción 
   con el usuario del programa a implementar.
7. A no ser de que sea explicitamente pedido, mantengan los programas simples. 
   Y en particular, teniendo en cuenta que las correcciones pueden ser corriendo sus programas 
   sobre GNU/Linux por lo que no es recomendable utilizar funcionalidad que dependa del 
   sistema operativo en el que esten.
8. La indentación no es tan importante como en Python pero esto no implica que su ausencia
   esté justificada. La prolijidad de los trabajos es un factor que puede provocar el 
   rechazo de un Trabajo Practico. Utilicen cuatro espacios para cada bloque de código.

## Parte A - Introducción a la programación en C

### 1. Hola Mundo

Desarrollar un programa que muestre por STDOUT el mensaje "Hola Mundo".

Indicar en un comentario la instrucción de compilación con GCC por linea de comandos.

### 2. El ajedrez y los granos de trigo

Desarrollar un programa que calcule la cantidad de granos de trigo que debería haberle pagado el rey al inventor del tablero de ajedrez.
Suponiendo que en 1kg hay 20000 granos. ¿cuantos kilos debio pagar?

**Leyenda del tablero de ajedrez**
```
El rey deberá pagar un grano por el primer casillero y el doble en los sucesivos hasta llegar al 64° y ultimo.
```

**Ejemplo de salida**
```
Casillero 1 = 1
Casillero 2 = 2
Casillero 3 = 4
Casillero 4 = 8
Casillero 5 = 16
...
Casillero 64 = xxx
El rey deberá entregarle xxx kg
```


### 3. Operadores aritmeticos

Desarrollar un programa que pida al usuario 2 numeros enteros (A y B) y devuelva las siguientes operaciones aritmeticas: multiplicación, división y resto.

**Ejemplo de salida**
```
primer numero: A = 13
segundo numero: B = 3
Operador multiplicacion: A*B = 39
Operador división: A/B = 4
Operador resto: A%B = 1
```

### 4. Multiplos

Desarrollar un programa que pida al usuario 1 numero entero mayor a 100 y devuelva si es multiplico de 2, 3, 4, 5 y 6.

**Ejemplo de salida**
```
Ingrese un numero entero mayor a 100: A = 200
Es multiplo de 2: SI
Es multiplo de 3: NO
Es multiplo de 4: SI
Es multiplo de 5: SI
Es multiplo de 6: NO
```

### 5. Lazos

Desarrollar un programa en el que el usuario ingrese dos números enteros y se muestren
todos los números enteros comprendidos entre estos dos, incluyéndolos.

**Ejemplo de salida**
```
primer numero: -2
segundo numero: 3
-2
-1
0
1
2
3
```

### 6. Factorial

Desarrollar un programa que pida un numero entero y devuelva su factorial

**Calculo de un factorial**
```
n! = 1*2*...*(n-1)*n
```

**Ejemplo de salida**
```
Ingrese el valor n: 5
El factorial de 5!: 120
```

### 7. Factorial *reload

Desarrollar un programa que pida un numero entero y que en lineas sucesivas devuelva su factorial y el de los resultados parciales en orden descendente.

**Ejemplo de salida**
```
Ingrese el valor n: 5
El factorial de 5!: 120
El factorial de 4!: 24
El factorial de 3!: 6
El factorial de 2!: 2
El factorial de 1!: 1
```

### 8. Fibonacci

Desarrollar un programa que pida un numero entero mayor a 10 y que devuelva los numeros de la sucecsión de fibonacci menores a dicho numero.

**Sucesión de fibonacci**
```
los primeros numeros de la sucesión son: 0, 1, 1, 2, 3, 5, 8, 13,...
Los primeros estan definidos: 0 y 1
El resto es la suma de los anteriores.
```


**Ejemplo de salida**
```
Ingrese un numero entero mayor a 100: n: 120
Los numeros de la sucesion de fibonacci menor a 120 son: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
```


### 9. Bucle infinito

Desarrollar un programa que pida un numero entero y determine si es mayor a 100. En caso de no serlo, debera pedir un nuevo numero.

**Ejemplo de salida**
```
Ingrese un numero n: 5
El numero es menor a 100.

Ingrese un numero n: 10
El numero es menor a 100.

Ingrese un numero n: -50
El numero es menor a 100.

Ingrese un numero n: 50
El numero es menor a 100.

Ingrese un numero n: 500
El numero es mayor a 100.
```

## Parte 2 - Funciones y procedimientos

### 1. Dias de la semana

Utilizando la instrucción `switch`, solicitar un número entero comprendido entre el 1 y el 7.
Indicar si el número ingresado esta fuera de este rango.
Mostrar el dia de la semana que corresponde cada número.

```
1 - lunes
2 - martes
3 - miercoles
4 - jueves
5 - viernes
6 - sabado
7 - domingo
```

### 2. Suma Lenta

Escribir una función que haga la suma entre dos números naturales con un lazo de a uno, esto es, sin hacer la operación de manera directa. Esto quiere decir que para hacer la suma entre 4 y 3, las operaciones resultantes deberán ser 4+1+1+1.

Solo es neceario retornar el resultado de la suma entre ambos números.

El programa a implementar que de uso a esta funcion debe pedir el ingreso de dos números por `STDIN` y mostrar el resultado de la suma lenta por `STDOUT`.

```C
int suma_lenta(int numero, int otronumero);
```

### 3.Comparación de números

Escribir una función que reciba dos valores y retorne:
 * Retornar `-1` si el primero es menor que el segundo
 * Retornar `0` si son iguales
 * Retornar `1` si el primero es mayor que el segundo

```C
int compara(int numero, int otronumero);
```

### 4.¿Es un número Primo?

Escribir una función que indique con `1` si un numero indicado es Primo y con un `0` si no lo es.
```C
int es_primo(int numero);
```

### 5. Restas sucesivas
Escribir una función que mediante restas sucesivas, retorne el valor del cociente de dos números naturales.
De la misma manera, implementar una funcion que retorne el resto de la división de dos números naturales.

En el programa a implementar, dar el resultado de la division y del resto con los mismos números.

```C
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);
```

### 6. Compara fechas

Implementar la funcion `compara_fechas` que recibe como argumentos dos cadenas de caracteres 
en el formato "dia/mes/año" y las compare de forma que retorne 

* -1 si la primera fecha es anterior a la segunda
* 0 si las fechas son iguales
* 1 si la primera fecha es posterior a la segunda

```c
int compara_fechas(char *primera, char *segunda)
```

# Plantilla de archivo

```C
/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{

}
```

# Observación general

Los nombres de los archivos ejecutables finales en los ejemplos usan la forma de Windows
recuerden que en Linux (y MacOS) la parte `.exe` no es necesaria
