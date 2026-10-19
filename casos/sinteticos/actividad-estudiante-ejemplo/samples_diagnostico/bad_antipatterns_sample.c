#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Muestra de código con antipatrones intencionales para practicar
 * la detección estática con spunkmeyer, kaneda y gaff.
 */
int funcion_con_antipatrones(void) {
    /* Antipatrón 1: Cast innecesario de malloc (Spunkmeyer SPK001) */
    int* buffer = (int*)malloc(10 * sizeof(int));

    /* Antipatrón 2: Comparación redundante con booleano (Spunkmeyer SPK003) */
    bool flag = true;
    if (flag == true) {
        printf("Flag activa\n");
    }

    /* Antipatrón 3: NULL check redundante antes de free (Spunkmeyer SPK002) */
    if (buffer != NULL) {
        free(buffer);
    }

    return 0;
}
