CC=gcc
CFLAGS=-Wall -Werror -Wextra -I. 
DEPS = mis_funciones.h mis_cadenas.h
OBJ  = mis_funciones.o mis_cadenas.o

TARGET = ejercicio

default: $(TARGET)
all: default

clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f *.c.orig *.h.orig

indent:
	[ -f *.h ] && astyle *.h
	[ -f *.c ] && astyle *.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ejercicio: ejercicio.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

