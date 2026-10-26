# Variables generales
CC ?= gcc
CFLAGS ?= -Wall -Wextra -pedantic -std=c11 -g

ROOT_DIR = ../..

# Detectar automáticamente librerías en libs/
DETECTED_LIBS := $(notdir $(wildcard $(ROOT_DIR)/libs/*))
LIB_NAME ?= $(filter-out p1_test, $(DETECTED_LIBS)) p1_test
LIBRARY = $(addprefix -l,$(LIB_NAME))
INCLUDE_DIRS = $(foreach lib,$(LIB_NAME),$(if $(wildcard $(ROOT_DIR)/libs/$(lib)/include),-I$(ROOT_DIR)/libs/$(lib)/include -I$(ROOT_DIR)/libs/$(lib),-I$(ROOT_DIR)/libs/$(lib)))
LIBRARY_DIRS = $(foreach lib,$(LIB_NAME),$(if $(wildcard $(ROOT_DIR)/libs/$(lib)/build),-L$(ROOT_DIR)/libs/$(lib)/build,$(if $(wildcard $(ROOT_DIR)/libs/$(lib)/lib),-L$(ROOT_DIR)/libs/$(lib)/lib,-L$(ROOT_DIR)/libs/$(lib))))

# Implementación primaria: secuencia_arreglo (arreglo contiguo)
# Implementación alternativa: secuencia_lista (nodos enlazados)

HDRS = secuencia.h

# Objetivos primarios
PROG_TARGET = programa
TEST_TARGET = test_bin

# Objetivos alternativos
PROG_ALT_TARGET = programa_lista
TEST_ALT_TARGET = test_bin_lista

all: $(PROG_TARGET) $(TEST_TARGET) alt

secuencia_arreglo.o: secuencia_arreglo.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

secuencia_lista.o: secuencia_lista.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

main.o: main.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

prueba.o: prueba.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Enlace de versión primaria (secuencia_arreglo)
$(PROG_TARGET): main.o secuencia_arreglo.o
	$(CC) $(CFLAGS) -o $@ main.o secuencia_arreglo.o $(LIBRARY_DIRS) $(LIBRARY)

$(TEST_TARGET): prueba.o secuencia_arreglo.o
	$(CC) $(CFLAGS) -o $@ prueba.o secuencia_arreglo.o $(LIBRARY_DIRS) $(LIBRARY)

# Enlace de versión alternativa (secuencia_lista)
$(PROG_ALT_TARGET): main.o secuencia_lista.o
	$(CC) $(CFLAGS) -o $@ main.o secuencia_lista.o $(LIBRARY_DIRS) $(LIBRARY)

$(TEST_ALT_TARGET): prueba.o secuencia_lista.o
	$(CC) $(CFLAGS) -o $@ prueba.o secuencia_lista.o $(LIBRARY_DIRS) $(LIBRARY)

.PHONY: alt
alt: $(PROG_ALT_TARGET) $(TEST_ALT_TARGET)

# Ejecución
.PHONY: run run-arreglo
run: $(PROG_TARGET)
	@echo "Ejecutando programa (implementación primaria: secuencia_arreglo)..."
	./$(PROG_TARGET)

run-arreglo: run

.PHONY: run-alt run-lista
run-alt: $(PROG_ALT_TARGET)
	@echo "Ejecutando programa (implementación alternativa: secuencia_lista)..."
	./$(PROG_ALT_TARGET)

run-lista: run-alt

# Pruebas unitarias
.PHONY: test test-arreglo test-lista test-alt
test-arreglo: $(TEST_TARGET)
	@echo "=== [Ejercicio 4] Pruebas: secuencia_arreglo (primaria) ==="
	./$(TEST_TARGET)

test-lista: $(TEST_ALT_TARGET)
	@echo "=== [Ejercicio 4] Pruebas: secuencia_lista (alternativa) ==="
	./$(TEST_ALT_TARGET)

test-alt: test-lista

test: test-arreglo test-lista

# Verificación de memoria con Valgrind
.PHONY: memcheck memcheck-arreglo memcheck-lista memcheck-alt
memcheck-arreglo: $(TEST_TARGET)
	@echo "=== [Ejercicio 4] Memcheck: secuencia_arreglo (primaria) ==="
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TEST_TARGET)

memcheck-lista: $(TEST_ALT_TARGET)
	@echo "=== [Ejercicio 4] Memcheck: secuencia_lista (alternativa) ==="
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TEST_ALT_TARGET)

memcheck-alt: memcheck-lista

memcheck: memcheck-arreglo memcheck-lista

.PHONY: clean
clean:
	@echo "Limpiando archivos objeto y ejecutables..."
	rm -f *.o $(PROG_TARGET) $(TEST_TARGET) $(PROG_ALT_TARGET) $(TEST_ALT_TARGET)

-include local.mk
