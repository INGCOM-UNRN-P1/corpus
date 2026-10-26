

#include <stdio.h>


int suma_lenta(int numero, int otro_numero)
{
    int i;

    if (otro_numero < 0)
	{
		for (i = 0;i > otro_numero; i--)
		{
			numero = numero + (-1);
            //printf("%d\n", numero);
		}
	}
    else
    {
        for(i = 0;i < otro_numero; i++)
        {
            numero = numero + 1;
           // printf("%d\n", numero);
        }
    }

    return numero;
}

int main()
{
    int numero;
    int otro_numero;
    int resultado;

    printf("Ingrese dos numeros enteros para realizar la suma lenta\n");
    printf("Primer numero: ");
    scanf("%d", &numero);
    printf("Segundo numero: ");
    scanf("%d", &otro_numero);

    resultado = suma_lenta(numero, otro_numero);

    printf("Resultado de la suma lenta: %d", resultado);

    return 0;
}
