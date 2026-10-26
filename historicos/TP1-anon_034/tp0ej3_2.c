
 
 #include <stdio.h>
 
 int compara(int numero, int otronumero)
 {
	if(numero == otronumero)
	{
		return 0;
	}
	else if (numero < otronumero) 
	{
		return -1;
	}
	else 
	{
		return 1;
	}
 }
 
 int main()
 {	
	int ingreso, otro_ingreso, resultado;
	
	printf("1: ");
	scanf("%d", &ingreso);
	printf("2: ");
	scanf("%d", &otro_ingreso);
	
	resultado = compara(ingreso, otro_ingreso);
	printf("El resultado es: %d", resultado);

	return 0;
 }