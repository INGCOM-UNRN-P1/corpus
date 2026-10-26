

#include <stdio.h>
#define capacidad 100

int largo_seguro(char cadena[]){
	int i = 0;
	cadena[100] = '\0';
	
	while (cadena[i] != '\0'){
		i++;
	}
	return i;
}

void copia_cadena(char cadena[]){
	char copia[capacidad];
	int i = 0;
	
	while (cadena[i] != '\0'){
		copia[i] = cadena[i];
		i++;
	}
	copia[i] = '\0';
	printf("La cadena copia es: %s", copia);
	printf ("El largo de la cadena copia es de %d caracteres.\n\n", largo_seguro(copia));
}
void insercion(char cadena[]) {
    char injerto[capacidad];
    int posicion;
    int carinjerto;
    int i;
    
    printf("Ingrese una cadena de caracteres a insertar: ");
    fgets(injerto, sizeof(injerto), stdin);
    
    printf("En que posicion quiere insertar la palabra? ");
    scanf("%d", &posicion);
    
    printf("Cuantos caracteres tiene la palabra a insertar? ");
    scanf("%d", &carinjerto);
    
    for (i = largo_seguro(cadena); i >= posicion; i--) {
        cadena[i + carinjerto] = cadena[i];
    }
    
    for (i = 0; i < carinjerto; i++) {
        cadena[posicion + i] = injerto[i];
    }
    
    cadena[largo_seguro(cadena) + carinjerto] = '\0';

    printf("La cadena con injerto ingresada es: %s", cadena);
}
void limpieza (char cadena[]){
	char aux[capacidad];
	
	for (int i = 0; i != '\0'; i++){
		aux[i] = cadena[i];
	}
	
	for (int i = 0; aux[i] != '\0'; i++){
		if ((aux[i] >= 'A' && aux[i] <= 'Z') || (aux[i] >= 'a' && aux[i] <= 'z')) {
			continue;
    	}
    	if (aux[i] >= '0' && aux[i] <= '9') {
        }else{
        	aux[i] = ' ';
		} 
	}
  	
    printf("La cadena limpia es: %s\n", aux);
    printf ("El largo de la cadena limpia es de %d caracteres.\n\n", largo_seguro(aux));
}
void comparacion(){
    char comparacion[capacidad];
    char comparacion_dos[capacidad];
    int i = 0;

    printf("Ingrese una cadena de caracteres a comparar: ");
    fgets(comparacion, sizeof(comparacion), stdin);

    printf("Ingrese otra cadena de caracteres a comparar: ");
    fgets(comparacion_dos, sizeof(comparacion_dos), stdin);

    if (comparacion[0] > comparacion_dos[0]){
        printf("1\n");
    } else if (comparacion[0] < comparacion_dos[0]){
        printf("-1\n");
    } else {
        while (comparacion[i] == comparacion_dos[i]){
            if (comparacion[i] == '\0') {
                printf("0\n");
                return;
            }
            i++;
        }
        if (comparacion[i] < comparacion_dos[i]){
            printf("-1\n");
        } else if (comparacion[i] > comparacion_dos[i]){
            printf("1\n");
        }
    }
}
void minus_mayus(char cadena[]){
    int i = 0;
    while (cadena[i] != '\0'){
        if (cadena[i] >= 'A' && cadena[i] <= 'Z'){
            cadena[i] = cadena[i] + ('a' - 'A');
        }
        i++;
    }
    printf("La cadena en minuscula es: %s\n", cadena);
}
void palindromo(char cadena[]) {
    char palin[capacidad];
    int largo = 0;
    int i = 0;

    largo = largo_seguro(cadena);

    if (largo > 0 && cadena[largo - 1] == '\n') {
        cadena[largo - 1] = '\0';
        largo--; 
    }

    for (i = 0; i < largo; i++) {
        palin[i] = cadena[i];
    }

    int inicio = 0;
    largo = largo - 1;

    while (largo > inicio) {
        if (palin[inicio++] != palin[largo--]) {
            printf("La palabra NO es un palindromo.\n");
            return;
        }
    }

    printf("La palabra es un palindromo.\n");
}	
int main(){
	char cadena[capacidad];
	
	printf("Ingrese una cadena de caracteres: ");
	fgets(cadena, sizeof(cadena), stdin);
	printf("La cadena ingresada es: %s", cadena);
	
	printf ("El largo de la cadena es de %d caracteres.\n\n", largo_seguro(cadena));
	
	copia_cadena(cadena);
	
	limpieza(cadena);
	
	comparacion();
	
	minus_mayus(cadena);
	
	palindromo(cadena);
	
	insercion(cadena);
	
	return 0;
}

//precondicion: se pide por pantalla poner una cadena con la cual se desarrollaran todas las funciones pedidas. en algunas funciones se pueden pedir mas cadenas para su correcto funcionamiento.
//poscondiciones: con la cadena escrita se desarrollan todas las funciones pedidas.
