
#include <stdio.h>

#include <stdio.h>
#define L 1000
char * cuadrado(int numero);
char * aster(int numero);

int main(int argc, char *argv[])
{
	int largo;
	char * disc,* cajon;
	printf("Ingrese numero de asteriscos que desea : ");
	scanf("%d",&largo);

	disc = aster(largo);
	printf("\nPunto a):\n%s\n",disc);

	cajon = cuadrado(largo);
	printf("Punto b)\n\n%s",cajon);

	printf("Punto c)\n");
	int alpha, omega;
	for (alpha = 0; alpha < largo; alpha++)
    {
		for (omega = 0; omega < alpha*2+1; omega++)
        {
            printf("*");
		}
		printf("\n");
	}


	return 0;
}



char * aster(int numero)
{
	char asteros[L];
	char * final;
	for (int i = 0; i < numero ; i++)
    {
		asteros[i] = '*';
	}
	final = asteros;
	return final;
}



char * cuadrado(int numero)
{
	char caja[L];
	char * cajaf;
	int contadorV,contadorH, contadorcopia, numero2,numerobajo;
	contadorV = 0;
	contadorH = 0;
	contadorcopia = 0;
	numero2 = numero;
	while (contadorV < numero)
    {
		numerobajo = numero2 - 1;
		for (int i = contadorcopia; i<numero2; i++){
			if (contadorH == contadorcopia || contadorH == numero - 1)
            {
				caja[i] = '*';
			}
			else if (i == contadorcopia || i == numerobajo){
				caja[i] = '*';
			}
			else{
				caja[i] = ' ';
			}
		}
		contadorcopia = numero2 + 1;
		contadorV += 1;
		contadorH += 1;
		caja[numero2] = '\n';
		numero2 = numero2 + numero + 1;
	}
	cajaf = caja;
	return cajaf;
}
