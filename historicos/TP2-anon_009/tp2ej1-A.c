/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>


int calcular_raiz(unsigned int num);// llama a la funcion que calcula la raiz

 
int main(int argc, char *argv[])
{
    unsigned int num = 0;
    while (num < 1)// se solicita un numero hasta que sea natural y se almacena en n
    {
    printf("Ingrese un numero natural: ");
    scanf("%d", &num);
    }
    
    printf("El entero de la raiz raiz de %i es: %i\n", num, calcular_raiz(num));

}




int calcular_raiz(unsigned int num)
{
    int raiz = 0; //se almacenan todos los enteros desde 0 hasta llegar al entero de la raiz
    int comparador = 0; // va almacenando los resultados parciales de las raices

    while (comparador < num) //calcula el entero de la raiz
    {
    if ((raiz + 1) * (raiz + 1) > num)
        {
            break;
        } else   
        {
        raiz = raiz + 1;
        comparador = raiz * raiz;
        };
    };
    return raiz;

}