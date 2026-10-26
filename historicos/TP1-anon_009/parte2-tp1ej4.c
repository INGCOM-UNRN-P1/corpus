/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int es_primo(int num);

int main(int argc, char *argv[])
{
    printf("%i\n", es_primo(10));
}



int es_primo(int num)//chequea si el resto de algun numero entre 1 y el indicado por el usuario es 0. Si lo es devuelve 0 y sino devuelve 1
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
            break;
        }
    }
    return 1;
    
}    
