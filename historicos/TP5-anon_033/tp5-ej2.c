/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de Github
*************************/

#include <stdio.h>
#define CADENA_CORTA -1
#define LONGITUD 100
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Declaracion de "largo_cadena":
int largo_cadena(char *cadena, int capacidad_cadena);

int Largo_de_cadenas()
{
  printf("\nLargo de cadenas\n");
  char texto_ingresado[LONGITUD];
  int result_ej_largo_cadena;
  printf("Ingrese una frase: ");
  fgets(texto_ingresado, LONGITUD, stdin);
  result_ej_largo_cadena = largo_cadena(texto_ingresado,LONGITUD);
  printf("\nLa longitud del texto es de: %d \n", result_ej_largo_cadena);
  return 0;
}

// Inicialización de "largo_cadena":
int largo_cadena(char *cadena, int capacidad_cadena)
{
  int i = 0;
  while (i <= capacidad_cadena && cadena[i] != '\0')
  {
    i++;
    }
    i = i - 1;

    if(i > capacidad_cadena)
    {
      i = CADENA_CORTA;
    }

    return i;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Inserción de cadenas
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion);

int Insercion_de_cadenas()
{
  printf("Insercion de cadenas\n");
  char la_oracion[LONGITUD];
  char por_insertar[LONGITUD];
  int unNumero, result_ej_insersion;
  // Los prints
  printf("Ingrese una oracion: ");
  fgets(la_oracion, LONGITUD, stdin);
  printf("Ingrese una palabra: ");
  fgets(por_insertar, LONGITUD, stdin);
  printf("Ingrese la posicion desde la cual desea insertar: ");
  scanf("%d", &unNumero);
  result_ej_insersion = insercion(la_oracion, LONGITUD, por_insertar, unNumero);
  printf("El largo de la nueva cadena es de: %d\n", result_ej_insersion);
  return 0;
}

// Inicialización de "insercion":
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion)
{
  int cont_destino = 0, cont_insercion = 0;
  int cont_posicion = posicion;
  int cont_i = 0;
  char cadena_de_guardado[LONGITUD];
  int largo_insertar = largo_cadena(insertar,capacidad_destino);
  int largo_destino = largo_cadena(destino,capacidad_destino);
  int largo_mixto = largo_destino + largo_insertar;

  for (;cont_i < largo_mixto; cont_i++)
  {
    if (cont_i < cont_posicion || cont_insercion >= largo_insertar)
    {
      cadena_de_guardado[cont_i] = destino[cont_destino];
      cont_destino ++;
    }
    else if (cont_i >= cont_posicion && cont_insercion < largo_insertar)
    {
      cadena_de_guardado[cont_i] = insertar[cont_insercion];
      cont_insercion ++;
    }

  }
  if (largo_mixto <= 0)
  {
      largo_mixto = CADENA_CORTA;
  }
  return largo_mixto;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

int copiadora(char *origen, char *destino, int capacidad_destino);
int Copia_de_cadenas()
{
  printf("Copia de cadenas\n");
  char origen_copiadora[LONGITUD];
  char destino_copiadora[LONGITUD];
  int result_ej_copia;

  printf("Ingrese una cadena: ");
  fgets(origen_copiadora, LONGITUD, stdin);

  result_ej_copia = copiadora(origen_copiadora, destino_copiadora, LONGITUD);
  printf("El largo de la cadena copiada es de: %d", result_ej_copia);
  return 0;
}

int copiadora(char *origen, char *destino, int capacidad_destino)
{
  int largo_origen = largo_cadena(origen,LONGITUD);
  int contador_copiadora = 0;

  for (;contador_copiadora <= largo_origen; contador_copiadora++)
  {
      destino[contador_copiadora] = origen[contador_copiadora];
  }

  int largo_copia = largo_cadena(destino,LONGITUD);
  if (largo_copia <= 0)
  {
      largo_copia = CADENA_CORTA;
  }
  return largo_copia;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// int limpiadora(char *origen, char *destino, int capacidad_destino);
// int Limpieza()
// {
//     printf("Limpieza\n");
//
//     char cadena_origen_ejlimpieza[LONGITUD];
//     int result_ejlimpieza;
//     printf("Ingrese su bendita cadena porfis ヾ(•ω•`)o : ");
//     fgets(cadena_origen_ejlimpieza, LONGITUD, stdin);
//
//     result_ejlimpieza = limpiador(cadena_origen_ejlimpieza, destino,LONGITUD);
//     printf("El largo del texto es de: %d!", result_ejlimpieza);
//     return 0;
// }

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
int main() {
  printf("Ejercicio 2\n");
  int accion;
  printf("Elija el ejercicion entre 1 y 3, o 0 para cerrar el programa:\n\t-(1)Largo de cadena\n\t-(2)Insercion de cadena\n\t-(3)Copia de cadenan\n");
  printf("Accion: ");
  scanf("%d", &accion);
  getchar();
  switch (accion)
  {
      case 0:
      break;

      case 1:
      Largo_de_cadenas();
      break;
      case 2:
      Insercion_de_cadenas();
      break;

      case 3:
      Copia_de_cadenas();
      break;
  }
  return 0;
}
