## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:10:
prueba.c: In function ‘_p1_test_func_prueba_cadena_entero’:
prueba.c:120:57: error: ‘INT_MIN’ undeclared (first use in this function)
  120 |     ASSERT_TRUE(cadena_entero(destino, sizeof(destino), INT_MIN));
      |                                                         ^~~~~~~
../../libs/p1_test/include/p1_test.h:811:11: note: in definition of macro ‘ASSERT_TRUE_MSG’
  811 |     if (!(cond)) { \
      |           ^~~~
prueba.c:120:5: note: in expansion of macro ‘ASSERT_TRUE’
  120 |     ASSERT_TRUE(cadena_entero(destino, sizeof(destino), INT_MIN));
      |     ^~~~~~~~~~~
prueba.c:12:1: note: ‘INT_MIN’ is defined in header ‘<limits.h>’; this is probably fixable by adding ‘#include <limits.h>’
   11 | #include "cadenas.h"
  +++ |+#include <limits.h>
   12 | 
prueba.c:120:57: note: each undeclared identifier is reported only once for each function it appears in
  120 |     ASSERT_TRUE(cadena_entero(destino, sizeof(destino), INT_MIN));
      |                                                         ^~~~~~~
../../libs/p1_test/include/p1_test.h:811:11: note: in definition of macro ‘ASSERT_TRUE_MSG’
  811 |     if (!(cond)) { \
      |           ^~~~
```

> 📄 **Salida completa:** registrada en `compilacion_e4b6215.log`.
