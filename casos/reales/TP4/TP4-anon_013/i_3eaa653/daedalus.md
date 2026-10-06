## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from ../../libs/p1_test/include/p1_arrays.h:13,
                 from prueba.c:9:
prueba.c: In function ‘_p1_test_func_prueba_arreglo_fusionar’:
prueba.c:140:17: warning: ‘destinonull’ is used uninitialized [-Wuninitialized]
  140 |         0, (int)arreglo_fusionar(arreglo1_2, 5, arreglo2_2, 5, destinonull, 6));
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:832:34: note: in definition of macro ‘ASSERT_INT_EQ_MSG’
  832 |     long long _act = (long long)(actual); \
      |                                  ^~~~~~
prueba.c:139:5: note: in expansion of macro ‘ASSERT_INT_EQ’
  139 |     ASSERT_INT_EQ(
      |     ^~~~~~~~~~~~~
prueba.c:138:10: note: ‘destinonull’ was declared here
  138 |     int *destinonull;
      |          ^~~~~~~~~~~
prueba.c:143:17: warning: ‘arreglonull’ is used uninitialized [-Wuninitialized]
  143 |         0, (int)arreglo_fusionar(arreglonull, 5, arreglo2_2, 5, destino_2, 6));
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:832:34: note: in definition of macro ‘ASSERT_INT_EQ_MSG’
  832 |     l
```

> 📄 **Salida completa:** registrada en `compilacion_3eaa653.log`.
