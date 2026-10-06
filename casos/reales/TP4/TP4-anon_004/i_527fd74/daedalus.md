## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
matriz_dinamica.c:60:40: error: unknown type name ‘bool’
   60 | static char *leer_linea(FILE *archivo, bool *error)
      |                                        ^~~~
matriz_dinamica.c:15:1: note: ‘bool’ is defined in header ‘<stdbool.h>’; this is probably fixable by adding ‘#include <stdbool.h>’
   14 | #include <string.h>
  +++ |+#include <stdbool.h>
   15 | 
matriz_dinamica.c:110:8: error: unknown type name ‘bool’
  110 | static bool convertir_entero(const char *texto, int *resultado)
      |        ^~~~
matriz_dinamica.c:110:8: note: ‘bool’ is defined in header ‘<stdbool.h>’; this is probably fixable by adding ‘#include <stdbool.h>’
matriz_dinamica.c: In function ‘convertir_entero’:
matriz_dinamica.c:120:16: error: ‘false’ undeclared (first use in this function)
  120 |         return false;
      |                ^~~~~
matriz_dinamica.c:120:16: note: ‘false’ is defined in header ‘<stdbool.h>’; this is probably fixable by adding ‘#include <stdbool.h>’
matriz_dinamica.c:120:16: note: each undeclared identifier is reported only once for each function it appears in
matriz_dinamica.c:140:12: error: ‘true’ undeclared (first use in this function)
  140 |     return true;
      |   
```

> 📄 **Salida completa:** registrada en `compilacion_527fd74.log`.
