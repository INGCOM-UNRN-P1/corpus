## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
cadenas.c: In function ‘cadena_duplicar_segura’:
cadenas.c:24:28: warning: comparison of integer expressions of different signedness: ‘int’ and ‘size_t’ {aka ‘long unsigned int’} [-Wsign-compare]
   24 |         for ( int i = 0; i < longitud + 1 ; i ++ ){
      |                            ^
cadenas.c: In function ‘cadena_subcadena_dinamica’:
cadenas.c:100:16: error: assignment to ‘char’ from ‘char *’ makes integer from pointer without a cast [-Wint-conversion]
  100 |     destino[0] = "";
      |                ^
cadenas.c:103:8: warning: unused variable ‘restante’ [-Wunused-variable]
  103 | size_t restante = longitud_origen - inicio;
      |        ^~~~~~~~
make[1]: *** [Makefile:61: cadenas.o] Error 1
make: *** [Makefile:17: libs/string] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_9f47f59.log`.
