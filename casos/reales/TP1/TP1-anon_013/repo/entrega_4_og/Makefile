# Makefile Principal

# Detectar ejercicios en ejercicios/
EX_DIRS := $(wildcard ejercicios/*)

.PHONY: all clean run test $(EX_DIRS)

all: $(EX_DIRS)

# Regla para compilar cada ejercicio de forma independiente
$(EX_DIRS):
	@if [ -f $@/Makefile ]; then \
		echo "Compilando ejercicio en $@..."; \
		$(MAKE) -C $@ || exit 1; \
	fi

run:
	@echo "Ejecutando programas de ejercicios..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "--- Ejecutando $$dir ---"; \
			$(MAKE) -C $$dir run || exit 1; \
		fi; \
	done

test:
	@echo "Ejecutando pruebas de ejercicios..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "--- Probando ejercicio $$dir ---"; \
			$(MAKE) -C $$dir test || exit 1; \
		fi; \
	done

clean:
	@echo "Limpiando archivos objeto y ejecutables..."
	@for dir in $(EX_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			$(MAKE) -C $$dir clean; \
		fi; \
	done

# Incluir personalizaciones locales si existen
-include local.mk
