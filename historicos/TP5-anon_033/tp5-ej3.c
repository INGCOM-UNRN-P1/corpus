
 #include <stdio.h>
 char* busqueda(char *cadena, int largo, char *busqueda);
 #define LARGO_MAXIMO_TEXTO 100

 int main()
 {
     printf("Ejercicio 3: Busqueda\n\n");

     char texto_ingresado[LARGO_MAXIMO_TEXTO];
     char texto_busqueda[LARGO_MAXIMO_TEXTO];
     char *ptr_resultado[LARGO_MAXIMO_TEXTO];

     printf("Ingrese texto: ");
     fgets(texto_ingresado,LARGO_MAXIMO_TEXTO,stdin);

     printf("Ingrese clave a buscar: ");
     fgets(texto_busqueda,LARGO_MAXIMO_TEXTO,stdin);
     *ptr_resultado = busqueda(texto_ingresado, LARGO_MAXIMO_TEXTO, texto_busqueda);

     printf("%s\n", *ptr_resultado);
     return 0;
 }

 char* busqueda(char *cadena, int largo, char *busqueda)
 {
     int i = 0;
     int posicion = 0;
     int largo_texto = 0;
     int mismo_texto = 0;
     int contador_adicional = 0;

     for(; i < largo ; i++)
     {
         if(busqueda[i] != '\n')
         {
             largo_texto ++;
         }
         else
         {
             break;
         }
     }
     i = 0;
     for(; i < largo ; i++)
     {
         if (cadena[i] == busqueda[contador_adicional] )
         {
             mismo_texto ++;
             contador_adicional ++;
         }
         else if(mismo_texto == largo_texto)
         {
             posicion = i;
             break;
         }
         else
         {
             contador_adicional = 0;
             mismo_texto = 0;
         }



     }

     if(posicion > 0)
     {
         posicion = posicion - largo_texto;
         return cadena + posicion;
     }
     else
     {
         return NULL;
     }
 }
