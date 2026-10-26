
#include <stdio.h>

//Funciones declaradas
float centigrados_a_fahrenheit(float centigrados);
float fahrenheit_a_centigrados(float fahrenheit);

int main()
{
    float centigrados = 30;
    float fahrenheit = 90;
    
    //declaramos variables llamando a la funcion 
    float convertidos_a_fahrenheit = centigrados_a_fahrenheit(centigrados);
    printf("%.2f grados centigrados son %.2f grados fahrenheit\n", centigrados, convertidos_a_fahrenheit);
    
    //se declara una nueva variable que llama a la funcion  
    float convertidos_a_centigrados = fahrenheit_a_centigrados(fahrenheit);
    printf("%.2f grados fahrenheit son %.2f grados centigrados\n", fahrenheit, convertidos_a_centigrados);

    return 0;
}
//Funcion que convierte grados centigrados a fahrenheit
float centigrados_a_fahrenheit(float centigrados)
{
    float resultado = (9 * centigrados) / 5 + 32;
    return resultado;
}
// pre: recibe un numero flotante
// pos:retorna la conversion a fahrenheit


//Funcion que convierte grados fahrenheit a centigrados
float fahrenheit_a_centigrados(float fahrenheit)
{
    float resultado = (fahrenheit - 32) * 5 / 9;
    return resultado;
}
//pre: reciben un numero flotante
//pos: retornan la conversion a centigrados 