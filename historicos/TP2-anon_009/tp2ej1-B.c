/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>


int calcular_raiz(unsigned int num);// llama a la funcion que calcula la raiz

 
int main(int argc, char *argv[])
{
    unsigned int n = 0;
    unsigned int m = 0;
    while (n < 1)// se solicita un numero hasta que sea natural y se almacena en n
    {
    printf("Ingrese un numero natural n: ");
    scanf("%d", &n);
    }
    while (m < 1)// se solicita un numero hasta que sea natural y se almacena en n
    {
    printf("Ingrese otro numero natural m: ");
    scanf("%d", &m);
    }
    
    printf("Los enteros de las raices de %i y %i son: %i y %i\n", n, m, calcular_raiz(n), calcular_raiz(m));
    


    


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
        } 
        else
        {
        raiz = raiz + 1;
        comparador = raiz * raiz;
    };
}

    return raiz;

    
    

}