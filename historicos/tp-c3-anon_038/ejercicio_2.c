


#include <stdio.h>

typedef struct division_lenta{
    int dividendo;
    int divisor;
	int cociente;
	int resto;
} division_t;

 
 
 
division_t divide_lento(division_t div_1)
	{
	division_t resultado_div_lenta;
	
	int dividendo = div_1.dividendo;
	int divisor = div_1.divisor;
	div_1.cociente = 0;
	
	while (dividendo>=divisor)
		{
		dividendo = dividendo - divisor;
		div_1.cociente = div_1.cociente + 1;
		printf("%d \n", div_1.cociente);
		}
	
	resultado_div_lenta.cociente = div_1.cociente;
	
	div_1.resto = div_1.dividendo - (div_1.divisor * div_1.cociente);
	
	resultado_div_lenta.resto = div_1.resto;
	
	return resultado_div_lenta;
	
	}

int main()
{
	division_t div_1;
	division_t res_final;
	
	printf("Ingrese un numero para usar como dividendo \n");
	scanf("%d", &div_1.dividendo);

	printf("Ingrese un numero para usar como divisor \n");
	scanf("%d", &div_1.divisor);

	res_final = divide_lento(div_1);
	
	printf("El cociente es %d, y el resto es %d \n", res_final.cociente,res_final.resto);


	return 0;

}