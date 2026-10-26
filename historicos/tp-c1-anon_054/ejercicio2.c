

#include <stdio.h>
float convertir_a_centigrados(float farenheit ); //funcion para convertir farenheit a centigrados
float convertir_a_farenheit (float centigrados); // funcion para convertir centigrados a farenheit
float resultado_f= 0; //variable para guardar el resultado de la conversion
float resultado_c = 0;



float  main (float argc, char *argv[])
{
    float centigrados = 0; //variable en la guardo el resultado de la conversion de farenheit a centigrados
    float farenheit = 0; // variable en la que guardo  el resultado de la conversion  de centigrado a farenheit
    float resultado_f = 0;



    printf ("Ingrese una temperatura en grados centigrados : \n");
    scanf("%f",&centigrados);
    resultado_f = convertir_a_farenheit(centigrados);
    printf ("La temperatura en grados farenheit es : %f\n",resultado_f);  

    printf ("Ingrese una temperatura en grados farenheit : \n");
    scanf("%f",&farenheit);
    resultado_c = convertir_a_centigrados(farenheit);
    printf ("La temperatura en grados centigrados es : %f\n",resultado_c);
    return 0;
}

float convertir_a_farenheit(float centigrados)
{

    float resultado_f;
    resultado_f = ((centigrados * 9.0/5.0 )+ 32) ;
    return resultado_f;
}

float convertir_a_centigrados(float farenheit)
{
    float resultado_c;
    resultado_c = (farenheit-32) *(5/9);
    return resultado_c;
}
    
    
