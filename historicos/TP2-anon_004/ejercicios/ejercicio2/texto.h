#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>


bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
