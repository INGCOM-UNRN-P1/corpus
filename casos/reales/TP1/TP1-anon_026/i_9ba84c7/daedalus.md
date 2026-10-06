## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
consola.c: In function ‘leer_logico’:
consola.c:113:21: error: implicit declaration of function ‘tolower’ [-Wimplicit-function-declaration]
  113 |         respuesta = tolower((unsigned char)respuesta);
      |                     ^~~~~~~
consola.c:3:1: note: include ‘<ctype.h>’ or provide a declaration of ‘tolower’
    2 | #include <stdio.h>
  +++ |+#include <ctype.h>
    3 | 
make[1]: *** [Makefile:37: consola.o] Error 1
make: *** [Makefile:17: libs/consola] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_9ba84c7.log`.
