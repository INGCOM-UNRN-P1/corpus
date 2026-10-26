# TP C2

En este TP, vamos a trabajar principalmente con arreglos.

Tengan **POR LO MENOS** encarado este TP antes de la proxima clase, hará mas facil la tarea
de entender que pasa con los temas que trataremos.

## Forma de entrega

* Cada archivo debe seguir la estructura indicada dentro de `anon_060.c`, la cual debe
estar completa con su nombre y usuario de GitHub.
* La prolijidad cuenta.
* No mezclen tabuladores y espacios en la indentación.
* En ningún caso se aceptara el uso de variables globales. Toda la información 
necesaria para el funcionamiento de las funciones a desarrollar tienen que ser
pasado como argumentos de las mismas.
* Indiquen las pre y poscondiciones de cada funcion implementada.
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"

# Fecha de entrega

La fecha de entrega de este TP es el dia viernes 2 de septiembre a las 17 horas. (02/09/anon_001)

## Ejercicios

Los tres ejercicios pueden convivir en un solo archivo, para no tener que estar duplicando código.
(la forma correcta de mantener las cosas separadas la veremos mas adelante)

Por lo que la entrega puede ser un archivo como `arreglos.c`

### 1. Cargador de arreglos

Un detalle importante que quedó fuera de la clase, tiene que ver con la forma en la que 
los argumentos de tipo arreglo viajan a una función.

Al pasarlo como `int conjunto[]`, lo que viaja a la funcion, no es el arreglo como bloque,
sino como su ubicacion en la memoria. Por lo tanto, los cambios que le hagan al mismo,
se reflejaran en la variable original. (De la misma manera que `scanf` funciona)

Desarrollar una función que dado un arreglo de numeros enteros, y la cantidad de elementos. 
Solicite valores para completar las posiciones.

Desarrollar tambien una función que permita mostrar el contenido de dicho arreglo, indicando
en que posicion se encuentra cada valor.

Utilicen el valor de `return` para indicar potenciales fallos.

Su programa debe de ser capaz de almacenar e imprimir una cantidad ajustable
en tiempo de compilación.

```C
int cargar_arreglo(int cantidad, int arreglo[]);
int muestra_arreglo(int cantidad, int arreglo[]);
```

## 2. Operaciones con arreglos

Implementar funciones que permitan hacer las siguientes operaciones sobre arreglos de numeros enteros:

 * Promedio
 * Minimo
 * Maximo
 * Ordenar de menor a mayor
 * Ordenar de mayor a menor

## 3. Carga como argumentos

Implementar una funcion que emplee los argumentos del programa para cargar un arreglo, de forma
que sea posible hacer algo como:

```sh
$> ./programa 10 23 4 23 4 5 6 6
```

Pero si no estan estos argumentos, que se utilice la tecnica del punto 1.
