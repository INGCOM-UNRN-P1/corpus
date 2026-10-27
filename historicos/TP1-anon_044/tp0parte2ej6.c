
#include <stdio.h>
#include <stdlib.h>

#define LONG 11

int char_to_int(char fecha[LONG], int op)
{
    

    char dia[3],mes[3], anio[5];
    volatile int retorno;
    int i, pos;
    int flag = 0;
    
    for(i = 0; i < LONG; i++)
    {
        if(fecha[i] == '/')
        {
            flag++;
            if(flag == 0)
            {
                dia[i] = '\0';
            }
            else
            {
                mes[i] = '\0';
            }
            pos = i;
            continue;
        }
        if(!flag)
        {
            dia[i] = fecha[i];
        }
        else if(flag == 1)
        {
            mes[i - pos - 1] = fecha[i];
        }
        else
        {
            anio[i - pos -1] = fecha[i];
        }
    }
    
    if(op == 1)
    {
        retorno = atoi(dia);
    }
    else
    {
        if(op == 2)
        {
            retorno = atoi(mes);
        }
        else
        {
            retorno = atoi(anio);
        }
    }
    return retorno;
}

int comparacion(int fecha1[3], int fecha2[3])
{
    volatile int i, retorno;
    if(fecha1[2] > fecha2[2])
    {
        retorno = 1;
    }
    else
    {
        if(fecha1[1] > fecha2[1])
        {
            retorno = 1;
        }
        else
        {
            if(fecha1[0] > fecha2[0])
            {
                retorno = 1;
            }
            else
            {
                if (fecha1[0] == fecha2[0] && fecha1[1] == fecha2[1] && fecha1[2] == fecha2[2])
                {
                    retorno = 0;
                }
                else
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

int main()
{
    char fecha1[LONG], fecha2[LONG];
    char trash;
    int fecha1_int[3], fecha2_int[3];
    volatile int i;

    printf("Ingrese la fecha 1 con el formato dd/mm/aaaa:\n");
    fgets(fecha1, LONG, stdin);
    scanf("%c", &trash);
    printf("Ingrese la fecha 2 con el formato dd/mm/aaaa:\n");
    fgets(fecha2, LONG, stdin);
    scanf("%c", &trash);

    for(i = 1; i < 4; i++)
    {
        fecha1_int[i - 1] = char_to_int(fecha1, i);
        fecha2_int[i - 1] = char_to_int(fecha2, i);
    }


    printf("fecha 1: %d/%d/%d\n", fecha1_int[0], fecha1_int[1], fecha1_int[2]);
    printf("fecha 2: %d/%d/%d\n", fecha2_int[0], fecha2_int[1], fecha2_int[2]);

    printf("Resultado: %d", comparacion(fecha1_int, fecha2_int));

    return 0;
}
