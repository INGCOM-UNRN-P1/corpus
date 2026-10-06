## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:54:9: error: implicit declaration of function ‘free’ [-Wimplicit-function-declaration]
   54 |         free(promedios);
      |         ^~~~
main.c:9:1: note: include ‘<stdlib.h>’ or provide a declaration of ‘free’
    8 | #include "consulta_csv.h"
  +++ |+#include <stdlib.h>
    9 | 
main.c:54:9: warning: incompatible implicit declaration of built-in function ‘free’ [-Wbuiltin-declaration-mismatch]
   54 |         free(promedios);
      |         ^~~~
main.c:54:9: note: include ‘<stdlib.h>’ or provide a declaration of ‘free’
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio6] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_fc0a9b3.log`.
