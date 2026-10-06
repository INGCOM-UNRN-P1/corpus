## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
cadenas.c: In function ‘cadena_longitud’:
cadenas.c:19:45: error: expected expression before ‘)’ token
   19 |         for (size_t i = 0; (i < capacidad &&) (cadena[i] != '\0'); i++)
      |                                             ^
cadenas.c: In function ‘cadena_copiar’:
cadenas.c:33:58: error: stray ‘\’ in program
   33 |         for (i = 0; (i < capacidad - 1) && (origen[i] != \0); i++)
      |                                                          ^
make[1]: *** [Makefile:61: cadenas.o] Error 1
make: *** [Makefile:17: libs/cadenas] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_e7f5be4.log`.
