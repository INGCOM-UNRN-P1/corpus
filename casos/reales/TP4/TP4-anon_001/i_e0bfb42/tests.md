## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo'
Compilando librería en libs/cadenas...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo/libs/cadenas'
Compilando prueba.c
cc -Wall -Wextra -std=c11 -pedantic -g -I../../libs/p1_test/include -I../../libs/p1_test -c prueba.c
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo/libs/cadenas'
make: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo'

In file included from prueba.c:9:
prueba.c: In function ‘main’:
../../lib
```
