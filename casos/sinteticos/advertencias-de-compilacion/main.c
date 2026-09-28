#include <stdio.h>
#include <string.h>

int main(void)
{
    int sin_usar = 3;
    const char *texto = "hola";
    for (int i = 0; i < strlen(texto); i++)
    {
        putchar(texto[i]);
    }
    putchar('\n');
    return 0;
}
