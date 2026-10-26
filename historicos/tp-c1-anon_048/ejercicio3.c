

#include <stdio.h>

int signo(int numero);

int main(){
    
    int numero, resultado;

    printf("Digite un numero para conocer si es positivo, negativo o cero: ");
    scanf("%d", &numero);
    resultado = signo(numero);

    if(resultado == 0)
    {
        printf("El numero es cero\n");
    }
    else if(resultado == 1)
    {
        printf("El numero es positivo\n");
    }
    else{
        printf("El numero es negativo\n");
    }   
}


int signo(int numero)
{
    int i;
    int auxiliar;
    auxiliar = numero / 2;
    
    if(auxiliar < 0)
    {
        auxiliar = auxiliar * -1;
    }

    if(numero == 0)
    {
        return 0;
    }
    
    for (i = 0; i < auxiliar; i++)
    {
        numero = numero + auxiliar;
    }   

    if((numero == 0) || (numero == -1))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}