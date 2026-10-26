

#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// 1er paso: Ejecutar el comando gcc ejercicio1.c
// 2do paso: Ejecutar el comando ./a.exe

int main()
{
    printf(ANSI_COLOR_CYAN "\nEjercicio 1: Hola Mundo" ANSI_COLOR_RESET "\n");
    printf("Hola mundo\n");
    return 0;
}