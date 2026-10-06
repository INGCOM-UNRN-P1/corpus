## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:13:5: error: implicit declaration of function ‘prinft’; did you mean ‘printf’? [-Wimplicit-function-declaration]
   13 |     prinft("====================================\n\n");
      |     ^~~~~~
      |     printf
main.c:26:9: error: implicit declaration of function ‘liberar_arreglo_cadenas’; did you mean ‘liberar_arreglo_cadena’? [-Wimplicit-function-declaration]
   26 |         liberar_arreglo_cadenas(&tokens, cantidad);
      |         ^~~~~~~~~~~~~~~~~~~~~~~
      |         liberar_arreglo_cadena
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio5] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_c853e84.log`.
