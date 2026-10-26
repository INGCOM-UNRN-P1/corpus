# TP 5 Punteros, arreglos y estructuras

La entrega de este trabajo debe ser hecha con el pull request (cualquier cosa la vemos en Discord).

Agreguen al principio del archivo un comentario del tipo:

 ```C
 /*************************
  * Ingenieria en Computación - UNRN Andina
  * Programación 1
  * minombredeusuario de GitHub
  *************************/
 ```

## Ejercicio 1

Escriba un programa corto en `C` que declare e inicialice a cualquier valor deseado, sin ser necesario que sea ingresado por el usuario, variables de tipo `double`, `int` y `char`.  A continuación, declare e inicialice un puntero a cada una de las tres variables. Su programa debe imprimir la dirección y el valor almacenado y el tamaño de la memoria (en bytes) de cada una de las seis variables.

Utilice el especificador de formato "0x% x" para imprimir direcciones en hexadecimal. usted debería ver direcciones que se parecen a esto: "0xbfe55918". El prefijo de caracteres "0x" se usan para indicar que se está utilizando la notación hexadecimal; el resto de los dígitos dan la dirección en sí.

Para obtener los tamaños en memoria de las variables, utilice el operador `sizeof` para determinar el
tamaño de memoria asignado para cada variable.

Para armar la salida en columnas, pueden usar tabuladores `\t` en el string del `printf`.

**Salida esperada**

```
La direccion del char		____ es 0x______
La direccion del int		____ es 0x______
La direccion del double		____ es 0x______
La direccion del char*		____ es 0x______
La direccion del int*		____ es 0x______
La direccion del double*	____ es 0x______

La valor del char			____ es   ______
La valor del int			____ es   ______
La valor del double			____ es   ______
La valor del char*			____ es 0x______
La valor del int*			____ es 0x______
La valor del double*		____ es 0x______

El tamaño del char			es ______ bytes
El tamaño del int			es ______ bytes
El tamaño del double		es ______ bytes
El tamaño del char*			es ______ bytes
El tamaño del int*			es ______ bytes
El tamaño del double*		es ______ bytes
```

En donde el primer espacio es para el nombre de la variable

## Ejercicio 2 - Strings seguros

**Implementen no menos de tres de estas funciones, idealmente todas. La practica nunca sobra.**

Manipular un arreglo de manera segura es poder limitar la cantidad de posiciones que serán recorridas en el caso de que la cadena de caracteres no cuente con su carácter de terminación (`\0`).

* Las funciones a implementar no pueden utilizar las funciones de la librería.
* Implementar las funciones indicadas a continuación en un único programa.
* Implementar un programa que haga uso de estas funciones con datos ingresados por la consola.

Retornen números negativos para las situaciones de error en el programa, como que la cadena de destino es mas chica de lo que se necesita. Utilicen `#define` para darles un nombre concreto a estas situaciones, por ejemplo:

```c
#define CADENA_CORTA -1
```

### Largo de cadenas

Implementar una función que cuente el largo de una cadena de texto de manera segura

```c
int largo_cadena(char *cadena, int capacidad_cadena);
```

La función debe retornar el largo de la cadena o el código de error correspondiente.

### Inserción de cadenas

Implementar una función que inserte una cadena en otra luego de la posición indicada de manera segura.

```C
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion);
```

**Ejemplo**

Insertar "HOLA" en "Mundo" en la posición 2 daría como resultado "MunHOLAdo"

La función debe retornar el largo de la cadena destino o el código de error correspondiente.

### Copia de cadenas

Implementar una función que copie una cadena en otra y deje solo un `\0` en la cadena destino

```C
int copiadora(char *origen, char *destino, int capacidad_destino);
```

La función debe retornar el largo de la cadena destino o el código de error correspondiente.

### Limpieza

Implementar una función que limpie la cadena de todos los caracteres que no sean los alfanuméricos (`AZaz09`) menos el `\0` en una cadena diferente a la de entrada.

```C
int limpiadora(char *origen, char *destino, int capacidad_destino);
```

La función debe retornar el largo de la cadena destino o el código de error correspondiente.

### Inversor

Implementar una función que en un string destino devuelva el de origen invertido.

```C
int inversor(char* origen, char* destino, int capacidad_destino);
```

**Ejemplo**

Hola -> aloH

### Comparación

Implementar una función que indique el ordenamiento alfabético de dos cadenas (solo minúsculas)

* -1 la primera cadena va antes de que las segunda
* 0 ambas cadenas son iguales
* 1 la primera cadena va después que la segunda.

```C
int compara(char* primera, char *segunda);
```

### Palindromo

Implementar una función que indique con VERDADERO si la cadena es un palindromo, con FALSO si no lo es o indicar un error si no posee `\0`.

Una palabra es palindromo cuando se puede leer de la misma manera en ambas direcciones.

Ignoren mayúsculas y minúsculas.

```C
int es_palindromo(char *cadena, int largo);
```

Neuquen -> es palindromo

## Ejercicio 3 - Búsqueda

Implementar una función que retorne un puntero de una cadena a la primera ocurrencia de un string o `NULL` si no se encuentra

```C
char* busqueda(char *cadena, int largo, char *busqueda);
```

Una observación importante. El puntero tiene que ser relativo a la cadena que se recibe como argumento.

## Ejercicio 4 - Agenda

Implementar las funciones necesarias para manipular una agenda de 100 posiciones.

No es necesario que la agenda esté ordenada, pero puede ser un buen ejercicio adicional.

Solo debe existir una agenda en memoria.

Como no es necesario manipular numericamente el numero de telefono, lo guardamos como un string (que permite guardarlo incluso con formato: +54-9-294 462 9159).

A continuación, la estructura de datos base, de acá pueden agregar los campos que crean convenientes.

```C
struct contacto{
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
};

struct agenda {
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
};
```
No olviden definir las constantes necesarias para el programa.

Operaciones a implementar.

* Agregar contacto al final.
* Borrar por posición
* Mostrar por posición

Operaciones opcionales a implementar

* Borrar por nombre

## Ejercicio 5 -  División de cadenas segura

Implementar una función que divida una cadena en lineas por los caracteres de salto de linea `\n`. 

El programa que hace uso de esta función debe tomar el string desde la linea de comandos y luego mostrar cada linea por separado.

Este ejercicio es una version simplificada de la funcion `strtok` presente en `string.h`. Una funcion que no pueden utilizar para resolver el ejercicio pero si para comparar resultados.

La funcion debe recibir el string a dividir junto a su largo maximo (para funcionar de manera segura).

Aparte de esos argumentos, tambien es necesario pasar un puntero a un arreglo de strings junto a sus dos limites, el maximo de caracteres por string y el maximo de strings. Esto lo hace funcionar escencialmente como una matriz. En la misma, se debe retornar una copia de cada linea (menos el `\n`). 

Utilicen variables con un tamaño razonable y codifiquen las faltas de espacio con constantes para el retorno de la función.

Este ejercicio tiene una variación muy interesante utilizando punteros.

Esta variacion permite ahorrar el espacio y el trabajo de la copia de los strings, en lugar de retornar una copia de los strings, se retorna un arreglo de punteros relativos al primer string, escencialmente utilizando en partes el primer string (recordando que cada parte debe terminar con `\0`).

