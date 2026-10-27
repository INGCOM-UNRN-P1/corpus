
#include <stdio.h>
 
int compara_fechas(char *primera, char *segunda)
{
	int i;
	for (i=6;i<10;i++)
	{
		if (primera[i] > segunda[i])
		{
			return 1;
		} 
		else if (primera[i] < segunda[i])
		{
			return -1;
		}
	}
	
	for (i=3;i<5;i++)
	{
		if (primera[i] > segunda[i])
		{
			return 1;
		} 
		else if (primera[i] < segunda[i])
		{
			return -1;
		}
	}
	
	for (i=0;i<2;i++)
	{
		if (primera[i] > segunda[i])
		{
			return 1;
		} 
		else if (primera[i] < segunda[i])
		{
			return -1;
		}
	}
	
	return 0;
}

int main(int argc, char *argv[])
{
	char primera[11], segunda[11];
	int resultado;
	printf("Ingrese la primer fecha (dd/mm/aaaa):");
	scanf("%s",&primera);
	printf("Ingrese la segunda fecha (dd/mm/aaaa):");
	scanf("%s",&segunda);
	resultado = compara_fechas(primera,segunda);
	printf("%d",resultado);
	return 0;
}