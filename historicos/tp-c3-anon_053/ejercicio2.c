

#include <stdio.h>

typedef struct division{
    int numerador;
    int denominador;
}division_t;

typedef struct resultado{
    int cociente;
    int resto;
}res_t;

res_t division_lenta(division_t datos_entrada, res_t datos_salida);

int main()
{
    division_t datos_entrada;
    res_t datos_salida;
    
    printf("Ingrese el dividendo: \n");
    scanf("%d", &datos_entrada.numerador);
    
    printf("Ingrese el divisor: \n");
    scanf("%d", &datos_entrada.denominador);
    
    res_t resultado_division = division_lenta(datos_entrada, datos_salida);
    printf("El cociente es: %d\nEl resto es: %d\n", resultado_division.cociente, resultado_division.resto);
    return 0;
}
//funcion que retorna cociente y resto mediante restas sucesivas
res_t division_lenta(division_t datos_entrada, res_t datos_salida)
//precondicion recibe dos numeros enteros
//poscondicion retorna dos numeros enteros resto y cociente de division

{
    res_t res;    
    res.cociente = 0;
    res.resto = datos_entrada.numerador;
    
    while (res.resto >= datos_entrada.denominador)
    {
        res.resto = res.resto - datos_entrada.denominador;
        res.cociente ++;
    }

   return res;
   
}
