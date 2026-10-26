/****************
Ingeniería en computación
Programación I
UNRN- ejecicio 1
florenciadevalucero
****************/ 
#include<stdio.h>
int raiz(n);

int main(){
	int n, m, resultado1, resultado2;
	
	do{
		printf("Ingrese un numero natural: ");
		scanf("%d", &n);
		if(n < 1)
		{
			printf("Un numero natural!\n");
		}
	}while(n < 1);
	
	do{
		printf("Ingrese otro numero natural: ");
		scanf("%d", &m);
		if(m < 1){
			printf("Un numero natural!\n");
		}
	}while(m < 1);
	
	resultado1 = raiz(n);
	resultado2 = raiz(m);	
	printf("La raiz de %d es: %d", n, resultado1);
	printf("\nLa raiz de %d es: %d", m, resultado2);
	return 0;
}


int raiz(int n){
	int i, max;
	
	max = 0;
	i = 0;
	
	while(max <= n){	
		i = i + 1;
		max = i * i;
	}
	
	if(max > n){
		i = i -1;
	}
	return i;
}

