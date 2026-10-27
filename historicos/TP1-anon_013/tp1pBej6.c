

//Trabajo práctico 1:
//Parte B:
//Ejercicio 6: Compara fechas

#include <stdio.h>
#include <string.h>
#define PRIMERA 12
#define SEGUNDA 12
int compara_fechas(char *primera, char *segunda);
int main(int argc, char *argv[])
{
    char primera[PRIMERA];
    char segunda[SEGUNDA];
    int valor;
    printf("Introduzca la primera fecha y luego la segunda, en formato: xx/xx/xxxx.\n");
    scanf("%s%s", primera, segunda);
    valor=compara_fechas(primera, segunda);
    return valor;
}
int compara_fechas(char *primera, char *segunda)
{
    int j, contador=-1, contador_ano=0, contador_mes=0;
	  char barra='/';
    if (strlen(primera)!=strlen(segunda)||strlen(primera)!=10)
    {
        printf("\nReinicie e introduzca las fechas en formato: xx/xx/xxxx.\n");
    }
	  if (primera[2]!=barra||primera[5]!=barra)
	  {
		    printf("\nNo se ingresaron las barras correctamente.\n");
	  }
    for (j=0; j<=strlen(primera); j++)
    {
        if (primera[j]==segunda[j])
        {
            contador++;
        }
    }
    if (contador==strlen(primera))
    {
        printf("\n0: Las fechas son iguales.\n");
    }
    for (j=6; j<10; j++)
    {
        if (primera[j]>segunda[j])
        {
            printf("\n1: La primera fecha es posterior a la segunda.\n");
            break;
        }
        if (segunda[j]>primera[j])
        {
            printf("\n-1: La primera fecha es anterior a la segunda.\n");
            break;
        }
        if (primera[j]==segunda[j])
        {
            contador_ano++;
        }
    }
    if (contador_ano==4)
    {
        for (j=3; j<5; j++)
        {
            if (primera[j]>segunda[j])
            {
                printf("\n1: La primera fecha es posterior a la segunda.\n");
                break;
            }
            if (segunda[j]>primera[j])
            {
                printf("\n-1: La primera fecha es anterior a la segunda.\n");
                break;
            }
            if (primera[j]==segunda[j])
            {
                contador_mes++;
            }
        }
    }
    if (contador_mes==2)
    {
        for (j=0; j<3; j++)
        {
            if (primera[j]>segunda[j])
            {
                printf("\n1: La primera fecha es posterior a la segunda.\n");
                break;
            }
            if (segunda[j]>primera[j])
            {
                printf("\n-1: La primera fecha es anterior a la segunda.\n");
                break;
            }
        }    
    }
}
