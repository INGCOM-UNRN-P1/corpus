
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int i;
	double resultado;
	for(i=1;i<65;i++)
	{
		if(i==1)
		{
			resultado=1;
		}else{
			resultado=resultado*2;
		}
		printf("Casillero %d = %.0f\n",i,resultado);		
	}
	printf("El rey debera entregarle %.0f kg\n",resultado);
	return 0;
}
