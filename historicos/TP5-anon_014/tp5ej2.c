
#include <stdio.h>
#include <string.h>
#define CADENA_MAX 50
#define CADENA_CORTA -1
#define CADENA_CORRECTA 1


int main(int argc, char *argv[]);
int largo_cadena(char *cadena, int capacidad_cadena);
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion);
int copiadora(char *origen, char *destino, int capacidad_destino);
int inversor(char* origen, char* destino, int capacidad_destino);


int largo_cadena(char *cadena, int capacidad_cadena)
{
    for(int i = 0 ; i <= capacidad_cadena; i++)
    {
        if (cadena[i] == '\0')
        {
            return i;
        }
    }
    return CADENA_CORTA;
}

int insercion(char *destino, int capacidad_destino, char* insertar, int posicion)
{
    char inicio[capacidad_destino];
    char final[capacidad_destino];
    int i = 0;
    int j = 0;
    posicion ++;
    // cortamos la cadena en dos partes
    while(i<posicion)
    {
        inicio[i] = destino[i];
        i++;
    }
    while(j<=capacidad_destino)
    {
        final[j] = destino[i];
        j++;
        i++;
    }
        //a la primer parte de la cadena le agregamos la cedena a insertar
    i=0;
    j=0;
    while (i < posicion && i <= capacidad_destino)
    {
        destino[i]=inicio[i];
        i++;
    }
    while(j <= sizeof(insertar) && i <= capacidad_destino)
    {
        if(insertar[j] != '\0' )
        {
            destino[i] = insertar[j];
            i++;
            j++;
        }
        else
        {
            break;
        }
    }
    j=0;
      //agregamos la segunda parte de la cadena
    while(j <= sizeof(final) && i<= capacidad_destino)
    {
        if(final[j] != '\0')
        {
            destino[i] = final[j];
            i++;
            j++;
        }
        else
        {
            destino[i] = '\0';
            break;
        }
    }
    return largo_cadena(destino, capacidad_destino);
}

int copiadora(char *origen, char *destino, int capacidad_destino)
{
    int i;
    int j=largo_cadena(destino, capacidad_destino);
    int q = j;
    i = 0;
    while(q >=j && i<= largo_cadena(destino, capacidad_destino))
    {
        if(origen[i] != '\0')
        {
            destino[q] = origen[i];
            q++;
            i++;
        }
        else
        {
            break;
        }
    }
    return largo_cadena(destino, capacidad_destino);
}

int inversor(char* origen, char* destino, int capacidad_destino)
{
  int i;
  int j=largo_cadena(origen, capacidad_destino);
  i = 0;
  j--;
  while(j>=0 && i<= largo_cadena(origen, capacidad_destino))
  {
      if(origen[i] != '\0')
      {
          destino[i] = origen[j];
          j--;
          i++;
      }
      else
      {
          break;
      }
  }
  return largo_cadena(destino, capacidad_destino);

}

int main(int argc, char *argv[])
{
    int posicion =0;
    char cadena_original;
    char mi_cadena[CADENA_MAX];
    char mi_cadena_dos[CADENA_MAX];

    printf("\t\t\t\t** FUNCION DE LONGITUD Cadena **\n" );
    printf("Ingrese la Cadena 1 : ");
    scanf("%s",&mi_cadena);
    printf("Ingrese la Cadena 2: ");
    scanf("%s",&mi_cadena_dos);
    int largo = largo_cadena(mi_cadena, CADENA_MAX);
    printf("Largo_cadena 1 : %i\n", largo);
    largo = largo_cadena(mi_cadena_dos, CADENA_MAX);
    printf("Largo_cadena 2 : %i\n", largo);

    memset(mi_cadena, 0, CADENA_MAX);
    memset(mi_cadena_dos, 0, CADENA_MAX);

    printf("\t\t\t\t** FUNCION DE INSERCION **\n" );
    printf("Ingrese la Cadena 1 : ");
    scanf("%s",&mi_cadena);
    printf("Ingrese la Cadena 2: ");
    scanf("%s",&mi_cadena_dos);
    printf("Ingrese la posicion de la insercion: #");
    scanf("%i",&posicion );
    int insert = insercion(mi_cadena, CADENA_MAX, mi_cadena_dos, posicion);
    printf("resultado insercion: %i\n",insert);

    memset(mi_cadena, 0, CADENA_MAX);
    memset(mi_cadena_dos, 0, CADENA_MAX);

    printf("\t\t\t\t** FUNCION DE COPIA **\n" );
    printf("Ingrese la Cadena 1 : ");
    scanf("%s",&mi_cadena);
    printf("Ingrese la Cadena 2: ");
    scanf("%s",&mi_cadena_dos);
    int copia = copiadora(mi_cadena, mi_cadena_dos, CADENA_MAX);
    printf("resultado copia: %i\n", copia);

    memset(mi_cadena, 0, CADENA_MAX);
    memset(mi_cadena_dos, 0, CADENA_MAX);

    printf("\t\t\t\t** FUNCION DE INVERSION **\n" );
    printf("Ingrese la Cadena Para Conocer Su Inverso : ");
    scanf("%s",&mi_cadena);
    int inverso = inversor(mi_cadena, mi_cadena_dos, CADENA_MAX);
    printf("resultado inversor: %i\n"
           "La cadena destino quedo asi: %s",inverso, mi_cadena_dos );

    memset(mi_cadena, 0, CADENA_MAX);
    memset(mi_cadena_dos, 0, CADENA_MAX);

    return 0;
  }
