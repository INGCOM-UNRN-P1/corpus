

int main(int argc, char *argv[])
{
	int numero1,numero2,contador;
    
    printf("Ingrese primer numero \n");
	scanf("%d", &numero1);
	printf("Ingrese Segundo numero \n");
	scanf("%d", &numero2);
	
	printf("primer numero: %d \n)", numero1);

	printf("segundo numero: %d \n", numero2);

	
	if (numero1 < numero2)
	{
		contador = numero1;
		
		while(contador <= numero2)
		{
			printf("%d \n", contador);
			
			contador = contador + 1;
		
		}
	
	}
	else
	{
		while(contador <= numero1)
		{
			printf("%d \n", contador);
			contador = contador + 1;
		}
	
	}
    return 0;
}
