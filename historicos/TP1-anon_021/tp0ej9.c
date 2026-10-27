
#include <stdio.h>
 
int main(int argc, char *argv[])
{

int numeromayora100;

printf(" Ingrese un valor mayor a 100 :  ");

scanf("%d",&numeromayora100);

while(numeromayora100 <= 100)
{
	
	printf("\n %d es menor a 100, reintente :",numeromayora100);
	
	scanf("%d",&numeromayora100);
	
}

printf("\n\n %d es mayor a 100",numeromayora100);

return 0;
}
