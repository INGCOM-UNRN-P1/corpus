

#include <stdio.h>

void suma_en_rango(int numero, int otro_numero){
	int contador;
	
	if (numero < otro_numero) {
    	contador = 1;
        while (contador <= otro_numero) {
            numero = numero + 1;
            contador++;
            printf("%d\n", numero);
        }
    } else if (numero > otro_numero) {
        while (contador < numero) {
            otro_numero = otro_numero + 1;
            contador++;
            printf("%d\n", otro_numero);
        }
    } else {
        numero = numero + otro_numero;
        printf("%d", numero);
    }
}



int main() {
    int numero;
    int otro_numero;
    
    printf("Escriba un numero: ");
    scanf("%d", &numero);
    
    printf("Escriba otro numero: ");
    scanf("%d", &otro_numero);
    
    suma_en_rango(numero,otro_numero);
    
    return 0;
}

//precondicion: Se le pide al usuario que escriba dos numeros 
//poscondicion; La funcion imprime los numeros en rango desde el numero menor al numero mayor terminando con el numero que se obtendria en la suma. Si los numeros son iguales se imprime la suma. 
