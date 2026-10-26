
#include <stdio.h>


typedef struct division_entrada{
    int dividendo;
    int divisor;
} division_entrada_t;

typedef struct division_salida{
    int resto;
    int cociente;  
}division_salida_t;


division_salida_t division_lenta(division_entrada_t division);

int main()
{
    division_entrada_t division;
    division_salida_t resultado_division;
    
    printf("Ingrese el dividendo: ");
    scanf("%d",&division.dividendo);
    
    printf("Ingrese el divisor: ");
    scanf("%d",&division.divisor);
    
    resultado_division = division_lenta(division);
    
    printf("El cociente es: %d y el resto es %d.",resultado_division.cociente, resultado_division.resto);
    
    
}




division_salida_t division_lenta(division_entrada_t division)
{
    division_salida_t res_division;
    
    res_division.resto = division.dividendo;//El resto es lo que sobra de la division
    
    
    while (res_division.resto >= division.divisor)//si todavia se le puede restar, se puede dividir
    {
        //0             5          -5  
        res_division.resto = res_division.resto - division.divisor;//aca resta
        res_division.cociente = res_division.cociente + 1;//La cantidad de veces que se pueda dividir, es el cociente.
        
        
    }
     
    return res_division;//devuelve el resto.  
    
}