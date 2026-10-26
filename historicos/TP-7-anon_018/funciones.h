#ifndef FUNCIONES_H
#define FUNCIONES_H

#define ARCHNAME 30
#define ANCHOALTO 100
#define CADENACORTA -1


int copiar_archivo(int tam, FILE *txt, char matriz[tam][tam]);


int leer_operaciones(int alto, int ancho, char matriz[alto][ancho]);


int suma(int inicio, int fin, int ancho, int sub,char matriz[fin][ancho]);


int resta(int inicio, int fin, int ancho, int sub,char matriz[fin][ancho]);


int promedio(int inicio, int fin, int ancho, int sub,char matriz[fin][ancho]);


int multiplica(int inicio, int fin, int ancho, int sub,char matriz[fin][ancho]);


int total(int op, int subtotal);

int atoi();


#endif