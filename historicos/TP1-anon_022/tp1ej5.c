
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero1, numero2;
	printf("Ingrese dos numeros");
	scanf("%d,%d",&numero1,&numero2);
	if(numero1<numero2){
		for(numero1;numero2;numero1+1){
			printf("%d\n"numero1);
		}
		else{
			for(numero2;numero1;numero2+1){
				printf("%d\n"numero2)
			}
		}	
	}
	return 0;
}