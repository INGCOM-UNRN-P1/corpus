

#include <stdio.h>


float convertir_a_fahrenheit(float grados_c);
float convertir_a_centigrados(float grados_f);    
    

int main()
{
	float grados_c;
	float grados_f;
	printf("Ingrese grados_c a convertir: \n");
	scanf("%f", &grados_c);
	grados_f = convertir_a_fahrenheit(grados_c); 
	printf("Resultado en grados fahrenheit:  %.1f \n", grados_f);
	printf("Ingrese grados_f a convertir: \n");
	scanf("%f", &grados_f);
	grados_c = convertir_a_centigrados(grados_f);
	printf("Resultado en grados centigrados:  %.1f \n", grados_c);
 	
	return 0;
}



float convertir_a_fahrenheit(float grados_c)
{
	float grados_f;
	grados_f= (grados_c * 9.0/5.0) + 32;
	return grados_f;
	
}


float convertir_a_centigrados(float grados_f)
{
	float grados_c;
	grados_c = (grados_f - 32)*(5.0/9.0);
	return grados_c;
	
}