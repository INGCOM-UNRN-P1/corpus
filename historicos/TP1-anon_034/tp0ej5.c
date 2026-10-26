
 
 #include <stdio.h>
 
 int main()
 {
	int ingreso_entero_uno;
	int ingreso_entero_dos;
	int i;
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &ingreso_entero_uno);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &ingreso_entero_dos);	
	
	for (i = ingreso_entero_uno; i < ingreso_entero_dos + 1; i++)
	{
		printf("%d \n", i);
	}
	 
	return 0;
 }