/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int compara(int num1, int num2);

int main(int argc, char *argv[])
{
    compara(3, 2);
}


int compara(int num1, int num2)//compara ambos numeros para ver quien es mayor o si son iguales y devuelve -1, 0 o 1 dependiendo del resultado.
{
    if(num1 < num2)
    {
        return -1;
    }
    else if (num1 == num2)
    {
        return 0;
    }
    else
    {
        return 1;
    };
}
