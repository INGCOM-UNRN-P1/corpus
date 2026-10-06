/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"

int main(void)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
    
    printf("probamos clonar_cadena\n");
    
   const char *original = "buuuuuenas";
    char *copy = clonar_cadena(original);
    if (copy != NULL){
        printf ("orishinal; %s\n", original);
        printf("copy = %s\n", copy);
    }else{
        printf("error en malloc./");
    }
    printf("probamos unir_Cadenas_dinamicas\n");
    const char *primera = "divi";
    const char *segunda = "didos";
    char *divididos = unir_cadenas_dinamicas (primera, segunda);

    if(divididos != NULL){
        printf("la aplanadora del rocanrol: %s\n", divididos);
    } else{
        printf("fallo malloc\n");
    }

    free(divididos);
    free(copy);
    return 0;
}
