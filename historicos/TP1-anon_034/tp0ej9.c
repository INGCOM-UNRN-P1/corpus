
 
 #include <stdio.h>
 
 int main()
 {
	int ingreso;
	
	do
	{
		printf("\nIngrese un numero n: ");
		scanf("%d", &ingreso);
		if (ingreso <= 100)
		{
			printf("\nEl numero es menor a 100\n");
		}
	}
	while(ingreso <= 100);
	
	printf("\nEl numero es mayor a 100\n");
	 
	return 0;
 }