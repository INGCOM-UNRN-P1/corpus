

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int factorial, i;
	
	factorial = rand() % 10;
	
	printf("el numero es: %d\n", factorial);
	
	for(i = factorial - 1; i > 0; i--) {
		factorial = factorial * i;
	}
	
	printf("%d", facorial);
	return 0;
}