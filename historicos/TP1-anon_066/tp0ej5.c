/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int i;
	int numerouno;
	int numerouno_aux;
	int numerodos;
	int numerodos_aux;
	printf("primer numero:");
	scanf("%d", &numerouno);
	printf("primer numero:");
	scanf("%d", &numerodos);
	numerouno_aux=numerouno;
	numerodos_aux=numerodos;
	if(numerodos_aux>=numerouno_aux)
	{
		for(i=numerouno_aux;i<=numerodos_aux;i++)
		{
			printf("%d\n",i);
		}
	}else{
		for(i=numerodos_aux;i<=numerouno_aux;i++)
		{
			printf("%d\n",i);
		}
		
	}
	return 0;
}
