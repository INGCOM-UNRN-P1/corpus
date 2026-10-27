
#include <stdio.h>

char* busqueda(char *cadena, int largo, char *busqueda);


int main()
{
   printf("La ubicación del primer caracter de busqueda es: %p\n", busqueda("Hola carlos como estas?", 50, "estas"));
   
   return 0;
}


char* busqueda(char *cadena, int largo, char *busqueda)
{
    

    for (int i = 0; cadena[i] != '\0'; i++) // itera sobre los caracteres de la cadena hasta encontrar uno que coincida con el primer caracter de busqueda
    {
        if (cadena[i] == busqueda[0]) //si algun caracter de cadena coincide con el primero de busqueda
        {
            for (int j = 0; j < largo; j++)
            {
                if (busqueda[j] == '\0')
                {
                    return (&cadena[i]);
                }
                else if (busqueda[j] != cadena[i + j])
                {
                    break;
                }
                
                
            }
        }
    }

    return NULL;
}
