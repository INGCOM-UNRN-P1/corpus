
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARACTERES 150
#define MAX_LINEAS 50
#define CADENA_ERROR -1

void cinta_calculo(FILE *archivo);
int largo_cadena(char *cadena, int capacidad_cadena, char caracter_medicion);
int separar_por_resultados(int largo_total_cadena, char cadena_calculos[MAX_CARACTERES], char cadena_dividida[MAX_LINEAS][MAX_CARACTERES]);
int calculo_resultados(int cantidad_lineas, char calculos_divididos[MAX_LINEAS][MAX_CARACTERES], int resultados[MAX_CARACTERES]);
int suma(int resultado_anterior, int numero[MAX_CARACTERES], int cantidad_numeros);
int resta(int resultado_anterior,int numero[MAX_CARACTERES], int cantidad_numeros);
int multiplicacion(int resultado_anterior, int numero[MAX_CARACTERES], int cantidad_numeros);
int promedio(int resultado_anterior, int numero[MAX_CARACTERES], int cantidad_numeros);

//Función PRINCIPAL
int main(int argc, char *argv[])
{
    char nombre_archivo[MAX_CARACTERES];
    FILE* calculadora;

    printf("Ingrese el nombre del archivo (incluido .txt) : \n");
    scanf("%s", &nombre_archivo);

    calculadora = fopen(nombre_archivo,"r");
    
    if(calculadora != NULL)
    {
        cinta_calculo(calculadora);
    }
    else
    {
        printf("Error al leer archivo");
    }
    return 0;
}

void cinta_calculo(FILE *archivo)
{
    int i;
    int total_caracteres = 0;
    int largo_linea;
    int linea = 0;
    char linea_archivo[MAX_CARACTERES];
    char linea_operacion[MAX_CARACTERES];
    char operaciones_separadas[MAX_LINEAS][MAX_CARACTERES];
    int cantidad_lineas;
    int resultados_cuentas[MAX_CARACTERES];
    int POSIBLE_ERROR;

    while(fgets(linea_archivo, MAX_CARACTERES, archivo) != NULL)
    {
        largo_linea = largo_cadena(linea_archivo, MAX_CARACTERES, '\0');

        for (i = 0 ; i < largo_linea ; i++)
        {
            if (linea_archivo[i] != '\n')
            {
                linea_operacion[total_caracteres] = linea_archivo[i];
                total_caracteres++;
            }
            else
            {
                linea_operacion[total_caracteres] = ' ';
                total_caracteres++;
            }
        }
    }

    largo_linea = largo_cadena(linea_operacion, MAX_CARACTERES, '\0');

    cantidad_lineas = separar_por_resultados(largo_linea, linea_operacion, operaciones_separadas); 

    if(cantidad_lineas > 0)
    {
       POSIBLE_ERROR = calculo_resultados(cantidad_lineas, operaciones_separadas, resultados_cuentas);
    }

    if (POSIBLE_ERROR > 0)
    {
        for ( i = 0; i < cantidad_lineas ; i++)
        {
            printf("\n----------Operacion N %d-----------\n%s %d\n", i, operaciones_separadas[i], resultados_cuentas[i]);
        }
    }
    else
    {
        printf("-------------------------------------\nx-x-ENTRADA DE ARCHIVO NO VALIDA-x-x\n-------------------------------------");
    }

}

int separar_por_resultados(int largo_total_cadena, char cadena_calculos[MAX_CARACTERES], char cadena_dividida[MAX_LINEAS][MAX_CARACTERES])
{
    int espacio_en_blanco = 0;
    int linea = 0;
    int caracter = 0;
    int j = 0;

    //Si la funcion "largo_total_cadena" retorna un valor de error este filtro tambien hará lo devido.
    if (largo_total_cadena > 0)
    {
        //Lazo que permitirá ver cada caracter del texto ingresado.
        while (j < largo_total_cadena)
        {
            

            if(cadena_calculos[j] != '=')
            {
                
                if (espacio_en_blanco == 0)
                {
                    cadena_dividida[linea][caracter] = cadena_calculos[j];
                    caracter++;
                }
                else
                {
                    espacio_en_blanco = 0;
                }
            }
            else
            {
                if (cadena_calculos[j-1] != cadena_calculos[j])
                {
                    cadena_dividida[linea][caracter] = cadena_calculos[j];
                    cadena_dividida[linea][caracter+1] = '\0';
                    linea++;
                    caracter = 0;
                    espacio_en_blanco = 1;
                }
            }
            j++;
        }
        //Retorno para saber la cantidad de lineas en la que se dividió la cadena de texto original.
        return linea;
    }
    else
    {
        //Retorno si hay un caso de error.
        return CADENA_ERROR;
    }
}


int calculo_resultados(int cantidad_lineas, char calculos_divididos[MAX_LINEAS][MAX_CARACTERES], int resultados[MAX_CARACTERES])
{
    int fila = 0;
    int caracter;
    int cant_numeros;
    int largo;
    char numeros_temporales[MAX_CARACTERES];
    int numeros[MAX_CARACTERES];
    int numero_tmp;
    int resultados_operaciones;
    int num_guardados;
    int j;

    //Lazo para ciclar por todas las lineas que llegaron hasta esta función.
    while ( fila < cantidad_lineas)
    {
        //Cantidad de veces que va a ciclar el lazo, esta cantidad es la cantidad de caracteres que tiene la cadena.
        largo = largo_cadena(calculos_divididos[fila],MAX_CARACTERES, '\0');
        //Setear todo en 0 para volver a hacer las cuentas de otra fila.
        cant_numeros = 0;
        num_guardados = 0;
        resultados_operaciones = 0;

        for (caracter = 0; caracter < largo; caracter++)
        {
            //Cuando los caracteres son caracteres de numeros, estos se guardan en una variable temporal hasta que se encuentre un espacio u otro caracter esperado.
            if ((calculos_divididos[fila][caracter] >= 48) && (calculos_divididos[fila][caracter] <= 57))
            {
                if ((calculos_divididos[fila][(caracter)] >= 48) && (calculos_divididos[fila][(caracter)] <= 57)&&(calculos_divididos[fila][(caracter-1)] == '-'))
                {
                    numeros_temporales[cant_numeros] = calculos_divididos[fila][caracter-1];
                    cant_numeros++;
                    numeros_temporales[cant_numeros] = calculos_divididos[fila][caracter];
                    cant_numeros++;
                }
                else if ((calculos_divididos[fila][caracter] >= 48) && (calculos_divididos[fila][caracter] <= 57))
                {
                    numeros_temporales[cant_numeros] = calculos_divididos[fila][caracter];
                    cant_numeros++;
                }
            }
            
            else if ((calculos_divididos[fila][caracter] == ' ') && (cant_numeros > 0))
            {
                sscanf(numeros_temporales, "%d", &numero_tmp);
                if ((numero_tmp < -65536)||(numero_tmp > 65536))
                {
                    return CADENA_ERROR;
                }
                else
                {
                    numeros[num_guardados] = numero_tmp;

                    memset(numeros_temporales, ' ', cant_numeros);

                    num_guardados++;
                    cant_numeros = 0;
                }
            }
            //A partir de este punto es la comparación de caracteres para saber que operaciones realizar con los números convertidos.
            else if (calculos_divididos[fila][caracter] == '+') 
            {
                resultados_operaciones = suma(resultados_operaciones, numeros, num_guardados);

                memset(numeros,' ', num_guardados);

                num_guardados = 0;
            }
            else if (calculos_divididos[fila][caracter] == '-') 
            {
                resultados_operaciones = resta(resultados_operaciones, numeros, num_guardados);

                memset(numeros,' ', num_guardados);

                num_guardados = 0;
            }
            else if (calculos_divididos[fila][caracter] == '*') 
            {
                resultados_operaciones = multiplicacion(resultados_operaciones, numeros, num_guardados);

                memset(numeros,' ', num_guardados);

                num_guardados = 0;
            }
            else if (calculos_divididos[fila][caracter] == 'a') 
            {
                resultados_operaciones = promedio(resultados_operaciones, numeros, num_guardados);

                memset(numeros, ' ', num_guardados);

                num_guardados = 0;
            }
            //El resultado de las operaciones es almacenado en una variable, la cual va acorde con su fila.
            else if (calculos_divididos[fila][caracter] == '=') 
            {
                num_guardados = 0;
                cant_numeros = 0;

                resultados[fila] = resultados_operaciones;
            }
        }
        fila++;
    }
}

int largo_cadena(char *cadena, int capacidad_cadena, char caracter_medicion)
{
    int i = 0;
    
    while (cadena[i] != caracter_medicion)
    {
        if (i <= capacidad_cadena)
        {
            i++;
        }
        else
        {
            return CADENA_ERROR;
        }
    }
    return i;
}


int suma(int resultado_anterior, int numeros[MAX_CARACTERES], int cantidad_numeros)
{
    int i;
    int resultado = resultado_anterior;

    for(i = 0; i < cantidad_numeros; i++)
    {
        resultado = resultado + numeros[i];
    }
    return resultado;
}

int resta(int resultado_anterior, int numeros[MAX_CARACTERES], int cantidad_numeros)
{
    int i;
    int resultado = resultado_anterior;
    
    for(i = 0; i < cantidad_numeros; i++)
    {
        resultado = resultado - numeros[i];
    }

    return resultado;
}

int multiplicacion(int resultado_anterior, int numeros[MAX_CARACTERES], int cantidad_numeros)
{
    int i;
    int resultado = resultado_anterior;

    for(i = 0; i < cantidad_numeros; i++)
    {
        resultado = resultado * numeros[i];
    }
    return resultado;
}

int promedio(int resultado_anterior, int numeros[MAX_CARACTERES], int cantidad_numeros)
{
    int i;
    int resultado = resultado_anterior;
    float promedio = 0;

    for(i = 0; i < cantidad_numeros; i++)
    {
        resultado = resultado + numeros[i];
    }

    cantidad_numeros++;
    promedio = resultado / cantidad_numeros;

    return promedio;
}