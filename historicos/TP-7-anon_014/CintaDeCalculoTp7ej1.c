/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_014 de GitHub
 *************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LARGO 100
#define CORTO 25
#define CORRECTO 0

int printIntegers(long int arr[], size_t size,int indice, int resultado, int i);
int acomodaLista(char *contenido[], int max);
void encabezado(int resultado);

int acomodaLista(char *contenido[], int max)
{
    int i=0;
		for(i=0; i<max;i++)
		    {
    				if(contenido[i]=='\n')
    						{
      							contenido[i]=' ';
    						}
  			}
    i=0;
  	int j=0;
  	while(i<max)
    		{
    				if(contenido[i]==' ')
	    					{
      							while(i<=max)
      									{
        										contenido[i] = contenido[i+1];
        										i++;
      									}
      							i=0;
    						}
        		i++;
    		}
  	int q=0;
  	int k=0;
  	while(q<LARGO)
    		{
    				if(contenido[q]== '\0')
    						{
      							k=q+1;
      							q=LARGO;
      							break;
    						}
    				q++;
    			}
  	return(k);
}

int main(int argc, char const *argv[])
{
		int i=0;
    char *contenido[LARGO];
    char *operadores[]= {43,45,42,97,61};
    FILE *archivo;
    archivo = fopen("archivo.txt", "r");
    if(archivo == NULL)
    		{
        		printf("Error al intentar abrir el archivo. :/ \n");
            exit(1);
        }
    while(!feof(archivo))
				{
        		contenido[i] = fgetc(archivo);
        		i++;
        }
    size_t len;
    len = acomodaLista(contenido, i);
    int q=0;
    int resultado=0;
    int indiceSig=0;
    i=0;
    long int arr3[len];
    int k=0;
    resultado = 0;
    while(i<len)
    		{
        		for(int j=0; j<5;j++)
          			{
            				if (contenido[i] == operadores[j])
            						{
              							resultado = printIntegers(arr3,k,j, resultado, indiceSig);
              							k=0;
              							break;
            						}
          			}

						arr3[k]= strtol(&contenido[i], NULL,10);
          	i++;
          	k++;
        }
		return 0;
}

int printIntegers(long int arr[], size_t size,int indice, int resultado, int i)
{
		int aux=0;
		switch(indice)
				{
    				case 0:for(i; i<size; i++)
           						 {
              						 resultado= resultado+arr[i];
           						 }
              		  break;

            case 1:for(i; i<size; i++)
									 	   {
     											 resultado= resultado-arr[i];
             					 }
             			  break;

  					case 2:for(i; i<size-1; i++)
											 {
            							 resultado= resultado*arr[i+1];
          						 }
									  break;

    				case 3:
									 for(i; i<size; i++)
              				 {
                					 resultado= resultado+arr[i];
													 aux++;
              				 }
										resultado= resultado/aux;
										break;

						case 4:encabezado(resultado);
									 break;

						default:printf("\t\tOperador No Valido\n" );
										break;
  			}
		printf("\n");
    return resultado;
}

void encabezado(int resultado)
{
		system("CLS");
  	printf("\t\t");

  	for(int i=0; i<sizeof(resultado)*20;i++)
  			{
      			printf("*");
  			}

  	printf("\n\t\t*" );
  	int posRes=0;
  	posRes= sizeof(resultado)*20/2;
  	int k=0;

  	while(k<1)
  			{
						for(int i =0; i<posRes-(sizeof(resultado)+sizeof("El Resultado Es: ")); i++)
								{
										printf(" ");
								}

    				printf("El Resultado Es : %i",resultado );
    				k++;
  			}
		for(int i =0; i<posRes-sizeof(resultado); i++)
				{
						printf(" ");
				}

    printf("*\n\t\t");
  	for(int i=0; i<sizeof(resultado)*20;i++)
  			{
      			printf("*");
  			}
}
