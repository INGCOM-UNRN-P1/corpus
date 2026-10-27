

// TP1 - ej8 - fibonacci

#include <stdio.h>

int main (){
	
	int n, x, y, res, i;
	
	printf ("Sucesion de Fibonacci \nindique el numero de terminos: ");
	scanf ("%i", &n);
	
	i = 3;
	x = 0;
	y = 1;
	printf ("%i, %i, ", x, y);
	while (i <= n){
		res = x + y;
		printf ("%i, " ,res);
		x = y;
		y = res;
		i++;
	}
	
	printf ("\n");
	
	system ("pause");
	return 0;
}	
