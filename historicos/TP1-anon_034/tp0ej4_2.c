
 
 #include <stdio.h>
 
 int es_primo(int numero)
 {
	int contador = 0;
	int resto_div;
	
	for (contador = 0; contador < numero; contador++)
	{
		if(contador + 1 == numero){
			return 1;
		}
		else if(contador + 1 == 1)
		{
			
		}
		else
		{
			resto_div = numero % (contador + 1);
			if(resto_div == 0)
			{
				return 0; 
			}
		}
	}
 }
 
 int main()
 {	
	int ingreso, resultado;
	
	printf("\nBienvenido a mi codigo!\n");
	printf("\nIngrese un numero entero para analizar si es primo o no.\n");
	scanf("%d", &ingreso);
	
	resultado = es_primo(ingreso);
	printf("Es: %d", resultado);
	 
	return 0;
 }