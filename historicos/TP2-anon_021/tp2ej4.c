/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>

#define tamanio 99999

char * cajapiola(int cantidad);

char * asterisc(int cantidad);

char * triangulo(int taman);

int main(int argc, char *argv[])
{
int tamano;

char * unidiscos,* cajap,*rectangulo;

printf("\n ingrese la cantidad de asteriscos que desea : ");

scanf("%d",&tamano);

unidiscos = asterisc(tamano);

printf("\na)\n aqui tiene sus %d asteriscos : \n\n                   %s  \n",tamano,unidiscos);

cajap = cajapiola(tamano);

printf("b)\n\n%s",cajap);

rectangulo = triangulo(tamano);

printf("c)\n\n%s",rectangulo);

return 0;
}

char * asterisc(int cantidad){
	
	char asteriscos[tamanio];
	
	char * final;
	
	for (int i = 0; i < cantidad ; i++){
		
		asteriscos[i] = '*';
		
	}
	
	final = asteriscos;
	
	return final;
}

char * cajapiola(int cantidad){
	
	char caja[tamanio];
	
	char * cajaf;
	
	int contadorV,contadorH, contadorcopia, cantidad2,cantidadbajo;
	
	contadorV = 0;
	
	contadorH = 0;
	
	contadorcopia = 0;
	
	cantidad2 = cantidad;
	
	while (contadorV<cantidad){
		
		cantidadbajo = cantidad2 - 1;
		
		for (int i = contadorcopia; i<cantidad2; i++){
			
			if (contadorH == contadorcopia || contadorH == cantidad - 1){
				
				caja[i] = '*';
				
			}
			else if (i == contadorcopia || i == cantidadbajo){
				
				caja[i] = '*';
				
				
				
			
			}
			else{
				
				caja[i] = ' ';
				
			}
			
		}
		
		
		
		contadorcopia = cantidad2 + 1;
		
		contadorV += 1;
		
		contadorH += 1;
		
		caja[cantidad2] = '\n';
		
		cantidad2 = cantidad2 + cantidad + 1;
		
	}
	
	cajaf = caja;
	
	return cajaf;
}

char * triangulo(int taman){
	
	int forma,formareal, inicio, contadorforma, asteriscos;
	
	char triangulo[tamanio];
	
	char * trianguloR;
	
	contadorforma = 3;
	
	formareal = 1;
	
	forma = 1;
	
	inicio = 0;
	
	asteriscos = 0;
	
	while (formareal <= taman){
	
		for(int i = inicio; i < forma ; i++){

			triangulo[i] = '*';
			
			asteriscos ++;
			
		}
		
		inicio = forma + 1;
		
		triangulo[forma] = '\n';
		
		formareal ++;
		
		forma = forma + contadorforma;

		contadorforma ++;
		
	
	}
	
	for (int i = inicio; i<500; i++){
		
		triangulo[i] = ' ';
		
	}
	
	trianguloR = triangulo;
	
	printf ("astersicos %d",asteriscos);
	
	return trianguloR;
}