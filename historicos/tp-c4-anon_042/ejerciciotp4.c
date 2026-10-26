
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
#define MAXIMO 20
#define TRUE -2
#define FALSE -3
int largo_seguro(char cadena[], int capacidad){ 
	int caracteres = 0;
	while(cadena[caracteres] != '\0'){
		caracteres= caracteres + 1;
	}
	if(caracteres>=capacidad){
		caracteres= CADENA_SIN_TERMINADOR;
	}
	return caracteres;
}
int insercion(char cadena[],char cadena1[],int capacidad, int posicion){ 
	int largoTotal = largo_seguro(cadena, capacidad) + largo_seguro(cadena1, capacidad);
	char aux[MAXIMO];
	int largodos;
	int largoinsercion = largo_seguro(cadena1, capacidad) + posicion;
	largodos = largo_seguro(cadena1, capacidad);
	int j = 0;
	int k = 0;
	if(largoTotal>=capacidad || largoTotal == CADENA_SIN_TERMINADOR){
		largoTotal= CADENA_SIN_TERMINADOR;
		return largoTotal;
	}
	else{
		for(int i=posicion; i<=largoTotal; i++){
			if(i > posicion && j <= largodos){
				aux[j] = cadena[i];
				cadena[i] = cadena1[j];
				j++;
			}
			if(i > largoinsercion){
				cadena[i] = aux[k];
				k++;
			}
		}
	}
	printf("La nueva cadena formada es: %s\n", cadena);
	return largoTotal;
}
int copia(char cadena[],char cadena1[],int capacidad){
	int largodos = largo_seguro(cadena1, capacidad);
	int i=0;
	if(largodos>=capacidad){
		largodos= CADENA_SIN_TERMINADOR;
	}
	else{
		for(i=0; i<largodos; i++){
		cadena[i] = cadena1[i];
		}
		cadena[i] = '\0';
		printf("La cadena copiada es: %s \n", cadena);
	}
	return largodos;
}
int limpieza(char cadena[],int capacidad){ 
	int limite = largo_seguro(cadena, capacidad);
	int resulstado;
	for(int i = 0; i <= limite; i++){
		if(cadena[i]>= 48 && cadena[i]<= 57){
		;
		}
		else if(cadena[i]>= 65 && cadena[i]<= 90){
		;	
		}
		else if(cadena[i]>= 97 && cadena[i]<= 122){
		;	
		}
		else{
			int j = 0;
			int aux = i;
			int limitedos = limite - i;
			while(j < limitedos){
				cadena[i]=cadena[i+1];
				j++;
				i++;
			}
			i = aux;
		}
	}
	printf("La cadena limpia es: %s \n", cadena);
	resultado = largo_seguro(cadena, capacidad);
	return resultado;
}

void invertir(char cadena[],int capacidad){ 
	int limite = largo_seguro(cadena, capacidad) /2;
	char aux[MAXIMO];
	int j= largo_seguro(cadena, capacidad)-1;
	for(int i = 0; i<limite;i++){
		aux[i]= cadena[i];
		cadena[i]=cadena[j];
		cadena[j]=aux[i];
		j--;
	}
	printf("La cadena invertida es: %s\n", cadena);
	
}
int comparacion(char cadena[],char cadena1[],int capacidad){
	int largouno= largo_seguro(cadena, capacidad);
	int largodos= largo_seguro(cadena1, capacidad);
	int limite;	
	if (largouno > largodos){
		limite = largouno;
	}
	else{
		limite= largodos;
	}
	for(int i = 0; i<limite;i++){
		if(cadena[i]<cadena1[i]){
			return -1;
		}
		else if(cadena[i]>cadena1[i]){
			return 1;
		}
	}
	return 0;
}
int contador(char cadena[],int capacidad){ 
	int limite = largo_seguro(cadena, capacidad);
	int contador=0;
	for(int i =0; i<=limite; i++){
		if(cadena[i]>= 48 && cadena[i]<= 57){
		contador++;
		}
		else if(cadena[i]>= 65 && cadena[i]<= 90){
		contador++;
		}
		else if(cadena[i]>= 97 && cadena[i]<= 122){
		contador++;
		}
	}
	printf("cadena %s\n", cadena);
	return contador;
}
int contador_c(char cadena[],int capacidad){ 
	int contador_cn = largo_seguro(cadena, capacidad) - contador(cadena, capacidad);
	return contador_cn;
}
void min_a_mayus(char cadena[], int capacidad){ 
	int limite = largo_seguro(cadena, capacidad);
	for(int i = 0; i< limite; i++){
		if(cadena[i]>=65 && cadena[i]<=90){
			cadena[i]=cadena[i]+32;
		}
	}
	printf("%s\n", cadena);
}
int palindromo(char cadena[],int capacidad){ 
	int resultado = TRUE;
	printf("Conversion a minuscula\n");
	min_a_mayus(cadena, capacidad);
	int limite = largo_seguro(cadena, capacidad)/2;
	char cadena_aux[MAXIMO];
	printf("Copio la cadena en una cadena auxiliar nueva: \n");
	copia(cadena_aux,cadena, capacidad);
	printf("Invierto la cadena para la comparacion de palindromo: \n");
	invertir(cadena_aux, capacidad);
	for(int i=0;i<=limite;i++){
		if(cadena[i]==cadena_aux[i]){
			resultado = TRUE;
		}
		else{
			return FALSE;
		}
		
	}
	return resultado;
}
int main(int argc, char *argv[])
{
	int resultado_largo;
	int resultado_insercion;
	int resultado_copia;
	int resultado_limpieza;
	int resultado_comparacion;
	int resultado_contador;
	int resultado_contadorc;
	int resultado_palindromo;
	int seleccion;
	int seleccion1;
	int posicion;
	int capacidad = MAXIMO;
	int argCount= argc -1;
	
	printf("Seleccione entre los %d argumentos para medir el largo: \n", argCount);
	scanf("%d", &seleccion);
	
	printf("--Funcion de largo cadena-- \n");
	resultado_largo = largo_seguro(argv[seleccion], capacidad);
	printf("El largo de la cadena seleccionada es: %d \n", resultado_largo);
	
	printf("--Funcion de insercion-- \n");
	printf("Seleccione entre los %d argumentos para el argumento destino: \n", argCount);
	scanf("%d", &seleccion);
	printf("Seleccione otro argumento para insertar: \n");
	scanf("%d", &seleccion1);
	printf("En que posicion quiere insertar la cadena \n");
	scanf("%d", &posicion);
	resultado_insercion = insercion(argv[seleccion],argv[seleccion1],capacidad, posicion);
	printf("El largo de la cadena formada es de %d \n", resultado_insercion);
	
	printf("Seleccione entre los %d argumentos para el argumento destino: \n", argCount);
	scanf("%d", &seleccion);
	printf("Seleccione otro argumento para copiar: \n");
	scanf("%d", &seleccion1);
	resultado_copia = copia(argv[seleccion],argv[seleccion1],capacidad);
	printf("El largo de la cadena formada es de %d \n", resultado_copia);
	
	printf("Seleccione argumento para limpiar: \n");
	scanf("%d", &seleccion);
	resultado_limpieza = limpieza(argv[seleccion], capacidad);
	printf("El largo del argumento limpio es de: %d\n", resultado_limpieza);
	
	printf("Seleccione argumento para invertir: \n");
	scanf("%d", &seleccion);
	invertir(argv[seleccion], capacidad);
	
	printf("Seleccione entre los %d argumentos para el primer argumento a comparar: \n", argCount);
	scanf("%d", &seleccion);
	printf("Seleccione entre los %d argumentos para el segundo argumento a comparar: \n", argCount);
	scanf("%d", &seleccion1);
	resultado_comparacion = comparacion(argv[seleccion],argv[seleccion1],capacidad);
	printf("Resultado de la comparacion: %d \n", resultado_comparacion);
	
	printf("Seleccione argumento para contar los caracteres: \n");
	scanf("%d", &seleccion);
	resultado_contador = contador(argv[seleccion],capacidad);
	printf("La cantidad de caracteres alfanumericos en el argumento son: %d \n", resultado_contador);
	
	printf("Seleccione argumento para contar los caracteres no alfanumericos: \n");
	scanf("%d", &seleccion);
	resultado_contadorc = contador_c(argv[seleccion],capacidad);
	printf("La cantidad de caracteres no alfanumericos en el argumento son: %d \n", resultado_contadorc);
	
	printf("Seleccione argumento para convertir a minuscula: \n");
	scanf("%d", &seleccion);
	min_a_mayus(argv[seleccion], capacidad);
	
	printf("Seleccione argumento para verificar si es palindromo: \n");
	scanf("%d", &seleccion);
	resultado_palindromo = palindromo(argv[seleccion],capacidad);
	printf(" -2 para TRUE y -3 para FALSE--->El argumento es palindromo?: %d \n", resultado_palindromo);
return 0;
}
