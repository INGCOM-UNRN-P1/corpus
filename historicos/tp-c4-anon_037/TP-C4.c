

#include <stdio.h>

#define CADENA_SIN_TERMINADOR -1
#define MAX_CADENA 12
#define CADENA_LIMITE 17
#define MAX_CADENA_INS 50
#define TRUE 1
#define FALSE 0

int largo_seguro(char cadena[], int capacidad);

int insercion(char destino[], int capacidad, char insertar[], int posicion);

int copia_cadena(char cad_acopiar[], char destino[], int capacidad);

int limpieza(char cadena[], int capacidad);

int inversion(char origen[], char destino[]);

int comparacion(char cad_uno[], char cad_dos[]);

int contador(char cadena[]);

int contador_simbolos(char cadena[]);

int a_minusculas(char cadena[]);

int palindromo(char cadena[]);



int main()
{
    int opcion;
    
    while (1)
    {
        printf("\n\n1. Largo de cadenas\n2. Insercion de cadenas\n3. Copia de cadenas\n4. Limpieza de caracteres\n5. Inversion de caracteres\n6. Comparacion de cadenas\n7. Contador de caracteres\n8. Contador de simbolos\n9. Caracteres a minusculas\n10. Palindromo\n");
        printf("\nSeleccione una opcion -> ");
        scanf("%d", &opcion);
        fflush(stdin);
        
        if (opcion == 1)
        {
            //LARGO DE CADENAS
            int largo;
            char cadena[CADENA_LIMITE];
            
            printf("\n//------------------------LARGO DE CADENAS------------------------//\n\n");
            printf("Ingrese una cadena menor a %d caracteres para saber su longitud -> ", MAX_CADENA);
            scanf("%s", &cadena);

            largo = largo_seguro(cadena, MAX_CADENA);

            printf("El largo de la cadena ingresada (incluyendo el caracter NULL) es %d", largo);
            printf("\n\n//----------------------------------------------------------------//");
        }
        else if (opcion == 2)
        {
            //INSERCION DE CADENAS
            printf("\n//-----------------------INSERCION DE CADENAS------------------------//\n\n");

            char destino[CADENA_LIMITE];
            char insertar[CADENA_LIMITE];
            int capacidad = MAX_CADENA*2;
            int posicion;
            int len_destino;
            int len_insertar;
            int largo_total_cadena;
            
            while (1)
            {
                printf("Se insertara una cadena en otra, la longitud de la nueva cadena no debe ser mayor a %d\n", capacidad);
                printf("Ingrese una cadena destino -> ");
                scanf("%s", &destino);
                len_destino = largo_seguro(destino, MAX_CADENA_INS);

                if(len_destino == -1)
                {
                    printf("Error, cadena muy larga.\n");
                    break;
                }
                
                printf("Ingrese una cadena origen -> ");
                scanf("%s", &insertar);
                len_insertar = largo_seguro(insertar, MAX_CADENA_INS);

                if(len_insertar == -1)
                {
                    printf("Error, cadena muy larga.\n");
                    break;
                }
                
                printf("Ingrese una posicion menor a %d en donde se insertara-> ", len_destino);
                scanf(" %d", &posicion);
                if(posicion >= len_destino)
                {
                    printf("Error.\n");
                    break;
                }
                
                largo_total_cadena = insercion(destino, capacidad, insertar, posicion);
                
                if (largo_total_cadena == -1)
                {
                    printf("Error, cadena demasiado larga.\n");
                    break;
                }
                else
                {
                    printf("\nLa nueva cadena insertada es %s y el largo es %d \n", destino, largo_total_cadena);
                }
                break;
            }
            printf("\n\n//---------------------------------------------------------------//");
        }
        else if (opcion == 3)
        {
            //COPIA DE CADENAS
            printf("\n//------------------------COPIA DE CADENAS------------------------//\n\n");

            char cad_acopiar[CADENA_LIMITE];
            char cad_destino[CADENA_LIMITE];
            int largo;
            
            char destin[19] = "-Destino de copia-";
            
            printf("Ingrese una cadena a copiar -> ");
            scanf(" %s", &cad_acopiar);

            largo = copia_cadena(cad_acopiar, cad_destino, 50);

            printf("\nLa cadena ha sido copiada correctamente: %s", cad_destino);
            printf("\nEl largo total es %d", largo);
            printf("\n\n//----------------------------------------------------------------//");
        }

        else if (opcion == 4)
        {
            //LIMPIEZA DE CADENAS
            printf("\n//------------------------LIMPIEZA DE CADENAS------------------------//\n\n");
            
            char cad_alimpiar[CADENA_LIMITE];
            int largo;
            
            printf("Ingrese una cadena para ser limpiada de caracteres que no sean alfanumericos -> ");
            scanf("%s", &cad_alimpiar);

            largo = limpieza(cad_alimpiar, CADENA_LIMITE);

            printf("\nLa cadena ha sido limpiada, ahora es %s", cad_alimpiar);
            printf("\nEl largo de la cadena es %d", largo);
            printf("\n\n//----------------------------------------------------------------//");
        }
        else if (opcion == 5)
        {
            //INVERSION DE CADENAS
            printf("\n//------------------------INVERSION DE CADENAS------------------------//\n\n");

            char cad_ainvertir[CADENA_LIMITE];
            char destino[CADENA_LIMITE];
            int largo;

            printf("Ingrese una cadena de caracteres para invertirla -> ");
            scanf("%s", &cad_ainvertir);

            largo = inversion(cad_ainvertir, destino);

            printf("\nLa cadena ha sido invertida, ahora es %s", destino);
            printf("\nEl largo de la cadena es %d", largo);
            printf("\n\n//----------------------------------------------------------------//");
        }
        else if (opcion == 6)
        {
            //COMPARADOR DE CADENAS
            printf("\n//------------------------COMPARADOR DE CADENAS------------------------//\n\n");

            char cadena_uno[CADENA_LIMITE];
            char cadena_dos[CADENA_LIMITE];
            int resultado;

            printf("Ingrese una cadena de caracteres -> ");
            scanf("%s", &cadena_uno);

            printf("Ingrese otra para compararlas alfabeticamente -> ");
            scanf("%s", &cadena_dos);

            resultado = comparacion(cadena_uno, cadena_dos);

            printf("\nEl resultado es %d", resultado);
            printf("\n\n//----------------------------------------------------------------//");
        }
        else if (opcion == 7)
        {
            //CONTADOR DE CARACTERES
            printf("\n//------------------------CONTADOR DE CARACTERES------------------------//\n\n");

            char cadena[CADENA_LIMITE];
            int cantidad;
            
            printf("Ingrese una cadena de caracteres con simbolos -> ");
            scanf("%s", &cadena);

            cantidad = contador(cadena);
            printf("\nLa cantidad de caracteres alfanumericos en la cadena son %d", cantidad);
            printf("\n\n//----------------------------------------------------------------//");
        }
        else if (opcion == 8)
        {
            //CONTADOR DE SIMBOLOS
            printf("\n//------------------------CONTADOR DE SIMBOLOS------------------------//\n\n");

            char cadena[CADENA_LIMITE];
            int cantidad;
            
            printf("Ingrese una cadena de caracteres con simbolos -> ");
            scanf("%s", &cadena);

            cantidad = contador_simbolos(cadena);
            printf("\nLa cantidad de simbolos en la cadena son %d", cantidad);
            printf("\n\n//----------------------------------------------------------------//");
        }
        else if (opcion == 9)
        {
            //CARACTERES A MINUSCULAS
            printf("\n//------------------------CARACTERES A MINUSCULAS------------------------//\n\n");

            char cadena[CADENA_LIMITE];
            int largo;
            
            printf("Ingrese una cadena de caracteres -> ");
            scanf("%s", &cadena);

            largo = a_minusculas(cadena);
            printf("\n--Los caracteres en mayuscula se transformaran en minuscula--\n");
            printf("\nLa cadena ahora es %s", cadena);
            printf("\n\n//----------------------------------------------------------------//");
        }
        else if (opcion == 10)
        {
            //PALINDROMO
            printf("\n//------------------------PALINDROMO------------------------//\n\n");

            char cadena[CADENA_LIMITE];
            int resultado;
            
            printf("Ingrese una cadena de caracteres del alfabeto -> ");
            scanf("%s", &cadena);

            resultado = palindromo(cadena);

            if (resultado == 1)
            {
                printf("\nLa cadena es un palindromo");
            }
            else if (resultado == 0)
            {
                printf("\nLa cadena no es un palindromo");
            }
            else
            {
                printf("\nError.");
            }
            printf("\n\n//----------------------------------------------------------------//");
        }
    }
}


int largo_seguro(char cadena[], int capacidad)
{
    int contador = 0;
    
    while (cadena[contador] != '\0')
    {
        contador++;
        
        if (contador > capacidad)
        {
            return -1;
        }
    }

    return contador +1;
}

int insercion(char destino[], int capacidad, char insertar[], int posicion)
{
    int i = 0;
	int j = 0;
	int largo_destino;
	int largo_origen;
	int largo_total;
	int pos = posicion;
	
	largo_destino = largo_seguro(destino, MAX_CADENA_INS);     // CALCULA LARGO DE DESTINO
	largo_origen = largo_seguro(insertar, MAX_CADENA_INS);     // CALCULA LARGO DE ORIGEN
	largo_total = largo_destino + largo_origen -1;             // SUMA LARGOS Y RESTA 1 PORQUE CADA LARGO TIENE UN NULL

	char cadena_destino_auxiliar[largo_total];                 // SE CREA LA CADENA AUXILIAR
    
	if (largo_total > capacidad)
	{
	    return CADENA_SIN_TERMINADOR;
	}
	
    for (i; i < largo_total; i++)
    {
	    if (i < posicion)                                     // TODAVIA NO SE DEBE INSERTAR
		{
		    cadena_destino_auxiliar[i] = destino[i];          // SE COPIA LO QUE VA ANTES DE EMPEZAR A INSERTAR
		}
		
		else if (i >= pos && i < pos + largo_origen -1)          // SE DEBE INSERTAR, YA QUE EL ITERADOR LLEGO A LA POSICION
		{
		    cadena_destino_auxiliar[i] = insertar[j];         // SE INSERTA LA CADENA ORIGEN
			j++;
		}
		
		else
		{
		    cadena_destino_auxiliar[i] = destino[pos];        // SE REANUDA LA INSERCION DE LA CADENA DESTINO
            pos++;			
	    }
    }		
	
    for (i = 0; i < largo_total; i++)
    {
        destino[i] = cadena_destino_auxiliar[i];             // SE TRANSCRIBE LO QUE HAY EN CADENA AUX A CADENA DESTINO
    }
	return largo_total;                                      // SE RETORNA EL LARGO DE LA CADENA
}

int copia_cadena(char cad_acopiar[], char destino[], int capacidad)
{
    int i = 0;
    int largo_total;
    
    while(cad_acopiar[i] != '\0')
    {
        destino[i] = cad_acopiar[i];
        i++;
    }
    
    if (i <= capacidad)
    {
        destino[i] = '\0';
    }
    else
    {
        return CADENA_SIN_TERMINADOR;
    }
    
    largo_total = i+1;
    return largo_total;
}

int limpieza(char cadena[], int capacidad)
{
    int i = 0;
	int j = 0;
	int k;
	int check = 1;

    for (i = 0; i < capacidad; i++)
    {
		if (check == 0)
		{
			i = i-1;
		}

		if (cadena[i] == '\0')
		{
			break;
		}
	
		
		if (cadena[i] == 'A' || cadena[i] == 'B' || cadena[i] == 'C' || cadena[i] == 'D' || cadena[i] == 'E' || cadena[i] == 'F' || cadena[i] == 'G' || cadena[i] == 'H' || cadena[i] == 'I' || cadena[i] == 'J' || cadena[i] == 'K' || cadena[i] == 'L' || cadena[i] == 'M' || cadena[i] == 'N' || cadena[i] == 'O' || cadena[i] == 'P' || cadena[i] == 'Q' || cadena[i] == 'R' || cadena[i] == 'S' || cadena[i] == 'T' || cadena[i] == 'U' || cadena[i] == 'V' || cadena[i] == 'W' || cadena[i] == 'X' || cadena[i] == 'Y' || cadena[i] == 'Z' || cadena[i] == 'a' || cadena[i] == 'b' || cadena[i] == 'c' || cadena[i] == 'd' || cadena[i] == 'e' || cadena[i] == 'f' || cadena[i] == 'g' || cadena[i] == 'h' || cadena[i] == 'i' || cadena[i] == 'j' || cadena[i] == 'k' || cadena[i] == 'l' || cadena[i] == 'm' || cadena[i] == 'n' || cadena[i] == 'o' || cadena[i] == 'p' || cadena[i] == 'q' || cadena[i] == 'r' || cadena[i] == 's' || cadena[i] == 't' || cadena[i] == 'u' || cadena[i] == 'v' || cadena[i] == 'w' || cadena[i] == 'x' || cadena[i] == 'y' || cadena[i] == 'z' || cadena[i] == '1' || cadena[i] == '2' || cadena[i] == '3' || cadena[i] == '4' || cadena[i] == '5' || cadena[i] == '6' || cadena[i] == '7' || cadena[i] == '8' || cadena[i] == '9')
		{
			check = 1;
		}
		else
		{
			j = i+1;
			cadena[i] = cadena[j];
			
			k = j;
			while (cadena[k] != '\0')
			{
				cadena[k] = cadena[k+1];
				k++;
			}
			check = 0;
		}
    }
    return i;
}

int inversion(char origen[], char destino[])
{
    int tope = 0;
    int i = 0;
    int j;
    
    while (origen[tope] != '\0')
    {
        tope++;
    }
    j = tope -1;

    for (i; i < tope; i++)
    {
        destino[i] = origen[j];
        j--;
    }

    destino[tope] = origen[tope];
    return tope+1;
}

int comparacion(char cad_uno[], char cad_dos[])
{
    char abc[27] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int tope;
    int tope_uno = 0;
    int tope_dos = 0;
    int cont = 0;
    int indice_uno;
    int indice_dos;

    while (cad_uno[tope_uno] != '\0')
    {
        tope_uno++;
    }

    while (cad_dos[tope_dos] != '\0')
    {
        tope_dos++;
    }

    if (tope_uno >= tope_dos)
    {
        tope = tope_dos;
    }
    else
    {
        tope = tope_uno;
    }
    

    for (i; i < tope; i++)
    {
        while (abc[cont] != '\0')
        {
            if (cad_uno[i] == abc[cont])
            {
                indice_uno = cont;
                cont = 0;
                break;
            }
            cont++;
        }
        
        while (abc[cont] != '\0')
        {
            if (cad_dos[i] == abc[cont])
            {
                indice_dos = cont;
                cont = 0;
                break;
            }
            cont++;
        }
        
        if (indice_uno < indice_dos)
        {
            return -1;
        }
        else if (indice_uno > indice_dos)
        {
            return 1;
        }
    }
    
    if (indice_uno == indice_dos)
    {
        return 0;
    }
}

int contador(char cadena[])
{
    char abc[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int contador = 0;
    int i = 0;
    int j;

    while (cadena[i] != '\0')
    {
        j = 0;
        while (abc[j] != '\0')
        {
            if (cadena[i] == abc[j])
            {
                contador++;
                break;
            }   
            j++;
        }
        i++;
    }
    return contador;
}

int contador_simbolos(char cadena[])
{
    char abc[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int contador = 0;
    int i = 0;
    int j;

    while (cadena[i] != '\0')
    {
        j = 0;
        while (abc[j] != '\0')
        {
            if (cadena[i] == abc[j])
            {
                contador++;
                break;
            }   
            j++;
        }
        i++;
    }
    return i - contador;
}

int a_minusculas(char cadena[])
{
    char mayusculas[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char minusculas[27] = "abcdefghijklmnopqrstuvwxyz";
    int contador = 0;
    int i = 0;
    int j;

    while (cadena[i] != '\0')
    {
        j = 0;
        while (mayusculas[j] != '\0')
        {
            if (cadena[i] == mayusculas[j])
            {
                cadena[i] = minusculas[j];
                break;
            }   
            j++;
        }
        i++;
    }
    return i;
}

int palindromo(char cadena[])
{
    char mayusculas[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char minusculas[27] = "abcdefghijklmnopqrstuvwxyz";
    
    int tope = 0;
    int mitad;
    int i = 0;
    int k;

    while (cadena[tope] != '\0')
    {
        if (tope == 50)
        {
            return CADENA_SIN_TERMINADOR;
        }
        tope++;
    }
    tope--;
    
    mitad = tope /2;
    
    for (i; i < mitad; i++)
    {
        for (k = 0; k < 27; k++)
        {
            if (cadena[i] == mayusculas[k] || cadena[i] == minusculas[k])
            {
                break;
            }
        }
        
        if (cadena[tope] == mayusculas[k] || cadena[tope] == minusculas[k])
        {
            tope--;
        }
        else
        {
            return FALSE;
        }
    }
    return TRUE;
}