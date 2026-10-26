/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>

void linea(int largo);
void cuadrado(int largo);
void triangulo(int altura);

int main(int argc, char *argv[])
{
    int numero;

    printf("Ingrese el largo de la línea: \n\t");
    scanf("%d", &numero);
    linea(numero);
    
    printf("Ingrese el largo del cuadrado: \n\t");
    scanf("%d", &numero);
    cuadrado(numero);
    
    printf("Ingrese la altura del triángulo: \n\t");
    scanf("%d", &numero);
    triangulo(numero);


}

void linea(int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        printf("*");
    }
    printf("\n");
}
void cuadrado(int largo)
{
    int i;
    int j;
    for(i=0;i<largo;i++)
    {
        for(j=0;j<largo;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void triangulo(int altura)
{
    int i;
    int j;
    for(i = altura; i >= 1; i--)
    {        
        for(j = i; j >= 1; j--)
        {
            printf("* ");
        }               
        printf("\n");
    }
}