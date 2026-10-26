/*
2. Conversión de temperaturas
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

void conversor(int transformador){
	
	float centigrados_a_fahrenheit;
    float fahrenheit_a_centigrados;
	
	if (transformador == 1 ){
   	printf("Escriba la cantidad de grados celsius a transformar: ");
   	scanf("%f", &centigrados_a_fahrenheit);
   	centigrados_a_fahrenheit = ((centigrados_a_fahrenheit * 1.8) + 32);
   	printf ("El equivalente en grados fahrenheit es: %f", centigrados_a_fahrenheit);
   	
   }else if (transformador == 2 ){
   	
   		printf("Escriba la cantidad de grados fahrenheit a transformar: ");
   		scanf("%f", &fahrenheit_a_centigrados);
   		fahrenheit_a_centigrados = ((fahrenheit_a_centigrados - 32) / 1.8);
   		printf ("El equivalente en grados celsius es: %f", fahrenheit_a_centigrados);	
   		
   }else{
   	
   	printf("Esa opcion no es valida.");
   	
   }
}

int main()
{
   float transformador;
   float centigrados_a_fahrenheit;
   float fahrenheit_a_centigrados;
   
   printf("Si quiere transformar de grados celsius a fahrenheit aprete \"1\", si quiere transformar de grados fahrenheit a celsius aprete \"2\"\n");
   scanf("%f", &transformador);
   
   conversor(transformador);
   
   return 0;
}

//precondicion: se da la opcion de elegir si se quiere transformar de fahrenheit a celsius o viceversa, luego te pide cuantos grados deseas transformar.
//poscondicion: la funcion calcula y muestra en pantalla la conversion de los grados dados.
