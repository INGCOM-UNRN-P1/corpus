

#include <stdio.h>

int main(int argc, char *argv[])
{
	int aumento, raiz = 0;
	double n;
    
    printf("Ingrese n para saber raiz ");
	scanf("%lf",&n);
	
	if(n > 0)
	{
		while(aumento < n)
		{
			raiz = raiz + 1;
			
			aumento = raiz * raiz;
			
			
		}
	
	}
	else
	{
		printf("Error valor n menor o igual 0");
		return 0;
	}
	
	printf("Raiz de %lf = %d", n, raiz);
	
    return 0;
}
