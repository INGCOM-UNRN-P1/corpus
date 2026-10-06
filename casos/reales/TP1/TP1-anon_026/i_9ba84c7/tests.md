## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_026/repo'
Compilando librería en libs/consola...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_026/repo/libs/consola'
Compilando consola.c
cc -Wall -Wextra -pedantic -g -c consola.c
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_026/repo/libs/consola'
make: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_026/repo'

consola.c: In function ‘leer_logico’:
consola.c:113:21: error: implicit declaration of function ‘tolower’ 
```
