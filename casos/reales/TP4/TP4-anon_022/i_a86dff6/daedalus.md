## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:7:
prueba.c: In function ‘_p1_test_func_prueba_matriz_destruir’:
prueba.c:74:17: error: ‘true’ undeclared (first use in this function)
   74 |     ASSERT_TRUE(true);
      |                 ^~~~
../../libs/p1_test/include/p1_test.h:811:11: note: in definition of macro ‘ASSERT_TRUE_MSG’
  811 |     if (!(cond)) { \
      |           ^~~~
prueba.c:74:5: note: in expansion of macro ‘ASSERT_TRUE’
   74 |     ASSERT_TRUE(true);
      |     ^~~~~~~~~~~
prueba.c:9:1: note: ‘true’ is defined in header ‘<stdbool.h>’; this is probably fixable by adding ‘#include <stdbool.h>’
    8 | #include "matriz_dinamica.h"
  +++ |+#include <stdbool.h>
    9 | 
prueba.c:74:17: note: each undeclared identifier is reported only once for each function it appears in
   74 |     ASSERT_TRUE(true);
      |                 ^~~~
../../libs/p1_test/include/p1_test.h:811:11: note: in definition of macro ‘ASSERT_TRUE_MSG’
  811 |     if (!(cond)) { \
      |           ^~~~
prueba.c:74:5: note: in expansion of macro ‘ASSERT_TRUE’
   74 |     ASSERT_TRUE(true);
      |     ^~~~~~~~~~~
make[1]: *** [Makefile:47: prueba.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio4] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_a86dff6.log`.
