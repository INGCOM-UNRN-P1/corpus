## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
prueba.c:181:1: error: expected identifier or ‘(’ before ‘}’ token
  181 | }
      | ^
In file included from prueba.c:10:
../../libs/p1_test/include/p1_test.h:573:32: warning: ‘_p1_test_func_prueba_agregar_al_bloque_enteros’ defined but not used [-Wunused-function]
  573 | #define TEST(name) static void _p1_test_func_##name(void)
      |                                ^~~~~~~~~~~~~~
prueba.c:129:1: note: in expansion of macro ‘TEST’
  129 | TEST(prueba_agregar_al_bloque_enteros)
      | ^~~~
../../libs/p1_test/include/p1_test.h:573:32: warning: ‘_p1_test_func_prueba_fusionar_bloques_enteros’ defined but not used [-Wunused-function]
  573 | #define TEST(name) static void _p1_test_func_##name(void)
      |                                ^~~~~~~~~~~~~~
prueba.c:83:1: note: in expansion of macro ‘TEST’
   83 | TEST(prueba_fusionar_bloques_enteros)
      | ^~~~
../../libs/p1_test/include/p1_test.h:573:32: warning: ‘_p1_test_func_prueba_bloque_enteros_redimensionar_casos_borde’ defined but not used [-Wunused-function]
  573 | #define TEST(name) static void _p1_test_func_##name(void)
      |                                ^~~~~~~~~~~~~~
prueba.c:55:1: note: in expansion of macro ‘TEST’
  
```

> 📄 **Salida completa:** registrada en `compilacion_a770357.log`.
