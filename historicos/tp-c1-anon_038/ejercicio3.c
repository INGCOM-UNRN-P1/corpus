

#include <stdio.h>
#include <stdlib.h>




int determinar_signo(int numero)
{
	int valor_absoluto, resultado, respuesta, resultado_2;
	
	resultado = numero;
	resultado_2 = numero + 1;

	
	if (resultado_2 == 1)
	{
		respuesta = 0;
	}
	else
	{
		resultado = resultado - abs(resultado);
	
		if (resultado == 0)
		{
		respuesta = 1;
		}
		else
		{
		respuesta = -1;
		}

		
	}
	
	return respuesta;

}

int main()
{
	int numero;
	
	printf("Ingresa un numero para determinar su signo \n");
	scanf("%d", &numero);
	
	int valor_signo = determinar_signo(numero);
	
	printf("Su numero es %d", valor_signo);

} 