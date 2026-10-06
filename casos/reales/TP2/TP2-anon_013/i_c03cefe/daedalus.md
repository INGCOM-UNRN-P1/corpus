## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:10:
prueba.c: In function ‘_p1_test_func_prueba_arreglo_fusionar’:
prueba.c:135:27: warning: ‘destinonull’ is used uninitialized [-Wuninitialized]
  135 |     ASSERT_INT_EQ(0, (int)arreglo_fusionar(arreglo1_2, 5, arreglo2_2, 5, destinonull, 6));
      |                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:832:34: note: in definition of macro ‘ASSERT_INT_EQ_MSG’
  832 |     long long _act = (long long)(actual); \
      |                                  ^~~~~~
prueba.c:135:5: note: in expansion of macro ‘ASSERT_INT_EQ’
  135 |     ASSERT_INT_EQ(0, (int)arreglo_fusionar(arreglo1_2, 5, arreglo2_2, 5, destinonull, 6));
      |     ^~~~~~~~~~~~~
prueba.c:134:10: note: ‘destinonull’ was declared here
  134 |     int *destinonull;
      |          ^~~~~~~~~~~
prueba.c:137:27: warning: ‘arreglonull’ is used uninitialized [-Wuninitialized]
  137 |     ASSERT_INT_EQ(0, (int)arreglo_fusionar(arreglonull, 5, arreglo2_2, 5, destino_2, 6));
      |                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:832:34: note: in defin
```

> 📄 **Salida completa:** registrada en `compilacion_c03cefe.log`.
