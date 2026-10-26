

#include <stdio.h>
#include <string.h>
#include <ctype.h>



void es_palindromo(char palindromo[]) {
	
	int i, k, boolean;
	
	k = strlen(palindromo) - 1;
	boolean = 0;
	
	for(i=0; i < strlen(palindromo); i++) {
		if(tolower(palindromo[i]) != tolower(palindromo[k])) {
			boolean = 1;
			break;
		}
		k-=1;
	}
	
	if(boolean == 0) {
		printf("True");
	}
}

int main()
{
	char cadena[] = "Ana";
	
	es_palindromo(cadena);
	return 0;
}