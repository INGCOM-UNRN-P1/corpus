#include "envio.h"
#include "lista_envios.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_crear_destruir_envio(void) {
    envio_t* e = envio_crear(101, "AR-9921", "Cordoba", 5000, 2.5, 3, false);
    assert(e != NULL);
    assert(e->id_tracking == 101);
    assert(e->peso_kg == 2.5);
    assert(envio_calcular_tarifa(e) > 0.0);
    envio_destruir(e);
    printf("PASS: test_crear_destruir_envio\n");
}

void test_lista_insertar_y_buscar(void) {
    lista_envios_t* l = lista_crear();
    assert(l != NULL);
    assert(lista_largo(l) == 0);

    envio_t* e1 = envio_crear(1, "ENV-1", "Rosario", 2000, 1.2, 2, false);
    envio_t* e2 = envio_crear(2, "ENV-2", "Mendoza", 5500, 3.4, 8, false);

    assert(lista_insertar_final(l, e1));
    assert(lista_insertar_final(l, e2));
    assert(lista_largo(l) == 2);

    envio_t* hallado = lista_buscar_por_id(l, 2);
    assert(hallado != NULL);
    assert(hallado->id_tracking == 2);

    assert(lista_buscar_por_id(l, 999) == NULL);

    lista_destruir(l);
    printf("PASS: test_lista_insertar_y_buscar\n");
}

void test_lista_eliminar(void) {
    lista_envios_t* l = lista_crear();
    envio_t* e1 = envio_crear(10, "A", "La Plata", 1900, 0.5, 1, false);
    envio_t* e2 = envio_crear(20, "B", "Mar del Plata", 7600, 1.5, 1, false);

    lista_insertar_final(l, e1);
    lista_insertar_final(l, e2);

    assert(lista_eliminar_por_id(l, 10) == true);
    assert(lista_largo(l) == 1);
    assert(lista_buscar_por_id(l, 10) == NULL);
    assert(lista_buscar_por_id(l, 20) != NULL);

    assert(lista_eliminar_por_id(l, 999) == false);

    lista_destruir(l);
    printf("PASS: test_lista_eliminar\n");
}

void test_lista_recursiva_prioritarios_e_invertir(void) {
    lista_envios_t* l = lista_crear();
    envio_t* e1 = envio_crear(1, "P1", "Salta", 4400, 1.0, 2, false);
    envio_t* e2 = envio_crear(2, "P2", "Jujuy", 4600, 2.0, 9, true);
    envio_t* e3 = envio_crear(3, "P3", "Tucuman", 4000, 1.5, 7, false);

    lista_insertar_final(l, e1);
    lista_insertar_final(l, e2);
    lista_insertar_final(l, e3);

    size_t prioritarios = lista_contar_prioritarios(l, 6);
    assert(prioritarios == 2);

    lista_invertir(l);
    assert(l->primero->dato->id_tracking == 3);
    assert(l->ultimo->dato->id_tracking == 1);

    lista_destruir(l);
    printf("PASS: test_lista_recursiva_prioritarios_e_invertir\n");
}

int main(void) {
    printf("=== Ejecutando Suite de Pruebas TDA Lista ===\n");
    test_crear_destruir_envio();
    test_lista_insertar_y_buscar();
    test_lista_eliminar();
    test_lista_recursiva_prioritarios_e_invertir();
    printf("=== Todas las pruebas unitarias pasaron exitosamente ===\n");
    return 0;
}
