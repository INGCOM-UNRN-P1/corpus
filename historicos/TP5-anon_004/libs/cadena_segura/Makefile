CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c11 -pedantic -g

TEST_LIB_NAME ?= p1_test
TEST_LIBS ?= $(TEST_LIB_NAME)

ROOT_DIR = ../..
LIBS_DIR = $(ROOT_DIR)/libs

TEST_INCLUDE_DIRS = $(foreach lib,$(TEST_LIBS),$(if $(wildcard $(LIBS_DIR)/$(lib)/include),-I$(LIBS_DIR)/$(lib)/include -I$(LIBS_DIR)/$(lib),-I$(LIBS_DIR)/$(lib)))
TEST_LIBRARY_DIRS = $(foreach lib,$(TEST_LIBS),$(if $(wildcard $(LIBS_DIR)/$(lib)/build),-L$(LIBS_DIR)/$(lib)/build,$(if $(wildcard $(LIBS_DIR)/$(lib)/lib),-L$(LIBS_DIR)/$(lib)/lib,-L$(LIBS_DIR)/$(lib))))
TEST_LIBRARY = $(addprefix -l,$(TEST_LIBS))

SRCS = $(filter-out prueba.c, $(wildcard *.c))
HDRS = $(wildcard *.h)

LIB_NAME := $(notdir $(CURDIR))
LIBRARY_NAME = lib$(LIB_NAME).a

TEST_TARGET = test_bin
TEST_SRCS = $(SRCS) prueba.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(LIBRARY_NAME) $(TEST_TARGET)

$(LIBRARY_NAME): $(OBJS)
	@echo "Generando librería estática $@"
	ar rcs $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	@for lib in $(TEST_LIBS); do \
		if [ -d "$(LIBS_DIR)/$$lib" ] && [ -f "$(LIBS_DIR)/$$lib/Makefile" ] && [ ! -f "$(LIBS_DIR)/$$lib/lib$$lib.a" ] && [ ! -f "$(LIBS_DIR)/$$lib/build/lib$$lib.a" ]; then \
			echo "Compilando dependencia $$lib..."; \
			$(MAKE) -C "$(LIBS_DIR)/$$lib" >/dev/null 2>&1 || exit 1; \
		fi; \
	done
	@echo "Compilando $@"
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(TEST_LIBRARY_DIRS) $(TEST_LIBRARY)

prueba.o: prueba.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) $(TEST_INCLUDE_DIRS) -c $<

%.o: %.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) -c $<

.PHONY: test
test: $(TEST_TARGET)
	@echo "Probando librería..."
	./$(TEST_TARGET)

.PHONY: memcheck
memcheck: $(TEST_TARGET)
	@echo "Verificando con Valgrind..."
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TEST_TARGET)

.PHONY: clean
clean:
	@echo "Limpiando..."
	rm -f *.o $(LIBRARY_NAME) $(TEST_TARGET)

-include local.mk
