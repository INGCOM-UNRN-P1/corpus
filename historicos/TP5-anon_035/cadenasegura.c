

#include <stdio.h>

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int contador=0, i;
    char vector[capacidad_cadena];
    vector[capacidad_cadena] = *cadena;
    
    for(i=0; i<=capacidad_cadena; i++)
    {
        if(vector[i] != 0 || vector[i] != '\0')
        {
            contador++;
        }


    }        
        
 return contador;   
}






int main(int argc, char *argv[])
{
    int capacidad_cadena = 20;
    char cadena[capacidad_cadena] = "hola";
    int largo;
    
    largo = largo_cadena(char *cadena, int capacidad_cadena);
    printf("el largo de la cadena es: %d", largo);
}