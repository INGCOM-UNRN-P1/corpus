

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMS 100


void agregar_numero(int num, int pos, int *array)
{
    if (num > 65536 || num < -65536)
    {
        //no se hace nada porque el numero no comple las condiciones
    }
    else
    {
        array[pos] = num;
    }
}



void suma(int *array, int *res, int pos_inicial, int pos_final, int *bandera)
{
    int suma = 0;

    if (*bandera == 1)
    {
        printf("%d", array[pos_inicial]);
        suma = suma + array[pos_inicial];
        pos_inicial++;
        for (;pos_inicial < pos_final; pos_inicial++)
        {
            suma = suma + array[pos_inicial];
            printf(" + %d", array[pos_inicial]);
        }
        *res = suma;
        *bandera = 0;
    }
    else
    {
        printf("%d + %d", *res, array[pos_inicial]);
        *res = *res + array[pos_inicial];
        pos_inicial++;

        for (;pos_inicial < pos_final; pos_inicial++)
        {
            *res = *res + array[pos_inicial];
            printf(" + %d", array[pos_inicial]);
        }
    }

    printf(" = %d\n",*res);
    
}

void resta(int *array, int *res, int pos_inicial, int pos_final, int *bandera)
{
    int resta = 0;

    if (*bandera == 1)
    {
        printf("%d", array[pos_inicial]);
        resta = resta - array[pos_inicial];
        pos_inicial++;
        for (;pos_inicial < pos_final; pos_inicial++)
        {
            resta = resta - array[pos_inicial];
            printf(" - %d", array[pos_inicial]);
        }
        *res = resta;
        *bandera = 0;
    }
    else
    {
        printf("%d - %d", *res, array[pos_inicial]);
        *res = *res - array[pos_inicial];
        pos_inicial++;

        for (;pos_inicial < pos_final; pos_inicial++)
        {
            *res = *res - array[pos_inicial];
            printf(" - %d", array[pos_inicial]);
        }
    }
    printf(" = %d\n",*res);
    
}

void producto(int *array, int *res, int pos_inicial, int pos_final, int *bandera)
{
    int producto = 1;

    if (*bandera == 1)
    {
        printf("%d", array[pos_inicial]);
        producto = producto * array[pos_inicial];
        pos_inicial++;
        for (;pos_inicial < pos_final; pos_inicial++)
        {
            producto = producto * array[pos_inicial];
            printf(" * %d", array[pos_inicial]);
        }
        *res = producto;
        *bandera = 0;
    }
    else
    {
        printf("%d * %d", *res, array[pos_inicial]);
        *res = *res * array[pos_inicial];
        pos_inicial++;

        for (;pos_inicial < pos_final; pos_inicial++)
        {
            *res = *res * array[pos_inicial];
            printf(" * %d", array[pos_inicial]);
        }
    }
    printf(" = %d\n",*res);
    
}

void division(int *array, int *res, int pos_inicial, int pos_final, int *bandera)
{
    float division = array[pos_inicial];

    if (*bandera == 1)
    {
        printf("%d", array[pos_inicial]);
        pos_inicial++;

        for (;pos_inicial < pos_final; pos_inicial++)
        {
            division = division / array[pos_inicial];
            printf(" / %d", array[pos_inicial]);
        }
        *res = division;
        *bandera = 0;
    }
    else
    {
        printf("%d / %d", *res, array[pos_inicial]);
        *res = *res / array[pos_inicial];
        pos_inicial++;

        for (;pos_inicial < pos_final; pos_inicial++)
        {
            *res = *res / array[pos_inicial];
            printf(" / %d", array[pos_inicial]);
        }
    }
    printf(" = %d\n",*res);
    
}

void promedio(int *array, int *res, int pos_inicial, int pos_final, int *bandera)
{
    int suma = 0;
    int cantidad = 1;

    if (*bandera == 1)
    {
        printf("%d", array[pos_inicial]);
        suma = suma + array[pos_inicial];
        pos_inicial++;
        cantidad++;
        for (;pos_inicial < pos_final; pos_inicial++)
        {
            suma = suma + array[pos_inicial];
            printf(" + %d", array[pos_inicial]);
            cantidad++;
        }
        *res = suma/cantidad;
        *bandera = 0;
    }
    else
    {
        printf("%d + %d", *res, array[pos_inicial]);
        *res = *res + array[pos_inicial];
        pos_inicial++;
        cantidad++;
        for (;pos_inicial < pos_final; pos_inicial++)
        {
            *res = *res + array[pos_inicial];
            printf(" + %d", array[pos_inicial]);
            cantidad++;
        }
        *res = *res/cantidad;
    }

    printf(" / %d = %d\n",cantidad, *res);
}



void read(FILE *archivo, int *array, int *result)
{
    char caracter[10];
    int numero;
    
    int posicion_inicial = 0;
    int posicion_final = 0;
    int valor = 1;

    int booleano = 0;

    int *flag;
    flag = &valor;

    while (1)
    {
        if (fgets(caracter,10, archivo) != NULL)
        {
            
            if (*caracter == '+')
            {
                suma(array, result, posicion_inicial, posicion_final, flag);
                booleano = 0;
                break;
            }
            else if (*caracter == '-')
            {
                resta(array, result, posicion_inicial, posicion_final, flag);
                booleano = 0;
            }

            else if (*caracter == '*')
            {
                producto(array, result, posicion_inicial, posicion_final,flag);
                booleano = 0;
            }

            else if (*caracter == '/')
            {
                division(array, result, posicion_inicial, posicion_final, flag);
                booleano = 0;
            }
            else if (*caracter == 'a')
            {
                promedio(array, result, posicion_inicial, posicion_final, flag);
                booleano = 0;
            }
            else if (*caracter == '=')
            {
                *result = 0;
                *flag = 1;
                booleano = 0;
            }
            

            else
            {
                numero = atoi(caracter);
                    
                if (numero != -38)
                {
                    if (booleano == 0)
                    {
                        posicion_inicial = posicion_final;
                        agregar_numero(numero, posicion_final, array);
                        posicion_final++;
                        booleano = 1;
                    }
                    else
                    {
                        agregar_numero(numero, posicion_final, array);
                        posicion_final++;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    fclose(archivo);
}


int main(int argc, char* argv[])
{
    FILE *file;
    int *lista;

    int *resultado;
    int valor = 0;
    resultado = &valor;

    lista = malloc(MAX_NUMS);

    if (argc > 2)
    {
        printf("Se han ingresado mas de dos argumentos\n");
    }
    if (argc == 1)
    {
        printf("Falta ingresar el archivo .txt!\n");
    }
    else
    {
        file = fopen(argv[1], "r");
        if (file == NULL || ferror(file))
        {
            printf("El archivo no existe en el directorio! \n");
            return -1;
        }
        read(file, lista, resultado);
        free(lista);

    }
    
    return 0;
}

