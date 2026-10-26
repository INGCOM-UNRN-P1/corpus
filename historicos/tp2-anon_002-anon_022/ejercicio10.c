



#include <stdio.h>



float litros_a_galones(float litro) //convierte los litros a galones 
{
    return (litro/3.785);
}


float galones_litros(float galon) //convierte los galones a litros 
{
    return (galon*3.785);
}



float millas_a_kms(float millas) //convierte las millas a kilometros 
{
    return (millas * 1.609);
}



float kms_millas(float kms) //convierte los kilometros a millas
{
    return (kms / 1.609);
}

int main()
{
   float litro;
   float galon;
   float millas;
   float kms;
   int opcion; 
   printf("Ingrese una opcion \n 1 para convertir de litro a galon \n 2 para convertir de galon a litro \n 3 para convertir de millas a kms \n 4 para convertir de kms a millas\n");
   scanf("%d", &opcion);
   switch (opcion)
   {
   case 1:
        printf("Ingrese la cantidad de litros\n");
        scanf("%f", &litro);
        printf("%.0f Lts equivalen a %.2f galeones", litro, litros_a_galones(litro));
        break;
    case 2:
        printf("Ingrese la cantidad de galeones\n");
        scanf("%f", &galon);
        printf("%.0f galones equivalen a %.2f litros", galon, galones_litros(galon));
        break;
    case 3:
        printf("Ingrese la cantidad de millas\n");
        scanf("%f", &millas);
        printf("%.0f millas equivalen a %.2f kms", millas, millas_a_kms(millas));
        break;
    case 4:
        printf("Ingrese la cantidad de kms\n");
        scanf("%f", &kms);
        printf("%.0f kms equivalen a %.2f millas", kms, kms_millas(kms));
        break;
    default:
        printf("Ingrese una opcion valida");
   }
   return 0;
}