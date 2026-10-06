# Variables generales
CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c11 -pedantic -g

# Dependencias para las pruebas (separadas por espacio)
TEST_LIB_NAME ?= p1_test
TEST_LIBS ?= $(TEST_LIB_NAME)

# Directorio raíz del proyecto para referenciar libs
ROOT_DIR = ../..
LIBS_DIR = $(ROOT_DIR)/libs

# Detección dinámica de los directorios de headers y biblioteca según el esquema (plano o estructurado)
TEST_INCLUDE_DIRS = $(foreach lib,$(TEST_LIBS),$(if $(wildcard $(LIBS_DIR)/$(lib)/include),-I$(LIBS_DIR)/$(lib)/include -I$(LIBS_DIR)/$(lib),-I$(LIBS_DIR)/$(lib)))
TEST_LIBRARY_DIRS = $(foreach lib,$(TEST_LIBS),$(if $(wildcard $(LIBS_DIR)/$(lib)/build),-L$(LIBS_DIR)/$(lib)/build,$(if $(wildcard $(LIBS_DIR)/$(lib)/lib),-L$(LIBS_DIR)/$(lib)/lib,-L$(LIBS_DIR)/$(lib))))
TEST_LIBRARY = $(addprefix -l,$(TEST_LIBS))

# Archivos comunes, se autodetectan los .c y .h
SRCS = $(filter-out prueba.c, $(wildcard *.c))
HDRS = $(wildcard *.h)

# Nombre de la librería estática (se deduce del nombre de la carpeta)
LIB_NAME := $(notdir $(CURDIR))
LIBRARY_NAME = lib$(LIB_NAME).a

# Archivos para tests
TEST_TARGET = test_bin
TEST_SRCS = $(SRCS) prueba.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Archivos objeto de la librería
OBJS = $(SRCS:.c=.o)

# Compilar ambos: libreria y tests
all: $(LIBRARY_NAME) $(TEST_TARGET)

# Crear la librería estática .a
$(LIBRARY_NAME): $(OBJS)
	@echo "Generando librería estática $@"
	ar rcs $@ $^

# Compilar el ejecutable de pruebas
$(TEST_TARGET): $(TEST_OBJS)
	@for lib in $(TEST_LIBS); do \
		if [ -d "$(LIBS_DIR)/$$lib" ] && [ -f "$(LIBS_DIR)/$$lib/Makefile" ] && [ ! -f "$(LIBS_DIR)/$$lib/lib$$lib.a" ] && [ ! -f "$(LIBS_DIR)/$$lib/build/lib$$lib.a" ]; then \
			echo "Compilando dependencia $$lib..."; \
			$(MAKE) -C "$(LIBS_DIR)/$$lib" >/dev/null 2>&1 || exit 1; \
		fi; \
	done
	@echo "Compilando $@"
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(TEST_LIBRARY_DIRS) -L../cadenas $(TEST_LIBRARY) -lcadenas

# Regla específica para compilar el archivo de pruebas con sus dependencias
prueba.o: prueba.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) $(TEST_INCLUDE_DIRS) -c $<

# Regla genérica para compilar archivos .o a partir de .c
%.o: %.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) -c $<

# Ejecutar las pruebas
.PHONY: test
test: $(TEST_TARGET)
	@echo "Probando librería..."
	./$(TEST_TARGET)

# Verificación con Valgrind
.PHONY: memcheck
memcheck: $(TEST_TARGET)
	@echo "Verificando con Valgrind..."
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TEST_TARGET)

# Limpiar archivos objeto y ejecutables
.PHONY: clean
clean:
	@echo "Limpiando..."
	rm -f *.o $(LIBRARY_NAME) $(TEST_TARGET)

# Incluir personalizaciones locales si existen
-include local.mk
