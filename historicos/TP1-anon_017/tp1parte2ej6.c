/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#include <stdlib.h>
#define SEGMENTO 5


int compara_fechas(char *primera, char *segunda);
int separa(char* destino, char* origen,int inicio,int largo);

int main()
{
    char primera[11];
    char segunda[11];
    
    printf("ingrese la primera fecha en formato DD/MM/AAAA: ");
    scanf("%s",&primera);
    
    printf("ingrese la segunda fecha en formato DD/MM/AAAA: ");
    scanf("%s",&segunda);
   
    int resultado=compara_fechas(primera, segunda);
    printf("El resultado de comparar es %d",resultado);
}

int compara_fechas(char *primera, char *segunda)
{
	char fragmento[SEGMENTO];

    separa(fragmento,primera,6,4);
    int añocadena1=atoi(fragmento);
    
    separa(fragmento,segunda,6,4);
    int añocadena2=atoi(fragmento);

    if (añocadena1<añocadena2)
    {
        return -1;
    }
    else if(añocadena1>añocadena2)
    {
        return 1;
    }
    else
    {
        separa(fragmento,primera,3,2);
        int mescadena1=atoi(fragmento);
        
        separa(fragmento,segunda,3,2);
        int mescadena2=atoi(fragmento);
        
        if(mescadena1<mescadena2)
        {
            return -1;
        }
        else if(mescadena1>mescadena2)
        {
            return 1;
        }
        else
        {
            separa(fragmento,primera,0,2);
            int diacadena1=atoi(fragmento);
            
            separa(fragmento,segunda,0,2);
            int diacadena2=atoi(fragmento);
            
            if (diacadena1<diacadena2)
            {
                return -1;
            }
            else if(diacadena1>diacadena2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int separa(char* destino, char* origen,int inicio,int largo)
{
    int i=0;
    for(int contador=inicio;contador<inicio+largo;contador++)
    {
        destino[i]=origen[contador];
        i++;
    }
    destino[i]='\0';
    return i;   
}




