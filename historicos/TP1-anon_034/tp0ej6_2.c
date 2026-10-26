
 
 #include <stdio.h>

 int compara_fechas(char *primera, char *segunda)
 {
   char anio1[4];
   char anio2[4];
   char mes1[2];
   char mes2[2];
   char dia1[2];
   char dia2[2];

   anio1[0] = primera[6];
   anio1[1] = primera[7];
   anio1[2] = primera[8];
   anio1[3] = primera[9];
   anio2[0] = segunda[6];
   anio2[1] = segunda[7];
   anio2[2] = segunda[8];
   anio2[3] = segunda[9];

   mes1[0] = primera[3];
   mes1[1] = primera[4];
   mes2[2] = segunda[3];
   mes2[3] = segunda[4];

   dia1[0] = primera[0];
   dia1[1] = primera[1];
   dia2[0] = segunda[0];
   dia2[1] = segunda[1];

   int i;

   for (i = 0; i < 4; i++)
   {
      if (anio1[i] > anio2[i])
      {
         return 1;
      }
      else if (anio1[i] < anio2[i])
      {
         return -1;
      }
   }
   for (i = 0; i < 2; i++)
   {
      if (mes1[i] > mes2[i])
      {
         return 1;
      }
      else if (mes1[i] < mes2[i])
      {
         return -1;
      }
   }
   for (i = 0; i < 2; i++)
   {
      if (dia1[i] > dia2[i])
      {
         return 1;
      }
      else if (dia1[i] < dia2[i])
      {
         return -1;
      }
   }

   return 0;
 }

 int main()
 {
   char primera[LARGO], segunda[LARGO];
   int resultado;

   printf("Ingrese un fecha DD/MM/AAAA");
   scanf("%s" &primera);
   printf("Ingrese otra fecha para comparar con la primera DD/MM/AAAA");
   scanf("%s" &segunda);

   resultado = compara_fechas(primera, segunda);

   printf("%d", resultado);
   
   return 0;
 }