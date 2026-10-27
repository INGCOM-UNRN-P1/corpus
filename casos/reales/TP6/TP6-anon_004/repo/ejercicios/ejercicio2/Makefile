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

# Implementación primaria: tiempo_hms (desglosada)
# Implementación alternativa: tiempo_seg (segundos totales)

HDRS = tiempo.h

# Objetivos primarios
PROG_TARGET = programa
TEST_TARGET = test_bin

# Objetivos alternativos
PROG_ALT_TARGET = programa_seg
TEST_ALT_TARGET = test_bin_seg

all: $(PROG_TARGET) $(TEST_TARGET) alt

tiempo_hms.o: tiempo_hms.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

tiempo_seg.o: tiempo_seg.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

main.o: main.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

prueba.o: prueba.c $(HDRS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Enlace de versión primaria (tiempo_hms)
$(PROG_TARGET): main.o tiempo_hms.o
	$(CC) $(CFLAGS) -o $@ main.o tiempo_hms.o $(LIBRARY_DIRS) $(LIBRARY)

$(TEST_TARGET): prueba.o tiempo_hms.o
	$(CC) $(CFLAGS) -o $@ prueba.o tiempo_hms.o $(LIBRARY_DIRS) $(LIBRARY)

# Enlace de versión alternativa (tiempo_seg)
$(PROG_ALT_TARGET): main.o tiempo_seg.o
	$(CC) $(CFLAGS) -o $@ main.o tiempo_seg.o $(LIBRARY_DIRS) $(LIBRARY)

$(TEST_ALT_TARGET): prueba.o tiempo_seg.o
	$(CC) $(CFLAGS) -o $@ prueba.o tiempo_seg.o $(LIBRARY_DIRS) $(LIBRARY)

.PHONY: alt
alt: $(PROG_ALT_TARGET) $(TEST_ALT_TARGET)

# Ejecución
.PHONY: run run-hms
run: $(PROG_TARGET)
	@echo "Ejecutando programa (implementación primaria: tiempo_hms)..."
	./$(PROG_TARGET)

run-hms: run

.PHONY: run-alt run-seg
run-alt: $(PROG_ALT_TARGET)
	@echo "Ejecutando programa (implementación alternativa: tiempo_seg)..."
	./$(PROG_ALT_TARGET)

run-seg: run-alt

# Pruebas unitarias
.PHONY: test test-hms test-seg test-alt
test-hms: $(TEST_TARGET)
	@echo "=== [Ejercicio 2] Pruebas: tiempo_hms (primaria) ==="
	./$(TEST_TARGET)

test-seg: $(TEST_ALT_TARGET)
	@echo "=== [Ejercicio 2] Pruebas: tiempo_seg (alternativa) ==="
	./$(TEST_ALT_TARGET)

test-alt: test-seg

test: test-hms test-seg

# Verificación de memoria con Valgrind
.PHONY: memcheck memcheck-hms memcheck-seg memcheck-alt
memcheck-hms: $(TEST_TARGET)
	@echo "=== [Ejercicio 2] Memcheck: tiempo_hms (primaria) ==="
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TEST_TARGET)

memcheck-seg: $(TEST_ALT_TARGET)
	@echo "=== [Ejercicio 2] Memcheck: tiempo_seg (alternativa) ==="
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TEST_ALT_TARGET)

memcheck-alt: memcheck-seg

memcheck: memcheck-hms memcheck-seg

.PHONY: clean
clean:
	@echo "Limpiando archivos objeto y ejecutables..."
	rm -f *.o $(PROG_TARGET) $(TEST_TARGET) $(PROG_ALT_TARGET) $(TEST_ALT_TARGET)

-include local.mk
