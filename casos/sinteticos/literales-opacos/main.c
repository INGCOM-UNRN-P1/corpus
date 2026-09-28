/**
 * Caso sintético del corpus: las reglas de espaciado no miran dentro de los
 * literales (antes, "a+b" o "x ,y" daban diez falsos positivos).
 */
#include <stdio.h>

int main(void)
{
    const char *formula = "a+b*c-d/e";
    const char *lista = "uno ,dos;tres ,  cuatro";
    const char *falso_comentario = "/* no es un comentario */ // tampoco";
    const char *condicion = "if(x==1){return y;}";
    char separador = ',';
    char operador = '+';
    printf("%s %s %s %s %c %c\n", formula, lista, falso_comentario, condicion, separador, operador);
    return 0;
}
