

// TP1 - ej3 operadores aritmeticos

# include <stdio.h>

int main ()
{
	int A, B;
	float multi, div, resto;
	
	printf ("Indique el valor de A: \n");
	scanf ("%i", &A);
	
	printf ("Indique el valor de B: \n");
	scanf ("%i", &B);
	
	multi = A * B; // A *= B
	printf ("El valor de A * B es: %f \n", multi);
	
	div = A / B; // A /= B
	printf ("El valor de A / B es: %f \n", div);	
	
	resto = A % B;
	printf ("El valor de A resto B es: %f \n", resto);
	
	
	system ("pause");
	return 0;
}
