## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:21:40: error: request for member ‘menor’ in something not a structure or union
   21 |     printf("ordenar_par: antes(%d, %d)". menor, mayor);
      |                                        ^
main.c:34:5: error: expected identifier or ‘(’ before ‘if’
   34 |     if (sumar_acumulado(datos, 4, &suma))
      |     ^~
main.c:33:15: warning: unused variable ‘suma’ [-Wunused-variable]
   33 |     long long suma = 0,
      |               ^~~~
main.c:32:9: warning: unused variable ‘datos’ [-Wunused-variable]
   32 |     int datos[] = {10, 20, 30, 40};
      |         ^~~~~
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio1] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_f4ab418.log`.
