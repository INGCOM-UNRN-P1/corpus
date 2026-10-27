
#include <stdio.h>
 
int main(int argc, char *argv[]){
	int numeroA, resultado, cont;
	cont=2;
	printf("Intrusca un numero mayor a 100: ");
	scanf("%d" ,&numeroA);
	while (cont<=6){
		resultado=numeroA%cont;
		if (resultado==0){
			
			printf("%d si es multiplo de %d\n" ,numeroA ,cont);
			}
			else 
			{
				printf("%d no es multiplo de %d\n" ,numeroA ,cont);
				}
	cont=cont+1;
	}
	return 0;
}