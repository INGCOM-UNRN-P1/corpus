

#include <stdio.h>

#define LARGO 100
#define TRUE 1
#define FALSE 0

int es_palindromo(char texto[], int largo);
int definir(int resultado);

int main()
{
    char cadena[LARGO];
    int resultado, i, largo;
    largo = 0;

    printf("Digite una palabra o frase (sin usar espacios) para saber si es palindromo: ");
    fgets(cadena, LARGO, stdin);
    for (i = 0; i < LARGO; i++)
    {
        if (cadena[i] != '\0')
        {
            largo = largo + 1;
        }
    }

    resultado = es_palindromo(cadena, largo);
    definir(resultado);

    return 0;
}

int es_palindromo(char cadena[], int largo)
{
    int i, contador, coincidencias;
    char cadena2[LARGO];
    contador = 0;
    coincidencias = 0;

    for (i = 0; i < largo; i++)
    {
        contador = contador + 1;
        
        switch (cadena[i])
        {
        case 'A':
            cadena2[i] = 'a';
            break;
        case 'B':
            cadena2[i] = 'b';
            break;
        case 'C':
            cadena2[i] = 'c';
            break;
        case 'D':
            cadena2[i] = 'd';
            break;
        case 'E':
            cadena2[i] = 'e';
            break;
        case 'F':
            cadena2[i] = 'f';
            break;
        case 'G':
            cadena2[i] = 'g';
            break;
        case 'H':
            cadena2[i] = 'h';
            break;
        case 'I':
            cadena2[i] = 'i';
            break;
        case 'J':
            cadena2[i] = 'j';
        case 'K':
            cadena2[i] = 'k';
            break;
        case 'L':
            cadena2[i] = 'l';
            break;
        case 'M':
            cadena2[i] = 'm';
            break;
        case 'N':
            cadena2[i] = 'n';
            break;
        case 'O':
            cadena2[i] = 'o';
            break;
        case 'P':
            cadena2[i] = 'p';
            break;
        case 'Q':
            cadena2[i] = 'q';
            break;
        case 'R':
            cadena2[i] = 'r';
            break;
        case 'S':
            cadena2[i] = 's';
            break;
        case 'T':
            cadena2[i] = 't';
            break;
        case 'U':
            cadena2[i] = 'u';
            break;
        case 'V':
            cadena2[i] = 'v';
            break;
        case 'W':
            cadena2[i] = 'w';
            break;
        case 'X':
            cadena2[i] = 'x';
            break;
        case 'Y':
            cadena2[i] = 'y';
            break;
        case 'Z':
            cadena2[i] = 'z';
            break;
        default:
            cadena2[i] = cadena[i];
        }
    }
    
    for ( i = 0; i < contador -1 ; i++)
    {
        //printf("%c----%c\n",cadena2[(contador -2) - i], cadena2[i]); 
        if (cadena2[(contador -2) - i] == cadena2[i] ) //esquivamos comparar el \n final de las lineas
        {
            coincidencias = coincidencias + 1;
        }
        else
        {
            continue;
        }
        
    }
    
    //printf("coincidencias: %d\n",coincidencias);
    if (coincidencias == contador -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


int definir(int resultado)
{
	if(resultado == 1)
	{
		printf("Es palindromo\n");
	}
	else 
	{
		printf("No es palindromo\n");
	}
}