

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j, h;
	int n, k, m;
	
	double factorialn = 1, factorialk = 1, factorialm = 1;
	double combinatoria;
    
    
    printf("Ingresa numero n para calcular combinatoria: \n");
	
    scanf("%d", &n);
    
    printf("Ingresa numero k para calcular combinatoria: \n");
	
    scanf("%d", &k);	
	
	
	
	m = n-k;
	
	
	
	if(k <= n)
	{
	
		
		for (i = 1; i <= n; i++)
		{
			
			factorialn = factorialn * i;
			
		}
		
		for (j = 1; j <= k; j++)
		{
			
			factorialk = factorialk * j;
			
		}
	
		for (h = 1; h <= m; h++)
		{
			
			factorialm = factorialm * h;
			
		}
		
		
		
		combinatoria = factorialn / ( factorialk * factorialm);
	}	
	else
	{
		printf("error numero k mayor a n");
		return 0;
	}
	
    
	
    printf("la combinatoria es: %0.lf \n", combinatoria);

    return 0;
}