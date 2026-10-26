# Variables generales
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g

# Nombres de las librerías (sin prefijo 'lib' y sin extensión '.a')
LIB_NAME = estandar cadenas arreglos

# Directorios de las librerías
LIB_DIR = $(addprefix ../,$(LIB_NAME))

# Archivos de las librerías estáticas
LIBRARY = $(addprefix -l,$(LIB_NAME))
LIBRARY_DIRS = $(addprefix -L,$(LIB_DIR))

# Directorios de los programas
PROG_DIRS = ejercicio2 ejercicio3

# Objetivos para compilar todos los programas y las librerías
.PHONY: all
all: librerias $(PROG_DIRS)

# Ejecutar programas para cada directorio en PROG_DIRS
.PHONY: run
run: $(PROG_DIRS)
	@echo "Ejecutando programas..."
	$(foreach prog_dir, $(PROG_DIRS), $(MAKE) -C $(prog_dir) run;)

# Compilar las librerías estáticas
.PHONY: librerias
librerias: 
	@echo "Compilando librerías..."
	@echo "Estandar"
	$(MAKE) -C estandar
	@echo "Cadenas Seguras"
	$(MAKE) -C cadenas
	@echo "Arreglos"
	$(MAKE) -C arreglos


# Regla para compilar cada programa
$(PROG_DIRS): librerias
	@echo "Compilando programa en $@"
	$(MAKE) -C $@

# Limpieza generales de todos los programas y librerías
.PHONY: clean
clean:
	@echo "Limpiando todos los programas y librerías..."
	$(MAKE) -C estandar clean
	$(MAKE) -C cadenas clean
	$(MAKE) -C arreglos clean
	$(MAKE) -C ejercicio2 clean
	$(MAKE) -C ejercicio3 clean


# Ejecutar pruebas para un programa específico (ejemplo: ejercicio2)
.PHONY: test
test: 
	@echo "Ejecutando pruebas..."
	@echo "Test"
	$(MAKE) -C estandar test
	@echo "Cadenas Seguras"
	$(MAKE) -C cadenas test
	@echo "Arreglos"
	$(MAKE) -C arreglos test
	$(foreach prog_dir, $(PROG_DIRS), $(MAKE) -C $(prog_dir) test;)

