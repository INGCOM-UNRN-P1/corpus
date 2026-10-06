## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:23:17: error: passing argument 1 of ‘ordenar_par’ makes pointer from integer without a cast [-Wint-conversion]
   23 |     ordenar_par(par_x, par_y);
      |                 ^~~~~
      |                 |
      |                 int
main.c:23:17: note: possible fix: take the address with ‘&’
   23 |     ordenar_par(par_x, par_y);
      |                 ^~~~~
      |                 &
In file included from main.c:7:
intercambio.h:44:23: note: expected ‘int *’ but argument is of type ‘int’
   44 | void ordenar_par(int *menor, int *mayor);
      |                  ~~~~~^~~~~
main.c:23:24: error: passing argument 2 of ‘ordenar_par’ makes pointer from integer without a cast [-Wint-conversion]
   23 |     ordenar_par(par_x, par_y);
      |                        ^~~~~
      |                        |
      |                        int
main.c:23:24: note: possible fix: take the address with ‘&’
   23 |     ordenar_par(par_x, par_y);
      |                        ^~~~~
      |                        &
intercambio.h:44:35: note: expected ‘int *’ but argument is of type ‘int’
   44 | void ordenar_par(int *menor, int *mayor);
      |                      
```

> 📄 **Salida completa:** registrada en `compilacion_b7ea096.log`.
