#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numero1, numero2;



    printf("dime el numero1: ");
    scanf("%d", &numero1);
    printf("dime el numero2: ");
    scanf("%d", &numero2);

    while (numero1 <= numero2)
    {
        printf("%d \n", numero1);
        numero1++;
    }
    

    return 0;
}