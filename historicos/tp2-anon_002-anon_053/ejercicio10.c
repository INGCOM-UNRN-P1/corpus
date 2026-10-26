

#include <stdio.h>
//funciones declaradas
float millasAkm(float millas);
float kmAmillas(float km);
float galeonesAlitro(float galeones);
float litroAgaleones(float litro);

int main()
{
   float millas = 900;
   float km;
   float galeones = 800;
   float litro;
//si imprimiran las siguientes lineas con la conversiones de cada funcion
   km = millasAkm(millas);
   printf("%.2f millas son %.2f km\n", millas, km);

   km = 150;
   millas = kmAmillas(km);
   printf("%.2f km son %.2f millas\n", km, millas);

   litro = galeonesAlitro(galeones);
   printf("%.2f galeones son %.2f litros\n", galeones, litro);

   litro = 1000;
   galeones = litroAgaleones(litro);
   printf("%.2f litros son %.2f galeones\n", litro, galeones);

   return 0;
}
//pre:ingresa valor de tipo flotante
float millasAkm(float millas)
{// funcion convierte millas a km
   int km;
   km = millas * 1.609;
   return km;
}// pos: retorna conversion en tipoflotante del valor ingresado 

//pre: ingresa valor de tipo flotante
float kmAmillas(float km)
{//funcion convierte km a millas
   int millas;
   millas = km / 1.609;
   return millas;
}//pos: retorna conversion del valor ingresado

// pre: ingresa valor de tipo flotante
float galeonesAlitro(float galeones)
{//funcion convierte galeones a litro
   int litro;
   litro = galeones * 3.785;
   return litro;
}//pos: retorna conversion del valor ingresado

//pre: ingresa valor de tipo flotante
float litroAgaleones(float litro)
{//funcion convierte litro a galeones
   int galeones;
   galeones = litro / 3.785;
   return galeones;
}//pos: retorna conversion del valor ingresado


// volumen(gal) = volumen(l) ÷ 3.785
// volumen(l) = volumen(gal) × 3.785

// longitud(km) = longitud(mi) × 1.609
// longitud(mi) = longitud(km) ÷ 1.609


