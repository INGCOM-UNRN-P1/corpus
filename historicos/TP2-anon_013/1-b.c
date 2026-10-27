

//Trabajo práctico 2:
//Ejercicio 1-b: Partes eteras de las raíces cuadradas de n y m

#include<stdio.h>
void main()
{
    int n, m, parte_entera_n, parte_entera_m;
    float temp, sqrt_n, sqrt_m;
    printf("Introduzca dos numeros.\n");
    scanf("%d%d", &n, &m);
    sqrt_n=n/2;
    sqrt_m=m/2;
    temp=0;
    while (sqrt_n!=temp)
    {
        temp=sqrt_n;
        sqrt_n=(n/temp+temp)/2;
    }
    while (sqrt_m!=temp)
    {
        temp=sqrt_m;
        sqrt_m=(m/temp+temp)/2;
    }
	parte_entera_n=(int)sqrt_n;
	parte_entera_m=(int)sqrt_m;
	printf("\nLa parte entera de la raiz cuadrada de %d es: %d.", n, parte_entera_n);
	printf("\nLa parte entera de la raiz cuadrada de %d es: %d.\n", m, parte_entera_m);
}
