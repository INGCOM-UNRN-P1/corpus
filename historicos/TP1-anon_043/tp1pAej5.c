

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nro1 = 0;
    int nro2 = 0;

    printf("Primer numero: ");
    scanf("%d", &nro1);

    printf("Segundo numero: ");
    scanf("%d", &nro2);
    
    for (int i = nro1; i <= nro2; i++)
    {
        printf("%d \n", i);
    }
    

    return 0;
}