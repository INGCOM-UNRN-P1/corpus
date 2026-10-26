/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_033 de GitHub
 *************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>

 #define ERROR -1
 #define OK 0
 #define LARGO 100
 void la_cosa_de_martin();
 void interger();
 void lector_archivo();
 void concat();

 void la_cosa_de_martin()
 {
     // int x,y,tablero,max_col,max_row;
     // int despejar(tablero, max_col, max_row, x, y);
     // despejar(tablero, max_col, max_row, x+1, y+1);
     // despejar(tablero, max_col, max_row, x+1, y);
     // despejar(tablero, max_col, max_row, x, y+1);
     // despejar(tablero, max_col, max_row, x, y);
     // despejar(tablero, max_col, max_row, x-1, y-1);
     // despejar(tablero, max_col, max_row, x, y-1);
     // despejar(tablero, max_col, max_row, x, y);

// x e y tienen que estar dentro de los limites del tablero.
// si tablero[x][y] contiene cero, destapo.

 }
 void concat()
 {
     char destination[] = "1";
     char source[] = "2";
     int number[LARGO];
     number[0] = atoi(strcat(destination,source));
     number[1] = atoi(destination) + atoi(source);

     printf("Concatenated String: %s\n", strcat(destination,source));
     printf("Concatenated Number: %d\n", number[0]);
     printf("Added Number: %d\n", number[1]);
}

 void interger()
 {
     // Converting a numeric string
     char str[10] = "122";
     int x = atoi(str);
     printf("\nConverting '122': %d\n", x);

     // Converting an alphanumeric string
     char str2[10] = "Hello!";
     x = atoi(str2);
     printf("Converting 'Hello!': %d\n", x);

     // Converting a partial string
     char str3[10] = "99Hello!";
     x = atoi(str3);
     printf("Converting '99Hello!': %d\n", x);
 }

 void lector_archivo()
 {
     FILE *archivo_en_uso;
     int cosa_rara;

     archivo_en_uso = fopen("ejemplo.txt","r");

     if(archivo_en_uso == NULL || ferror(archivo_en_uso))
     {
        perror("Ooops");
        ERROR;
     }


     while(1)
     {
        cosa_rara = fgetc(archivo_en_uso);

        if( feof(archivo_en_uso) )
        {
           break ;
        }

        printf("%c", cosa_rara);
     }
     fclose(archivo_en_uso);
 }

 int main()
 {
    lector_archivo();
    interger();
    concat();
     return 0;
 }
