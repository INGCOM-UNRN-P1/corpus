## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:9:
prueba.c: In function ‘main’:
../../libs/p1_test/include/p1_test.h:783:13: error: expected ‘)’ before ‘_p1_prev_segv’
  783 |     (void (*_p1_prev_segv)(int) = NULL; void (*_p1_prev_fpe)(int) = NULL;      \
      |             ^~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:1108:9: note: in expansion of macro ‘_P1_SIG_VARS’
 1108 |         _P1_SIG_VARS;                                                          \
      |         ^~~~~~~~~~~~
prueba.c:80:5: note: in expansion of macro ‘RUN_TEST’
   80 |     RUN_TEST(prueba_cadena_longitud);
      |     ^~~~~~~~
../../libs/p1_test/include/p1_test.h:783:27: error: expected ‘)’ before ‘(’ token
  783 |     (void (*_p1_prev_segv)(int) = NULL; void (*_p1_prev_fpe)(int) = NULL;      \
      |     ~                     ^
../../libs/p1_test/include/p1_test.h:1108:9: note: in expansion of macro ‘_P1_SIG_VARS’
 1108 |         _P1_SIG_VARS;                                                          \
      |         ^~~~~~~~~~~~
prueba.c:80:5: note: in expansion of macro ‘RUN_TEST’
   80 |     RUN_TEST(prueba_cadena_longitud);
      |     ^~~~~~~~
../../libs/p1_test/include/p1_test.h:1109:27: error: ‘_p1_prev_s
```

> 📄 **Salida completa:** registrada en `compilacion_e0bfb42.log`.
