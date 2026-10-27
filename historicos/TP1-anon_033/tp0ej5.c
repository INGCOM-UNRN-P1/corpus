
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a,b,max,min,cont;
    printf("Primer numero: ");
    scanf("%d",&a);
    printf("Segundo numero: ");
    scanf("%d",&b);
    if(a < b)
    {
        max=b;
        min=a;
	}
	else
    {
        max=a;
        min=b;
	}
	cont = min;
	while(cont <= max)
    {
        printf("%d\n",cont);
        cont++;
	}
	return 0;
}
