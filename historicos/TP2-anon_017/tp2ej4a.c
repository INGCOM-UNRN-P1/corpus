
#include <stdio.h>

int asterisco(int numero);

int main()
{
	
    int numero;
           
    printf("Ingrese un numero para imprirmir en asteriscos: ");
    scanf("%d",&numero);
	
    asterisco(numero);

}

int asterisco(int numero)
{
	while (numero>0)
	{
        printf("*");
		numero=numero-1;
    }
   return 0;
}