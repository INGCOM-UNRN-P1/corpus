

#include <stdio.h>

float centigrados_a_fahrenheit(float centigrados); //Convierte a fahrenheit. Formula : ( X °C × 9/5) + 32 = °F.
float fahrenheit_a_centigrados(float fahrenheit); //Convierte a centigrados. Formula : (X °F − 32) × 5/9 = °C.

//pre: se necesita que se ingrese 1 numero 
//post: se retornara el numero "convertido"
int main()
{
   int opcion = 0; //Guardo la opcion para saber a que funcion se llama.
   float respuesta = 0; //Es donde se va a guardar lo que retorne la funcion.
   float temperatura = 0;
   
   printf("\n");
   printf("--------------------------------------------------------------\n");
   printf("                  Conversion de temperaturas                  \n");
   printf("--------------------------------------------------------------\n");
   printf("\n");
   
   
   printf("Seleccione 1 si quiere convertir de centigrados a fahrenheit.\n");
   printf("Seleccione 2 si quiere convertir de fahrenheit a centigrados.\n");
   printf("Opcion: ");
   scanf("%d",&opcion);//Guarda la opcion en "opcion".
    
   
   if (opcion == 1)//Si la opcion es 1 llama convierte a fahrenheit.
   {
       
       printf("Ingrese la temperatura: ");
       scanf("%f",&temperatura);//Guarda la temperatura en "temperatura".
       
       printf("\n");
       printf("--------------------------------------------------------------\n"); 
       
       respuesta = centigrados_a_fahrenheit(temperatura);//El retorno de la funcion se guarda en "respuesta".
       printf("La temperatura: %f C° equivale a %f F°. ", temperatura, respuesta);// Imprimo la respuesta.
       
       printf("\n");
       printf("--------------------------------------------------------------\n");     
   }
   else if (opcion == 2)//Si la opcion es 2 llama a convierte a centigrados.
   {
       printf("Ingrese la temperatura: ");
       scanf("%f",&temperatura);//Guarda la temperatura en "temperatura".
       
       
       printf("\n");
       printf("--------------------------------------------------------------\n");  
       
       respuesta = fahrenheit_a_centigrados(temperatura);//El retorno de la funcion se guarda en "respuesta".
       printf("La temperatura: %f F° equivale a %f C°. ", temperatura, respuesta);// Imprimo la respuesta.
       
       printf("\n");
       printf("--------------------------------------------------------------\n");    
   }
   else //Si la opcion no es 1 ni 2 sale del programa.
   {
        printf("\n");
        printf("--------------------------------------------------------------\n"); 
        printf("No es una opcion!");
        printf("\n");
        printf("--------------------------------------------------------------\n"); 
   
   }
  
}

//pre: usa el numero ingresado para hacer la ecuacion
//post: retorna el resultado de la ecuacion

float centigrados_a_fahrenheit(float centigrados)
{
    float resultado = 0; //es donde guardo la conversion (en float por los decimales).
    
    resultado = ((centigrados * 9/5) + 32);//Guardo la operacion en resultado.
    
    return resultado; //Retorno el resultado a la funcion que la llamo (main).
       
}

//pre: usa el numero ingresado para hacer la ecuacion
//post: retorna el resultado de la ecuacion

float fahrenheit_a_centigrados(float fahrenheit)
{
    float resultado = 0; //es donde guardo la conversion (en float por los decimales).
    
    resultado = ((fahrenheit - 32) * 5/9);
    
    return resultado;
    
}
