/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_056
*************************/

#include <stdio.h>


int raiz(int b){

    int raiz = b;

    for (int i = 1; i <= b; i++){
        raiz = (raiz +(b/raiz))/2;
    }

    return raiz;
}


int main(int argc, char const *argv[])
{

    int n;
    int m;

    printf("Ingrese el valor n: ");
    scanf("%d", &n);
    printf("Ingrese el valor m: ");
    scanf("%d", &m);

    if (m>0 && n>0){
        printf("raiz n => %d\n", raiz(n));
        printf("raiz m => %d\n", raiz(m));
    }
    else{
        printf("Los numeros deben ser mayores a 0");
    }

    return 0;
}


