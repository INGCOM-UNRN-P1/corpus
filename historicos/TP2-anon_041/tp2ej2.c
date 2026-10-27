
#include <stdio.h>

int potencia(int base, int exponente);
int producto(int n, int m);

int main(int argc, char *argv[])
{
	int n;
	int m;
	int resultado_potencia;
	int resultado_producto;
	while(1)
    {
        printf("Ingrese dos numeros naturales para saber el producto y la potencia entre si! \nPrimero numero: ");
		scanf("%d", &n);
        if(n > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0\n");
        }
    }
	while(1)
	{
		printf("Segundo numero: ");
		scanf("%d", &m);
		if(m > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0\n");
        }
	}
	resultado_potencia = potencia(n, m);
	resultado_producto = producto(n, m);
	printf("Potencia: %d\nProducto: %d", resultado_potencia, resultado_producto);
	
	return 0;
}


int producto(int n, int m)
{
	int x;
	x = n * m;
	
	return x;
}


int potencia(int base, int exponente)
{
	int x = base;
	
	if (exponente == 0)
	{
		return 1;
	}
	
	while (exponente > 1)
	{
		x = x * base;
		exponente = exponente - 1;
	}
	
	return x;
}
