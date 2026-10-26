

#include <stdio.h>

int signo(int numero);

int main()
{
    int numero;
    printf("Ingrese valor: ");
    scanf("%d", &numero);
    
    printf("El signo del numero %d es: %d\n",numero, signo(numero));
    return 0;
}

int signo(int numero)
{
    int res;
    if ((numero + numero) >0){
        return 1;
    }
        else if ((numero + numero) <0){
            return -1;
        }
        else{
            return 0;
        }

    return res;
}


