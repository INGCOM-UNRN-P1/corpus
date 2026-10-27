
#include <stdio.h>
#define KG_HARINA 20000;

int main(){
	
	int i;
	unsigned long long int granos_de_trigo, kilogramos, resultado, suma;
	granos_de_trigo = 1;
	suma = 1;
	resultado = 0;
	
	
	for(i=1; i < 65; i++){
		printf("Casillero %d: %llu\n", i, granos_de_trigo);
		if (i == 64){
			break;
		}
		else{
			granos_de_trigo = granos_de_trigo * 2;
			suma = suma + granos_de_trigo;
		}
		
	}
	resultado = suma /KG_HARINA
	
	printf("El total de kg de granos de trigo ue tiene que pagar: %llu", resultado);
	
	return 0;
}