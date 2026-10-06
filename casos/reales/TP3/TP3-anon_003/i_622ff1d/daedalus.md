## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:21:5: error: implicit declaration of function ‘ordenar_par’ [-Wimplicit-function-declaration]
   21 |     ordenar_par(&a,&b);
      |     ^~~~~~~~~~~
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio1] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_622ff1d.log`.
