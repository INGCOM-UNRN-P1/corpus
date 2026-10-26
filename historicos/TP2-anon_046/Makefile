CC=gcc
CFLAGS=-I. 
DEPS = mis_funciones.h
OBJ = mis_funciones.o 

TARGET = tp2ej1a_raiz_de_n tp2ej1b_raiz_de_n_y_de_m tp2ej2_producto_y_potencia tp2ej3_factorial_y_combinatoria tp2ej4_asteriscos tp2ej5_min_max_mean

default: $(TARGET)
all: default

clean:
	rm -f *.o
	rm -f $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp2ej1a_raiz_de_n: tp2ej1a_raiz_de_n.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp2ej1b_raiz_de_n_y_de_m: tp2ej1b_raiz_de_n_y_de_m.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp2ej2_producto_y_potencia: tp2ej2_producto_y_potencia.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp2ej3_factorial_y_combinatoria: tp2ej3_factorial_y_combinatoria.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp2ej4_asteriscos: tp2ej4_asteriscos.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp2ej5_min_max_mean: tp2ej5_min_max_mean.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

