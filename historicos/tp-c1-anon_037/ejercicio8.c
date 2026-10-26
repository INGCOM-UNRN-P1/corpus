

#include <stdio.h>
#include <stdbool.h>
#define LARGO 20

bool es_palindromo(char texto[]);



int main()

{
    char texto[LARGO];
    bool resultado;

    printf("Ingrese un texto -> ");
    fgets(texto, LARGO, stdin);
    
    resultado = es_palindromo(texto);
    
    if (resultado)
    {
        printf("\nEl texto es palindromo");
    }
    else
    {
        printf("\nEl texto no es palindromo");
    }
    return 0;
}


bool es_palindromo(char texto[])
{
    int i = 0;
    int j = 0;
    int k;
    int resto;
    
    while (texto[i] != '\0')
    {     
        i++;
    }
    k = i-1;
    
    while (j < k)
    {
        if (texto[j] == texto[k])
        {
            j++;
            k--;
        }
        else
        {
            break;
        }
    }
    
    if (j >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}