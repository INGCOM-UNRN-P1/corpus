CC=gcc
CFLAGS=-I. 
DEPS = mis_funciones.h
OBJ = mis_funciones.o 

TARGET = tp0eja1_Hola_Mundo tp0eja2_ajedrez_y_granos_de_trigo tp0eja3_operadores_aritmeticos tp0eja4_multiplos tp0eja5_lazos tp0eja6_factorial tp0eja7_factorial_reload tp0eja8_fibonacci tp0eja9_bucle_infinito tp0ej201_dias_de_la_semana tp0ej202_suma_lenta tp0ej203_comparacion_de_numeros tp0ej204_es_primo tp0ej205_restas_sucesivas tp0ej206_compara_fechas

default: $(TARGET)
all: default

clean:
	rm -f *.o
	rm -f $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp0eja1_Hola_Mundo: tp0eja1_Hola_Mundo.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja2_ajedrez_y_granos_de_trigo: tp0eja2_ajedrez_y_granos_de_trigo.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja3_operadores_aritmeticos: tp0eja3_operadores_aritmeticos.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja4_multiplos: tp0eja4_multiplos.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja5_lazos: tp0eja5_lazos.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja6_factorial: tp0eja6_factorial.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja7_factorial_reload: tp0eja7_factorial_reload.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja8_fibonacci: tp0eja8_fibonacci.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0eja9_bucle_infinito: tp0eja9_bucle_infinito.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0ej201_dias_de_la_semana: tp0ej201_dias_de_la_semana.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0ej202_suma_lenta: tp0ej202_suma_lenta.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0ej203_comparacion_de_numeros: tp0ej203_comparacion_de_numeros.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0ej204_es_primo: tp0ej204_es_primo.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0ej205_restas_sucesivas: tp0ej205_restas_sucesivas.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tp0ej206_compara_fechas: tp0ej206_compara_fechas.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
