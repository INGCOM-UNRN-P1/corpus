
#include <stdio.h>
//Declaracion funcion
int suma_lenta(int numero, int otro_numero);

int main()
{
    int numero = 4;
    int otro_numero = 3;
    //se asigna la funciom a una variable 
    int suma = suma_lenta(numero, otro_numero);

    printf("\n%d",suma);
    return 0;
}

int suma_lenta(int numero, int otro_numero)
{
    int resultado = numero + otro_numero;//
    printf("%d\n", numero);
    while(numero < resultado)//condicion donde el numero tiene que ser menor al resultado    
    {
        int i = 1;        
        printf("+%d\n", i);
        numero = numero + 1;//a numero se le suma 1 en cada vuelta hasta llegar al valor del resultado
    }
    return resultado;
}
// pre: recibe 2 numeros enteros 
// pos: retorna n +1, +1, +1


