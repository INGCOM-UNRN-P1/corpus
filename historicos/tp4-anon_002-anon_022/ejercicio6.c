#include <stdio.h>
#define PARAMETROS_INVALIDOS 0
#define INTERCAMBIO 1
#define SIZE 500




/**
 * Intercambia dos caracteres en una cadena de caracteres.
 * @param cadena Cadena de caracteres en la que se realizara el intercambio.
 * @param capacidad_cadena Capacidad maxima de la cadena.
 * @param origen Posicion del primer caracter a intercambiar.
 * @param destino Posicion del segundo caracter a intercambiar.
 * @return 0 si el intercambio se realizo con exito, un valor negativo si hay un error.
 * @pre cadena es una cadena valida, capacidad_cadena es mayor que origen y destino, y origen y destino son indices validos en cadena.
 * @post Los caracteres en las posiciones origen y destino de la cadena han sido intercambiados.
 */


int intercambia(char cadena[], int capacidad_cadena, int origen, int destino)
{
    char temp;
    int resultado;
    if (cadena == NULL || origen < 0 || destino < 0 || origen >= capacidad_cadena || destino >= capacidad_cadena)
    {
        resultado = PARAMETROS_INVALIDOS;
    }
   temp = cadena[origen];
   cadena[origen] = cadena[destino];
   cadena[destino] = temp;
   resultado = INTERCAMBIO;
   return resultado;
}

int main ()
{
    char cadena[SIZE];
    int capacidad;
    int origen;
    int destino;
    printf("Ingrese la cadena: ");
    scanf("%s", cadena);
    printf("La cadena ingresada es: %s\n",cadena);
    printf("Ingrese la posicion del caracter origen: ");
    scanf("%d", &origen);
    printf("Ingrese la posicion del caracter destino: ");
    scanf("%d", &destino);
    intercambia(cadena,capacidad,origen,destino);
    if (intercambia)
    {
        printf("La cadena con los caracteres intercambiados: %s",cadena);
    }
    else
    {
        printf("Caracteres no validos");
    }
    return 0;
}
