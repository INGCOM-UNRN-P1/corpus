

#include <stdio.h>


int raiz(int n){

    float raiz = n;

    for (int i = 1; i <= n; i++){
        raiz = (raiz +(n/raiz))/2;
    }

    return raiz;

    
}


int main(int argc, char const *argv[])
{

    int n;

    printf("Ingrese el valor n: ");
    scanf("%d", &n);

    if (n>0)
    {
        printf("%d\n", raiz(n));
    }
    else
    {
        printf("El numero debe ser mayor a 0");
    }
    
    return 0;
}
