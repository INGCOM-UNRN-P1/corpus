

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j, h, z;
	int n, k, m;
	
	double factorialn = 1, factorialk = 1, factorialm = 1;
	double combinatoria;
    
    
    printf("Ingresa numero n para calcular combinatoria: \n");
	
    scanf("%d", &n);
	
	k = n - 1;
	m = n - k;
	
	
	if(n > 1)
	{
	
		for (i = 1; i <= n; i++)
		{
			
			factorialn = factorialn * i;
			
		}
		
		
		
		for(z = 1; z <= n; z++)
		{
			
			m = n - k;
			
			
			
			for (h = 1; h <= k; h++)
			{
				
				factorialk = factorialk * h;
				

			}
			
			
			for (j = 1; j <= m; j++)
			{

				factorialm = factorialm * j;

			}
			
			k = k - 1;
			
			
			combinatoria = factorialn / ( factorialk * factorialm);
				
			printf("la combinatoria es: %0.lf \n\n", combinatoria);
			
		}
		
	}
	else
	{
		printf("error numero k mayor a n");
		return 0;
	}
	
    return 0;
}