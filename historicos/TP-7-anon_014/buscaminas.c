

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLEAR() system("CLS")

void jugar_partida_nueva(int minas, int filas, int columnas, char **mapa_base, char **tablero);
void rellenar_mapa_base(int filas, int columnas, char **tablero);
void colocar_contadores(int filas, int columnas, char **tablero);
void colocar_minas(int filas, int columnas, int minas, char **tablero);
void rellenar_mapa_base(int filas, int columnas, char **tablero);
void jugar_partida_nueva(int minas, int filas,int columnas, char **mapa_base, char **tablero);
void rellenar_mapa_base(int filas, int columnas, char **tablero);
void colocar_minas(int filas, int columnas, int minas, char **tablero);
void colocar_contadores(int filas, int columnas, char **tablero);
void imprimir_mapa(int filas, int columnas, char **tablero);
void guardar_mapa(int filas, int columnas, char **tablero_base);
int mostrar_campo(int filas, int columnas, int posf, int posc, char **mapa_base, char **tablero);
void imprimir_minas(int filas, int  columnas, char **mapa_base, char **tablero);
void juego_perdido(int filas, int columnas, char **tablero);
int poner_bandera(int posc, int posf, int filas, int columnas, char **tablero);
int revisar_partida(int minas, int filas, int columnas, char **tablero, char**mapa_base);
void copia_mapa_ganador(int filas, int columnas, char **tablero, char**mapa_base);
void juego_ganado(int filas, int columnas, char **tablero);
int quitar_bandera(int posf, int posc, int filas, int columnas, char **tablero);

int main(int argc, char* argv[])
{
    int entrada;
    do
    {
        CLEAR();
        printf("\n");
        printf("\n\n\t\t[1] JUGAR.");
        printf("\n\t\t[2] Salir.\n");
        printf("\t\t Ingrese una opcion: ");
        scanf("%d", &entrada);

        switch (entrada)
        {
        case 1:
            srand(time(NULL));
            CLEAR();
            int filas, columnas, totalminas;
            printf("\nIngrese un valor para las Filas y Columnas del mapa a crear.\n");
            printf("Limite de Columnas: de 4 a 26\n");
            printf("Limite de Filas: de 2 a 9\n");
            printf("Cuantas Columnas tendra? ");
            scanf("%d", &columnas);
            while (columnas>26 || columnas<4)
            {
                printf("El valor no es correcto, debe estar entre 4 y 26.\n");
                printf("Ingrese el valor de Columnas nuevamente: ");
                scanf("%d", &columnas);
            }
            printf("Y cuantas Filas? ");
            scanf("%d", &filas);
            while (filas>9 || filas<2)
            {
                printf("El valor no es correcto, debe estar entre 2 y 9.\n");
                printf("Ingrese el valor de Filas nuevamente: ");
                scanf("%d", &filas);
            }
            totalminas = (filas*columnas)/7;
            char **mapa_base;
            mapa_base = (char **) malloc(sizeof(char*)*filas);
            for(int i=0;i<filas;i++)
            {
                mapa_base[i] = (char *) malloc(sizeof(char)*columnas);
            }
            if(mapa_base == NULL)
            {
                printf("No se a podido reservar espacio en memoria.\n");
                return 0;
            }

            char **tablero;
            tablero = (char **) malloc(sizeof(char*)*filas);
            for(int i=0;i<filas;i++)
            {
                tablero[i] = (char *) malloc(sizeof(char)*columnas);
            }
            if(tablero == NULL)
            {
                printf("No se a podido reservar espacio en memoria.\n");
                return 0;
            }
            for(int i=0;i<filas;i++)
            {
                for(int j=0;j<columnas;j++)
                {
                    tablero[i][j] = '/';
                }

            }
            printf("\nSe crearan %d minas de forma aleatoria.\n", totalminas);

            rellenar_mapa_base(filas, columnas, mapa_base);

            colocar_minas(filas, columnas, totalminas, mapa_base);
            printf("Las minas se crearon correctamente\n");
            colocar_contadores(filas, columnas, mapa_base);
            guardar_mapa(filas, columnas,tablero);
            jugar_partida_nueva(totalminas, filas, columnas, mapa_base, tablero);

            free(mapa_base);
            free(tablero);
            break;
        default:
            break;
        }

    } while(entrada !=2);
    CLEAR();
    return 0;
}

void colocar_contadores(int filas, int columnas, char **tablero)
{
    int i, j, k, l, cont;
    int x = filas-1;
    int y = columnas-1;
    for(i=1;i<x;i++)//centro del tablero
    {
        for(j=1;j<y;j++)
        {
            if(tablero[i][j] != 88)
            {
                cont = 48;
                for(k=-1;k<=1;k++)
                {
                    for(l=-1;l<=1;l++)
                    {
                        if(tablero[i+k][j+l] == 88)
                        {
                            cont++;
                        }
                    }
                }
                tablero[i][j] = cont;
            }
        }
    }
    if(tablero[0][0] != 88)//esquina superior izquierda
    {
        cont = 48;
        for(k=0;k<=1;k++)
        {
            for(l=0;l<=1;l++)
            {
                if(tablero[k][l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[0][0] = cont;
    }
    if(tablero[x][0] != 88)//esquina inferior izquierda
    {
        cont = 48;
        for(k=-1;k<=0;k++)
        {
            for(l=0;l<=1;l++)
            {
                if(tablero[x+k][l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[x][0] = cont;
    }
    if(tablero[0][y] != 88)//esquina superior derecha
    {
        cont = 48;
        for(k=0;k<=1;k++)
        {
            for(l=-1;l<=0;l++)
            {
                if(tablero[k][y+l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[0][y] = cont;
    }
    if(tablero[x][y] != 88)//esquina inferior derecha
    {
        cont = 48;
        for(k=-1;k<=0;k++)
        {
            for(l=-1;l<=0;l++)
            {
                if(tablero[x+k][y+l] == 88)
                {
                    cont++;
                }
            }
        }
        tablero[x][y] = cont;
    }
    for(j=1;j<y;j++)//barra superior
    {
        i=0;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=0;k<=1;k++)
            {
                for(l=-1;l<=1;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }
    for(j=1;j<y;j++)//barra superior
    {
        i=x;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=-1;k<=0;k++)
            {
                for(l=-1;l<=1;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }
    for(i=1;i<x;i++)//barra ixquierda
    {
        j=0;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=-1;k<=1;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }
    for(i=1;i<x;i++)//barra derecha
    {
        j=y;
        if(tablero[i][j] != 88)
        {
            cont = 48;
            for(k=-1;k<=1;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(tablero[i+k][j+l] == 88)
                    {
                        cont++;
                    }
                }
            }
            tablero[i][j] = cont;
        }
    }



    for(i=0;i<filas;i++)//poner espacios en los lugares lejanos a las minas
    {
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] == 48)
            {
                tablero[i][j] = ' ';
            }
        }

    }
}

void colocar_minas(int filas, int columnas, int minas, char **tablero)
{
    int posx, posy, i = 0;
    do
    {
        i++;
        posx = 0 + rand() % (filas);
        posy = 0 + rand() % (columnas);
        if(tablero[posx][posy] == 'X')
        {
            i--;
        }
        else
        {
            tablero[posx][posy] = 'X';
        }

    }while(i<minas);
}

void rellenar_mapa_base(int filas, int columnas, char **tablero)
{
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            tablero[i][j] = '0';
        }

    }
}

void jugar_partida_nueva(int minas, int filas,int columnas, char **mapa_base, char **tablero)
{

    int posc, posf, op, perdio = 0;
    char col;
    int cantbanderas = minas;
    int gano = 0;
    int banderacolocada = 0;
    do
    {
        CLEAR();
        printf("\tTotal de minas: %d\tTotal de Banderas: %d\n", minas, cantbanderas);

        imprimir_mapa(filas, columnas, tablero);
        printf("\n\t[1] Jugar Turno.\t[2] Poner Bandera.\t[3] Quitar Bandera.\n");
        printf("\t\t[4] Salir.\n");
        printf("\t\t\tIngrese Opcion: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\tPara jugar debe escribir la FILA y luego la COLUMNA.\n");
            printf("\tFILA: ");
            scanf("%d", &posf);
            if(posf<1 || posf>filas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            posf -= 1;
            printf("\tCOLUMNA: ");
            scanf("%c", &col);
            scanf("%c", &col);
            if(col >= 97)
            {
                posc = col;
                posc -= 97;
            }
            else
            {
                posc = col;
                posc -= 65;
            }
            if(posc<0 || posc >=columnas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            perdio = mostrar_campo(filas, columnas, posf, posc, mapa_base, tablero);
            if(perdio == 1)
            {
                imprimir_minas(filas, columnas, mapa_base, tablero);
                juego_perdido(filas, columnas, tablero);
                rellenar_mapa_base(filas, columnas, mapa_base);
                colocar_minas(filas, columnas, minas, mapa_base);
                colocar_contadores(filas, columnas, mapa_base);
                perdio = 0;
            }
            break;
        case 2:
            if(cantbanderas == 0)
            {
                printf("No hay mas bandera para colocar!.\n");
                system("pause");
                break;
            }
            printf("\tPara colocar una bandera debe escribir FILA y COLUMNA.\n");
            printf("\tEjemplo->\tFILA: 2\tCOLUMNA: C\n\n");
            printf("\tFILA: ");
            scanf("%d", &posf);
            if(posf<1 || posf>filas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            posf -= 1;
            printf("\tCOLUMNA: ");
            scanf("%c", &col);
            scanf("%c", &col);
            if(col >= 97)
            {
                posc = col;
                posc -= 97;
            }
            else
            {
                posc = col;
                posc -= 65;
            }
            if(posc<0 || posc >=columnas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            banderacolocada = poner_bandera(posc, posf, filas, columnas, tablero);
            if(banderacolocada == 1)
            {
                cantbanderas -= 1;
                gano = revisar_partida(minas, filas, columnas, tablero, mapa_base);
                if(gano == 1)
                {
                    copia_mapa_ganador(filas, columnas, tablero, mapa_base);
                    juego_ganado(filas, columnas, tablero);
                    rellenar_mapa_base(filas, columnas, mapa_base);
                    colocar_minas(filas, columnas, minas, mapa_base);
                    colocar_contadores(filas, columnas, mapa_base);
                }
                break;
            }
            else
            {
                printf("No se puede colocar una bandera en esa posicion.\n");
                system("pause");
                break;
            }
        case 3:
            if(cantbanderas == minas)
            {
                printf("No hay banderas para quitar!!!\n");
                system("pause");
                break;
            }
            printf("\tPara quitar una bandera debe escribir FILA y COLUMNA.\n");
            printf("\tEjemplo->\tFILA: 2\tCOLUMNA: C\n\n");
            printf("\tFILA: ");
            scanf("%d", &posf);
            if(posf<1 || posf>filas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            posf -= 1;
            printf("\tCOLUMNA: ");
            scanf("%c", &col);
            scanf("%c", &col);
            if(col >= 97)
            {
                posc = col;
                posc -= 97;
            }
            else
            {
                posc = col;
                posc -= 65;
            }
            if(posc<0 || posc >=columnas)
            {
                printf("Esa posisicon no existe, intente otra vez.\n");
                system("pause");
                break;
            }
            int banderaquitada = quitar_bandera(posf, posc, filas, columnas, tablero);
            if(banderaquitada == 0)
            {
                printf("No hay una bandera para quitar en esa posicion.\n");
                system("pause");
                break;
            }
            cantbanderas++;
            break;
        default:
            break;
        }
    } while(op != 4);

    if(op == 4)
    {
        for(int i=0;i<filas;i++)
        {
            for(int j=0;j<columnas;j++)
            {
                tablero[i][j] = '/';
            }
        }
    }

}


void imprimir_mapa(int filas, int columnas, char **tablero)
{
    int i, j;
    char letra = 'A';
    int largo = filas*columnas;
    printf("\n    ");
    for(i=0;i<columnas;i++)
    {
        printf(" %c  ", letra+i);
    }
    printf("\n   %c",201);
    for(i=0;i<columnas;i++)
    {
        printf("%c%c%c%c",205,205,205,203);
    }
    printf("\b%c\n",187);
    for(i=0;i<filas-1;i++)
    {
        printf("  %d%c", i+1, 186);
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] == 47)
            {
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] == 32)
            {
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] == 88)
            {
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] == 80)
            {
                printf(" %c", tablero[i][j]);
            }
            if(tablero[i][j] >= 49 && tablero[i][j] <= 57)
            {
                printf(" %c", tablero[i][j]);
            }

            printf(" %c", 186);
        }
        printf("\n   %c", 204);
        for(j=0;j<columnas-1;j++)
        {
            printf("%c%c%c%c",205,205,205,206);
        }
        printf("%c%c%c%c\n",205,205,205,185);
    }

    printf("  %d%c", i+1, 186);
    for(j=0;j<columnas;j++)
    {
        if(tablero[i][j] == 47)
        {
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] == 32)
        {
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] == 88)
        {
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] == 80)
        {
            printf(" %c", tablero[i][j]);
        }
        if(tablero[i][j] >= 49 && tablero[i][j] <= 57)
        {
            printf(" %c", tablero[i][j]);
        }
        printf(" %c", 186);
    }
    printf("\n   %c", 200);
    for(j=0;j<columnas-1;j++)
        {
            printf("%c%c%c%c",205,205,205,202);
        }
        printf("%c%c%c%c\n",205,205,205,188);
}

void guardar_mapa(int filas, int columnas, char **tablero_base)
{
    int i, j;
    FILE *mapa;
    mapa = fopen("mapagenerado.txt", "w");

    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            fprintf(mapa, "%c", tablero_base[i][j]);
        }
        if(i<filas-1)
        {
            fprintf(mapa, "\n");
        }

    }
    fclose(mapa);

}

int mostrar_campo(int filas, int columnas, int posf, int posc, char **mapa_base, char **tablero)
{
    int res, i, j, k, l;
    if(mapa_base[posf][posc] == 'X')
    {
        res = 1;
        return res;
    }

    if(posc == 0)
    {
        if(posf == 0)
        {
            for(k=0;k<=1;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(mapa_base[k][l] != 88)
                    {
                        tablero[k][l] = mapa_base[k][l];
                    }
                }
            }
            res = 0;
            return res;
        }
        else if(posf == filas-1)
        {
            for(k=-1;k<=0;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(mapa_base[(filas-1)+k][l] != 88)
                    {
                        tablero[(filas-1)+k][l] = mapa_base[(filas-1)+k][l];
                    }
                }
            }
        }
        else
        {
            for(k=-1;k<=1;k++)
            {
                for(l=0;l<=1;l++)
                {
                    if(mapa_base[posf+k][l] != 88)
                    {
                        tablero[posf+k][l] = mapa_base[posf+k][l];
                    }
                }
            }
        }
    }
    else if(posc == columnas-1)
    {
        if(posf == 0)
        {
            for(k=0;k<=1;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(mapa_base[k][posc+l] != 88)
                    {
                        tablero[k][posc+l] = mapa_base[k][posc+l];
                    }
                }
            }
            res = 0;
            return res;
        }
        else if(posf == filas-1)
        {
            for(k=-1;k<=0;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(mapa_base[posf+k][posc+l] != 88)
                    {
                        tablero[posf+k][posc+l] = mapa_base[(filas-1)+k][posc+l];
                    }
                }
            }
        }
        else
        {
            for(k=-1;k<=1;k++)
            {
                for(l=-1;l<=0;l++)
                {
                    if(mapa_base[posf+k][posc+l] != 88)
                    {
                        tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                    }
                }
            }
        }
    }
    if(posf == 0)
    {
        printf("USANDO LA FUNCION CORRECTA\n");
        for(k=0;k<=1;k++)
        {
            for(l=-1;l<=1;l++)
            {
                if(mapa_base[posf+k][posc+l] != 88)
                {
                    tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                }
            }
        }
        printf("LA COMPLETO\n");
    }
    else if(posf == filas-1)
    {
        for(k=-1;k<=0;k++)
        {
            for(l=-1;l<=1;l++)
            {
                if(mapa_base[posf+k][posc+l] != 88)
                {
                    tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                }
            }
        }
    }
    else
    {
        for(k=-1;k<=1;k++)
        {
            for(l=-1;l<=1;l++)
            {
                if(mapa_base[posf+k][posc+l] != 88)
                {
                    tablero[posf+k][posc+l] = mapa_base[posf+k][posc+l];
                }
            }
        }
    }
}

void imprimir_minas(int filas, int  columnas, char **mapa_base, char **tablero)
{
    int i, j;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(mapa_base[i][j] == 'X')
            {
                tablero[i][j] = 'X';
            }
        }

    }
}
void juego_perdido(int filas, int columnas, char **tablero)
{
    system("cls");
    printf("\n");
    imprimir_mapa(filas, columnas, tablero);
    printf("\tJuego Perdido, intenta nuevamente.\n");
    system("pause");
    int i, j;
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            tablero[i][j] = '/';
        }
    }
}

int poner_bandera(int posc, int posf, int filas, int columnas, char **tablero)
{
    if(tablero[posf][posc] == 32)
    {
        return 0;
    }
    if(tablero[posf][posc]>48 && tablero[posf][posc]<57)
    {
        return 0;
    }
    else
    {
        tablero[posf][posc] = 80;
        return 1;
    }
}

int revisar_partida(int minas, int filas, int columnas, char **tablero, char**mapa_base)
{
    int i, j, banderacorrecta = 0;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] == 80)
            {
                if(mapa_base[i][j] == 88)
                {
                    banderacorrecta++;
                }
            }
        }
    }
    if(banderacorrecta == minas)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void copia_mapa_ganador(int filas, int columnas, char **tablero, char**mapa_base)
{
    int i, j;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(tablero[i][j] != 80)
            {
                tablero[i][j] = mapa_base[i][j];
            }
        }
    }
}

void juego_ganado(int filas, int columnas, char **tablero)
{
    system("cls");
    printf("\n");
    imprimir_mapa(filas, columnas, tablero);
    printf("\tJuego GANADO, Felicitaciones!!!!!.\n");
    system("pause");
    int i, j;
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            tablero[i][j] = '/';
        }
    }
}

int quitar_bandera(int posf, int posc, int filas, int columnas, char **tablero)
{
    if(tablero[posf][posc] != 80)
    {
        return 0;
    }
    else
    {
        tablero[posf][posc] = 47;
        return 1;
    }
}
