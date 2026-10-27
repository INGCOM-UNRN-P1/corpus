

// TP1 - ej4 - multiplos

# include <stdio.h>

int main (){
	
	int n, i, j;
	
	printf ("ingrese un numero mayor que 100: ");
	scanf ("%i", &n);
	
	//inicia contadores:
	i = 0;
	j = 1;	
	
	// multiplo de 2:
	while (i < 1){
		j = n % 2;
		i++;
		if (j != 0){
			printf ("es multiplo de 2: NO \n"); break;
		}
	}
	if (j == 0){
		printf ("es multiplo de 2: SI \n");
	}
	
	// limpia contadores:
	i = 0;
	j = 1;
	
	//multiplo de 3:
		while (i < 1){
		j = n % 3;
		i++;
		if (j != 0){
			printf ("es multiplo de 3: NO \n"); break;
		}
	}
	if (j == 0){
		printf ("es multiplo de 3: SI \n");	
	}
	
	// limpia contadores:
	i = 0;
	j = 1;
	
	//multiplo de 4:
		while (i < 1){
		j = n % 4;
		i++;
		if (j != 0){
			printf ("es multiplo de 4: NO \n"); break;
		}
	}
	if (j == 0){
		printf ("es multiplo de 4: SI \n");	
	}
	
	// limpia contadores:
	i = 0;
	j = 1;
	
	//multiplo de 5:
		while (i < 1){
		j = n % 5;
		i++;
		if (j != 0){
			printf ("es multiplo de 5: NO \n"); break;
		}
	}
	if (j == 0){
		printf ("es multiplo de 5: SI \n");	
	}	
	
	// limpia contadores:
	i = 0;
	j = 1;
	
		//multiplo de 6:
		while (i < 1){
		j = n % 6;
		i++;
		if (j != 0){
			printf ("es multiplo de 6: NO \n"); break;
		}
	}
	if (j == 0){
		printf ("es multiplo de 6: SI \n");	
	}	
	system ("pause");
	return 0;
}
