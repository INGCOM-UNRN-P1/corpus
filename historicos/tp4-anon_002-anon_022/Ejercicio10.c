#include<stdio.h>
#define SIZE 500





/**
 * Reemplaza todas las vocales en una cadena de caracteres con un carácter especificado.
 * @param cadena Cadena de caracteres en la que se reemplazarán las vocales.
 * @param longitud Longitud de la cadena.
 * @param caracter Carácter con el cual se reemplazarán las vocales.
 * @pre cadena es una cadena válida, longitud es mayor o igual a cero.
 * @post Las vocales en la cadena han sido reemplazadas con el carácter especificado.
 */
void reemplaza_vocales (char* cadena, int longitud, char caracter)
{
    int i=0;
    for (i;i<longitud;i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o'|| cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] =='I' || cadena[i] == 'O' || cadena[i] == 'U')
        {
            cadena[i] = caracter;
        }
    }
}


int main()
{
    char cadena[SIZE];
    int longitud;
    char caracter;
    printf("Ingrese la longitud");
    scanf("%d", &longitud);
    printf("Ingresé la cadena: "); 
    scanf("%s", cadena);
    printf("Ingresé el caracter a reemplazar: ");
    scanf(" %c", &caracter);
    reemplaza_vocales(cadena, longitud, caracter);
    printf("Cadena con vocales reemplazadas: %s",cadena);
    return 0; 
}
