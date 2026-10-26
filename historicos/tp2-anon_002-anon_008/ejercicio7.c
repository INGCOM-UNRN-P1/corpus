

#include <stdio.h>

int multiplicacion(int numero, int otro_numero){ //funcion que multiplica a base de sumas reiteradas.
	int aux;
	int save;
	
	aux = 1;
	save = numero;
	
	while (aux < otro_numero){
		numero = numero + save;
		aux++;
	}
	return numero;
}

int potencia(int base, int exponente) { //funcion que hace la potencia de un numero utilizando la funcion anterior que multiplica todo a base de sumas.
    int resultado = base;
    int aux = 1;
    
    while (aux < exponente) {
        resultado = multiplicacion(resultado, base);
        aux++;
    }
    
    return resultado;
}

int main(){
	int base;
	int exponente;
	int resultado;
	
	
	printf("Escriba la base: ");
	scanf("%d",&base);
	
	printf("Escriba el exponente: ");
	scanf("%d",&exponente);
	
	resultado = potencia(base,exponente);
	
	if(exponente == 0){
		printf("%d elevado a %d es igual a 1\n", base, exponente);
	}else{
		printf("%d elevado a %d es igual a %d\n", base, exponente, resultado);
	}
	return 0;
}

//precondicion: Se pide al usuario poner un numero de base el cual debe ser entero y positivo y un numero de exponente que tambien debe ser enterno y positivo.
//poscondicion: La funcion imprime por pantalla los valores de elevar el numero dado a la potencia dada.
