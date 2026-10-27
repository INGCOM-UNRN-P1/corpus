



#include <stdio.h>

int main(int argc, char *argv[])
{
    int numeroUno;
    int numeroDos;
	
    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d", &numeroUno, &numeroDos);
	
	printf("\n");
    printf("Primer numero: A= %d \n", numeroUno);
    printf("Segundo numero: B = %d \n", numeroDos);
    printf("Operador multiplicacion: A*B = %d \n", (numeroUno * numeroDos));
    printf("Operador division: A/B = %d \n", (numeroUno / numeroDos));
    printf("Operador resto: A%B = %d \n", (numeroUno % numeroDos));
}
