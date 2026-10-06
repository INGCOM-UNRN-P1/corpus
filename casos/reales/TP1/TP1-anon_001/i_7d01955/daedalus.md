## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
consola.c: In function ‘esta_en_rango_entero’:
consola.c:13:31: warning: unused parameter ‘valor’ [-Wunused-parameter]
   13 | bool esta_en_rango_entero(int valor, int min, int max)
      |                           ~~~~^~~~~
consola.c:13:42: warning: unused parameter ‘min’ [-Wunused-parameter]
   13 | bool esta_en_rango_entero(int valor, int min, int max)
      |                                      ~~~~^~~
consola.c:13:51: warning: unused parameter ‘max’ [-Wunused-parameter]
   13 | bool esta_en_rango_entero(int valor, int min, int max)
      |                                               ~~~~^~~
consola.c: In function ‘esta_en_rango_flotante’:
consola.c:18:35: warning: unused parameter ‘valor’ [-Wunused-parameter]
   18 | bool esta_en_rango_flotante(float valor, float min, float max)
      |                             ~~~~~~^~~~~
consola.c:18:48: warning: unused parameter ‘min’ [-Wunused-parameter]
   18 | bool esta_en_rango_flotante(float valor, float min, float max)
      |                                          ~~~~~~^~~
consola.c:18:59: warning: unused parameter ‘max’ [-Wunused-parameter]
   18 | bool esta_en_rango_flotante(float valor, float min, float max)
      |     
```

> 📄 **Salida completa:** registrada en `compilacion_7d01955.log`.
