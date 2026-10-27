
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int n, i;
	
	printf("Ingrese la cantidad de asteriscos que quiere que tenga la fila \n# ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
		{
		printf("*");
		}
	
	printf("\n");
}

