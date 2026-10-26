# Makefile Principal Dinámico

# Detectar librerías en libs/
LIB_DIRS := $(wildcard libs/*)

# Detectar ejercicios en ejercicios/
EX_DIRS := $(wildcard ejercicios/*)

.PHONY: all librerias clean run run-alt alt test test-alt memcheck memcheck-alt $(EX_DIRS) $(LIB_DIRS)

all: librerias $(EX_DIRS)

librerias: $(LIB_DIRS)

# Regla para compilar cada librería de forma independiente si tiene un Makefile
$(LIB_DIRS):
	@if [ -f $@/Makefile ]; then \
		echo "Compilando librería en $@..."; \
		$(MAKE) -C $@ || exit 1; \
	fi

# Regla para compilar cada ejercicio, asegurando que primero se compilen las librerías
$(EX_DIRS): librerias
	@if [ -f $@/Makefile ]; then \
		echo "Compilando ejercicio en $@..."; \
		$(MAKE) -C $@ || exit 1; \
	fi

# Compilar versiones alternativas en aquellos ejercicios que las posean
alt: librerias
	@echo "Compilando implementaciones alternativas en ejercicios..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			if grep -q "^alt:" $$dir/Makefile 2>/dev/null; then \
				echo "--- Compilando alternativa en $$dir ---"; \
				$(MAKE) -C $$dir alt || exit 1; \
			fi; \
		fi; \
	done

# Ejecución de programas demostrativos primarios
run: librerias
	@echo "Ejecutando programas de ejercicios (implementaciones primarias)..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "--- Ejecutando $$dir ---"; \
			$(MAKE) -C $$dir run || exit 1; \
		fi; \
	done

# Ejecución de programas con implementaciones alternativas
run-alt: librerias
	@echo "Ejecutando programas de ejercicios con implementaciones alternativas..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			if grep -q "^run-alt:" $$dir/Makefile 2>/dev/null; then \
				echo "--- Ejecutando alternativa en $$dir ---"; \
				$(MAKE) -C $$dir run-alt || exit 1; \
			fi; \
		fi; \
	done

# Ejecutar pruebas (cada ejercicio con variantes ejecuta automáticamente ambas)
test: librerias
	@echo "Ejecutando pruebas de librerías..."
	@for dir in $(LIB_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "--- Probando librería $$dir ---"; \
			$(MAKE) -C $$dir test || exit 1; \
		fi; \
	done
	@echo "Ejecutando pruebas de ejercicios..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "--- Probando ejercicio $$dir ---"; \
			$(MAKE) -C $$dir test || exit 1; \
		fi; \
	done

# Ejecutar pruebas de implementaciones alternativas exclusivamente
test-alt: librerias
	@echo "Ejecutando pruebas de implementaciones alternativas en ejercicios..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			if grep -q "^test-alt:" $$dir/Makefile 2>/dev/null; then \
				echo "--- Probando alternativa en $$dir ---"; \
				$(MAKE) -C $$dir test-alt || exit 1; \
			fi; \
		fi; \
	done

# Verificación con Valgrind (ejecuta sobre primarias y alternativas)
memcheck: librerias
	@echo "Ejecutando verificación con Valgrind en librerías..."
	@for dir in $(LIB_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "--- Memcheck en $$dir ---"; \
			$(MAKE) -C $$dir memcheck || exit 1; \
		fi; \
	done
	@echo "Ejecutando verificación con Valgrind en ejercicios..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "--- Memcheck en $$dir ---"; \
			$(MAKE) -C $$dir memcheck || exit 1; \
		fi; \
	done

# Verificación de Valgrind exclusiva sobre alternativas
memcheck-alt: librerias
	@echo "Ejecutando verificación con Valgrind en implementaciones alternativas..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			if grep -q "^memcheck-alt:" $$dir/Makefile 2>/dev/null; then \
				echo "--- Memcheck alternativa en $$dir ---"; \
				$(MAKE) -C $$dir memcheck-alt || exit 1; \
			fi; \
		fi; \
	done

clean:
	@echo "Limpiando todos los ejecutables, librerías estáticas y archivos objeto..."
	@for dir in $(LIB_DIRS) $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			$(MAKE) -C $$dir clean; \
		fi; \
	done

# Incluir personalizaciones locales si existen
-include local.mk
