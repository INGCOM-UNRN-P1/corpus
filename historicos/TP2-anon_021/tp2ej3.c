
#include <stdio.h>
 
int factorial(int numero);
 
 int convinatorio(int n, int k);
 
int main(int argc, char *argv[])
{

int numero, numerok;
unsigned long long int todojunto,resultadoA;

printf("\ningrese un numero : ");

scanf("%d",&numero);

resultadoA = factorial(numero);

printf ("\n a) !%d = %llu\n",numero,resultadoA); 

do
{
	printf("\n Ingrese un numero K menor o igual a %d : ",numero);
	
	scanf("%d",&numerok);	
}
while (numerok >= numero);

todojunto = convinatorio(numero,numerok);

printf("\n\n       !%d\n    -------- = %llu\n    !%d(%d-%d)!\n",numero,todojunto,numerok,numero,numerok);	

numerok = numero - 1;

printf("\n\nc)");

while (numerok>0){
	
	todojunto = convinatorio(numero,numerok);
	
	printf("\n\n       !%d\n    -------- = %llu\n    !%d(%d-%d)!\n",numero,todojunto,numerok,numero,numerok);
	
	numerok -= 1;
	
}


return 0;
}

unsigned factorial(int numero){
	
unsigned long long int contador, valor;

contador = 1;

valor = 1;

while (contador < numero){
	
	contador += 1;
	
	valor = valor * contador;
	
}

return valor;
}

unsigned convinatorio(int n, int k){
    
unsigned long long int resultadoA, resultadoB,resultadoC;

resultadoA = factorial(n);

resultadoB = factorial(k);

resultadoC = n - k ;

resultadoC = factorial(resultadoC);

resultadoA = resultadoA/resultadoB;

return resultadoA;
}