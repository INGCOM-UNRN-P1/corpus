
 
 #include <stdio.h>
 
 int main()
 {
	int calculo_factorial = 1;
	int ingreso_fact;
	int i;
	
	printf("Ingrese el valor de n: ");
	scanf("%d", &ingreso_fact);

	for(i = 1; i <= ingreso_fact; i++)
	{
		calculo_factorial = calculo_factorial * i;
	}
	
	printf("El factorial de %d!: %d", ingreso_fact, calculo_factorial);
	
	return 0;
 }