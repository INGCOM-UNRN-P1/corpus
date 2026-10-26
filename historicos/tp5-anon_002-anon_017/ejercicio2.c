
#include <stdio.h>
#define FILAS 3
#define COLUMNAS 3 
#define MAXIMO 20
#define TRUE 1
#define FALSE 0


void imprime_tablero(char matriz[FILAS][COLUMNAS]);//No paso el tamaño de las filas y columnas por que siembre va a ser 3
int verifica_ganador(char matriz[FILAS][COLUMNAS], char caracter);
int verifica_casilla(char matriz[FILAS][COLUMNAS], int fila, int columna);
void control(char matriz[FILAS][COLUMNAS], char jugador_X[], char jugador_O[]);
void limpia_matriz(char matriz[FILAS][COLUMNAS]);



int main()
{
    char matriz[FILAS][COLUMNAS] = {
        
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
        
        
    };
    
    char jugador_X[MAXIMO];
    char jugador_O[MAXIMO];
    char opcion = 'Y';
    int juega = 0;
    
    
    
    
    printf("Ingrese el nombre del jugador de la X: ");
    fgets(jugador_X, MAXIMO, stdin);
    
    printf("Ingrese el nombre del jugador de la O: ");
    fgets(jugador_O, MAXIMO, stdin);
    
    while(juega == 0)//mientras se quiera jugar.
    {
        control(matriz, jugador_X, jugador_O);//llama a la funcion que controla el juego.
        
        printf("Jugar de nuevo? Y/N: ");
        fflush(stdin);
        scanf("\n%c",&opcion);
        
        if(opcion == 'Y')//Si se quiere jugar, limpia la matriz
        {
            juega = 0;
            limpia_matriz(matriz);//Dejo la matriz solamente con espacios
        }
        else
        {
            juega = 1;//Si no se quiere jugar, sale del bucle.
        }
    }
    

    
 
}





void imprime_tablero(char matriz[FILAS][COLUMNAS])
{
    int recorre_filas = 0;
    int recorre_columnas = 0;
    
    while(recorre_filas < FILAS)//Comparo con constantes por que no cambia el valor
    {
        printf("\n");//Salto para que muestre la otra fila
        
        recorre_columnas = 0;//Esto reinicia el contador de las filas.
        
        while(recorre_columnas < COLUMNAS)//Comparo con constantes por que no cambia el valor
        {
            printf("[%c]",matriz[recorre_filas][recorre_columnas]);
            recorre_columnas++;
        }
        recorre_filas++;
    }
    
    
}




int verifica_ganador(char matriz[FILAS][COLUMNAS], char caracter)
{
    int recorre_filas = 0;
    int recorre_columnas = 0;
    int retorno = FALSE;

    
    while (recorre_filas < FILAS)//Esto comprueba si coincide alguna fila completa
    {
        if(matriz[recorre_filas][0] == caracter && matriz[recorre_filas][1] == caracter && matriz[recorre_filas][2] == caracter)
        {
            retorno = TRUE;
        }
        recorre_filas++;
    }
    
    while (recorre_columnas < COLUMNAS)//Esto ve si hay una columna completa
    {
        if(matriz[0][recorre_columnas] == caracter && matriz[1][recorre_columnas] == caracter && matriz[2][recorre_columnas] == caracter)
        {
            retorno = TRUE;
        }
        recorre_columnas++;
    }
    
    //Este if ve si coincide en diagonal descendente
    if(matriz[0][0] == caracter && matriz[1][1] == caracter && matriz[2][2] == caracter)
    {
        retorno = TRUE;
    }
    else if(matriz[2][0] == caracter && matriz[1][1] == caracter && matriz[0][2] == caracter)//este ve si coincide la diagonal ascendente
    {
        retorno = TRUE;
    }
    
    return retorno;
    
    
}





int verifica_casilla(char matriz[FILAS][COLUMNAS], int fila, int columna)
{
    int retorno = FALSE;
    
    if(((fila > 0 || columna > 0)) || ((fila < 3 || columna < 3 )))//Si la posicion es valida, puede jugar
    {
        if(matriz[fila][columna] == ' ')//Si esta vacia(con un espacio), puede jugar.
        {
            retorno = TRUE;
        }
    }

    return retorno;

    
}




void control(char matriz[FILAS][COLUMNAS], char jugador_X[], char jugador_O[])
{
    int jugadas = 0;
    int validacion_jugada = 0;
    int ganador = FALSE;
    char caracter = 'X';
    int retorno = 0;
    int fila = 0;
    int columna = 0;
    
    while(jugadas < 9 || ganador == FALSE)//Mientras sean posibles los movimientos, y no haya ganador, se puede jugar
    {
        
        imprime_tablero(matriz);
        
        printf("\n");
        
        printf("Ingrese la jugada, jugador: %c: ",caracter);
        scanf("%d %d",&fila, &columna);
        
        validacion_jugada = verifica_casilla(matriz, fila, columna);
        
        if(validacion_jugada == TRUE)//Puede jugar
        {
            
            matriz[fila][columna] = caracter;//Eso pone la ficha en el lugar
            ganador = verifica_ganador(matriz, caracter);//ve si gano alguien
            
        
            if(ganador == TRUE)
            {
                
                if(caracter == 'X')
                {
                    printf("\n\n");
                    printf("Gano la (%c) : %s ", caracter, jugador_X);
                    imprime_tablero(matriz);
                    jugadas = 9; //Para que salga del bucle
                }
                else if(caracter == 'O')
                {
                    printf("\n\n");
                    printf("Gano el (%c) : %s ", caracter, jugador_O);
                    imprime_tablero(matriz);
                    jugadas = 9; //Para que salga del bucle
                }

            }
            else//si no hay ganador, intercambia el que juega
            {
                if(caracter == 'X')
                {
                    caracter = 'O';
                    printf("Es el turno de (%c) %s", caracter, jugador_O);
                }
                else
                {
                    caracter = 'X';
                    printf("Es el turno de (%c) %s", caracter, jugador_X);
                }
                jugadas++;//Si jugo y no hubo ganador, suma moviemientos
            }
            //Si no pudo jugar, sigue en bucle y no suma movimientos.
            
        }
        
        
    }
    
    if(jugadas == 9 && ganador == FALSE)
    {
        printf("EMPATE!");
    }
    
}




void limpia_matriz(char matriz[FILAS][COLUMNAS])
{
    int recorre_filas = 0;
    int recorre_columnas = 0;
    
    while(recorre_filas < FILAS)//Comparo con constantes por que no cambia el valor
    {

        recorre_columnas = 0;//Esto reinicia el contador de las filas.
        
        while(recorre_columnas < COLUMNAS)//Comparo con constantes por que no cambia el valor
        {
            matriz[recorre_filas][recorre_columnas] = ' ';//Eso asigna un espacio a la posicion.
            recorre_columnas++;
        }
        recorre_filas++;
    }
    
}

