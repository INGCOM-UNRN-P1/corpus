/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub
*************************/
#include <stdio.h>
int divide_lento(int dividendo,int divisor);
int resta_lento(int dividendo,int divisor);
int main(int argc, char *argv[])
{
    int numero, otro_numero;
    printf("Ingrese un primer numero = ");
    scanf("%d",&numero);
    printf("Ingrese otro numero = ");
    scanf("%d",&otro_numero);
    printf("El cociente es %d < Resto %d >",resta_lento(numero,otro_numero), divide_lento(numero,otro_numero));
return 0;
}
int resta_lento(int dividendo,int divisor)
{
    int cociente;
    if (dividendo>0&&divisor>0)
    {
        cociente=0;
        while(dividendo>=divisor)
        {
            dividendo-=divisor;
            cociente++;
        }
    }
   return cociente;
}
int divide_lento(int divisor, int dividendo)
{

        while(dividendo>=divisor)
        {
            dividendo-=divisor;

        }

   return dividendo;
}
