# Variables generales
CC ?= gcc
CFLAGS ?= -Wall -Wextra -pedantic -std=c99 -g
LDFLAGS ?= -lm

# Archivos comunes (código fuente y cabeceras del ejercicio)
SRCS = $(filter-out main.c prueba.c, $(wildcard *.c))
HDRS = $(wildcard *.h)
OBJS = $(SRCS:.c=.o)

# Objetivo del programa principal
PROG_TARGET = programa
PROG_SRCS = main.c
PROG_OBJS = $(PROG_SRCS:.c=.o)

# Objetivo de los tests
TEST_TARGET = test_bin
TEST_SRCS = prueba.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Compilar ambos: programa y tests
all: $(PROG_TARGET) $(TEST_TARGET)

# Compilar el programa principal
$(PROG_TARGET): $(PROG_OBJS) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(PROG_OBJS) $(OBJS) $(LDFLAGS)

# Compilar el ejecutable de pruebas
$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(OBJS) $(LDFLAGS)

# Regla genérica para compilar archivos .o a partir de .c
%.o: %.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) -c $<

# Ejecutar el programa principal
.PHONY: run
run: $(PROG_TARGET)
	@echo "Ejecutando el programa"
	./$(PROG_TARGET)

# Ejecutar las pruebas
.PHONY: test
test: $(TEST_TARGET)
	@echo "Ejecutando pruebas"
	./$(TEST_TARGET)

# Limpiar archivos objeto y ejecutables
.PHONY: clean
clean:
	@echo "Limpiando archivos objeto y ejecutables..."
	rm -f *.o $(PROG_TARGET) $(TEST_TARGET)

# Incluir personalizaciones locales si existen
-include local.mk
