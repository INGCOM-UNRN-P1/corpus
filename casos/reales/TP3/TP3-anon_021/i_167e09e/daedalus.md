## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
recorrido.c: In function ‘invertir_arreglo’:
recorrido.c:57:17: error: implicit declaration of function ‘intercambiar’ [-Wimplicit-function-declaration]
   57 |                 intercambiar(inicio, fin);//paso direccion de los dos extremos
      |                 ^~~~~~~~~~~~
make[1]: *** [Makefile:47: recorrido.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio3] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_167e09e.log`.
