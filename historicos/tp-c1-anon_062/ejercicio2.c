

#include <stdio.h>
//  ------------------------------
float convertir_a_fahrrenheit(centigrados)
{
    float resulta;

    resulta = centigrados * 9/5 + 32;    

    return resulta;
}

//  ---------------------------------
float convertir_a_centigrados(fahrenheit)
{
    float resulta;

    resulta = (fahrenheit - 32) * 9/5;    

    return resulta;
}


int main ()
{
    float temperatura;
    float convertida;

    printf("Dame la temperatura en grados centigrados  \n");  // Texto solicitando datos en pantalla
    scanf("%f",&temperatura);
  
    convertida = convertir_a_fahrrenheit(temperatura); 
    printf("La conversion a F es %f", convertida);  // Proyeccion del resultado en pantalla

//-------
    printf("Dame la temperatura en grados fahrenheit  \n");  // Texto solicitando datos en pantalla
    scanf("%f",&temperatura);
  
    convertida = convertir_a_centigrados(temperatura); 
    printf("La conversion a C es %f \n", convertida);  // Proyeccion del resultado en pantalla

    return 0;
}


