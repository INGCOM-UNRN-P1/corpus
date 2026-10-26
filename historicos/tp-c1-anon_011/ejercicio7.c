

#include <stdio.h>

void es_primo(int primo) {
	
	int boolean, i;
	
	boolean = 0;
	
	for(i=2; i < primo; i++) {
		if(primo % i == 0) {
			boolean = 1;
			break;
		}
	}
	if(boolean == 0) {
		printf("True");
	}
}

int main()
{
	int numero;

	numero = 13;
	
	es_primo(numero);
	
	return 0;
}