#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numero;

    printf("ingrese un numero: \n");
    scanf("%d", &numero);


    if (numero<=100)
    {
        while (numero <=100)
        {
        printf("el numero es menor a 100 \n");
        printf("ingrese un numero: \n");
        scanf("%d", numero);
        }
        
    }    
    
    else{
        printf("el numero es mayor a 100 \n");
    }
    
    

    return 0;
}