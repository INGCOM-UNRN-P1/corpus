## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
texto_dinamico.c: In function ‘cadena_repetir’:
texto_dinamico.c:77:32: error: ‘SIZE_MAX’ undeclared (first use in this function)
   77 |     if ((len > 0) && (veces > (SIZE_MAX / len)))
      |                                ^~~~~~~~
texto_dinamico.c:10:1: note: ‘SIZE_MAX’ is defined in header ‘<stdint.h>’; this is probably fixable by adding ‘#include <stdint.h>’
    9 | #include <ctype.h>
  +++ |+#include <stdint.h>
   10 | 
texto_dinamico.c:77:32: note: each undeclared identifier is reported only once for each function it appears in
   77 |     if ((len > 0) && (veces > (SIZE_MAX / len)))
      |                                ^~~~~~~~
make[1]: *** [Makefile:47: texto_dinamico.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio2] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_a20aadc.log`.
