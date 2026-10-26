CC=gcc
CFLAGS=-Wall -Werror -Wextra -I. 
DEPS = mis_funciones.h
OBJ = mis_funciones.o 

TARGET = ejercicio01 ejercicio02 ejercicio03 ejercicio04 ejercicio05 ejercicio06 ejercicio07 ejercicio08 ejercicio09 ejercicio10

default: $(TARGET)
all: default

clean:
	rm -f *.o
	rm -f $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ejercicio01: ejercicio01.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio02: ejercicio02.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio03: ejercicio03.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio04: ejercicio04.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio05: ejercicio05.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio06: ejercicio06.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio07: ejercicio07.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio08: ejercicio08.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio09: ejercicio09.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio10: ejercicio10.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

