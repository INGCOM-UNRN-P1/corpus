

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINA '*'
#define MINA_MARCADA '?'
#define MARCADO '0'

#define CASILLA_CON_MINA -1
#define CASILLA_YA_ELEGIDA -2
#define CASILLA_VACIA -3
#define CASILLA_YA_MARCADA -4




int verificar_casilla(char *tabla, int f, int c, int columnas)
{
    if (tabla[f*columnas+c] == MINA)
    {
        return CASILLA_CON_MINA;
    }
    else if (tabla[f*columnas + c] == MARCADO)
    {
        return CASILLA_YA_ELEGIDA;
    }
    else if (tabla[f*columnas+c] == ' ')
    {
        return CASILLA_VACIA;
    }
    else
    {
        return CASILLA_YA_MARCADA;
    }
    
}

int obtener_minas(char *tabla, int fila, int columna, int filas, int columnas)
{
    int cantidad = 0;

    int primeraFila, primeraColumna;
    int ultimaFila, ultimaColumna;

    if (fila <= 0)
    {
        primeraFila = 0;
    }
    else
    {
        primeraFila = fila - 1;
    }
    if (columna <= 0)
    {
        primeraColumna = 0;
    }
    else
    {
        primeraColumna = columna - 1;
    }

    //
    

    if (fila + 1 >= filas)
    {
        ultimaFila = filas-1;
    }
    else
    {
        ultimaFila = fila+1;
    }
    
    if (columna + 1 >= columnas)
    {
        ultimaColumna = columnas - 1;
    }
    else
    {
        ultimaColumna = columna + 1;
    }
    
    for (int i = primeraFila; i <= ultimaFila; i++)
    {
        for (int x = primeraColumna; x <= ultimaColumna; x++)
        {
            if (tabla[i*columnas+x] == MINA)
            {
                cantidad++;
            }   
        }
    }

    return cantidad;
}



void imprimirBanner()
{
    printf("    ╔══════════════════════════════════════════╗\n");
    printf("    ║ * * * * * * *  BUSCAMINAS   * * * * * * *║\n");
    printf("    ╚══════════════════════════════════════════╝\n");
}

void imprimirLineaTablero(int col)
{
    for (int i = 0; i <= col; i++)
    {
        printf("╬════");
    }
    printf("╬\n");   
}

void imprimircoordenadasFila(int numeroFila)
{
    printf("║ F%d ", numeroFila);
}

void imprimircoordenadasColumna(int columnas)
{
    int i;
    printf("║ -- ");
    for (i = 0; i < columnas; i++)
    {
        printf("║ C%d ", i);
    }
    printf("║");
    putc('\n',stdout);
}

void imprimir(int filas,  int columnas, char tabla[filas][columnas])
{
    printf("\n");
    imprimirLineaTablero(columnas);
    imprimircoordenadasColumna(columnas);
    for(int i = 0; i < filas; i++)
    {
        imprimirLineaTablero(columnas);
        imprimircoordenadasFila(i);
        for(int j=0; j < columnas; j++)
        {
            printf("║ %c  ", tabla[i][j]);
        }
        printf("║");
        putc('\n',stdout);
    }
    imprimirLineaTablero(columnas);
}

void agregar_mina(char *tabla, int f, int c, int columnas)
{
    tabla[f*columnas+c] = MINA;
}

void leer_agregar_minas(char *tabla, int *array, int cantidadMinas, int columnas)
{

    int coordenadasfila, coordenadascolumna;

    int x = 3;
    int j = 1;
    while (j <= cantidadMinas)
    {
        coordenadasfila = array[x];
        coordenadascolumna = array[x+1];
        x = x + 2;
        j++;
        agregar_mina(tabla, coordenadasfila, coordenadascolumna, columnas);
    }
}

void marcar_casilla(char *tabla, int f, int c, int columnas)
{
    if (verificar_casilla(tabla, f, c, columnas) == -3)
    {
        tabla[f*columnas+c] = MINA_MARCADA;
    }
}

void desmarcar_casilla(char *tabla, int f, int c, int columnas)
{
    tabla[f*columnas+c] = ' ';
}

void casillas_adyacentes(char *tablajuego, char* tabla, int f, int c, int filas, int columnas)
{
    int primeraFila, primeraColumna;
    int ultimaFila, ultimaColumna;

    if (f <= filas)
    {
        primeraFila = 0;
    }
    else
    {
        primeraFila = f-1;
    }
    if (c-1 <= columnas)
    {
        primeraColumna = 0;
    }
    else
    {
        primeraColumna = c-1;
    }

    //------------------//

    if (f + 1 >= filas)
    {
        ultimaFila = filas-1;
    }
    else
    {
        ultimaFila = f + 1;
    }

    if (c+1 >= columnas)
    {
        ultimaColumna = columnas-1;
    }
    else
    {
        ultimaColumna = c+1;
    }

    for (int i = primeraFila; i <= ultimaFila; i++)
    {
        for (int x = primeraColumna; x <= ultimaColumna; x++)
        {
            if (obtener_minas(tabla, i, x, filas, columnas) == 0)
            {
                tablajuego[i*columnas+x] = MARCADO;
            }
            
        }
        
    }
}

void abrir_casilla(char *tablaJuego, char *tablero , int f, int c,int filas,  int columnas)
{
    int cantidadDeMinas;

    cantidadDeMinas = obtener_minas(tablero, f, c, filas,  columnas);

    if (cantidadDeMinas == 0)
    {
        casillas_adyacentes(tablaJuego, tablero, f, c, filas, columnas);
    }
    
    cantidadDeMinas = cantidadDeMinas + '0';

    tablaJuego[f*columnas+c] = cantidadDeMinas;
}


int main(int argc, char const *argv[])
{
    FILE *file;

    int filas, columnas;
    
    int array[20];
    char data[5];

    int numero, cantidadMinas;

    int terminarJuego = 0;

    int filaSeleccionada, columnaSeleccionada;

    
    file = fopen("configuracion.txt", "r");
    if (file == NULL || ferror(file))
    {
        printf("El archivo no existe en el directorio! \n");
        return -1;
    }
    else
    {

        //  Se agregan los datos al array
        //  tanto las dimensiones del tablero como la cantidad de minas y sus posiciones
        
        int i = 0;

        while (1)
        {   
            if (fgets(data, 5, file) != NULL)
            {
                numero = atoi(data);
                array[i] = numero;
                i++;
            }
            else
            {
                break;
            }
        }
    }

    fclose(file);

    filas = array[0];
    columnas = array[1];
    cantidadMinas = array[2];

    char tablero[filas][columnas];
    memset(tablero,' ',filas*columnas);
    leer_agregar_minas(*tablero, array, cantidadMinas,columnas);

    
    char tableroJuego[filas][columnas];
    memset(tableroJuego,' ',filas*columnas);

    int verificacion;
    int accion;
    int minasMarcadas = 0;

    imprimirBanner();
    while (terminarJuego == 0)
    {
        imprimir(filas, columnas, tableroJuego);

        printf("\nIngrese numero fila (f): ");
        scanf("%d", &filaSeleccionada);
        printf("Ingrese numero columna (c): ");
        scanf("%d", &columnaSeleccionada);
        printf("Elija accion (0: marcar) (1:desmarcar) (2: abrir): ");
        scanf("%d", &accion);

        if (filaSeleccionada >= filas || columnaSeleccionada >= columnas)
        {
            printf("Coordenadas ingresadas fuera de los limites!\n");
        }
        else
        {
            if (accion == 0)
            {
                verificacion = verificar_casilla(*tablero, filaSeleccionada, columnaSeleccionada, columnas);
                
                if (verificacion == -4)
                {
                    printf("Ya marcaste esa casilla!\n");
                }
                else if (verificacion == -1)
                {
                    minasMarcadas++;
                    if (minasMarcadas == cantidadMinas)
                    {
                        printf("Marcaste todas las minas correctamente!! Ganaste!\n");
                        terminarJuego = 1;
                    }
                }
                marcar_casilla(*tableroJuego, filaSeleccionada, columnaSeleccionada, columnas);
            }
            else if (accion == 1)
            {
                verificacion = verificar_casilla(*tableroJuego, filaSeleccionada, columnaSeleccionada, columnas);

                if (verificacion == -2)
                {
                    printf("No puedes desmarcar esa casilla\n");
                }
                else if (verificacion == -3)
                {
                    printf("\nEsa casilla no esta marcada!\n");
                }
                else
                {
                    desmarcar_casilla(*tableroJuego, filaSeleccionada, columnaSeleccionada, columnas);
                }
            }
            else if (accion == 2)
            {
                verificacion = verificar_casilla(*tablero, filaSeleccionada, columnaSeleccionada, columnas);

                if (verificacion == -1)
                {
                    printf("Oops! La casilla tenia una mina! Perdiste\n");
                    terminarJuego = 1;
                }
                else if (verificacion == -2)
                {
                    printf("Ya habias elegido esa casilla antes\n");
                }
                else if (verificacion == -3)
                {
                    abrir_casilla(*tableroJuego, *tablero ,filaSeleccionada, columnaSeleccionada, filas,  columnas); 
                }
            }
        }
    }
    
    return 0;
}
