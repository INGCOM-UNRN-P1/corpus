

#include <stdio.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0

int es_primo(int numero);

int main()
{
    int numero;
    printf("Ingrese un número \n");
    scanf("%i", &numero);
    if(es_primo(numero))        {
        return true;
    }
    else{
        return false;
    }
       
}
int es_primo(int num1)

{
    int i, contador=0;
    for (i=1; i<=num1;i++){
        if(num1%i==0){
            contador++;
        }
    }
    return 0;
}
   


