

// TP1 - ej5. Lazos

#include <stdio.h>

int main (){
	
	int A, B, i;
	
	printf ("Indique un numero: \n");
	scanf ("%i", &A);
	printf ("indique un numero mayor que el anterior: \n");
	scanf ("%i", &B);
	
	// for
	for (i = A+1 ; i<B ; i++){
		printf ("%i, ", i);
	}
	
	printf ("\n");
	
	//while
	i = A+1;
	while (i<B){
		printf ("%i, ", i);
		i++;
	}
	
	system ("pause");
	return 0;
}
