
#include <stdio.h>

int producto(int multiplicando, int multiplicador);
int potencia(int base, int exponente);

int main(int argc, char *argv[])
{
    int n, m;
    
    printf("ingrese el numero n: ");
    scanf("%d", &n);    
    printf("ingrese el numero m: ");
    scanf("%d", &m);
    
    printf("El resultado de hacer n*m es: %d \n", producto(n, m));    
    printf("El resultado de hacer n^m es: %d \n", potencia(n, m));    
    
    return 0;
}

int producto(int multiplicando, int multiplicador)
{
    int producto;
    producto = multiplicando * multiplicador;
    return producto;
}

int potencia(int base, int exponente)
{
    int resultado, temp;
    temp = base;
    
    while (exponente > 1)
    {
        resultado = producto(temp, base);
        temp = resultado;
        exponente = exponente - 1;
    }
    return resultado;
}