CC=gcc
CFLAGS=-Wall -Werror -Wextra -I. 
DEPS = mis_funciones.h
OBJ = mis_funciones.o 

TARGET = ejercicio1 ejercicio2 ejercicio3

default: $(TARGET)
all: default

clean:
	rm -f *.o
	rm -f $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ejercicio1: ejercicio1.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio2: ejercicio2.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

ejercicio3: ejercicio3.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

