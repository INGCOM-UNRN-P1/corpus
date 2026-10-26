/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 

int suma_lenta(int num1, int num2);//invoca a la función suma_lenta

int main(int argc, char *argv[])
{
    printf("%i\n", suma_lenta(2, 3));//imprime el resultado de la función suma lenta
    
}



int suma_lenta(int num1,int num2)//la función toma 2 numeros como entrada y al primero le suma el segundo de 1 en 1.
{
    for(int i = 0; i < num2; i++)
    {
        num1 = num1 + 1;
    }
    return num1;
}


