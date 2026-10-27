
#include <stdio.h>
 
int main(int argc, char *argv[])
{ 
	int numero,i, factorial=1;
	printf("Ingrese el numero para calcular su factorial\n");
	scanf("%d",&numero);
	for(i=numero; i>1; i--){
		factorial= factorial*i;
	}
	printf("El factorial de %d es = %d\n", numero, factorial);
	return 0;
}