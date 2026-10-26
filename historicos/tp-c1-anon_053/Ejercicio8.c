

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0

char es_palindromo(char texto);

int main()
{
    char texto[20];
    int i, largo, res = 0;
    printf("Ingrese texto para verificar si es palindromo:");
    scanf("%s", texto); 
        
            if(res){
                return true;
            }
            else {
                return false;
            }
}
char es_palindromo(char texto)
{
    int res, largo, i=0;
    largo = strlen(texto); 
        while(i < largo) {
        (texto[i] != texto[largo-i-1]);
        i++;
        res = 1;
        }
    return 0;
}

