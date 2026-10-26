/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024
*************************/
#include <stdio.h>

int factorial(int numeroN);
int combinatorio (int numeroN, int numeroK);


int main(int argc, char *argv[]){
int numeroN, resultado1;
int numeroK,resultadoCom;

printf("ingrese su numero entero ");
	scanf("%d",&numeroN);
	

do
{
	printf("Ingrese un numero entero menor al anterior ");
	scanf("%d"  ,&numeroK);
}
while (numeroK>=numeroN);
	
resultado1=factorial(numeroN);

printf("El factorial de %d es: " ,numeroN);
printf("%d",resultado1);
resultadoCom=combinatorio(numeroN, numeroK);
printf("\n El combinatorio es %d " ,resultadoCom);


int numeromaximo;
int numerominimo;

if (numeroN<numeroK){
	numeromaximo=numeroK;
	numerominimo=numeroN;
}
else {
	numerominimo=numeroK;
	numeromaximo=numeroN;
}
int resta=numeromaximo-numerominimo;
long long final;

printf("Los resultados entre %d y %d son: " ,numeroN ,numeroK);

while(numerominimo<numeromaximo){

final=combinatorio(numerominimo, numeromaximo);

printf("%d," ,&final);

numerominimo++;
}

return 0;

}

int factorial(int numeroN){
int cont,resultado=1;

cont=numeroN;

while (cont>=1){

resultado=resultado*cont;
cont--;
}
return resultado;
}

int combinatorio(int numeroN, int numeroK){
	int resultado2;
	int factorialK=factorial(numeroK),factorialN=factorial(numeroN);
	int divFac=(numeroN-numeroK),FacFac=factorial(divFac);
	resultado2=factorialN/(factorialK*FacFac);
return resultado2;
}