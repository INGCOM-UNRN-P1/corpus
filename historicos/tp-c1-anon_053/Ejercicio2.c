

#include <stdio.h>

float conv_fahr(float centi);
float conv_centi(float fahr);

float main()
{

    float centi;
    float fahr;
    float resul;
    float res;
    
    printf("Ingrese valor en Fahrenheit: \n");
    scanf("%f", &fahr);
    
    resul=conv_centi(fahr) ;
    printf("El valor en centigrados es: %f\n",resul);
    
    printf("Ingrese valor en Centigrados: \n");
    scanf("%f",&centi);
    
    res= conv_fahr(centi);
    printf("El valor en fahrenheit es: %f\n",res);
    
    return 0;
}

float conv_fahr(float centi)
{
    float resul;
    resul = (centi * 9 / 5) + 32;
    
    return resul;
}

float conv_centi(float fahr)
{
    float res;
    res = (fahr - 32)* 5/9;
   
      
    return res;
}
