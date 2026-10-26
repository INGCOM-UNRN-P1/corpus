

#include <stdio.h>


int division_lenta(int dividendo, int divisor)
{
    int cociente = 0;

	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		cociente = cociente + 1;
        //printf("%d\n", dividendo);
	}

    
	return dividendo;
}


int cociente_lento(int dividendo, int divisor)
{
    int cociente = 0;

	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
        //printf("%d\n", cociente);
		cociente = cociente + 1;
	}

	return cociente;
}

int main()
{
    int dividendo;
    int divisor;
    int cociente;
    int resto;

    printf("Ingrese dos numeros enteros para obtener el valor del cociente y el resto mediante restas sucesivas:\n");
    printf("Dividendo: ");
    scanf("%d", &dividendo);
    printf("Divisor: ");
    scanf("%d", &divisor);
    
    resto = division_lenta(dividendo, divisor);
    cociente = cociente_lento(dividendo, divisor);

    printf("Cociente: %d\nResto: %d", cociente, resto);
	
	return 0;
}
