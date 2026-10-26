

#include <stdio.h>
//Declaramos la funcion
int contador_circular(int i, int limite);

int main()
{
    int i = 2;
    int limite = 5;    
    int j = 0;
    
    while(1)//en cada vuelta se repetira la funcion
    {
        int contador = contador_circular(i, limite);
        contador;//variable que llama a la funciongit 
        j ++;
        printf("\n%d", contador);
    }

    return 0;
}

int contador_circular(int i, int limite)
{
    while (i < limite)//en cada vuelta se sumara 1 a i y cuando llegue a limite rewtornara 0
    {
        printf("\n%d", i);
        i ++;
    }
    return 0;
}

//pre: recibe 2 numeros enteros
//pos: en un ciclo imprime el valor aumentado de i hasta el limmite

