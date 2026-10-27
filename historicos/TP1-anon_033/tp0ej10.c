
#include <stdio.h>

int main(int argc, char *argv[])
{
    int dia;
    printf("\n   Introduzca numero de dia de la semana: ");
    scanf("%d",&dia);
    switch (dia){
		case 1:
        printf( "\n-   El numero %d corresponde al dia Lunes \n\n", dia);
		break;

		case 2:
        printf( "\n-   El numero %d corresponde al dia Martes\n\n", dia);
		break;

		case 3:
        printf( "\n-   El numero %d corresponde al dia Miercoles\n\n", dia);
		break;

		case 4:
        printf( "\n-   El numero %d corresponde al dia Jueves\n\n", dia);
		break;

		case 5:
        printf( "\n-   El numero %d corresponde al dia Viernes\n\n", dia);
		break;

		case 6:
        printf( "\n-   El numero %d corresponde al dia Sabado\n\n", dia);
		break;

		case 7:
        printf( "\n-   El numero %d corresponde al dia Domingo\n\n", dia);
		break;

		default:
        printf( "\n-  El numero %d no corresponde a ningun dia de la semana\n\n", dia);
	}
	return 0;
}
