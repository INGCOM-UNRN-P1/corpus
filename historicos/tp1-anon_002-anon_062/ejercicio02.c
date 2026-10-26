



#include <stdio.h>

//  ------------------------------
float convertir_a_fahrrenheit(float centigrados)
{
    float resulta;
    resulta = centigrados * 9/5 + 32;    

    return resulta;
}

//  ---------------------------------
float convertir_a_centigrados(float fahrenheit)
{
    float resulta;
    resulta = (fahrenheit - 32) * 5/9;    

    return resulta;
}


int main ()
{
    float temperatura;
    float convertida;

    printf("Ingrese temperatura en °C: ");		// Texto solicitando datos en pantalla
    scanf("%f",&temperatura);
  
    convertida = convertir_a_fahrrenheit(temperatura);
    printf("La conversion a °F es %f \n", convertida);	// Muestra el resultado en pantalla
    printf("\n");
//-------
    printf("Ingrese la temp en °F: ");			// Texto solicitando datos en pantalla
    scanf("%f",&temperatura);
  
    convertida = convertir_a_centigrados(temperatura); 
    printf("La conversion a °C es %f \n", convertida);  // Muestra el resultado en pantalla

    return 0;
}

