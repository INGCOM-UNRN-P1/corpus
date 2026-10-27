
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>

 #define ERROR -1
 #define MAX_LARGO 100

 void cargar_tablero(int *largo_tablero, int *alto_tablero);
 void tablero(int *alto_tablero, int *largo_tablero);
 ///////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////
 void tablero(int *alto_tablero, int *largo_tablero)
 {
     FILE *archivo_en_uso;
     int activo = 1;
     archivo_en_uso = fopen("Tablero_generado.txt","r");
     char tablero_original[*alto_tablero][*largo_tablero];
     // printf("\n");
     // Asigno valores a mi vector para el tablero
     if(archivo_en_uso == NULL || ferror(archivo_en_uso))
     {
         exit(ERROR);
     }
     for (int i = 0; i < MAX_LARGO ; i++)
     {
         fgets(tablero_original[i], MAX_LARGO, archivo_en_uso);
         // printf("\t%s", tablero_original[i]);
         // printf("%d", i);
         if (feof(archivo_en_uso))
         {
             // printf("\nTermino\n");
             break;
         }
     }


     // Cantidad de minas
     int cantidad_de_minas = 0;
     for (int i = 0; i < MAX_LARGO ; i++)
     {
         for (int j = 0; j < MAX_LARGO ; j++)
         {
             if (tablero_original[i][j] == 'M')
             {
                 cantidad_de_minas = cantidad_de_minas + 1;
             }
         }
     }
     // printf("%d\n", cantidad_de_minas);

     fclose(archivo_en_uso);

     ///////////////////////////////////////////////////////////////////
     // Tablero borroso
     char tab_blur[*alto_tablero][*largo_tablero];
     for (int i = 0; i < *alto_tablero ; i++)
     {
         printf("\t");
         for (int j = 0; j < *largo_tablero; j++)
         {
             tab_blur[i][j] = '*';
             printf("%c", tab_blur[i][j]);
         }
         printf("\n");
     }
     // Juego
     while (activo == 1)
     {
         int accion;
         int x;
         int y;
         printf("Seleccionar casilla(1)\nMarcar casilla(2)\n");
         printf("Que desea hacer: ");
         scanf("%d", &accion);
         getchar();

         switch (accion)
         {
             case 0:
             printf("TERMINO\n");
             activo = 0;
             break;
             ///////////////////////////////////////////////////////////////////
             case 1:
             printf("Seleccione sus cordenadas...");
             printf("\nX: ");
             scanf("%d", &x);
             getchar();
             printf("Y: ");
             scanf("%d", &y);
             getchar();
             tab_blur[y][x] = tablero_original[y][x];

             for (int i = 0; i < *alto_tablero ; i++)
             {
                 printf("\t");
                 for (int j = 0; j < *largo_tablero; j++)
                 {
                     printf("%c", tab_blur[i][j]);
                 }
                 printf("\n");
             }
             if(tablero_original[y][x] == 'M')
             {
                 printf("Te moriste wey\nGAME OVER\n");
                 activo = 0;
             }
             break;

             ///////////////////////////////////////////////////////////////////
             case 2:
             printf("Marcar mina...");
             printf("Seleccione sus cordenadas...");
             printf("\nX: ");
             scanf("%d", &x);
             getchar();
             printf("Y: ");
             scanf("%d", &y);
             getchar();
             tab_blur[y][x] = '?';
             if(tablero_original[y][x] == 'M')
             {
                 cantidad_de_minas--;
                 printf("%d", cantidad_de_minas);
             }
             for (int i = 0; i < *alto_tablero ; i++)
             {
                 printf("\t");
                 for (int j = 0; j < *largo_tablero; j++)
                 {
                     printf("%c", tab_blur[i][j]);
                 }
                 printf("\n");
             }
             if(cantidad_de_minas == 0)
             {
                 printf("Ganaste\n Anda a dormir\n");
                 activo = 0;
             }
             break;
             ///////////////////////////////////////////////////////////////////
         }
     }

 }
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
 void cargar_tablero(int *largo_tablero, int *alto_tablero)
 {
     char nombre_de_archivo[MAX_LARGO];
     FILE *archivo_en_uso;
     *largo_tablero = 0;
     *alto_tablero = 0;
     int i;
     int k;
     char t;
     char cadena_temp[MAX_LARGO];
     int error = 0;

     archivo_en_uso = fopen("Tablero_generado.txt","r");
     if(archivo_en_uso == NULL || ferror(archivo_en_uso))
     {
         exit(ERROR);
     }
     for (int i = 0; i < MAX_LARGO ; i++)
     {
         fgets(cadena_temp, MAX_LARGO, archivo_en_uso); //Verificar que fgets entre
         // printf("\t%s", cadena_temp);
         if (feof(archivo_en_uso))
         {
             *alto_tablero = i;
             *largo_tablero = strlen(cadena_temp);
             break;
         }
     }
     fclose(archivo_en_uso);
     printf("\nArchivo cargado exitosamente.\n");
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
 int main()
 {
     int altoPtr;
     int largoPtr;
     printf("Buscaminas\n\n");

     cargar_tablero(&altoPtr, &largoPtr);

     printf("\nLargo: %d\n", largoPtr);
     printf("Alto: %d\n", altoPtr);

     char tablero_original[largoPtr][altoPtr];
     tablero(&altoPtr,&largoPtr);
 }
