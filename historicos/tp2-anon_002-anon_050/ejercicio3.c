

#include <stdio.h>


int tablas(unsigned int numero)
{
    int res;
    for (int i = 1; i <= 10; i++)
    {
        res = i * numero;
        printf("%d x %d = %d\n", numero, i, res);
    }
    return 0;
}

int main()
{
    unsigned int num;
    printf("Escriba el número a operar: \n");
    scanf("%u", &num);

    printf("La tabla del %d es: \n", num);
    tablas(num);

    return 0;
}
