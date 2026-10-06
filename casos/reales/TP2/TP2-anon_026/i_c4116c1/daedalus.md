## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
arreglos.c: In function ‘arreglo_sumar’:
arreglos.c:22:40: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘<’ token
   22 |     for (size_t posicion = 0, posicion < cantidad; ++posicion)
      |                                        ^
arreglos.c:22:62: error: expected ‘;’ before ‘)’ token
   22 |     for (size_t posicion = 0, posicion < cantidad; ++posicion)
      |                                                              ^
      |                                                              ;
arreglos.c: In function ‘arreglo_buscar’:
arreglos.c:31:17: error: expected ‘)’ before ‘==’ token
   31 |     int (arreglo == NULL || cantidad ==0)
      |                 ^~~
      |                 )
arreglos.c: In function ‘arreglo_ordenado’:
arreglos.c:87:1: error: expected ‘;’ before ‘}’ token
   87 | }
      | ^
arreglos.c: At top level:
arreglos.c:113:2: error: expected identifier or ‘(’ before ‘{’ token
  113 |  {
      |  ^
make[1]: *** [Makefile:61: arreglos.o] Error 1
make: *** [Makefile:17: libs/arreglos] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_c4116c1.log`.
