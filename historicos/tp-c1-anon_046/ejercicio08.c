

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_CARACTERES 50
#define True  1
#define False 0


int es_palindromo(char* cadena) {
    int pos, len_cadena;

    for (pos = 0; cadena[pos] != '\0'; pos++);
    len_cadena = pos;
    pos = 0;
    while (pos < len_cadena/2) {
        if (cadena[pos] != cadena[len_cadena - 1 - pos]) {
            return False;
        }
        pos++;
    }

    return True;
}

int main()
{
    char entrada[MAX_CARACTERES + 1] = {"\0"};

    printf("Ingrese una cadena de hasta %d caracteres: ", MAX_CARACTERES);
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de cadena\n");
        return (-1);
    }

    printf("La frase %s es palindromo? %s\n",
           entrada, es_palindromo(entrada)?"True":"False");

    return 0;
}
