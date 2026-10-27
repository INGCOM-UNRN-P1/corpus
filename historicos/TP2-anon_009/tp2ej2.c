
#include <stdio.h>
 

int producto(unsigned int n, unsigned int m);
int potencia(unsigned int n, unsigned int m);

int main(int argc, char *argv[])
{
    unsigned int n = 0;
    unsigned int m = 0;

    while(n < 1)//chequea que el numero n sea natural
    {
        printf("Ingrese un numero n que sea natural: ");
        scanf("%d", &n);
    };
    
    while(m < 1)//chequea que el numero m sea natural
    {
        printf("Ingrese un numero m que sea natural: ");
        scanf("%d", &m);
    };  

    printf("El producto de %i y %i es: %i y la potencia de %i a la %i es: %i\n", n, m, producto(n, m), n, m, potencia(n, m));

}



int producto(unsigned int n, unsigned int m)
{

    return n * m;

}


int potencia(unsigned int n, unsigned int m)
{


    int resultado = 1;
    
    for (int i = 0; i < m; i++)//multiplica a n por si mismo la cantidad de veces que i es menor que m y lo almacena en la variable resultado
    {
        resultado = resultado * n;
    }

    return resultado;

}