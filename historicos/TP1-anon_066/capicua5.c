
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int i;
	int j;
	int numeroinvertido;
	for(j=0;j<10;j++)
	{
		for(i=10;i<100;i++){
			printf("%d",i);
			printf("%d",j);
			numeroinvertido=i;
			while(numeroinvertido >=10)
			{
				printf("%d",numeroinvertido%10);
				numeroinvertido/=10;
			}
			printf("%d",numeroinvertido%10);
			printf("\n");
		}	
	}
	return 0;
	
}