




    
# include <stdio.h>

int IngresoNumeroEntero();
void ImprimeLinea(int largo);
void ImprimeCuadrado(int largolados);
void ImprimeTriangulo(int altura);

int main()
{
    int numeroAsteriscos;
    
    printf("\nIngrese un numero mayor a 0 con el cual dibujaremos una linea, un cuadrado y un triangulo rectangulo: ");
    numeroAsteriscos = IngresoNumeroEntero();
    
    printf("\n");
    printf("Linea");
    printf("\n");
    ImprimeLinea(numeroAsteriscos);
    printf("\n");
    
    printf("\n");
    printf("Cuadrado");
    ImprimeCuadrado(numeroAsteriscos);
    printf("\n");
    
    printf("\n");
    printf("Triangulo");
    ImprimeTriangulo(numeroAsteriscos);
    printf("\n");
}





int IngresoNumeroEntero()
{
    int numero;
    
    while(numero <= 1)
    {
        scanf("\n%d", &numero);
        if(numero <= 1)
        {
            printf("El numero ingresado es menor o igual a 1. Por favor ingrese otro numero mayor o igual a 2: ");
        }
    }
    return numero;
}





void ImprimeLinea(int largo)
{
    int i;
    
    for(i=0; i<largo; i++)
    {
        printf("x ");
    }
}





void ImprimeCuadrado(int largolados)
{
    int i;
    int j;
    
    for(i=0; i<largolados; i++)
    {    
        printf("\n");
        for(j=0; j<largolados; j++)
        {    
            printf("x ");
        }
    }
}





void ImprimeTriangulo(int altura)
{
    int i;
    int j;
    
    for(i=0; i<altura; i++)
    {    
        printf("\n");
        for(j=i; j>-1; j--)
        {    
            printf("x ");
        }
    }
}