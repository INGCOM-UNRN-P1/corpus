## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:9:
../../libs/p1_test/include/p1_test.h:573:32: warning: ‘_p1_test_func_prueba_arreglo_compactar’ defined but not used [-Wunused-function]
  573 | #define TEST(name) static void _p1_test_func_##name(void)
      |                                ^~~~~~~~~~~~~~
prueba.c:99:1: note: in expansion of macro ‘TEST’
   99 | TEST(prueba_arreglo_compactar)
      | ^~~~
cadenas.c: In function ‘cadena_longitud’:
cadenas.c:25:20: warning: ordered comparison of pointer with integer zero [-Wpedantic]
   25 |     else if(cadena > 0)
      |                    ^
cadenas.c:28:55: warning: comparison of integer expressions of different signedness: ‘int’ and ‘size_t’ {aka ‘long unsigned int’} [-Wsign-compare]
   28 |         while((cadena[contador] != '\0') && (contador < capacidad))
      |                                                       ^
cadenas.c: In function ‘cadena_copiar’:
cadenas.c:52:15: error: ‘i’ undeclared (first use in this function)
   52 |         while(i < capacacidad && arreglo[i] != 0)
      |               ^
cadenas.c:52:15: note: each undeclared identifier is reported only once for each function it appears in
cadenas.c:52:19: error: ‘capacacidad’
```

> 📄 **Salida completa:** registrada en `compilacion_ef5efe1.log`.
