#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char* descripcion;
} registro_t;

int main(void) {
    registro_t* r = NULL;
    printf("Intentando acceder a estructura nula...\n");
    /* Provoca SIGSEGV desreferenciando puntero nulo para análisis forense con hal */
    r->id = 42;
    printf("ID: %d\n", r->id);
    return 0;
}
