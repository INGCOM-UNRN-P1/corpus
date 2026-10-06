## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
consola.c: In function ‘leer_flotante’:
consola.c:77:20: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘float *’ [-Wformat=]
   77 |         if(scanf("%d", &valor) == 1)
      |                   ~^   ~~~~~~
      |                    |   |
      |                    |   float *
      |                    int *
      |                   %e
consola.c: In function ‘leer_caracter’:
consola.c:122:14: warning: format ‘%s’ expects a matching ‘char *’ argument [-Wformat=]
  122 |     printf("%s, mensaje\n");
      |             ~^
      |              |
      |              char *
consola.c:119:32: warning: unused parameter ‘mensaje’ [-Wunused-parameter]
  119 | char leer_caracter(const char *mensaje)
      |                    ~~~~~~~~~~~~^~~~~~~
triangulo.c: In function ‘clasificar_triangulo’:
triangulo.c:34:1: warning: control reaches end of non-void function [-Wreturn-type]
   34 | }
      | ^

```

> 📄 **Salida completa:** registrada en `compilacion_fac8149.log`.
