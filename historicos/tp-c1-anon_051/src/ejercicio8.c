
#define tamanio 50
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int es_palindromo(char texto[])
{
    
    int i = 0;
    int j = 0;
    int guardar = 0;
    int contador = 0;
    int ret_value;
    guardar = strlen(texto);
    j = guardar - 1;
    while (i < guardar)
    {
        if (texto[i] == texto[j])
        {
            contador = contador + 1;
        }
        j = j - 1;
        i = i + 1;
    }
    if (guardar == contador)
    {
        ret_value = TRUE;
    }
    else
    {
        ret_value = FALSE;
    }
    return ret_value;
}
int main()
{
   char texto[tamanio];
   int resultado;
   printf("Ingrese una palabra para ver si es palindromo: \n");
   scanf("%s", texto);
   resultado = es_palindromo(texto);
   printf("El texto es : %i", resultado);
   return 0;
}
