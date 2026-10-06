## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:17:3: error: implicit declaration of function ‘ordenar_par’ [-Wimplicit-function-declaration]
   17 |   ordenar_par(&x, &y);
      |   ^~~~~~~~~~~
main.c:22:3: error: implicit declaration of function ‘probar_tria’ [-Wimplicit-function-declaration]
   22 |   probar_tria(1, 2, 3);
      |   ^~~~~~~~~~~
main.c:32:7: error: implicit declaration of function ‘sumar_acumulado’ [-Wimplicit-function-declaration]
   32 |   if (sumar_acumulado(datos, 5, &resultado))
      |       ^~~~~~~~~~~~~~~
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio1] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_991dab5.log`.
