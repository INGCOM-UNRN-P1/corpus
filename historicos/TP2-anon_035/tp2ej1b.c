

#include <stdio.h>

int main(int argc, char *argv[])
{
	int aumento, aumento2, raiz2 = 0, raiz = 0;
	double n,m;
    
    printf("Ingrese n para saber raiz ");
	scanf("%lf",&n);
	printf("Ingrese segundo valor m para saber raiz ");
	scanf("%lf",&m);
	
	if(n > 0 )
	{
		while(aumento < n)
		{
			raiz = raiz + 1;
			
			aumento = raiz * raiz;
			
			
		}
		printf("Raiz de %1.lf = %d \n\n", n, raiz);
		
		
	}
	else
	{
		printf("Error primer valor (n) menor o igual A 0\n\n");
		
	}
	
	if( m > 0)
	{
		while(aumento2 < m)
		{
			raiz2 = raiz2 + 1;
			
			aumento2 = raiz2 * raiz2;
			
			
		}
		printf("Raiz de %1.lf = %d \n\n", m, raiz2);		
	}
	else
	{
		printf("Error segundo valor (m) menor o igual A 0\n\n");
	}
	
	
    return 0;
}

/* los puntos a y b son similares, use un ciclo que empieza desde el uno a multiplicar entre si mismo hasta que la condicion se deje de cumplir
y en ese momento encuentre la raiz* ///