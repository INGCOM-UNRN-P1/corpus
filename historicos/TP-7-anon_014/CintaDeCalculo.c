
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Largo 100
#define Corto 25

int recorre(char*);
int calculo(char *, int, char*, int);
int correLista(char*);
int promedio(char *, char*, int);

int promedio(char* datos, char* operadores, int indiceOperador){
  int contador = 0;
  int i;
  for(i=0; i< indiceOperador;i++){
    if(datos[i] == '\n'){
      contador++;
    }
  }
  while(contador >=1){
    calculo(operadores,0, datos, indiceOperador);
    contador--;
  }
}


int correLista(char* a){
  int i=0;
  int j=1;
  int contador=0;
  for(i=0;i<strlen(a);i++){
    if(a[i]== '\n'){
      break;
    }
  }
  i++;
  a[0]= ' ';
  while(contador !=2){
    a[j] = a[i];
    if(a[i] == '\0'){
      contador =2;
    }
    j++;i++;
  }
}

int calculo(char *operadores, int indice, char* datos, int indiceOperador){
  int a=0;
  int b=0;
  int i=1;
  while(i < indiceOperador){
  a = atoi(datos);
  correLista(datos);
  b = atoi(datos);
    switch (operadores[indice]) {
      case '+':a= a+b;
              break;
      case '-':a=a-b;
              break;
      case '=':a=a;
              break;
      case '*':a=a*b;
              break;
      default: ;
              break;
    }
    datos[1] =a+48;
i=i*2;
}
  return 0;
}
int recorre(char *archivo){
  int i=0,j=0;
  char operadores[6]="+-=*a";
  for(i=0;i<strlen(archivo);i++){
    for(j=0; j<7;j++){
      if(archivo[i] == operadores[j]){
        calculo(operadores, j, archivo, i);
        i=0;
        j=0;
      }
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  int i=0;
  char contenido[Largo];
  FILE *archivo;
  archivo = fopen("archivo.txt", "r");
  if(archivo == NULL){
    printf("Error al intentar abrir el archivo. :/ \n");
    exit(1);
  }
  while(!feof(archivo)){ 
    contenido[i] = fgetc(archivo);
    i++;
  }
  recorre(contenido);
  printf("\t+-------------------------------------------------+\n");
  printf("\t|EL RESULTADO DE REALIZAR LAS OPERACIONES FUE :%s", contenido);
  printf("\t+-------------------------------------------------+\n");

  return 0;
}
