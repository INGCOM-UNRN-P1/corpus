## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
vector.c: In function ‘crear_bloque_enteros’:
vector.c:15:20: error: initialization of ‘char *’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
   15 |     char *bloque = (int *)calloc(cantidad, sizeof(int));
      |                    ^
vector.c:20:12: error: returning ‘char *’ from a function with incompatible return type ‘int *’ [-Wincompatible-pointer-types]
   20 |     return bloque;
      |            ^~~~~~
make[1]: *** [Makefile:61: vector.o] Error 1
make: *** [Makefile:17: libs/vector] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_dbcad9b.log`.
