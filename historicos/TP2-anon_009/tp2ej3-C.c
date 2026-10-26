/************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>

int todos_los_combinatorios(unsigned int n);

int main(int argc, char *argv[])
{

    unsigned int n = 0;
    
    while(n < 1)
    {
        printf("Ingrese un numero n que sea natural: ");
        scanf("%d", &n);
    };

    todos_los_combinatorios(n);

    

}


int todos_los_combinatorios(unsigned int n)
{

    int m = n - 1;
   
    double num = n;//Almacena el numero fractorial de n.

    for (int i = n - 1; i > 0; i--)//Loop entre todos los numeros desde n hasta 0, multiplicandolos entre si.
    {
        num = num * i;
    }

    
    for (int j = 0; j < n - 1; j++)//hace un loop entre todos los valores de 1<= m <n y calcula su combinatorio.
    {
    
    
    

        double num1 = m;//Almacena el numero fractorial de m.

        for (int i = m - 1; i > 0; i--)//Loop entre todos los numeros desde k hasta 0, multiplicandolos entre si.
        {
            num1 = num1 * i;
        }
    
    

        double num2 = n - m; //almacena el numero fractorial de (n-m).

        for (int i = n - m - 1; i > 0; i--)//Loop entre todos los numeros desde n - m hasta 0, multiplicandolos entre si.
        {
            num2 = num2 * i;
        }

        double resultado = num/(num1 * num2);//calcula el combinatorio y lo almacena en la variable resultado.

        printf("El combinatorio de %i y % i es: %0.f\n", n, m, resultado);
        
        m = m - 1;


        
    
    }


    return 0;   

}