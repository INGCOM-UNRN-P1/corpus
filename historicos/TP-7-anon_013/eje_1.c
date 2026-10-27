

#include <stdio.h>
#include <stdlib.h>

int suma(int valores[])
{
    int size = sizeof(valores);
    int suma =0;
    for (int i =0;i<size;i++)
    {
        suma =+valores[i];
    }
    return suma;
}

float promedio(int valores[])
{
    int size = sizeof(valores);
    int suma1;
    suma1 = suma(valores);
    return suma1/size;
}

int resta(int valores[])
{
    int resta1 =0;
    int size = sizeof(valores);
    for (int i =0;i<size;i++)
    {
        resta1 =-valores[i];
    }
    return resta1;
}

int multiplicacion(int valores[])
{
    int multiplicacion1 = 1;
    int size = sizeof(valores);
    for (int i =0;i<size;i++)
    {
        multiplicacion1 = multiplicacion1 * valores[i];
    }
    return multiplicacion1;
}



int main()
{
    FILE * flujo = fopen("datos.txt", "rb"); //abro el archivo.
    if (flujo == NULL){ //esto es por si lee mal el archivo.
        perror("Error en la apertura del archivo");
        return 1;
    }

    char texto[20]; //en esta cadena se almacenará los números a calcular.

    //char cadena[1];
int i = 0;
    while(fgets(texto, sizeof(texto), flujo)){ //con esto voy leyendo los números del archivo.
        //fscanf(flujo, "%c", &texto[i]); //almaceno los números en el arreglo 'numero'.

    printf("%s \n",texto); //me imprime los números con espacios.
    };
    //aun hay problema de que me entrega un número adicional al final. Eso lo arreglaré despues.
    fclose(flujo);

    printf("%s",texto);
    return 0;
}
