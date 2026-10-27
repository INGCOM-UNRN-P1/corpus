
#include <stdio.h>

int triangulo_rectangulo(int n);

int main(int argc, char *argv[])
{
    int n = 0;

    while (n < 1) //chequea que el numero n sea natural
    {
        printf("Ingrese un número: ");
        scanf("%d", &n);
    }
    
    triangulo_rectangulo(n);


}


int triangulo_rectangulo(int n)
{

    for (int i = 0; i < n; i++) // imprime un triangulo rectangulo de n asteriscos por lado
    {   
        
        for (int j = i; j < n ; j++)// imprime una linea de asteriscos, siendo la siguiente de 1 asterisco menor de longitud hasta llegar a n - (n-1)
        {
            printf("*");
        }
        
        

        printf("\n");//imprime una nueva linea n veces
    }
    
    return 0;

}