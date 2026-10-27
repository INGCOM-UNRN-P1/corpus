

#include <stdio.h>

int main()
{

	int n; 
	
	printf("Ingrese el tamanio del cuadrado #");
	scanf("%d",&n);
	
		for(int renglon=1; renglon<=n ; renglon++) 
	  	{
	  		for(int columna=1; columna<=n; columna++)
	  		{
	  			
				if(renglon == 1 || renglon == n || columna== 1 || columna==n) 
	  			{
					printf("*");  
				}
	  			else 
	  			{
	  				printf(" ");
				}
			}
			printf("\n");
	  }

	return 0;
}
