

 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 // #include <tp5-ej2.c>

 #define ERROR -1
 #define LARGO 500

 void lector_archivo(FILE *texto, char *lista_origen, int *lista_destino);

 void lector_archivo(FILE *texto, char *lista_origen, int *lista_destino)
 {
     FILE *archivo_resultados;
     int numero[LARGO];
     int cantidad_enter = 1;
     int cantidad_de_numeros = 0;
     int k = 0;
     int contador_desde_ultimo_enter = 0;
     int posicion_inicial = 0;
     int posicion_final = 0;
     int cal = 0;
     int resultados_a_mostrar[LARGO];
     int cant_resultados = 0;
     ///////////////////////////////////////////////////////////////////////
     // Lector de archivo
     memset(lista_origen, 0, sizeof(lista_origen));
     memset(numero, 0 , sizeof(numero));
     memset(resultados_a_mostrar, 0 , sizeof(resultados_a_mostrar));
     if(texto == NULL || ferror(texto))
     {
         exit(ERROR);
     }
     for (int i = 0; i < LARGO ; i++)
     {
         lista_origen[i] = fgetc(texto);
         if (feof(texto))
         {
             break;
         }
         else
         {
             printf("%c", lista_origen[i]);
         }
     }
     /////////////////////////////////////////////////////////////
     // Cantidad de lineas
     for (int i = 0; i < LARGO ; i++)
     {
         //Codigo para saber cuantos numeros o letras hay en cada linea
         if (lista_origen[i] == '\n')
         {
            cantidad_enter++;
         }
     }
     /////////////////////////////////////////////////////////////
     printf("\n\n");
     for (int i = 0; i < cantidad_enter*2 ; i++)
     {
         //Codigo para saber cuantos numeros o letras hay en cada linea
         if (lista_origen[i] == '\n')
         {
            contador_desde_ultimo_enter = 0;
         }
         else
         {
             if(contador_desde_ultimo_enter > 1 && isdigit(lista_origen[i]))
             {
                 numero[k] = lista_origen[i] - '0';
                 k++;
             }
             contador_desde_ultimo_enter++;

             // printf("%d", contador_desde_ultimo_enter);
         }
         ///////////////////////////////////////////////////////////////////////
         // Parte del codigo parsa copiar solo numeros a nuevo arreglo
         if (isdigit(lista_origen[i]))
         {
             // printf("Funciona");
             lista_destino[cantidad_de_numeros] = lista_origen[i] - '0';
             cantidad_de_numeros++;
             printf("%d\n", lista_destino[k]);
             k++;
             posicion_final++;
         }
         ///////////////////////////////////////////////////////////////////////
         ///////////////////////////////////////////////////////////////////////
         ///////////////////////////////////////////////////////////////////////
         // Codigo si reconoce simbolos para aritmetica

         // Suma
         else if (lista_origen[i] == '+')
         {
             for (int i = posicion_inicial; i < k; i++)
             {
                 cal = cal + lista_destino[i];
                 posicion_inicial = k;
             }
             // printf("Suma\n");
         }
         ////////////////////////////////////////////////
         // Resta
         else if (lista_origen[i] == '-')
         {
             for (int i = posicion_inicial; i < k; i++)
             {
                 cal = cal - lista_destino[i];
                 posicion_inicial = k;
             }
         }
         ////////////////////////////////////////////////
         // Multiplicación
         else if (lista_origen[i] == '*')
         {
             if(cant_resultados > 0)
             {
                 cal = 1;
             }
             for (int i = posicion_inicial; i < k; i++)
             {
                 cal = cal * lista_destino[i];
                 posicion_inicial = k;
             }
         }
         ////////////////////////////////////////////////
         else if (lista_origen[i] == 'a')
         {
             for (int i = posicion_final; i < k; i++)
             {
                 cal = cal + lista_destino[i];
                 posicion_inicial = k;
                 posicion_final = k;
             }
         }
         else if (lista_origen[i] == '=')
         {
             resultados_a_mostrar[cant_resultados] =  cal;
             cant_resultados++;
             posicion_final = k;
             posicion_inicial = k;
             cal = 0;
         }
         ////////////////////////////////////////////////
     }
     ///////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////
     // Imprimir resultado
     if (cant_resultados > 0)
     {
         archivo_resultados = fopen("Resultados_generado.txt","w");
         for (int i = 0; i < cant_resultados; i++)
         {
             fprintf(archivo_resultados, "Resultado de Op %d: %d\n",i+1, resultados_a_mostrar[i]);
             printf("\nResultado de Op %d: %d\n", i+1, resultados_a_mostrar[i]);
         }
     }
     // printf("CE: %d\n", cantidad_enter);
     // printf("CR: %d\n", cant_resultados);

     printf("\n\nArchivo generado y guardado exitosamente.\n");
     fclose(archivo_resultados);
 }
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
 int main()
 {
    FILE *archivo_en_uso;
    char lista_ingresada[LARGO];
    int mi_arreglo[LARGO];
    int resultado [LARGO];

    archivo_en_uso = fopen("ejemplo.txt","r");
    lector_archivo(archivo_en_uso, lista_ingresada, mi_arreglo);

    fclose(archivo_en_uso);
     return 0;
 }
