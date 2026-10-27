
#include <stdio.h>
int raizentera(int a)
{
	int i;
	int raizentera;
	for(i=1; i<a;i++)
	{
		if(i*i<=a)
		{
			raizentera=i;
		}
	}
	return raizentera;
}

int main(int argc, char *argv[])
{	
	int natural;
	int raiz;
	printf("Ingrese un numero natural: ");
	scanf("%d",&natural);
	if(natural>0)
	{
		raiz = raizentera(natural);
		printf("La raiz natural de %d = %d",natural,raiz);
	}else{
		printf("El numero ingresao %d no es un natural",natural);
	}
	return 0;
	
	
}
