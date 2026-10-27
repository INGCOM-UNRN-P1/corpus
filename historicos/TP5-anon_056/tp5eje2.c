 

#include <stdio.h>


#define MAX_LEN 100
#define CADENA_CORTA -1


int largo_cadena(char *cadena, int capacidad_cadena);
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion);
int es_palindromo(char *cadena, int largo);


int largo_cadena(char *cadena, int capacidad_cadena)
{
        int len;
        int i = 0;

        for (len = 0; len < capacidad_cadena; i++)
        {
            if (cadena[i] == '\n' || cadena[i] == '\0')
            {
                break;
            }
            else
            {
                len++;
            }
        }
        return len;
}

int insercion(char *destino, int capacidad_destino, char* insertar, int posicion)
{
        char nuevo_string[MAX_LEN];
        int y = 0;

        if (capacidad_destino < posicion)
        {
            return CADENA_CORTA;
        }
        else
        {
            for (int i = 0; i < capacidad_destino; i++)
            {
                if (i == posicion+1)
                {
                    for (int x = 0; insertar[x] != '\0'; x++)
                    {
                        nuevo_string[y] = insertar[x];
                        y++;
                    }
                }
                
                nuevo_string[y] = destino[i];
                y++;
            }
        }

        destino = nuevo_string;

        return largo_cadena(destino, 50);
	
}

int palindromo(char* cadena, int largo)
{
        int aciertos = 0;
        int x = largo-1;

        for (int i = 0; i < largo; i++)
        {
            if (cadena[i] == cadena[x])
            {
                aciertos++;
            }
            x--;
        }

        if (aciertos == largo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

int main(int argc, char const *argv[])
{
        char string1[MAX_LEN];
        char string2[MAX_LEN];
        int len_string1, len_string2;
        int pos;

        printf("Ingrese primera cadena: ");
        fgets(string1, MAX_LEN, stdin);
        printf("Ingrese segunda cadena: ");
        fgets(string2, MAX_LEN, stdin);
        printf("Ingrese posicion: ");
        scanf("%d", &pos);

        len_string1 = largo_cadena(string1, MAX_LEN);
        len_string2 = largo_cadena(string2, MAX_LEN);

        printf("Largo cadena 1 => %d\n", len_string1);
        printf("Largo cadena 2 => %d\n", len_string2);

        string1[len_string1] = '\0';
        string2[len_string2] = '\0';

        printf("El largo de la cadena %s insertada en %s es de %d\n", string1, string2, insercion(string2, 20, string1, pos));

        if (palindromo(string1, len_string1) == 1)
        {
            printf("%s es palindromo\n", string1);
        }
        else
        {
            printf("%s no es palindromo\n", string1);
        }


        if (palindromo(string2, len_string2) == 1)
        {
            printf("%s es palindromo\n", string2);
        }
        else
        {
            printf("%s no es palindromo\n", string2);
        }
        
        return 0;
}
