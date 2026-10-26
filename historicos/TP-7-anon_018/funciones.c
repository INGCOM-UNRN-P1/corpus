#include <stdio.h>
#include "funciones.h"

int copiar_archivo(int tam, FILE *txt, char matriz[tam][tam])
{
    int res, k, i = 0;
    char caracter;
    if(*matriz == NULL)
    {
        res = 0;
        return res;
    }
    else
    {
        do
        {
            for(k=0;k<tam;k++)
            {
                matriz[i][k] = '\0';
            }
            i++;
        } while (i<tam);
        
        for(i=0;i<=tam;i++)
        {
            for(k=0;k<tam;k++)
            {
                caracter = fgetc(txt);
                if(feof(txt))
                {
                    return 1;
                }
                if(caracter == '\n')
                {
                    matriz[i][k] = '\n';
                    break;
                }
                else
                {
                    matriz[i][k] = caracter;
                }
            }
        }
        res = 1;
    }
    return res;
}

int leer_operaciones(int alto, int ancho, char matriz[alto][ancho])
{
    int i, fin, res, inicio = 0;
    int subtotal = 0;
    int nro_op = 0;
    for(i=0;i<=alto;i++)
    {
        fin = i;
        if(atoi(matriz[i]) == 0)
        {
            if(matriz[i][0] == '+')
            {
                if(fin > inicio)
                {
                    subtotal = suma(inicio, fin-1, ancho, subtotal, matriz);
                    inicio = fin +1;
                    res = 1;
                }
                else
                {
                    res = 0;
                    return res;
                }
            }
            if(matriz[i][0] == '-')
            {
                if(fin > inicio)
                {
                    subtotal = resta(inicio, fin-1, ancho, subtotal, matriz);
                    inicio = fin +1;
                    res = 1;
                }
                else
                {
                    res = 0;
                    return res;
                }
            }
            if(matriz[i][0] == 'a')
            {
                if(fin > inicio)
                {
                    subtotal = promedio(inicio, fin-1, ancho, subtotal, matriz);
                    inicio = fin +1;
                    res = 1;
                }
                else
                {
                    res = 0;
                    return res;
                }
            }
            if(matriz[i][0] == '*')
            {
                if(fin > inicio)
                {
                    subtotal = multiplica(inicio, fin-1, ancho, subtotal, matriz);
                    inicio = fin +1;
                    res = 1;
                }
                else
                {
                    res = 0;
                    return res;
                }
            }
            if(matriz[i][0] == '=')
            {
                nro_op++;
                res = total(nro_op, subtotal);
                subtotal = 0;
                inicio = fin +1;
            }
        }
    }
    return res;
}

int suma(int inicio, int fin, int ancho, int sub,char matriz[fin][ancho])
{
    int resul = sub;
    for(inicio;inicio<=fin;inicio++)
    {
        if(-65536<atoi(matriz[inicio]) && atoi(matriz[inicio])<65536)
        {
            resul += atoi(matriz[inicio]);
        }
    }
    return resul;
}

int resta(int inicio, int fin, int ancho, int sub, char matriz[fin][ancho])
{
    int resul = sub;
    if(resul == 0)
    {
        resul += atoi(matriz[inicio]);
        inicio++;
    }
    for(inicio;inicio<=fin;inicio++)
    {
        if(-65536<atoi(matriz[inicio]) && atoi(matriz[inicio])<65536)
        {
            resul -= atoi(matriz[inicio]);
        }
    }
    return resul;
}

int promedio(int inicio, int fin, int ancho, int sub,char matriz[fin][ancho])
{
    int resul = sub;
    int cant = 0;
    for(inicio;inicio<=fin;inicio++)
    {
        if(-65536<atoi(matriz[inicio]) && atoi(matriz[inicio])<65536)
        {
            cant++;
            resul += atoi(matriz[inicio]);
        }
    }
    resul = resul/cant;
    return resul;
}

int multiplica(int inicio, int fin, int ancho, int sub,char matriz[fin][ancho])
{
    int resul = sub;
    if(resul == 0)
    {
        resul += atoi(matriz[inicio]);
        inicio++;
    }
    for(inicio;inicio<=fin;inicio++)
    {
        if(-65536<atoi(matriz[inicio]) && atoi(matriz[inicio])<65536)
        {
            resul = resul * atoi(matriz[inicio]);
        }
    }
    return resul;
}

int total(int op, int subtotal)
{
    char mensaje[] = "El resultado de la operacion N°";
    if(op == 1)
    {
        FILE *doc = fopen("Resultados.txt", "w");
        if(doc == NULL)
        {
            return 0;
        }
        fprintf(doc, "El resultado de la operacion N°%d es: %d\n", op, subtotal);
        fclose(doc);
    }
    if(op > 1)
    {
        FILE *doc = fopen("Resultados.txt", "a");
        if(doc == NULL)
        {
            return 0;
        }
        fprintf(doc, "El resultado de la operacion N°%d es: %d\n", op, subtotal);
        fclose(doc);
    }
    return 1;
}