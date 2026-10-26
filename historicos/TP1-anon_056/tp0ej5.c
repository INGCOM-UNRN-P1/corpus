#include <stdio.h>

int main(){
    int numeroA;
    int numeroB;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroA);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroB);

    if (numeroA>numeroB)
    {
        for (int i = numeroB; i <= numeroA; i++)
        {
            printf("%d\n", i);
        }
        
    }
    else{
        for (int i = numeroA; i <= numeroB; i++)
        {
            printf("%d\n", i);
        }
        
    }
    
    




    return 0;
}