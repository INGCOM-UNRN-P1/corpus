## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_026/repo'
Compilando librería en libs/arreglos...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_026/repo/libs/arreglos'
Compilando arreglos.c
cc -Wall -Wextra -std=c11 -pedantic -g -c arreglos.c
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_026/repo/libs/arreglos'
make: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_026/repo'

arreglos.c: In function ‘arreglo_sumar’:
arreglos.c:22:40: error: expected ‘=’, ‘,’, ‘;’, ‘a
```
