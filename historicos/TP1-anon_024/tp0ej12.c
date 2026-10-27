
#include <stdio.h>
 
int compara(int numero, int otronumero);


int main(int argc, char *argv[]){

int numero1, numero2, resultado;

printf("ingrese un numero ");
scanf("%d" ,&numero1);
printf("ingrese otro numero ");
scanf("%d" ,&numero2);

resultado = compara (numero1 ,numero2);


switch (resultado)
{
case -1:
printf ("-1");
break;
case 0:
printf("0");
break;
case 1:
printf("1");
break;
}
	
	return 0;
}
int compara(int numero, int otronumero){
	if (numero<otronumero){
	
	return -1;
	}
	else if (numero == otronumero){
		return 0;
	}
	else{
		return 1;
}
}


