## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘sumar_acumulado’:
main.c:10:1: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘{’ token
   10 | {
      | ^
In file included from main.c:7:
intercambio.h:64:76: warning: ISO C does not support omitting parameter names in function definitions before C23 [-Wmissing-parameter-name]
   64 | bool sumar_acumulado(const int *arreglo_fuente, size_t cantidad_elementos, long long)
      |                                                                            ^~~~~~~~~
main.c:15: error: expected ‘{’ at end of input
intercambio.h:64:33: warning: unused parameter ‘arreglo_fuente’ [-Wunused-parameter]
   64 | bool sumar_acumulado(const int *arreglo_fuente, size_t cantidad_elementos, long long)
      |                      ~~~~~~~~~~~^~~~~~~~~~~~~~
intercambio.h:64:56: warning: unused parameter ‘cantidad_elementos’ [-Wunused-parameter]
   64 | bool sumar_acumulado(const int *arreglo_fuente, size_t cantidad_elementos, long long)
      |                                                 ~~~~~~~^~~~~~~~~~~~~~~~~~
main.c:15: warning: control reaches end of non-void function [-Wreturn-type]
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejerci
```

> 📄 **Salida completa:** registrada en `compilacion_160faf9.log`.
