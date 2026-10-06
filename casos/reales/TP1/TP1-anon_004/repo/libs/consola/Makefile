# Variables generales
CC ?= gcc
CFLAGS ?= -Wall -Wextra -pedantic -g

# Archivos comunes, se autodetectan los .c y .h
SRCS = $(filter-out prueba.c, $(wildcard *.c))
HDRS = $(wildcard *.h)

# ==============================================================================
# NOTA DE CORRECCIÓN (Compatibilidad MinGW / Rutas con espacios en Windows):
# La deducción dinámica original generaba nombres partidos y omitía el prefijo 'lib':
#   LIB_NAME := $(notdir $(CURDIR))
#   LIBRARY_NAME = lib$(LIB_NAME).a
# Se fijó de forma explícita para garantizar la creación de 'libconsola.a' sin fallos.
# ==============================================================================
LIB_NAME = consola
LIBRARY_NAME = libconsola.a

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
	@echo "Compilando $@"
	$(CC) $(CFLAGS) -o $@ $^

# Regla genérica para compilar archivos .o a partir de .c
%.o: %.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) -c $<

# Ejecutar las pruebas
.PHONY: test
test: $(TEST_TARGET)
	@echo "Probando librería..."
	./$(TEST_TARGET)

# Limpiar archivos objeto y ejecutables
.PHONY: clean
clean:
	@echo "Limpiando..."
	rm -f *.o $(LIBRARY_NAME) $(TEST_TARGET)

# Incluir personalizaciones locales si existen
-include local.mk
