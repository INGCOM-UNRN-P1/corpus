
 
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
	for(i = ingreso_fact; i >= 1; i--)
	{
		printf("El factorial de %d! es: %d\n", ingreso_fact, calculo_factorial);
		calculo_factorial = calculo_factorial / ingreso_fact;
		ingreso_fact--;
	}
	 
	return 0;
 }