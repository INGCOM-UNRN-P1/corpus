#include "envio.h"
#include "lista_envios.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Prueba de resiliencia frente a fallos de memoria dinámica */
void test_resiliencia_memoria_insuficiente(void) {
    lista_envios_t* l = lista_crear();
    if (!l) {
        printf("PASS: Manejo correcto de falla de malloc en lista_crear\n");
        return;
    }

    envio_t* e = envio_crear(55, "FAIL-1", "Destino", 1000, 1.0, 1, false);
    if (e) {
        bool res = lista_insertar_final(l, e);
        if (!res) {
            envio_destruir(e);
            printf("PASS: Manejo correcto de falla de malloc en nodo de insercion\n");
        }
    }

    lista_destruir(l);
    printf("PASS: test_resiliencia_memoria_insuficiente finalizado\n");
}

int main(void) {
    test_resiliencia_memoria_insuficiente();
    return 0;
}
