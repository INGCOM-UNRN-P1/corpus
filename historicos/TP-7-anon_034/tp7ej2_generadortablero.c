/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * Hanchut - anon_034
 *************************/

#include <stdio.h>
#include <stdlib.h>
#include "tp7ej2-funciones-compartidas.h"

#define MAX_CHAR_NOMBRE_ARCHIVO 20

void ponerMina(Tablero tablero, short x, short y);
void ContabilizarMinas(Tablero * tablero);
void MostrarTableroRevelado(Tablero tablero);

void PonerMina(Tablero tablero, short x, short y)
{
	if (x < tablero.ancho && x >= 0 && y < tablero.alto && y >= 0)
	{
		tablero.celdas[y][x].tieneMina = 1;
	}
}

void ContabilizarMinas(Tablero * tablero)
{
	tablero->cantidadMinas = 0;

	for (short y = 0; y < tablero->alto; y++)
	{
		for (short x = 0; x < tablero->ancho; x++)
		{
			if (tablero->celdas[y][x].tieneMina)
			{
				tablero->cantidadMinas = tablero->cantidadMinas + 1;
				continue;
			}

			short minasVecinas = 0;

			for (short offY = -1; offY < 2; offY++)
			{
				for (short offX = -1; offX < 2; offX++)
				{
					if (x + offX >= 0 && x + offX < tablero->ancho && y + offY >= 0 && y + offY < tablero->alto)
					{
						minasVecinas += tablero->celdas[y + offY][x + offX].tieneMina;
					}
				}
			}

			tablero->celdas[y][x].minasVecinas = minasVecinas;
		}
	}
}

void MostrarTableroRevelado(Tablero tablero)
{
	printf("\nTablero: %d, %d -- Minas: %d\n", tablero.ancho, tablero.alto, tablero.cantidadMinas);

	for (short j = 0; j < tablero.ancho; j++)
	{
		printf("_");
	}

	printf("\n");

	for (short i = 0; i < tablero.alto; i++)
	{
		printf("%d|", i);

		for (short j = 0; j < tablero.ancho; j++)
		{
			if (tablero.celdas[i][j].tieneMina)
			{
				printf("x");
			}
			else
			{
				printf("%d", tablero.celdas[i][j].minasVecinas);
			}
		}

		printf("|\n");	
	}

	printf(" ");

	for (short j = 0; j < tablero.ancho; j++)
	{
		printf("%c", 97 + j);
	}

	printf("\n");
}

void ColocacionDeMinas(Tablero * tablero, short cantidadMinas)
{
	printf("\n\n--- Comienza alocacion de minas. ---");

	for (int i = 0; i < cantidadMinas; i++)
	{
		MostrarTableroRevelado(*tablero);

		char correcto = 0;
		short x, y;

		do
		{
			getchar();
			x = IngresarColumna(*tablero);
			y = IngresarFila(*tablero);

			if (tablero->celdas[y][x].tieneMina)
			{
				printf("No se puede colocar una mina sobre otra.\n");
			}
			else
			{
				correcto = 1;
			}
		}
		while(correcto == 0);

		PonerMina(*tablero, x, y);
		ContabilizarMinas(tablero);
	}
}

int main() 
{
	short w, h, cantidadMinas, opcion;
	char nombreArchivo[MAX_CHAR_NOMBRE_ARCHIVO];

	Tablero tablero;

	printf("\n--- Bienvenido al generador de tableros del buscaminas. ---\n");
	printf("Para comenzar, ingresa el alto (cantidad de filas) del tablero a generar: ");
	scanf("%hd", &h);

	printf("A continuacion, ingrese el ancho (cantidad de columnas) del tablero a generar, (MAXIMO 26): ");
	scanf("%hd", &w); 

	while(w > 26)
	{
		printf("A continuacion, ingrese el ancho (cantidad de columnas) del tablero a generar, (MAXIMO 26): ");
		scanf("%hd", &w); 
	}

	printf("Por ultimo, ingrese la cantidad de minas que desea que sean colocadas: ");
	scanf("%hd", &cantidadMinas);

	CrearTablero(&tablero,w,h);
    LimpiarTablero(&tablero);
    ColocacionDeMinas(&tablero,cantidadMinas);
    ContabilizarMinas(&tablero);

    printf("\n\n--- Tablero generado ---\n");
    MostrarTableroRevelado(tablero);
    printf("\n\n------------------------\n");

    printf("\nOpciones: \n1 - Guardar/Exportar tablero\n2 - Salir\n\nIngrese la opcion elegida: ");
    scanf("%hd", &opcion);

    if (opcion == 1)
    {
    	printf("Ingrese el nombre del archivo de texto a guardar (maximo 15 caracteres, colocar extension .txt): ");
    	scanf("%s", nombreArchivo);
    	GuardarTablero(tablero, nombreArchivo, 0);
    }

	return 0;
}
