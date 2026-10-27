

#include <stdio.h>

int suma_lenta(int nro1, int nro2)
{

    for (int i = 1; i <= nro2; i++)
    {
        nro1 = nro1 + 1;
    }

    return nro1;
    
}
int main(int argc, char const *argv[])
{
    int nro1 = 0, nro2 = 0, result = 0;

    printf("Ingrese el primer numero: ");
    do
    {
        scanf("%d", &nro1);
        if (nro1 < 0)
        {
            printf("El numero ingresado no es natural.");
        }
        
    } while (nro1 < 0);
    
    printf("Ingrese el segundo numero: ");
    do
    {
        scanf("%d", &nro2);
        if (nro2 < 0)
        {
            printf("El numero ingresado no es natural.");
        }
        
    } while (nro2 < 0);

    result = suma_lenta(nro1, nro2);
    printf("Le suma lenta es de: %d", result);

    return 0;

}
