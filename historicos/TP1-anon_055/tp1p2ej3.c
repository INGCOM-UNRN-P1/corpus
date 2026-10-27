

// TP1 - parte 2 - ej. 3 comparacion de numeros

# include <stdio.h>

int compara ();

int main (){
	
	int res, n1, n2;
	
	printf ("digite el primer numero: ");
	scanf ("%i", &n1);
	printf ("digite el segundo numero: ");
	scanf ("%i", &n2);
	
	res = compara (n1, n2);
	
	switch (res){
	case -1: printf ("el mayor es: %i. \n", n1); break;
	case 0: printf ("los numeros son iguales. \n"); break;
	case 1: printf ("el mayor es %i. \n", n2); break;
	}
	
	system ("pause");
	return 0;
}
	
	
int compara (n1, n2) {
	
	if (n1>n2){
		return -1;
	}
	else if(n1==n2){
		return 0;
	}
	else {
		return 1;
	}
}		

