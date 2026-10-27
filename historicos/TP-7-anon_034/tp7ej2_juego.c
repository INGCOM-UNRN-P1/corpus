

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp7ej2-funciones-compartidas.h"

#define MAX_CHAR_NOMBRE_ARCHIVO 20

#define CELDA_OCULTA '#'
#define CELDA_MARCADA 30
#define CELDA_MINA 'X'

int contarMinasMarcadas(Tablero * tablero);

void cargarTablero(Tablero * tablero, char archivo[], bool partidaGuardada)
{
    int ancho;
    int alto;
    int minas;
    char dato_leido;
    short marcas_usadas = 0;

    FILE * archivo_tablero;
    archivo_tablero = fopen(archivo, "r");

    if (archivo_tablero == NULL)
    {
        printf("Error cargando archivo.\n");
        CrearTablero(tablero, 1, 1);
        LimpiarTablero(tablero);
        return;
    }

    fscanf(archivo_tablero, "%d", &ancho);
    fscanf(archivo_tablero, "%d", &alto);
    fscanf(archivo_tablero, "%d", &minas);
    fgetc(archivo_tablero);
    CrearTablero(tablero, ancho, alto);
    LimpiarTablero(tablero);

    for (short i = 0; i < tablero->alto; i++)
    {
        for (short j = 0; j < tablero->ancho; j++)
        {
            dato_leido = fgetc(archivo_tablero);

            if (dato_leido == 'x')
            {
                tablero->celdas[i][j].tieneMina = 1;
            }
            else 
            {
                tablero->celdas[i][j].minasVecinas = dato_leido - 48;
            }
        }

        fgetc(archivo_tablero);
    }

    if (partidaGuardada)
    {
        fgetc(archivo_tablero);

        for (short i = 0; i < tablero->alto; i++)
        {
            for (short j = 0; j < tablero->ancho; j++)
            {
                dato_leido = fgetc(archivo_tablero);

                if (dato_leido == '#')
                {
                    tablero->celdas[i][j].estaRevelado = 0;
                }
                else if (dato_leido == '_')
                {
                    tablero->celdas[i][j].estaRevelado = 1;
                }
                else if (dato_leido == 'M')
                {
                    marcas_usadas++;
                    tablero->celdas[i][j].estaRevelado = 1;
                }
            }

            fgetc(archivo_tablero);
        }
    }

    tablero->marcasUsadas = marcas_usadas;
}

void RevelarTablero(Tablero tablero)
{
    for (short i = 0; i < tablero.alto; i++)
    {
        for (short j = 0; j < tablero.ancho; j++)
        {
            tablero.celdas[i][j].estaRevelado = 1;
        }
    }
}

void Revelar(Tablero * tablero, short x, short y)
{
    if (!DentroDelTablero(*tablero, x, y))
    {
        printf("\nIntentaste revelar una celda fuera de rango\n");
        return;
    }
    if (tablero->celdas[y][x].estaRevelado)
    {
        printf("\nLa celda ya esta revelada!\n");
        return;
    }

    tablero->celdas[y][x].estaRevelado = 1;

    if (tablero->celdas[y][x].tieneMina)
    {
        tablero->estado = ESTADO_PERDIDO;
        return;
    }

    if (tablero->celdas[y][x].minasVecinas > 0)
    {
        return;
    }

    Revelar(tablero, x - 1, y - 1);
    Revelar(tablero, x, y - 1);
    Revelar(tablero, x + 1, y - 1);

    Revelar(tablero, x - 1, y);
    Revelar(tablero, x + 1, y);

    Revelar(tablero, x - 1, y + 1);
    Revelar(tablero, x, y + 1);
    Revelar(tablero, x + 1, y + 1);
}

void MostrarTablero(Tablero tablero)
{
    printf("\nTablero: %d, %d -- Minas: %d\n", tablero.ancho, tablero.alto, tablero.cantidadMinas);

    if (tablero.alto > 9)
    {
        printf(" ");
    }

    for (short j = 0; j < tablero.ancho; j++)
    {
        printf("_");
    }

    printf("\n");

    for (short i = 0; i < tablero.alto; i++)
    {
        if (tablero.alto > 9 && i <= 9)
        {
            printf(" ");
        }
        printf("%d|", i);

        for (short j = 0; j < tablero.ancho; j++)
        {
            if (tablero.celdas[i][j].estaMarcado)
            {
                printf("%c", CELDA_MARCADA);
            }
            else if (!tablero.celdas[i][j].estaRevelado)
            {
                printf("%c", CELDA_OCULTA);
            }
            else if (tablero.celdas[i][j].tieneMina)
            {
                printf("%c", CELDA_MINA);
            }
            else if (tablero.celdas[i][j].minasVecinas > 0)
            {
                printf("%d", tablero.celdas[i][j].minasVecinas);
            }
            else
            {
                printf(" ");
            }
        }

        printf("|\n");
    }
    printf(" ");

    if (tablero.alto > 9)
    {
        printf(" ");
    }

    for (short j = 0; j < tablero.ancho; j++)
    {
        printf("%c", 97 + j);
    }
}

void ChequearVictoria(Tablero * tablero)
{
    if (tablero->marcasUsadas == tablero->cantidadMinas && contarMinasMarcadas(tablero) == tablero->cantidadMinas)
    {
        tablero->estado = ESTADO_GANADO;
    }
}

void MarcarCelda(Tablero * tablero, short x, short y)
{
    if (!DentroDelTablero(*tablero, x, y))
    {
        printf("\nIntentaste marcar fuera del tablero!\n");
        return;
    }

    if (tablero->celdas[y][x].estaRevelado)
    {
        printf("\nIntentaste marcar una celda ya revelada!\n");
        return;
    }

    if (tablero->marcasUsadas >= tablero->cantidadMinas)
    {
        printf("\nAlcanzaste el maximo de marcas simultaneas!\n");
        return;
    }

    if (!tablero->celdas[y][x].estaMarcado)
    {
        tablero->celdas[y][x].estaMarcado = 1;
        tablero->marcasUsadas = tablero->marcasUsadas + 1;
        ChequearVictoria(tablero);
    }
    else
    {
        printf("\nLa celda indicada no esta marcada.\n");
    }
}

void QuitarMarca(Tablero * tablero, short x, short y)
{
    if (!DentroDelTablero(*tablero, x, y))
    {
        printf("\nIntentaste sacar una marca fuera de rango!\n");
        return;
    }

    if (tablero->marcasUsadas <= 0)
    {
        printf("\nNo hay marcas en el tablero!\n");
        return;
    }

    if (tablero->celdas[y][x].estaMarcado)
    {
        tablero->celdas[y][x].estaMarcado = 0;
        tablero->marcasUsadas = tablero->marcasUsadas - 1;
    }
    else
    {
        printf("\nLa celda indicada no esta marcada.\n");
    }
}

int contarMinasMarcadas(Tablero * tablero)
{
    int contador = 0;

    for (short y = 0;  y < tablero->alto; y++)
    {
        for (short x = 0; x < tablero->ancho; x++)
        {
            if (tablero->celdas[y][x].estaMarcado && tablero->celdas[y][x].tieneMina)
            {
                contador++;
            }
        }
    }

    return contador;
}

int MostrarMenuConOpciones()
{
    int resultado;

    printf("\n--- Menu principal ---\n");
    printf("\n1-  Cargar tablero ---\n");
    printf("\n2-  Cargar partida guardada ---\n");
    printf("\nOpcion elegida: ");
    scanf("%d", &resultado);

    return resultado;
}

void IngresarPartidaGuardada(Tablero * tablero)
{
    printf("--- Cargar partida guardada ---\n");
    printf("(Maximo 15 caracteres)\n");
    printf("Nombre de archivo (incluyendo .txt): ");

    char archivo[MAX_CHAR_NOMBRE_ARCHIVO];

    scanf("%s", archivo);
    cargarTablero(tablero,archivo, 1);
}

void IngresarTablero(Tablero * tablero)
{
    getchar();
    printf("\n---  Cargar nuevo tablero ---");
    printf("\n(Maximo 15 caracteres)");
    printf("\nNombre de archivo (incluyendo .txt): ");

    char archivo[MAX_CHAR_NOMBRE_ARCHIVO];
    
    scanf("%s", archivo);
    cargarTablero(tablero,archivo, 0);
}

char MostrarOpcionesGameLoop()
{
    char resultado;

    printf("\n---    Menu de juego    ---");
    printf("\nr- Revelar una celda");
    printf("\nm- Marcar una celda");
    printf("\nn- Quitar una marca");
    printf("\ng- Guardar la partida");
    printf("\nx- Volver al menu principal (se pierde el progreso)");
    printf("\nOpcion elegida: ");
    scanf("%c", &resultado);

    getchar();

    return resultado;
}

void IntentarRevelar(Tablero * tablero)
{
    printf("\n--- Revelar ---\n");

    short x = IngresarColumna(*tablero);
    short y = IngresarFila(*tablero);

    Revelar(tablero, x, y);
}

void IntentarGuardar(Tablero tablero)
{
    printf("\n--- Guardar Partida ---\n");
    printf("\n(Maximo 15 caracteres)");
    printf("\nIngrese nombre de archivo: ");

    char archivo[MAX_CHAR_NOMBRE_ARCHIVO];

    scanf("%s", archivo);
    GuardarTablero(tablero, archivo, 1);
}

void MostrarPantallaPerder()
{
    getchar();
    printf("\n--- Perdiste ---\n");
    printf("Presiona ENTER para volver al menu principal.\n");
    getchar();
}

void IntentarMarcar(Tablero * tablero)
{
    if (tablero->marcasUsadas >= tablero->cantidadMinas)
    {
        printf("\nAlcanzaste el maximo de marcas utilizables!\n");
        return;
    }

    printf("\n--- Marcar celda ---\n");

    short x = IngresarColumna(*tablero);
    short y = IngresarFila(*tablero);

    MarcarCelda(tablero, x, y);
}

void IntentarQuitarMarca(Tablero * tablero)
{
    if (tablero->marcasUsadas <= 0)
    {
        printf("\nNo hay marcas en el tablero!\n");
        return;
    }

    printf("\n--- Quitar marca ---\n");

    short x = IngresarColumna(*tablero);
    short y = IngresarFila(*tablero);

    QuitarMarca(tablero, x, y);
}

void LimpiarMemoria(Tablero tablero)
{
    for (short i = 0; i < tablero.alto; i++)
    {
        free(tablero.celdas[i]);
    }

    free(tablero.celdas);
}

void MostrarPantallaGanar()
{
    getchar();
    printf("\n--- GANASTE ---\n");
    printf("Felicidades! Has ganado la partida.\n");
    printf("Presiona ENTER para volver al menu.\n");
    getchar();
}

int main()
{
    while(true) // loop del menu.
    {
        Tablero tablero;

        int opcion = MostrarMenuConOpciones();
        char salirMenu = 0;

        switch(opcion)
        {
            case 1:
                IngresarTablero(&tablero);
                break;
            case 2:
                IngresarPartidaGuardada(&tablero);
                break;
            default:
                salirMenu = 1;
                break;
        }

        if (salirMenu) break;

        while(true) // loop del juego.
        {
            char salirJuego = 0;
            getchar();

            MostrarTablero(tablero);
            char op = MostrarOpcionesGameLoop();

            switch(op)
            {
                default: break;

                case 'x':
                    salirJuego = 1;
                    break;
                case 'r':
                    IntentarRevelar(&tablero);
                    break;
                case 'm':
                    IntentarMarcar(&tablero);
                    break;
                case 'g':
                    IntentarGuardar(tablero);
                    break;
                case 'n':
                    IntentarQuitarMarca(&tablero);
                    break;
            }

            if (tablero.estado == ESTADO_PERDIDO)
            {
                MostrarPantallaPerder();
                RevelarTablero(tablero);
                MostrarTablero(tablero);
                salirJuego = 1;
                LimpiarMemoria(tablero);
            }
            else if (tablero.estado == ESTADO_GANADO)
            {
                MostrarPantallaGanar();
                RevelarTablero(tablero);
                MostrarTablero(tablero);
                salirJuego = 1;
                LimpiarMemoria(tablero);
            }

            if (salirJuego) break;
        } 

    }

    return 0;
}