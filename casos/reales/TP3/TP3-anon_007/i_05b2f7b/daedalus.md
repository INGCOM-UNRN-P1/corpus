## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
arreglos.c: In function ‘arreglo_ok’:
arreglos.c:17:37: warning: comparison of unsigned expression in ‘>= 0’ is always true [-Wtype-limits]
   17 |     if (arreglo != NULL && cantidad >= 0)
      |                                     ^~
cadenas.c: In function ‘cadena_segura’:
cadenas.c:18:12: warning: unused variable ‘contador’ [-Wunused-variable]
   18 |     size_t contador = 0;
      |            ^~~~~~~~
estadistica.c: In function ‘contar_en_rango’:
estadistica.c:62:28: warning: comparison of unsigned expression in ‘>= 0’ is always true [-Wtype-limits]
   62 |         if (*coincidencias >= 0)
      |                            ^~
main.c: In function ‘main’:
main.c:18:5: error: implicit declaration of function ‘imprimir_arreglo’; did you mean ‘invertir_arreglo’? [-Wimplicit-function-declaration]
   18 |     imprimir_arreglo(arreglo, cantidad_arreglo);
      |     ^~~~~~~~~~~~~~~~
      |     invertir_arreglo
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio3] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_05b2f7b.log`.
