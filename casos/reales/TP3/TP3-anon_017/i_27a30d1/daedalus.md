## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
prueba.c: In function ‘_p1_test_func_prueba_distancia_punteros’:
prueba.c:34:13: warning: missing terminating " character
   34 |     SUBCASE("Caso nulos);
      |             ^
prueba.c:49:2: error: unterminated argument list invoking macro ‘SUBCASE’
   49 | }
      |  ^
prueba.c:34:5: error: ‘SUBCASE’ undeclared (first use in this function)
   34 |     SUBCASE("Caso nulos);
      |     ^~~~~~~
prueba.c:34:5: note: ‘SUBCASE’ is a function-like macro and might be used incorrectly
prueba.c:34:5: note: each undeclared identifier is reported only once for each function it appears in
prueba.c:34:12: error: expected ‘;’ at end of input
   34 |     SUBCASE("Caso nulos);
      |            ^
      |            ;
......
prueba.c:34:5: error: expected declaration or statement at end of input
   34 |     SUBCASE("Caso nulos);
      |     ^~~~~~~
In file included from prueba.c:11:
prueba.c: At top level:
../../libs/p1_test/include/p1_test.h:573:32: warning: ‘_p1_test_func_prueba_distancia_punteros’ defined but not used [-Wunused-function]
  573 | #define TEST(name) static void _p1_test_func_##name(void)
      |                                ^~~~~~~~~~~~~~
prueba.c:32:1: note: in expansion of
```

> 📄 **Salida completa:** registrada en `compilacion_27a30d1.log`.
