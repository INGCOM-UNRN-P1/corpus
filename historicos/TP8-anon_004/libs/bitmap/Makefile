# Variables generales
CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c11 -pedantic -g

# Directorio raíz del proyecto para referenciar libs
ROOT_DIR = ../..
LIBS_DIR = $(ROOT_DIR)/libs

# Archivos comunes, se autodetectan los .c y .h
SRCS = $(filter-out prueba.c, $(wildcard *.c))
HDRS = $(wildcard *.h)

# Nombre de la librería estática (se deduce del nombre de la carpeta)
LIB_NAME := $(notdir $(CURDIR))
LIBRARY_NAME = lib$(LIB_NAME).a

# Archivos objeto de la librería
OBJS = $(SRCS:.c=.o)

# Compilar: solo la librería (sin tests propios en este contexto)
all: $(LIBRARY_NAME)

# Crear la librería estática .a
$(LIBRARY_NAME): $(OBJS)
	@echo "Generando librería estática $@"
	ar rcs $@ $^

# Regla genérica para compilar archivos .o a partir de .c
%.o: %.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) -c $<

# Limpiar archivos objeto y ejecutables
.PHONY: clean
clean:
	@echo "Limpiando..."
	rm -f *.o $(LIBRARY_NAME)

# Incluir personalizaciones locales si existen
-include local.mk
