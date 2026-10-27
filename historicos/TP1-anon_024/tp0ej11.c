
#include <stdio.h>
 
int suma_lenta (int numero, int otronumero);

int main(int argc, char *argv[]){

int numero1, numero2, resultado;
{
printf("ingrese un numero ");
scanf("%d" ,&numero1);
printf("ingrese otro numero ");
scanf("%d" ,&numero2);

resultado= suma_lenta(numero1, numero2);


printf("= %d" ,resultado);
}

	
return 0;

}

int suma_lenta(int numero, int otronumero){
	
	int resultado;
	resultado=numero+otronumero;
	printf("%d" ,numero);
	while (numero<resultado)
	{
		printf("+1");
		numero=numero+1;
	}
	
	return resultado;
}
