
#include <stdio.h>

double granosDeArroz(); //Defino la funcion

int main(int argc, char *argv[])
{
  double arroz, kg;// Las variables estan definidas como Double porque los numeros eran demasiado grandes (aunque tambien podrian haber sido float o long long int)
  arroz = granosDeArroz();
  kg = arroz/20000;// calcula la cantidad de kilogramos
  printf("N° de granos de arroz:%.0f \nKgs de arroz: %.3f\n", arroz, kg);// imprime los resultados
  return 1;
}

double granosDeArroz() //La funcion hace el calculo de la cantidad de granos de arroz
{
  double arroz = 1;
  for(int i=0;i<64;i++)// Itera 64 veces (cantidad de casilleros en el tablero)
      arroz *= 2;// Dobla la cantidad de granos de arroz por casillero

  return arroz;
}
