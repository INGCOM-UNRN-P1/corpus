/*
Ejercicio 4 - Gestionando el tiempo_t
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>

typedef struct {
    float horas;
    float minutos;
    float segundos;
} tiempo_t;

tiempo_t crear_tiempo(tiempo_t tiempo);
tiempo_t mostrar_tiempo(tiempo_t tiempo);
tiempo_t suma_tiempo(tiempo_t tiempo1, tiempo_t tiempo2);
int comparar_tiempo(tiempo_t tiempo1, tiempo_t tiempo2);

int main(){
	tiempo_t tiempo1, tiempo2,resultado;
	int resultado_1;
	
	printf("Escriba el tiempo 1:\n");
	tiempo1 = crear_tiempo(tiempo1);
	printf("\nEscriba el tiempo 2:\n");
	tiempo2 = crear_tiempo(tiempo2);
	
	printf("\nTiempo 1:\n");
	mostrar_tiempo(tiempo1);
	printf("\nTiempo 2:\n");
	mostrar_tiempo(tiempo2);
	
	printf("\nResultado de la suma de los dos tiempos:\n");
	resultado = suma_tiempo(tiempo1,tiempo2);
	mostrar_tiempo(resultado);
	
	resultado_1 = comparar_tiempo(tiempo1, tiempo2);

    if (resultado_1 == -1) {
        printf("\nEl primer tiempo es menor.\n");
    } else if (resultado_1 == 0) {
        printf("\nLos tiempos son iguales.\n");
    } else {
        printf("\nEl primer tiempo es mayor.\n");
    }
	
	return 0;
}

tiempo_t crear_tiempo(tiempo_t tiempo){
	printf("Escriba las horas: ");
	scanf("%f",&tiempo.horas);
	printf("Escriba los minutos: ");
	scanf("%f",&tiempo.minutos);
	printf("Escriba los segundos: ");
	scanf("%f",&tiempo.segundos);
	return tiempo;
}

tiempo_t mostrar_tiempo(tiempo_t tiempo) {
    if (tiempo.segundos >= 60) {
        tiempo.minutos += tiempo.segundos / 60;
        tiempo.segundos = tiempo.segundos - ((int)tiempo.segundos / 60) * 60;
    }
    if (tiempo.minutos >= 60) {
        tiempo.horas += tiempo.minutos / 60;
        tiempo.minutos = tiempo.minutos - ((int)tiempo.minutos / 60) * 60;
    }

    printf("%.0f Horas, %.0f Minutos, %.2f Segundos.\n", tiempo.horas, tiempo.minutos, tiempo.segundos);
    return tiempo;
}

tiempo_t suma_tiempo(tiempo_t tiempo1, tiempo_t tiempo2){
	tiempo_t resultado;
	resultado.segundos = tiempo1.segundos + tiempo2.segundos;
	resultado.minutos = tiempo1.minutos + tiempo2.minutos;
	resultado.horas = tiempo1.horas + tiempo2.horas;
	return resultado;
}

int comparar_tiempo(tiempo_t tiempo1, tiempo_t tiempo2) {
    while (tiempo1.segundos >= 60) {
        tiempo1.minutos += 1;
        tiempo1.segundos -= 60;
    }
    while (tiempo1.minutos >= 60) {
        tiempo1.horas += 1;
        tiempo1.minutos -= 60;
    }

    while (tiempo2.segundos >= 60) {
        tiempo2.minutos += 1;
        tiempo2.segundos -= 60;
    }
    while (tiempo2.minutos >= 60) {
        tiempo2.horas += 1;
        tiempo2.minutos -= 60;
    }
	
	if (tiempo1.horas < tiempo2.horas) {
        return -1;
    } else if (tiempo1.horas > tiempo2.horas) {
        return 1;
    } else if (tiempo1.minutos < tiempo2.minutos) {
        return -1;
    } else if (tiempo1.minutos > tiempo2.minutos) {
        return 1;
    } else if (tiempo1.segundos < tiempo2.segundos) {
        return -1;
    } else if (tiempo1.segundos > tiempo2.segundos) {
        return 1;
    } else {
        return 0;
    }
}

//Precondiciones: 
//Se espera que el usuario ingrese tres valores válidos (horas, minutos y segundos) para cada uno de los dos tiempos (tiempo1 y tiempo2) en la función crear_tiempo.
//El programa se ejecuta sin errores en la lectura de entrada y las operaciones matemáticas son válidas.

//Postcondiciones:
//Después de la ejecución, el programa muestra dos estructuras de tiempo: tiempo1 y tiempo2.
//Luego, calcula la suma de tiempo1 y tiempo2 y muestra el resultado en la función suma_tiempo.
//En la función mostrar_tiempo, se realiza una corrección de los valores para garantizar que los segundos y los minutos sean válidos y se muestra el tiempo en un formato legible.
//La función comparar_tiempo compara tiempo1 y tiempo2 y devuelve -1 si tiempo1 es menor, 0 si son iguales o 1 si tiempo1 es mayor.
//El programa finaliza sin errores.
