
 
 #include <stdio.h>
 
 int suma_lenta(int numero, int otronumero)
 {
	int i = 0;

	if (otronumero > 0)
	{
		for (i = 0; i < otronumero; i++){
			numero++;
		}
		return numero;
	}
	else if (otronumero < 0)
	{
		for(i = 0; i < -otronumero; i++)
		{	
			numero--;
		}
		return otronumero;
	}
	else 
	{
		return numero;
	}
 }
 
 int main()
 {	
	int ingreso, otro_ingreso, resultado;
	
	printf("Ingrese el primer entero: ");
	scanf("%d", &ingreso);
	printf("Ingrese el segundo entero: ");
	scanf("%d", &otro_ingreso);
 
	resultado = suma_lenta(ingreso, otro_ingreso);
	printf("El resultado de la suma lenta es: %d", resultado);

	return 0;
 }