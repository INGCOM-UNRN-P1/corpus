/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	
int A, B,chiste, resultadoint;

chiste = 0;

printf("\n\ningrese valor A:\n     ");

scanf("%d",&A);

printf("ingrese valor B:\n     ");

scanf("%d",&B);

printf("\n\nDado el valor A = %d \n         y \nDado el valor B = %d\n\n",A,B);

resultadoint = A * B;

printf("Multiplicacion %d * %d = %d\n\n",A,B,resultadoint);

while(B == 0)
{	

	printf("\n Se realizara una division, B no puede ser 0\n     ");
	
	scanf("%d",&B);
	
	chiste = chiste + 1;
	
	if (chiste == 5)
	{
		
		printf("   Andate a joder a otro lado, si te digo que 0 no va, NO VA\n");
		
		return 0;
		
	}
}
resultadoint = A / B;

printf("Divicion %d / %d = %d\n\n",A,B,resultadoint);

resultadoint = A % B;

printf("Resto de la division %d / %d = %d\n",A,B,resultadoint);

return 0;
}
