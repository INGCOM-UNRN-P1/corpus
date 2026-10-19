CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -pedantic -Wconversion -Wshadow -g -Iinclude
CFLAGS_ASAN ?= $(CFLAGS) -fsanitize=address,undefined

SRC = src/envio.c src/lista_envios.c src/procesador.c
OBJS = $(SRC:.c=.o)
MAIN_SRC = src/main.c
TEST_SRC = tests/test_lista.c

BIN_DIR = bin
TARGET = $(BIN_DIR)/sistema_envios
TEST_TARGET = $(BIN_DIR)/test_lista
FUZZ_TARGET = $(BIN_DIR)/fuzz_target
ASAN_TARGET = $(BIN_DIR)/sistema_envios_asan

TOOLS_ROOT ?= ..
PYTHON ?= python3

.PHONY: all build test clean doctor help \
        esper-build daedalus-build check-style check-ripley \
        check-antipatterns check-security audit-structs \
        trace-memory trace-recursion disasm-switch verify-contracts \
        callgraph test-sandbox test-faults test-asan fuzz diff-canon audit-all

all: build test

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

build: $(BIN_DIR) $(TARGET)

$(TARGET): $(SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(MAIN_SRC)

test: $(BIN_DIR) $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(TEST_SRC)

$(FUZZ_TARGET): $(SRC) tests/fuzz_target.c
	$(CC) $(CFLAGS) -o $@ $(SRC) tests/fuzz_target.c

$(ASAN_TARGET): $(SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS_ASAN) -o $@ $(SRC) $(MAIN_SRC)

clean:
	rm -rf $(BIN_DIR) *.o src/*.o tests/*.o *.log core core.* reporte_*.md

# ==============================================================================
# SECCIÓN: HERRAMIENTAS DE ESTUDIANTE (Ecosistema C)
# ==============================================================================

doctor:
	@echo "=== Diagnóstico del Entorno Estudiantil ==="
	@which gcc clang gdb valgrind typst >/dev/null 2>&1 || true
	@PYTHONPATH=$(TOOLS_ROOT)/ripley/src:$(TOOLS_ROOT)/esper/src:$(TOOLS_ROOT)/vasquez/src \
	$(PYTHON) -m ripley doctor 2>/dev/null || true

esper-build:
	@echo "=== 1. Compilación Asistida con Citas ISO C (esper) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/esper/src $(PYTHON) -m esper.cli compile $(SRC) $(MAIN_SRC) -o $(TARGET)

daedalus-build:
	@echo "=== 2. Compilación Pedagógica con Cátedra Flags (daedalus) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/daedalus/src $(PYTHON) -m daedalus.cli compile $(SRC) $(MAIN_SRC) -o $(TARGET)

check-style:
	@echo "=== 3. Auditoría de Estilo y Convenciones C (gaff) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/gaff/src $(PYTHON) -m gaff.cli check src/ include/

check-ripley:
	@echo "=== 4. Linter Pedagógico y Reglas 0xXXXXh (ripley) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/ripley/src $(PYTHON) -m ripley.cli check src/ include/ 2>/dev/null || true

check-antipatterns:
	@echo "=== 5. Detección de Antipatrones de C (spunkmeyer) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/spunkmeyer/src $(PYTHON) -m spunkmeyer.cli detect src/ include/

check-security:
	@echo "=== 6. Auditoría Estática de Seguridad (kaneda) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/kaneda/src $(PYTHON) -m kaneda.cli audit src/ include/

audit-structs:
	@echo "=== 7. Auditoría y Optimización de Structs (brett) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/brett/src $(PYTHON) -m brett.cli audit include/envio.h

trace-memory: $(TEST_TARGET)
	@echo "=== 8. Visualización de Memoria Stack & Heap (bishop) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/bishop/src $(PYTHON) -m bishop.cli trace -- $(TEST_TARGET) 2>/dev/null || true

trace-recursion:
	@echo "=== 9. Análisis de Funciones Recursivas y Stack (sebastian) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/sebastian/src $(PYTHON) -m sebastian.cli trace src/lista_envios.c

disasm-switch:
	@echo "=== 10. Desensamblado de Switch y Jump Tables (rachel) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/rachel/src $(PYTHON) -m rachel.cli check src/procesador.c

verify-contracts:
	@echo "=== 11. Verificación Formal de Contratos ACSL (callahan) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/callahan/src $(PYTHON) -m callahan.cli check include/envio.h include/lista_envios.h 2>/dev/null || true

callgraph:
	@echo "=== 12. Grafo de Llamadas y Detección de Código Muerto (giger) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/giger/src $(PYTHON) -m giger.cli callgraph src/ include/ 2>/dev/null || true

test-sandbox: $(TARGET)
	@echo "=== 13. Evaluación de Casos de Prueba en Sandbox Aislado (nostromo) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/nostromo/src $(PYTHON) -m nostromo.cli run --binary $(TARGET) --testcases testcases/ 2>/dev/null || true

test-faults: $(TEST_TARGET)
	@echo "=== 14. Inyección de Fallos de Memoria en Runtime (vasquez) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/vasquez/src $(PYTHON) -m vasquez.cli run --fault malloc -- $(TEST_TARGET) 2>/dev/null || true

test-asan: $(ASAN_TARGET)
	@echo "=== 15. Ejecución con AddressSanitizer ==="
	@$(ASAN_TARGET) < testcases/01_alta_simple.in >/dev/null

fuzz: $(FUZZ_TARGET)
	@echo "=== 16. Fuzzing Guiado por Límites (drake) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/drake/src $(PYTHON) -m drake.cli fuzz --binary $(FUZZ_TARGET) --runs 20 2>/dev/null || true

diff-canon:
	@echo "=== 17. Comparación Semántica AST con Solución Canónica (weyl) ==="
	@PYTHONPATH=$(TOOLS_ROOT)/weyl/src $(PYTHON) -m weyl.cli diff src/lista_envios.c canon/lista_envios_canon.c

# ==============================================================================
# PIPELINE INTEGRAL DE PRE-ENTREGA
# ==============================================================================

audit-all: check-style check-ripley check-antipatterns check-security audit-structs test test-sandbox
	@echo ""
	@echo "================================================================================"
	@echo " [AUDITORÍA ESTUDIANTIL EXITOSA] El código cumple los estándares de la cátedra."
	@echo "================================================================================"
