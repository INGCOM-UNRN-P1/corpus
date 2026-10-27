

#include <stdio.h>




int main(int argc, char *argv[])
{
	int n, i, j, asterisco = 1;
	
	printf("ingrese n\n\n");
	
	scanf("%d", &n);
	
	printf("*\n");
	for(i=0; i<=n; i++)
	{
		for(j=0;j <=asterisco; j++)
		{
			printf("*");
		
		}
		printf("\n");
		
		asterisco=asterisco+1;
	}
	
	return 0;
}