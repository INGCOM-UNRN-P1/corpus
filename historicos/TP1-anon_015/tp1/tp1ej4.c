#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a, b, resto;

    printf("primer numero: \n");
    scanf("%d", &a);

    b = 2;

    resto = (a % b);

    if (resto == 0){
        printf("%d es multiplo de %d \n" ,b, a);
    }
    else{
        printf("%d no es multiplo de %d \n", b, a);
    }

    
    



    return 0;
}