

#include <stdio.h>

int potencia(int n, int m){
    int potencia = 1;

    for (int i = 0; i < m; i++)
    {
        potencia = potencia*n;
    }
    
    return potencia;
}


int producto(int n, int m){
    int producto;

    producto = n*m;

    return producto;
}



int main(int argc, char const *argv[])
{
    int n;
    int m;

    printf("Ingrese numero n: ");
    scanf("%d", &n);
    printf("Ingrese numero m: ");
    scanf("%d", &m);

    printf("Producto => %d\n", producto(n,m));
    printf("Potencia => %d\n", potencia(n,m));

    return 0;
}

