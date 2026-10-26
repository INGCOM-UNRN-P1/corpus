# Plan de Implementación: Reorganización TP5-anon_004 (Librerías dinamicos y cadena_segura)

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Reorganizar los ejercicios 1, 2 y 3 del TP5 en dos bibliotecas estáticas (`libs/dinamicos` y `libs/cadena_segura`), reemplazarlos por dos ejercicios de aplicación directa (`ejercicio1` telemetría con arreglos dinámicos y `ejercicio2` slugs con cadenas seguras), eliminar los ejercicios 3 a 6 y actualizar la documentación y metadatos del TP.

**Architecture:** Se consolidan todas las operaciones sobre `arreglo_dinamico_t` en `libs/dinamicos` y se crea la biblioteca `libs/cadena_segura` para `cadena_segura_t`. Ambas bibliotecas se compilan como archivos estáticos `.a` y exponen suites de pruebas unitarias con `p1_test`. La carpeta `ejercicios/` contendrá exactamente `ejercicio1` y `ejercicio2`, enlazados dinámicamente contra sus respectivas librerías locales vía Makefiles estándar.

**Tech Stack:** C11 (GCC con flags `-Wall -Wextra -pedantic -std=c11 -g`), Make, Valgrind, framework de pruebas `p1_test`.

## Global Constraints

- Compilar en C11 con flags de cátedra: `-Wall -Wextra -pedantic -std=c11 -g`.
- Sin fugas de memoria en ningún ejecutable (`valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1`).
- Estricta verificación de punteros nulos y defensividad en funciones públicas.
- Estilo y convenciones de cátedra P1 (tipos con sufijo `_t`, sin variables globales).
- Todo mensaje y documentación técnica en español rioplatense.

---

### Task 1: Consolidar y actualizar `libs/dinamicos`

**Files:**
- Modify: `libs/dinamicos/dinamicos.h`
- Modify: `libs/dinamicos/dinamicos.c`
- Modify: `libs/dinamicos/prueba.c`

**Interfaces:**
- Consumes: C11 standard library (`stdlib.h`, `stdbool.h`, `stddef.h`), `p1_test.h`.
- Produces: API pública completa de `arreglo_dinamico_t`:
  - `bool arreglo_dinamico_crear(arreglo_dinamico_t *arreglo, size_t capacidad_inicial);`
  - `void arreglo_dinamico_destruir(arreglo_dinamico_t *arreglo);`
  - `bool arreglo_dinamico_agregar(arreglo_dinamico_t *arreglo, int valor);`
  - `int *arreglo_dinamico_obtener(const arreglo_dinamico_t *arreglo, size_t indice);`
  - `bool arreglo_dinamico_filtrar_pares(const arreglo_dinamico_t *origen, arreglo_dinamico_t *destino);`
  - `int arreglo_dinamico_buscar(const arreglo_dinamico_t *arreglo, int valor);`
  - `void arreglo_dinamico_invertir(arreglo_dinamico_t *arreglo);`
  - `size_t arreglo_dinamico_compactar(arreglo_dinamico_t *arreglo, int valor);`

- [ ] **Step 1: Actualizar encabezado `libs/dinamicos/dinamicos.h`**

Escribir en `libs/dinamicos/dinamicos.h` los prototipos completos y documentación Doxygen:

```c
#ifndef DINAMICOS_H
#define DINAMICOS_H

#include <stdbool.h>
#include <stddef.h>

typedef struct arreglo_dinamico {
    int *datos;
    size_t cantidad;
    size_t capacidad;
} arreglo_dinamico_t;

bool arreglo_dinamico_crear(arreglo_dinamico_t *arreglo, size_t capacidad_inicial);
void arreglo_dinamico_destruir(arreglo_dinamico_t *arreglo);
bool arreglo_dinamico_agregar(arreglo_dinamico_t *arreglo, int valor);
int *arreglo_dinamico_obtener(const arreglo_dinamico_t *arreglo, size_t indice);
bool arreglo_dinamico_filtrar_pares(const arreglo_dinamico_t *origen, arreglo_dinamico_t *destino);
int arreglo_dinamico_buscar(const arreglo_dinamico_t *arreglo, int valor);
void arreglo_dinamico_invertir(arreglo_dinamico_t *arreglo);
size_t arreglo_dinamico_compactar(arreglo_dinamico_t *arreglo, int valor);

#endif /* DINAMICOS_H */
```

- [ ] **Step 2: Implementar suite de pruebas en `libs/dinamicos/prueba.c`**

Integrar pruebas exhaustivas para todas las operaciones:

```c
#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "dinamicos.h"

TEST(prueba_arreglo_dinamico_creacion_destruccion)
{
    arreglo_dinamico_t arr;

    SUBCASE("Creacion y destruccion exitosa");
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 4));
    ASSERT_PTR_NOT_NULL(arr.datos);
    ASSERT_INT_EQ(0, (int)arr.cantidad);
    ASSERT_INT_EQ(4, (int)arr.capacidad);
    arreglo_dinamico_destruir(&arr);
    ASSERT_PTR_NULL(arr.datos);
    ASSERT_INT_EQ(0, (int)arr.cantidad);
    ASSERT_INT_EQ(0, (int)arr.capacidad);

    SUBCASE("Puntero nulo seguro");
    ASSERT_FALSE(arreglo_dinamico_crear(NULL, 10));
    arreglo_dinamico_destruir(NULL);
}

TEST(prueba_arreglo_dinamico_agregar)
{
    arreglo_dinamico_t arr;
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 2));

    ASSERT_TRUE(arreglo_dinamico_agregar(&arr, 10));
    ASSERT_TRUE(arreglo_dinamico_agregar(&arr, 20));
    ASSERT_INT_EQ(2, (int)arr.cantidad);
    ASSERT_INT_EQ(2, (int)arr.capacidad);

    ASSERT_TRUE(arreglo_dinamico_agregar(&arr, 30));
    ASSERT_INT_EQ(3, (int)arr.cantidad);
    ASSERT_TRUE(arr.capacidad >= 4);
    ASSERT_INT_EQ(10, arr.datos[0]);
    ASSERT_INT_EQ(20, arr.datos[1]);
    ASSERT_INT_EQ(30, arr.datos[2]);

    arreglo_dinamico_destruir(&arr);
}

TEST(prueba_arreglo_dinamico_obtener)
{
    arreglo_dinamico_t arr;
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 3));
    arreglo_dinamico_agregar(&arr, 100);
    arreglo_dinamico_agregar(&arr, 200);

    int *p0 = arreglo_dinamico_obtener(&arr, 0);
    int *p1 = arreglo_dinamico_obtener(&arr, 1);
    ASSERT_PTR_NOT_NULL(p0);
    ASSERT_PTR_NOT_NULL(p1);
    ASSERT_INT_EQ(100, *p0);
    ASSERT_INT_EQ(200, *p1);

    ASSERT_PTR_NULL(arreglo_dinamico_obtener(&arr, 2));
    ASSERT_PTR_NULL(arreglo_dinamico_obtener(NULL, 0));

    arreglo_dinamico_destruir(&arr);
}

TEST(prueba_arreglo_dinamico_filtrar_pares)
{
    arreglo_dinamico_t origen;
    arreglo_dinamico_t pares;

    ASSERT_TRUE(arreglo_dinamico_crear(&origen, 5));
    arreglo_dinamico_agregar(&origen, 1);
    arreglo_dinamico_agregar(&origen, 4);
    arreglo_dinamico_agregar(&origen, 7);
    arreglo_dinamico_agregar(&origen, 8);
    arreglo_dinamico_agregar(&origen, 10);

    ASSERT_TRUE(arreglo_dinamico_filtrar_pares(&origen, &pares));
    ASSERT_INT_EQ(3, (int)pares.cantidad);
    ASSERT_INT_EQ(4, pares.datos[0]);
    ASSERT_INT_EQ(8, pares.datos[1]);
    ASSERT_INT_EQ(10, pares.datos[2]);

    arreglo_dinamico_destruir(&origen);
    arreglo_dinamico_destruir(&pares);
}

TEST(prueba_arreglo_dinamico_operaciones)
{
    arreglo_dinamico_t arr;
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 5));
    arreglo_dinamico_agregar(&arr, 10);
    arreglo_dinamico_agregar(&arr, 20);
    arreglo_dinamico_agregar(&arr, 30);

    SUBCASE("Busqueda");
    ASSERT_INT_EQ(1, arreglo_dinamico_buscar(&arr, 20));
    ASSERT_INT_EQ(-1, arreglo_dinamico_buscar(&arr, 99));
    ASSERT_INT_EQ(-1, arreglo_dinamico_buscar(NULL, 10));

    SUBCASE("Inversion in-place");
    arreglo_dinamico_invertir(&arr);
    ASSERT_INT_EQ(30, arr.datos[0]);
    ASSERT_INT_EQ(20, arr.datos[1]);
    ASSERT_INT_EQ(10, arr.datos[2]);

    SUBCASE("Compactacion");
    arreglo_dinamico_agregar(&arr, 20);
    size_t eliminados = arreglo_dinamico_compactar(&arr, 20);
    ASSERT_INT_EQ(2, (int)eliminados);
    ASSERT_INT_EQ(2, (int)arr.cantidad);
    ASSERT_INT_EQ(30, arr.datos[0]);
    ASSERT_INT_EQ(10, arr.datos[1]);

    arreglo_dinamico_destruir(&arr);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libdinamicos", conteo_args, argumentos);
    RUN_TEST(prueba_arreglo_dinamico_creacion_destruccion);
    RUN_TEST(prueba_arreglo_dinamico_agregar);
    RUN_TEST(prueba_arreglo_dinamico_obtener);
    RUN_TEST(prueba_arreglo_dinamico_filtrar_pares);
    RUN_TEST(prueba_arreglo_dinamico_operaciones);
    return TEST_REPORT();
}
```

- [ ] **Step 3: Implementar código en `libs/dinamicos/dinamicos.c`**

Escribir todas las funciones requeridas:

```c
#include <stdlib.h>
#include "dinamicos.h"

bool arreglo_dinamico_crear(arreglo_dinamico_t *arreglo, size_t capacidad_inicial)
{
    if (arreglo == NULL) {
        return false;
    }
    size_t cap = (capacidad_inicial == 0) ? 4 : capacidad_inicial;
    int *bloque = (int *)malloc(cap * sizeof(int));
    if (bloque == NULL) {
        arreglo->datos = NULL;
        arreglo->cantidad = 0;
        arreglo->capacidad = 0;
        return false;
    }
    arreglo->datos = bloque;
    arreglo->cantidad = 0;
    arreglo->capacidad = cap;
    return true;
}

void arreglo_dinamico_destruir(arreglo_dinamico_t *arreglo)
{
    if (arreglo == NULL) {
        return;
    }
    free(arreglo->datos);
    arreglo->datos = NULL;
    arreglo->cantidad = 0;
    arreglo->capacidad = 0;
}

bool arreglo_dinamico_agregar(arreglo_dinamico_t *arreglo, int valor)
{
    if (arreglo == NULL || arreglo->datos == NULL) {
        return false;
    }
    if (arreglo->cantidad >= arreglo->capacidad) {
        size_t nueva_capacidad = arreglo->capacidad * 2;
        int *nuevo_bloque = (int *)realloc(arreglo->datos, nueva_capacidad * sizeof(int));
        if (nuevo_bloque == NULL) {
            return false;
        }
        arreglo->datos = nuevo_bloque;
        arreglo->capacidad = nueva_capacidad;
    }
    arreglo->datos[arreglo->cantidad] = valor;
    arreglo->cantidad++;
    return true;
}

int *arreglo_dinamico_obtener(const arreglo_dinamico_t *arreglo, size_t indice)
{
    if (arreglo == NULL || arreglo->datos == NULL || indice >= arreglo->cantidad) {
        return NULL;
    }
    return &arreglo->datos[indice];
}

bool arreglo_dinamico_filtrar_pares(const arreglo_dinamico_t *origen, arreglo_dinamico_t *destino)
{
    if (origen == NULL || origen->datos == NULL || destino == NULL) {
        return false;
    }
    if (!arreglo_dinamico_crear(destino, (origen->cantidad > 0) ? origen->cantidad : 4)) {
        return false;
    }
    for (size_t i = 0; i < origen->cantidad; i++) {
        if (origen->datos[i] % 2 == 0) {
            if (!arreglo_dinamico_agregar(destino, origen->datos[i])) {
                arreglo_dinamico_destruir(destino);
                return false;
            }
        }
    }
    return true;
}

int arreglo_dinamico_buscar(const arreglo_dinamico_t *arreglo, int valor)
{
    if (arreglo == NULL || arreglo->datos == NULL) {
        return -1;
    }
    for (size_t i = 0; i < arreglo->cantidad; i++) {
        if (arreglo->datos[i] == valor) {
            return (int)i;
        }
    }
    return -1;
}

void arreglo_dinamico_invertir(arreglo_dinamico_t *arreglo)
{
    if (arreglo == NULL || arreglo->datos == NULL || arreglo->cantidad <= 1) {
        return;
    }
    size_t i = 0;
    size_t j = arreglo->cantidad - 1;
    while (i < j) {
        int temp = arreglo->datos[i];
        arreglo->datos[i] = arreglo->datos[j];
        arreglo->datos[j] = temp;
        i++;
        j--;
    }
}

size_t arreglo_dinamico_compactar(arreglo_dinamico_t *arreglo, int valor)
{
    if (arreglo == NULL || arreglo->datos == NULL || arreglo->cantidad == 0) {
        return 0;
    }
    size_t j = 0;
    size_t eliminados = 0;
    for (size_t i = 0; i < arreglo->cantidad; i++) {
        if (arreglo->datos[i] != valor) {
            arreglo->datos[j] = arreglo->datos[i];
            j++;
        } else {
            eliminados++;
        }
    }
    arreglo->cantidad = j;
    return eliminados;
}
```

- [ ] **Step 4: Compilar, ejecutar tests y memcheck de `libs/dinamicos`**

Ejecutar:
```bash
make -C libs/dinamicos clean
make -C libs/dinamicos test
make -C libs/dinamicos memcheck
```
Verificar: todos los tests pasan con 0 errores y 0 fugas de memoria.

- [ ] **Step 5: Commit de Task 1**

```bash
git add libs/dinamicos/
git commit -m "feat(dinamicos): consolidar metodos de acceso, busqueda, filtrado y compactacion"
```

---

### Task 2: Crear biblioteca `libs/cadena_segura`

**Files:**
- Create: `libs/cadena_segura/cadena_segura.h`
- Create: `libs/cadena_segura/cadena_segura.c`
- Create: `libs/cadena_segura/prueba.c`
- Create: `libs/cadena_segura/Makefile`

**Interfaces:**
- Consumes: C11 standard library (`stdlib.h`, `stdbool.h`, `stddef.h`, `string.h`), `p1_test.h`.
- Produces: API pública completa de `cadena_segura_t`:
  - `bool cadena_segura_crear(cadena_segura_t *cadena, const char *literal);`
  - `void cadena_segura_destruir(cadena_segura_t *cadena);`
  - `bool cadena_segura_concatenar(cadena_segura_t *cadena, const char *sufijo);`
  - `bool cadena_segura_subcadena(const cadena_segura_t *origen, size_t inicio, size_t longitud, cadena_segura_t *destino);`
  - `bool cadena_segura_clonar(const cadena_segura_t *origen, cadena_segura_t *destino);`
  - `int cadena_segura_buscar(const cadena_segura_t *cadena, const char *aguja);`

- [ ] **Step 1: Crear `libs/cadena_segura/cadena_segura.h`**

```c
#ifndef CADENA_SEGURA_H
#define CADENA_SEGURA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct cadena_segura {
    char *texto;
    size_t longitud;
    size_t capacidad;
} cadena_segura_t;

bool cadena_segura_crear(cadena_segura_t *cadena, const char *literal);
void cadena_segura_destruir(cadena_segura_t *cadena);
bool cadena_segura_concatenar(cadena_segura_t *cadena, const char *sufijo);
bool cadena_segura_subcadena(const cadena_segura_t *origen, size_t inicio, size_t longitud, cadena_segura_t *destino);
bool cadena_segura_clonar(const cadena_segura_t *origen, cadena_segura_t *destino);
int cadena_segura_buscar(const cadena_segura_t *cadena, const char *aguja);

#endif /* CADENA_SEGURA_H */
```

- [ ] **Step 2: Crear `libs/cadena_segura/Makefile`**

Configurar adaptado de `libs/dinamicos/Makefile`:

```makefile
CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c11 -pedantic -g

TEST_LIB_NAME ?= p1_test
TEST_LIBS ?= $(TEST_LIB_NAME)

ROOT_DIR = ../..
LIBS_DIR = $(ROOT_DIR)/libs

TEST_INCLUDE_DIRS = $(foreach lib,$(TEST_LIBS),$(if $(wildcard $(LIBS_DIR)/$(lib)/include),-I$(LIBS_DIR)/$(lib)/include -I$(LIBS_DIR)/$(lib),-I$(LIBS_DIR)/$(lib)))
TEST_LIBRARY_DIRS = $(foreach lib,$(TEST_LIBS),$(if $(wildcard $(LIBS_DIR)/$(lib)/build),-L$(LIBS_DIR)/$(lib)/build,$(if $(wildcard $(LIBS_DIR)/$(lib)/lib),-L$(LIBS_DIR)/$(lib)/lib,-L$(LIBS_DIR)/$(lib))))
TEST_LIBRARY = $(addprefix -l,$(TEST_LIBS))

SRCS = $(filter-out prueba.c, $(wildcard *.c))
HDRS = $(wildcard *.h)

LIB_NAME := $(notdir $(CURDIR))
LIBRARY_NAME = lib$(LIB_NAME).a

TEST_TARGET = test_bin
TEST_SRCS = $(SRCS) prueba.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(LIBRARY_NAME) $(TEST_TARGET)

$(LIBRARY_NAME): $(OBJS)
	@echo "Generando librería estática $@"
	ar rcs $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	@for lib in $(TEST_LIBS); do \
		if [ -d "$(LIBS_DIR)/$$lib" ] && [ -f "$(LIBS_DIR)/$$lib/Makefile" ] && [ ! -f "$(LIBS_DIR)/$$lib/lib$$lib.a" ] && [ ! -f "$(LIBS_DIR)/$$lib/build/lib$$lib.a" ]; then \
			echo "Compilando dependencia $$lib..."; \
			$(MAKE) -C "$(LIBS_DIR)/$$lib" >/dev/null 2>&1 || exit 1; \
		fi; \
	done
	@echo "Compilando $@"
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(TEST_LIBRARY_DIRS) $(TEST_LIBRARY)

prueba.o: prueba.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) $(TEST_INCLUDE_DIRS) -c $<

%.o: %.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) -c $<

.PHONY: test
test: $(TEST_TARGET)
	@echo "Probando librería..."
	./$(TEST_TARGET)

.PHONY: memcheck
memcheck: $(TEST_TARGET)
	@echo "Verificando con Valgrind..."
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TEST_TARGET)

.PHONY: clean
clean:
	@echo "Limpiando..."
	rm -f *.o $(LIBRARY_NAME) $(TEST_TARGET)

-include local.mk
```

- [ ] **Step 3: Crear suite de pruebas `libs/cadena_segura/prueba.c`**

```c
#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadena_segura.h"

TEST(prueba_cadena_segura_creacion_destruccion)
{
    cadena_segura_t c;

    SUBCASE("Creacion desde literal");
    ASSERT_TRUE(cadena_segura_crear(&c, "Hola Mundo"));
    ASSERT_PTR_NOT_NULL(c.texto);
    ASSERT_INT_EQ(10, (int)c.longitud);
    ASSERT_STR_EQ("Hola Mundo", c.texto);
    cadena_segura_destruir(&c);
    ASSERT_PTR_NULL(c.texto);
    ASSERT_INT_EQ(0, (int)c.longitud);

    SUBCASE("Creacion desde NULL (vacia)");
    ASSERT_TRUE(cadena_segura_crear(&c, NULL));
    ASSERT_PTR_NOT_NULL(c.texto);
    ASSERT_INT_EQ(0, (int)c.longitud);
    ASSERT_STR_EQ("", c.texto);
    cadena_segura_destruir(&c);

    SUBCASE("Puntero a estructura nulo");
    ASSERT_FALSE(cadena_segura_crear(NULL, "test"));
    cadena_segura_destruir(NULL);
}

TEST(prueba_cadena_segura_concatenar)
{
    cadena_segura_t c;
    ASSERT_TRUE(cadena_segura_crear(&c, "Hola"));

    ASSERT_TRUE(cadena_segura_concatenar(&c, " "));
    ASSERT_TRUE(cadena_segura_concatenar(&c, "Mundo"));
    ASSERT_INT_EQ(10, (int)c.longitud);
    ASSERT_STR_EQ("Hola Mundo", c.texto);

    /* Concatenar NULL es seguro y retorna true sin cambios */
    ASSERT_TRUE(cadena_segura_concatenar(&c, NULL));
    ASSERT_STR_EQ("Hola Mundo", c.texto);

    cadena_segura_destruir(&c);
}

TEST(prueba_cadena_segura_subcadena_y_clonar)
{
    cadena_segura_t original;
    cadena_segura_t sub;
    cadena_segura_t clon;

    ASSERT_TRUE(cadena_segura_crear(&original, "Programacion 1"));

    SUBCASE("Subcadena valida");
    ASSERT_TRUE(cadena_segura_subcadena(&original, 0, 8, &sub));
    ASSERT_INT_EQ(8, (int)sub.longitud);
    ASSERT_STR_EQ("Programa", sub.texto);
    cadena_segura_destruir(&sub);

    SUBCASE("Subcadena excedente copia hasta el final");
    ASSERT_TRUE(cadena_segura_subcadena(&original, 13, 10, &sub));
    ASSERT_INT_EQ(1, (int)sub.longitud);
    ASSERT_STR_EQ("1", sub.texto);
    cadena_segura_destruir(&sub);

    SUBCASE("Clonacion profunda independiente");
    ASSERT_TRUE(cadena_segura_clonar(&original, &clon));
    ASSERT_STR_EQ("Programacion 1", clon.texto);
    ASSERT_TRUE(clon.texto != original.texto);
    cadena_segura_destruir(&clon);

    cadena_segura_destruir(&original);
}

TEST(prueba_cadena_segura_buscar)
{
    cadena_segura_t c;
    ASSERT_TRUE(cadena_segura_crear(&c, "universidad nacional de rio negro"));

    ASSERT_INT_EQ(0, cadena_segura_buscar(&c, "universidad"));
    ASSERT_INT_EQ(12, cadena_segura_buscar(&c, "nacional"));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(&c, "comahue"));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(&c, ""));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(&c, NULL));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(NULL, "nacional"));

    cadena_segura_destruir(&c);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libcadena_segura", conteo_args, argumentos);
    RUN_TEST(prueba_cadena_segura_creacion_destruccion);
    RUN_TEST(prueba_cadena_segura_concatenar);
    RUN_TEST(prueba_cadena_segura_subcadena_y_clonar);
    RUN_TEST(prueba_cadena_segura_buscar);
    return TEST_REPORT();
}
```

- [ ] **Step 4: Implementar `libs/cadena_segura/cadena_segura.c`**

```c
#include <stdlib.h>
#include <string.h>
#include "cadena_segura.h"

bool cadena_segura_crear(cadena_segura_t *cadena, const char *literal)
{
    if (cadena == NULL) {
        return false;
    }
    const char *fuente = (literal != NULL) ? literal : "";
    size_t len = strlen(fuente);
    size_t cap = len + 16; /* Capacidad con margen inicial */

    char *buf = (char *)malloc(cap);
    if (buf == NULL) {
        cadena->texto = NULL;
        cadena->longitud = 0;
        cadena->capacidad = 0;
        return false;
    }
    memcpy(buf, fuente, len + 1);
    cadena->texto = buf;
    cadena->longitud = len;
    cadena->capacidad = cap;
    return true;
}

void cadena_segura_destruir(cadena_segura_t *cadena)
{
    if (cadena == NULL) {
        return;
    }
    free(cadena->texto);
    cadena->texto = NULL;
    cadena->longitud = 0;
    cadena->capacidad = 0;
}

bool cadena_segura_concatenar(cadena_segura_t *cadena, const char *sufijo)
{
    if (cadena == NULL || cadena->texto == NULL) {
        return false;
    }
    if (sufijo == NULL || sufijo[0] == '\0') {
        return true;
    }
    size_t len_sufijo = strlen(sufijo);
    size_t total_len = cadena->longitud + len_sufijo;

    if (total_len + 1 > cadena->capacidad) {
        size_t nueva_capacidad = (total_len + 1) * 2;
        char *nuevo_buf = (char *)realloc(cadena->texto, nueva_capacidad);
        if (nuevo_buf == NULL) {
            return false;
        }
        cadena->texto = nuevo_buf;
        cadena->capacidad = nueva_capacidad;
    }
    memcpy(cadena->texto + cadena->longitud, sufijo, len_sufijo + 1);
    cadena->longitud = total_len;
    return true;
}

bool cadena_segura_subcadena(const cadena_segura_t *origen, size_t inicio, size_t longitud, cadena_segura_t *destino)
{
    if (origen == NULL || origen->texto == NULL || destino == NULL) {
        return false;
    }
    if (inicio >= origen->longitud || longitud == 0) {
        return cadena_segura_crear(destino, "");
    }
    size_t disponible = origen->longitud - inicio;
    size_t copiar = (longitud < disponible) ? longitud : disponible;

    char *tmp = (char *)malloc(copiar + 1);
    if (tmp == NULL) {
        return false;
    }
    memcpy(tmp, origen->texto + inicio, copiar);
    tmp[copiar] = '\0';

    bool ok = cadena_segura_crear(destino, tmp);
    free(tmp);
    return ok;
}

bool cadena_segura_clonar(const cadena_segura_t *origen, cadena_segura_t *destino)
{
    if (origen == NULL || origen->texto == NULL || destino == NULL) {
        return false;
    }
    return cadena_segura_crear(destino, origen->texto);
}

int cadena_segura_buscar(const cadena_segura_t *cadena, const char *aguja)
{
    if (cadena == NULL || cadena->texto == NULL || aguja == NULL || aguja[0] == '\0') {
        return -1;
    }
    char *pos = strstr(cadena->texto, aguja);
    if (pos == NULL) {
        return -1;
    }
    return (int)(pos - cadena->texto);
}
```

- [ ] **Step 5: Compilar, ejecutar tests y memcheck de `libs/cadena_segura`**

Ejecutar:
```bash
make -C libs/cadena_segura clean
make -C libs/cadena_segura test
make -C libs/cadena_segura memcheck
```
Verificar: 100% de tests aprobados, sin memory leaks.

- [ ] **Step 6: Commit de Task 2**

```bash
git add libs/cadena_segura/
git commit -m "feat(cadena_segura): crear biblioteca de cadenas dinamicas seguras en heap"
```

---

### Task 3: Implementar `ejercicios/ejercicio1` (Aplicación de `libdinamicos` - Telemetría de Sensores)

**Files:**
- Create: `ejercicios/ejercicio1/sensor_flujo.h`
- Create: `ejercicios/ejercicio1/sensor_flujo.c`
- Modify: `ejercicios/ejercicio1/main.c`
- Modify: `ejercicios/ejercicio1/prueba.c`
- Delete: `ejercicios/ejercicio1/vector_enteros.h`
- Delete: `ejercicios/ejercicio1/vector_enteros.c`

**Interfaces:**
- Consumes: `dinamicos.h` (`libdinamicos`), `p1_test.h`.
- Produces: API de procesamiento de telemetría:
  - `bool cargar_muestras(arreglo_dinamico_t *muestras, const int *valores, size_t n);`
  - `double calcular_promedio(const arreglo_dinamico_t *muestras);`
  - `size_t depurar_lecturas_erroneas(arreglo_dinamico_t *muestras, int codigo_error);`
  - `bool extraer_eventos_pares(const arreglo_dinamico_t *muestras, arreglo_dinamico_t *eventos);`

- [ ] **Step 1: Limpiar archivos viejos y crear `ejercicios/ejercicio1/sensor_flujo.h`**

Eliminar archivos obsoletos:
```bash
rm -f ejercicios/ejercicio1/vector_enteros.h ejercicios/ejercicio1/vector_enteros.c ejercicios/ejercicio1/*.o
```

Escribir `ejercicios/ejercicio1/sensor_flujo.h`:
```c
#ifndef SENSOR_FLUJO_H
#define SENSOR_FLUJO_H

#include <stdbool.h>
#include <stddef.h>
#include "dinamicos.h"

bool cargar_muestras(arreglo_dinamico_t *muestras, const int *valores, size_t n);
double calcular_promedio(const arreglo_dinamico_t *muestras);
size_t depurar_lecturas_erroneas(arreglo_dinamico_t *muestras, int codigo_error);
bool extraer_eventos_pares(const arreglo_dinamico_t *muestras, arreglo_dinamico_t *eventos);

#endif /* SENSOR_FLUJO_H */
```

- [ ] **Step 2: Implementar `ejercicios/ejercicio1/sensor_flujo.c`**

```c
#include "sensor_flujo.h"

bool cargar_muestras(arreglo_dinamico_t *muestras, const int *valores, size_t n)
{
    if (muestras == NULL || valores == NULL) {
        return false;
    }
    for (size_t i = 0; i < n; i++) {
        if (!arreglo_dinamico_agregar(muestras, valores[i])) {
            return false;
        }
    }
    return true;
}

double calcular_promedio(const arreglo_dinamico_t *muestras)
{
    if (muestras == NULL || muestras->cantidad == 0) {
        return 0.0;
    }
    double suma = 0.0;
    for (size_t i = 0; i < muestras->cantidad; i++) {
        int *val = arreglo_dinamico_obtener(muestras, i);
        if (val != NULL) {
            suma += *val;
        }
    }
    return suma / (double)muestras->cantidad;
}

size_t depurar_lecturas_erroneas(arreglo_dinamico_t *muestras, int codigo_error)
{
    return arreglo_dinamico_compactar(muestras, codigo_error);
}

bool extraer_eventos_pares(const arreglo_dinamico_t *muestras, arreglo_dinamico_t *eventos)
{
    return arreglo_dinamico_filtrar_pares(muestras, eventos);
}
```

- [ ] **Step 3: Actualizar `ejercicios/ejercicio1/prueba.c`**

```c
#include <stdio.h>
#include "p1_test.h"
#include "dinamicos.h"
#include "sensor_flujo.h"

TEST(prueba_telemetria_flujo)
{
    arreglo_dinamico_t sensor;
    ASSERT_TRUE(arreglo_dinamico_crear(&sensor, 4));

    const int lecturas[] = { 12, -999, 14, 18, -999, 20, 25 };
    ASSERT_TRUE(cargar_muestras(&sensor, lecturas, 7));
    ASSERT_INT_EQ(7, (int)sensor.cantidad);

    SUBCASE("Depuracion de lecturas erroneas");
    size_t eliminados = depurar_lecturas_erroneas(&sensor, -999);
    ASSERT_INT_EQ(2, (int)eliminados);
    ASSERT_INT_EQ(5, (int)sensor.cantidad);

    SUBCASE("Calculo de promedio");
    double prom = calcular_promedio(&sensor);
    /* (12 + 14 + 18 + 20 + 25) / 5 = 89 / 5 = 17.8 */
    ASSERT_DOUBLE_EQ(17.8, prom, 0.001);

    SUBCASE("Extraccion de eventos pares");
    arreglo_dinamico_t pares;
    ASSERT_TRUE(extraer_eventos_pares(&sensor, &pares));
    ASSERT_INT_EQ(4, (int)pares.cantidad); /* 12, 14, 18, 20 */
    ASSERT_INT_EQ(12, pares.datos[0]);
    ASSERT_INT_EQ(14, pares.datos[1]);
    ASSERT_INT_EQ(18, pares.datos[2]);
    ASSERT_INT_EQ(20, pares.datos[3]);
    arreglo_dinamico_destruir(&pares);

    SUBCASE("Inversion cronologica con libdinamicos");
    arreglo_dinamico_invertir(&sensor);
    ASSERT_INT_EQ(25, sensor.datos[0]);
    ASSERT_INT_EQ(12, sensor.datos[4]);

    arreglo_dinamico_destruir(&sensor);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1 (Telemetria)", conteo_args, argumentos);
    RUN_TEST(prueba_telemetria_flujo);
    return TEST_REPORT();
}
```

- [ ] **Step 4: Actualizar `ejercicios/ejercicio1/main.c`**

```c
#include <stdio.h>
#include "dinamicos.h"
#include "sensor_flujo.h"

int main(void)
{
    printf("=== Ejercicio 1: Procesamiento de Telemetria Dinamica ===\n");
    arreglo_dinamico_t sensor;
    if (!arreglo_dinamico_crear(&sensor, 4)) {
        fprintf(stderr, "Error al inicializar buffer de telemetria.\n");
        return 1;
    }

    const int lote[] = { 22, -999, 24, 28, -999, 30, 35 };
    size_t n = sizeof(lote) / sizeof(lote[0]);
    cargar_muestras(&sensor, lote, n);

    printf("Muestras cargadas: %zu\n", sensor.cantidad);
    size_t depuradas = depurar_lecturas_erroneas(&sensor, -999);
    printf("Lecturas anomalas eliminadas: %zu\n", depuradas);
    printf("Promedio validado: %.2f\n", calcular_promedio(&sensor));

    arreglo_dinamico_invertir(&sensor);
    printf("Ultima lectura recibida (mas reciente): %d\n", sensor.datos[0]);

    arreglo_dinamico_destruir(&sensor);
    return 0;
}
```

- [ ] **Step 5: Compilar, ejecutar tests y memcheck de `ejercicios/ejercicio1`**

```bash
make -C ejercicios/ejercicio1 clean
make -C ejercicios/ejercicio1 all
make -C ejercicios/ejercicio1 test
make -C ejercicios/ejercicio1 memcheck
```
Verificar: compila limpiamente, pasa tests y 0 memory leaks.

- [ ] **Step 6: Commit de Task 3**

```bash
git add ejercicios/ejercicio1/
git commit -m "feat(ejercicio1): implementar aplicacion de telemetria con arreglo dinamico"
```

---

### Task 4: Implementar `ejercicios/ejercicio2` (Aplicación de `libcadena_segura` - Generación de Slugs)

**Files:**
- Create: `ejercicios/ejercicio2/slug_generator.h`
- Create: `ejercicios/ejercicio2/slug_generator.c`
- Modify: `ejercicios/ejercicio2/main.c`
- Modify: `ejercicios/ejercicio2/prueba.c`
- Delete: `ejercicios/ejercicio2/vector_ops.h`
- Delete: `ejercicios/ejercicio2/vector_ops.c`

**Interfaces:**
- Consumes: `cadena_segura.h` (`libcadena_segura`), `p1_test.h`.
- Produces: API de generación y sanitización de slugs:
  - `bool generar_slug(const cadena_segura_t *titulo, cadena_segura_t *slug);`
  - `bool contiene_palabra_prohibida(const cadena_segura_t *texto, const char *palabra);`
  - `bool acotar_longitud_slug(cadena_segura_t *slug, size_t max_longitud);`

- [ ] **Step 1: Limpiar archivos viejos y crear `ejercicios/ejercicio2/slug_generator.h`**

Eliminar archivos obsoletos:
```bash
rm -f ejercicios/ejercicio2/vector_ops.h ejercicios/ejercicio2/vector_ops.c ejercicios/ejercicio2/*.o
```

Escribir `ejercicios/ejercicio2/slug_generator.h`:
```c
#ifndef SLUG_GENERATOR_H
#define SLUG_GENERATOR_H

#include <stdbool.h>
#include <stddef.h>
#include "cadena_segura.h"

bool generar_slug(const cadena_segura_t *titulo, cadena_segura_t *slug);
bool contiene_palabra_prohibida(const cadena_segura_t *texto, const char *palabra);
bool acotar_longitud_slug(cadena_segura_t *slug, size_t max_longitud);

#endif /* SLUG_GENERATOR_H */
```

- [ ] **Step 2: Implementar `ejercicios/ejercicio2/slug_generator.c`**

```c
#include <ctype.h>
#include <stdlib.h>
#include "slug_generator.h"

bool contiene_palabra_prohibida(const cadena_segura_t *texto, const char *palabra)
{
    if (texto == NULL || palabra == NULL) {
        return false;
    }
    return cadena_segura_buscar(texto, palabra) >= 0;
}

bool generar_slug(const cadena_segura_t *titulo, cadena_segura_t *slug)
{
    if (titulo == NULL || titulo->texto == NULL || slug == NULL) {
        return false;
    }
    if (!cadena_segura_crear(slug, "")) {
        return false;
    }

    char temp[2] = { '\0', '\0' };
    bool ultimo_fue_guion = true; /* Evita guion inicial */

    for (size_t i = 0; i < titulo->longitud; i++) {
        unsigned char c = (unsigned char)titulo->texto[i];
        if (isalnum(c)) {
            temp[0] = (char)tolower(c);
            if (!cadena_segura_concatenar(slug, temp)) {
                cadena_segura_destruir(slug);
                return false;
            }
            ultimo_fue_guion = false;
        } else if (!ultimo_fue_guion) {
            temp[0] = '-';
            if (!cadena_segura_concatenar(slug, temp)) {
                cadena_segura_destruir(slug);
                return false;
            }
            ultimo_fue_guion = true;
        }
    }

    /* Eliminar guion final si quedo uno */
    if (slug->longitud > 0 && slug->texto[slug->longitud - 1] == '-') {
        slug->texto[slug->longitud - 1] = '\0';
        slug->longitud--;
    }
    return true;
}

bool acotar_longitud_slug(cadena_segura_t *slug, size_t max_longitud)
{
    if (slug == NULL || slug->texto == NULL) {
        return false;
    }
    if (slug->longitud <= max_longitud) {
        return true;
    }
    cadena_segura_t recortado;
    if (!cadena_segura_subcadena(slug, 0, max_longitud, &recortado)) {
        return false;
    }
    /* Si termina en guion por el corte, ajustarlo */
    if (recortado.longitud > 0 && recortado.texto[recortado.longitud - 1] == '-') {
        recortado.texto[recortado.longitud - 1] = '\0';
        recortado.longitud--;
    }
    cadena_segura_destruir(slug);
    *slug = recortado;
    return true;
}
```

- [ ] **Step 3: Actualizar `ejercicios/ejercicio2/prueba.c`**

```c
#include <stdio.h>
#include "p1_test.h"
#include "cadena_segura.h"
#include "slug_generator.h"

TEST(prueba_slug_generator)
{
    cadena_segura_t titulo;
    cadena_segura_t slug;

    SUBCASE("Generacion basica de slug");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "Introduccion a Programacion 1!"));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_STR_EQ("introduccion-a-programacion-1", slug.texto);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);

    SUBCASE("Manejo de multiples espacios y simbolos");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "   Memoria    Dinamica   ---   C11   "));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_STR_EQ("memoria-dinamica-c11", slug.texto);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);

    SUBCASE("Deteccion de palabras prohibidas");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "Articulo con contenido spam aqui"));
    ASSERT_TRUE(contiene_palabra_prohibida(&titulo, "spam"));
    ASSERT_FALSE(contiene_palabra_prohibida(&titulo, "educacion"));
    cadena_segura_destruir(&titulo);

    SUBCASE("Acotado de longitud de slug");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "Un titulo excesivamente extenso para URL"));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_TRUE(acotar_longitud_slug(&slug, 9));
    ASSERT_STR_EQ("un-titulo", slug.texto);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 2 (Slug Generator)", conteo_args, argumentos);
    RUN_TEST(prueba_slug_generator);
    return TEST_REPORT();
}
```

- [ ] **Step 4: Actualizar `ejercicios/ejercicio2/main.c`**

```c
#include <stdio.h>
#include "cadena_segura.h"
#include "slug_generator.h"

int main(void)
{
    printf("=== Ejercicio 2: Generador de Slugs Seguros ===\n");
    cadena_segura_t titulo;
    cadena_segura_t slug;

    const char *ejemplo = "Trabajo Practico 5: Memoria Dinamica & Estructuras!";
    if (!cadena_segura_crear(&titulo, ejemplo)) {
        fprintf(stderr, "Error al crear cadena segura.\n");
        return 1;
    }

    printf("Titulo original: \"%s\"\n", titulo.texto);
    if (contiene_palabra_prohibida(&titulo, "spam")) {
        printf("Aviso: el titulo contiene terminos no admitidos.\n");
    }

    if (generar_slug(&titulo, &slug)) {
        printf("Slug generado: \"%s\"\n", slug.texto);
        acotar_longitud_slug(&slug, 25);
        printf("Slug acotado (max 25): \"%s\"\n", slug.texto);
        cadena_segura_destruir(&slug);
    }

    cadena_segura_destruir(&titulo);
    return 0;
}
```

- [ ] **Step 5: Compilar, ejecutar tests y memcheck de `ejercicios/ejercicio2`**

```bash
make -C ejercicios/ejercicio2 clean
make -C ejercicios/ejercicio2 all
make -C ejercicios/ejercicio2 test
make -C ejercicios/ejercicio2 memcheck
```
Verificar: compila limpiamente, pasa tests y 0 memory leaks.

- [ ] **Step 6: Commit de Task 4**

```bash
git add ejercicios/ejercicio2/
git commit -m "feat(ejercicio2): implementar aplicacion de generacion de slugs con cadena segura"
```

---

### Task 5: Eliminar ejercicios obsoletos y actualizar metadatos (`README.md`, `.deckard/guia.yaml`)

**Files:**
- Delete: `ejercicios/ejercicio3/`
- Delete: `ejercicios/ejercicio4/`
- Delete: `ejercicios/ejercicio5/`
- Delete: `ejercicios/ejercicio6/`
- Modify: `README.md`
- Modify: `.deckard/guia.yaml`

- [ ] **Step 1: Eliminar directorios de ejercicios 3 a 6**

```bash
rm -rf ejercicios/ejercicio3 ejercicios/ejercicio4 ejercicios/ejercicio5 ejercicios/ejercicio6
```

- [ ] **Step 2: Actualizar `README.md`**

Redactar el README con:
- Condición de completado actualizada (librerías `libdinamicos` y `libcadena_segura`, y 2 ejercicios de aplicación).
- Árbol de directorios con `libs/dinamicos`, `libs/cadena_segura`, `ejercicios/ejercicio1`, `ejercicios/ejercicio2`.
- Especificación formal de structs y contratos.
- Instrucciones de ejecución y tests.

- [ ] **Step 3: Actualizar `.deckard/guia.yaml`**

Reflejar la guía con `libdinamicos`, `libcadena_segura`, `ejercicio1` y `ejercicio2`.

- [ ] **Step 4: Ejecutar verificación integral en todo el repositorio**

```bash
make clean
make all
make test
make memcheck
```
Verificar: todas las librerías compilan, todos los ejercicios compilan, todos los tests pasan con 0 fugas de memoria.

- [ ] **Step 5: Commit de Task 5**

```bash
git add -A
git commit -m "refactor(tp5): depurar ejercicios obsoletos y actualizar documentacion y configuracion"
```
