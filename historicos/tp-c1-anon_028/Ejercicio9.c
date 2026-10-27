

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int es_multiplo(int numero, int multiplo);


int main()
{
    int numero, multiplo,resultado;

    printf("Digite un numero: \n");
    scanf("%d", &numero);
    printf("Digite otro numero para conocer si es multiplo del primero mediante sumas y restas: ");
    scanf("%d", &multiplo);
    resultado = es_multiplo(numero, multiplo);
    if(resultado == 1)
	{
		printf("El numero es multiplo\n");
	}
	else 
	{
		printf("No es multiplo\n");
	}
    
    

    return 0;
}


int es_multiplo(int numero, int multiplo)
{
    int i, sumas;
    sumas = 0;

    for ( i = 0; i <= multiplo; i++)
    {
        sumas = sumas + numero;
        if(sumas == multiplo)
        {
            return TRUE;
        }
    }
    return FALSE;
}


