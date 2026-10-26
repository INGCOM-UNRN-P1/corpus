/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{

int numeroA, numeroB, resultado;


printf ("Intrudusca su numero ");

scanf("%d" ,&numeroA);

printf ("introdusca su segundo numero ");

scanf("%d" ,&numeroB);

resultado=numeroA*numeroB;

printf("%d\n" ,resultado);

resultado=numeroA/numeroB;

printf("%d\n" ,resultado);

resultado=numeroA%numeroB;

printf("%d\n" ,resultado);


return 0;
}