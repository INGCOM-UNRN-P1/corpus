

#include <stdio.h>

   

int signo(int num);
   
int main()
{
	int num, res;
	printf("Ingrese un número: \n");
	scanf("%d", &num);
	res=signo(num);
	printf("Signo: %d\n", res);
	return 0;	   
}



int signo(int num)   

{
	int resultado;
	
	if ((num + num)>0) {
		return 1;
	}
		else if ((num + num)<0) {
			return -1;
		}
		else {
			return 0;
		}	
	
	return resultado;
}
	
