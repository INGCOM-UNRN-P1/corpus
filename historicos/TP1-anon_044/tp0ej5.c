
#include <stdio.h>

int main()
{
    int max, min, i;

    printf("Ingrese el limite inferior:\n");
    scanf("%d", &min);
    printf("Ingrese el limite superior:\n");
    scanf("%d", &max);
    
    printf("Primer numero: %d\nSegundo numero: %d\n\n", min, max);
    for(i = min; i <= max; i++)
    {
        printf("%d\n", i);
    }
    
    return 0;
}
