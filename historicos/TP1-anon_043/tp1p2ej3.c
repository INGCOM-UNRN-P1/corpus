

#include <stdio.h>

int compare(int nro1, int nro2)
{

    if (nro1 < nro2)
    {
        return -1;

    }else if (nro1 > nro2)
    {
        return 1;
    }else
    {
        return 0;
    }

}

int main(int argc, char const *argv[])
{
    int nro1 = 0, nro2 = 0, result = 0;

    printf("Ingrese el primer numero: ");
    scanf("%d", &nro1);
    
    printf("Ingrese el segundo numero: ");
    scanf("%d", &nro2);

    result = compare(nro1, nro2);
    printf("%d", result);

    return 0;

}
