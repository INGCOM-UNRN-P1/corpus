CC=gcc
CFLAGS=-Wall -Werror -Wextra -I. 
DEPS = mis_funciones.h
OBJ = mis_funciones.o 

TARGET = ejercicio

default: $(TARGET)
all: default

clean:
	rm -f *.o
	rm -f $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ejercicio: ejercicio.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

