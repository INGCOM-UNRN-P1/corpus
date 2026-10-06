## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from cadenas.c:12:
cadenas.h:185:1: warning: ‘/*’ within comment [-Wcomment]
  185 | /* =========================================================================
cadenas.c: In function ‘cadena_subcadena’:
cadenas.c:143:51: error: ‘SIZE_MAX’ undeclared (first use in this function)
  143 |     size_t largo_origen = cadena_longitud(origen, SIZE_MAX);
      |                                                   ^~~~~~~~
cadenas.c:16:1: note: ‘SIZE_MAX’ is defined in header ‘<stdint.h>’; this is probably fixable by adding ‘#include <stdint.h>’
   15 | #include <ctype.h>
  +++ |+#include <stdint.h>
   16 | 
cadenas.c:143:51: note: each undeclared identifier is reported only once for each function it appears in
  143 |     size_t largo_origen = cadena_longitud(origen, SIZE_MAX);
      |                                                   ^~~~~~~~
make[1]: *** [Makefile:61: cadenas.o] Error 1
make: *** [Makefile:17: libs/cadenas] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_eef3518.log`.
