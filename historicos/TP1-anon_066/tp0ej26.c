
#include <stdio.h>
int compara_fechas(char *primera, char *segunda)
{	
	int i;
	int retorno;
	for(i=6;i<10;i++)
	{
		if(primera[i]>segunda[i])
		{
			retorno=1;
			break;
		}else if(primera[i]==segunda[i])
		{
			retorno=0;
		}else
		{
			retorno=-1;
			break;
		}
	}
	if(retorno==0)
	{
		for(i=3;i<5;i++)
		{	
			if(primera[i]>segunda[i])
			{
				retorno=1;
				break;
			}else if(primera[i]==segunda[i])
			{
				retorno=0;
			}else
			{
				retorno=-1;
				break;
			}
		}
	}
	if(retorno==0)
	{
		for(i=0;i<2;i++)
		{
			if(primera[i]>segunda[i])
			{
				retorno=1;
				break;
			}else if(primera[i]==segunda[i])
			{
				retorno=0;
			}else
			{
				retorno=-1;
				break;
			}
		}
	}
	return retorno;
	
}
int main(int argc, char *argv[])
{	
	char fechados[20];
	char fechauno[20];
	int resutadocomparafechas;
	printf("Ingresa una fecha en formato dd/mm/aaaa: ");
	scanf("%s",fechauno);
	printf("\nIngresa otra fecha en formato dd/mm/aaaa: ");
	scanf("%s",fechados);
	resutadocomparafechas=compara_fechas(fechauno,fechados);
	switch(resutadocomparafechas)
	{
		case -1:
		printf("\nLa primer fecha %s es anterior a %s\n",fechauno,fechados);
		break;
		case 0:
		printf("\nLa primer fecha %s y la segunda fecha %s son iguales\n",fechauno,fechados);
		break;
		case 1:
		printf("\nLa primer fecha %s es posterior a %s\n",fechauno,fechados);
		break;
	}
	return 0;
}
