

#ifndef TDA_CONTRACTS_H
#define TDA_CONTRACTS_H

#include <stddef.h>


extern size_t tda_contratos_evaluados_;
size_t tda_contratos_evaluados_;

#ifdef NDEBUG

#define TDA_REQUIERE(cond)                 ((void)0)
#define TDA_GARANTIZA(cond)                ((void)0)
#define TDA_INVARIANTE(estructura, validador) ((void)0)
#define tda_contratos_evaluados()          ((size_t)0)

#else 
#include <stdio.h>
#include <stdlib.h>

#define TDA_REQUIERE(cond)                                                    \
    do {                                                                      \
        if (!(cond)) {                                                        \
            fprintf(stderr,                                                   \
                    "❌ PRECONDICIÓN rota  %s:%d  TDA_REQUIERE(%s)\n",        \
                    __FILE__, __LINE__, #cond);                               \
            abort();                                                          \
        }                                                                     \
    } while (0)

#define TDA_GARANTIZA(cond)                                                   \
    do {                                                                      \
        if (!(cond)) {                                                        \
            fprintf(stderr,                                                   \
                    "❌ POSTCONDICIÓN rota  %s:%d  TDA_GARANTIZA(%s)\n",      \
                    __FILE__, __LINE__, #cond);                               \
            abort();                                                          \
        }                                                                     \
    } while (0)

#define TDA_INVARIANTE(estructura, validador)                                 \
    do {                                                                      \
        if (!(validador)(estructura)) {                                       \
            fprintf(stderr,                                                   \
                    "❌ INVARIANTE roto  %s:%d  %s(estructura)\n",            \
                    __FILE__, __LINE__, #validador);                          \
            abort();                                                          \
        }                                                                     \
        tda_contratos_evaluados_++;                                           \
    } while (0)

#define tda_contratos_evaluados() (tda_contratos_evaluados_)

#endif 




static inline void *tda_siguiente(const void *nodo, size_t offset_sig)
{
    if (nodo == NULL) {
        return NULL;
    }
    void *sig;
    __builtin_memcpy(&sig, (const char *)nodo + offset_sig, sizeof sig);
    return sig;
}


static inline int tda_tiene_ciclo(const void *primero, size_t offset_sig,
                                  size_t max_nodos)
{
    const void *vistos[256];
    size_t n_vistos = 0;
    const void *actual = primero;

    while (actual != NULL && n_vistos < max_nodos) {
        for (size_t i = 0; i < n_vistos; i++) {
            if (vistos[i] == actual) {
                return 1; 
            }
        }
        if (n_vistos < sizeof vistos / sizeof vistos[0]) {
            vistos[n_vistos++] = actual;
        }
        actual = tda_siguiente(actual, offset_sig);
    }
    return 0;
}

#endif 
