
#include <stdio.h>

void imprimir_linea(int num)
{
    for (int i = 0; i < num; ++i) {
        putc('*', stdout);
    }
    putc('\n', stdout);
}

void imprimir_cuadrado(int num)
{
    imprimir_linea(num);
    for (int j = 2; j < num; ++j) {
        putc('*', stdout);
        for (int i = 2; i < num; ++i) {
            putc(' ', stdout);
        }
        putc('*', stdout);
        putc('\n', stdout);
    }
    if (num > 1) {
        imprimir_linea(num);
    }
}

void imprimir_triangulo_rectangulo(int num)
{
    putc('*', stdout);
    putc('\n', stdout);
    for (int j = 2; j < num; ++j) {
        putc('*', stdout);
        for (int i = 2; i < j; ++i) {
            putc(' ', stdout);
        }
        putc('*', stdout);
        putc('\n', stdout);
    }
    if (num > 1) {
        imprimir_linea(num);
    }
}

int main()
{
    int num = 0;
    printf("Ingrese el número de asteriscos deseados: ");
    scanf("%d", &num);
    putc('\n', stdout);
    imprimir_linea(num);
    putc('\n', stdout);
    imprimir_cuadrado(num);
    putc('\n', stdout);
    imprimir_triangulo_rectangulo(num);
}
