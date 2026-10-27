
#include <stdio.h>
 
int main(int argc, char *argv[]){
int numeroentero, numeroentero2, resultado, numeroma, numerome;

printf("ingrese un numero entero ");

scanf("%d" ,&numeroentero);

printf("Ingrese otro numero entero ");

scanf("%d" ,&numeroentero2);

if (numeroentero>numeroentero2){
	numeroma=numeroentero;
numerome=numeroentero2;
}

else if (numeroentero<numeroentero2){
numerome=numeroentero;
numeroma=numeroentero2;
}
printf("\n  sus numeros entre %d y %d son\n\n " ,numeroentero ,numeroentero2);
	
while (numerome<=numeroma)
	
{
	
	printf("%d\n " ,numerome);
	numerome=numerome+1;

	

}

return 0;
}