
#include <stdio.h>
#include <string.h>
#define DESORDEN 0





int esta_ordenado(int arreglo[], int largo, FILE *archivo);

int main()
{
    
    FILE *archivo;
    archivo = fopen("archivo_numeros.txt","r"); 
    int largo = 0;
    int respuesta = 0;
    
    fscanf(archivo,"%d",&largo); 
    
    fclose(archivo); 
    
    int arreglo[largo];
    
    respuesta = esta_ordenado(arreglo, largo, archivo);
    
    printf("La respuesta es: %d",respuesta);
    
}

int esta_ordenado(int arreglo[], int largo, FILE *archivo)
{
    int contador = 0;
    int contador2 = 0;
    int recorre = 0;
    int recorre2 = 0;
    int posicion = 0; 
    int numero = 0;
    int opcion = 0;
    
    archivo = fopen("archivo_numeros.txt", "r");
    
    
    while ((!feof(archivo)) && (posicion <= largo))
    {
        fflush(stdin);
        fscanf(archivo,"%d", &numero);
        arreglo[posicion] = numero;
        posicion++;
    }
    
    //Sumo a recorre2 para que este una posicion mas adelante que recorre //
    recorre++;
    recorre2++;
    recorre2++;
    
    if (arreglo[recorre] < arreglo[recorre2])
    {
        opcion = 1;
    }
    else  if (arreglo[recorre] > arreglo[recorre2])
    {
        opcion = 2;
    }
    
    printf ("%d\n ",opcion);
    
    if (opcion == 1)
    {
          while (recorre2 <= largo)
        {
            if (arreglo[recorre] < arreglo[recorre2])
            {
                contador++;
                printf ("CONT: %d\n ",contador);
            }
            recorre++;
            recorre2++;
        }  
    }
 
    if (opcion == 2)
    {
        while (recorre2 <= largo)
        {
            if (arreglo[recorre] > arreglo[recorre2])
            {
                contador2++;
            }
            recorre++;
            recorre2++;
        }
    }

    if (contador == largo - 1)
    {
        return 1;
    }
    else if (contador2 == largo - 1)
    { 
        return -1;
    }
    else 
    {
        return DESORDEN;
    }
  
}