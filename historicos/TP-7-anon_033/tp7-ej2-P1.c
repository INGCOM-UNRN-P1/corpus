
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>

 #define MAX_CANTIDAD 100

 void imprimir_tablero(char *tab[], int length, int height);
 void crear_tablero();

 void imprimir_tablero(char *tab[], int length, int height)
 {
     int i;
     int k;
     printf("\n");
     // Funcion para imprimir tablero
     for (i = 0; i < height; i++)
     {
         printf("\t");
         for (k = 0; k <length; k++)
         {
             printf("%c", tab[k][i]);
         }
             printf("%c", tab[k+1][i]);
     }
 }

 void crear_tablero()
 {
     FILE *archivo_tablero;
     printf("\nCrear tablero\n");
     int cantidad_de_minas;
     int largo;
     int alto;
     int x;
     int y;
     int i;
     int k;
     printf("Ingrese el LARGO del tablero: ");
     scanf("%d", &largo);
     getchar();
     printf("Ingrese el ALTO del tablero: ");
     scanf("%d", &alto);
     getchar();
     char tablero[largo+1][alto];
     // Hasta aca todo bien

     for (i = 0; i < alto ; i++)
     {
         for (k = 0; k < largo; k++)
         {
             tablero[k][i] = '0';
         }
         tablero[k+1][i] = '\n';
     }

     printf("\n");
     // Funcion para imprimir tablero
     for (i = 0; i < alto ; i++)
     {
         printf("\t");
         for (k = 0; k < largo; k++)
         {
             printf("%c", tablero[k][i]);
         }
             printf("%c", tablero[k+1][i]);
     }
     ////////////////////////////////////
     printf("\nCuantas minas desea? ");
     scanf("%d", &cantidad_de_minas);
     getchar();
     ////////////////////////////////////4
     // Agregar
     for (i = 0; i < cantidad_de_minas ; i++)
     {
         printf("Ingrese la posicion en X de mina %d: ", i+1);
         scanf("%d", &x);
         getchar();
         printf("Ingrese la posicion en Y de minas %d: ", i+1);
         scanf("%d", &y);
         getchar();
         tablero[x-1][y-1] = 'M';
     }

      // Funcion para imprimir tablero otra vez con sus cambios
     printf("Tablero con sus minas\n\n");
     // Adyacencias
     int numero;
     // Codigo que recorre el tablero y genera las adyacencias
     for (i = 0; i < alto ; i++)
     {
         for (k = 0; k < largo; k++)
         {
             if(isalpha(tablero[k][i]))
             {
                 if(isdigit(tablero[k-1][i-1]))
                 {
                     numero = tablero[k-1][i-1] - '0';
                     numero = numero + 1;
                     tablero[k-1][i-1] = numero + '0';
                 }
                 if(isdigit(tablero[k][i-1]))
                 {
                     numero = tablero[k][i-1] - '0';
                     numero = numero + 1;
                     tablero[k][i-1] = numero + '0';
                 }
                 if(isdigit(tablero[k+1][i-1]))
                 {
                     numero = tablero[k+1][i-1] - '0';
                     numero = numero + 1;
                     tablero[k+1][i-1] = numero + '0';
                 }
                 if(isdigit(tablero[k-1][i]))
                 {
                     numero = tablero[k-1][i] - '0';
                     numero = numero + 1;
                     tablero[k-1][i] = numero + '0';
                 }
                 if(isdigit(tablero[k+1][i]))
                 {
                     numero = tablero[k+1][i] - '0';
                     numero = numero + 1;
                     tablero[k+1][i] = numero + '0';
                 }
                 if(isdigit(tablero[k-1][i+1]))
                 {
                     numero = tablero[k-1][i+1] - '0';
                     numero = numero + 1;
                     tablero[k-1][i+1] = numero + '0';
                 }
                 if(isdigit(tablero[k][i+1]))
                 {
                     numero = tablero[k][i+1] - '0';
                     numero = numero + 1;
                     tablero[k][i+1] = numero + '0';
                 }
                 if(isdigit(tablero[k+1][i+1]))
                 {
                     numero = tablero[k+1][i+1] - '0';
                     numero = numero + 1;
                     tablero[k+1][i+1] = numero + '0';
                 }
             }
         }
     }
     /////////////////////////////////
     /////////////////////////////////
     /////////////////////////////////
     // Imprimir
     for (i = 0; i < alto ; i++)
     {
         printf("\t");
         for (k = 0; k < largo; k++)
         {
             printf("%c", tablero[k][i]);
         }
             printf("%c", tablero[k+1][i]);
     }
     /////////////////////////////////
     /////////////////////////////////
     /////////////////////////////////
     // Funcion para crear y guardar archivo
     archivo_tablero = fopen("Tablero_generado.txt","w");
     for (i = 0; i < alto ; i++)
     {
         printf("\t");
         for (k = 0; k < largo; k++)
         {
             fprintf(archivo_tablero, "%c", tablero[k][i]);
         }
         fprintf(archivo_tablero, "%c", tablero[k+1][i]);
     }

     printf("\n\nArchivo generado y guardado exitosamente.\n");
     fclose(archivo_tablero);
 }
/////////////////////////////////
/////////////////////////////////
int main()
{
    printf("Buscaminas\n");
    printf("\n\t%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,187);
    crear_tablero();
}
//
