
#include <stdio.h>

int raizN (int cont, int cont2, int raiz, int raiz2);
int main()
{
    int cont = 0;
    int cont2 = 0;
    int raiz;
    int temp;
	int raiz2;
    printf("ingrese el numero del cual quiere saber la raiz ");
    scanf("%d" ,&raiz);
	printf("ingrese su numero para calcular otra raiz ");
	scanf("%d" ,&raiz2);
    temp = raizN(cont, cont2, raiz, raiz2);
    return temp;
}
int raizN (int cont, int cont2, int raiz, int raiz2)
{
    int resultado = 0;
    cont=0;
    cont2=0;
    resultado=0;
    while (resultado<raiz)
    {
        cont2+=1;
        cont+=1;
        resultado=cont*cont2;
    }
    if (raiz%cont2 != 0)
    {
        cont2=cont2 - 1;
    }
	printf ("La raiz de %d es %d " ,raiz ,cont2);
	
	cont=0;
	cont2=0;
	resultado=0;
	
	while (resultado<raiz2)
    {
        cont2+=1;
        cont+=1;
        resultado=cont*cont2;
	}
	if (raiz%cont2 != 0)
    {
        cont2=cont2 - 1;
    }
	printf ("La raiz de %d es %d " ,raiz2 ,cont2);
    return 0;
}