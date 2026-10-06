## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
consola.c: In function ‘limpiar_buffer_entrada’:
consola.c:9:1: error: version control conflict marker in file
    9 | <<<<<<< HEAD
      | ^~~~~~~
consola.c:12:9: error: invalid suffix ‘f4143’ on integer constant
   12 | >>>>>>> 45f4143 (Entrega tp 1 completa)
      |         ^~~~~~~
consola.c: In function ‘esta_en_rango_entero’:
consola.c:18:1: error: version control conflict marker in file
   18 | <<<<<<< HEAD
      | ^~~~~~~
consola.c:28:9: error: invalid suffix ‘f4143’ on integer constant
   28 | >>>>>>> 45f4143 (Entrega tp 1 completa)
      |         ^~~~~~~
consola.c:16:31: warning: unused parameter ‘valor’ [-Wunused-parameter]
   16 | bool esta_en_rango_entero(int valor, int min, int max)
      |                           ~~~~^~~~~
consola.c:16:42: warning: unused parameter ‘min’ [-Wunused-parameter]
   16 | bool esta_en_rango_entero(int valor, int min, int max)
      |                                      ~~~~^~~
consola.c:16:51: warning: unused parameter ‘max’ [-Wunused-parameter]
   16 | bool esta_en_rango_entero(int valor, int min, int max)
      |                                               ~~~~^~~
consola.c: In function ‘esta_en_rango_flotante’:
consola.c:34:1: erro
```

> 📄 **Salida completa:** registrada en `compilacion_a3adbca.log`.
