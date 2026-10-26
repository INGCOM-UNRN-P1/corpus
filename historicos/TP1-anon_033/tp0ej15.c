/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>
#define LARGO_TEXTO 100

int compara_fechas(char *primera, char *segunda);

int main(int argc, char *argv[])
{
    char *primera[L], *segunda[L];
    printf("Ingrese la primera fecha en formato DD/MM/AAAA: ");
    scanf("%s", &primera);
    printf("Ingrese la segunda fecha en formato DD/MM/AAAA: ");
    scanf("%s", &segunda);

	return 0;
}
int compara_fechas(char *primera, char *segunda)
{
    char dia1,dia2,mes1,mes2,año1,año2;
    int l1,l2,dia1,dia2,mes1,mes2,año1,año2;
    l1=strlen(primera);
    l2=strlen(segunda);

	for(k=1,k<=3)
    {
		if(k=1)
		for(i=0, i<=l1,i++)
        {
			if(isdigit(primera[i])==1)
            g=atoi(primera[i]);

	return 0;
}
