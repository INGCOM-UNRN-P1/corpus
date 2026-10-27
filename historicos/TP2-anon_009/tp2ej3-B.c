
#include <stdio.h>
 
int combinatorio(unsigned int n, unsigned int k);

int main(int argc, char *argv[])
{   
    unsigned int n = 0;
    unsigned int k = 0;

    while(n < 1) //chequea que el numero n sea natural
    {
        printf("Ingrese un numero n que sea natural: ");
        scanf("%d", &n);
    };

   while(k < 1 || k > n) //chequea que el numero k sea natural y menor que n
    {
        printf("Ingrese un numero k que sea natural y menor o igual que n: ");
        scanf("%d", &k);
    };
   
   printf("El combinatorio de %i y % i es: %d\n", n, k, combinatorio(n, k));
   

}



int combinatorio(unsigned int n, unsigned int k)
{

    double num = n;//Almacena el numero fractorial de n.

    for (int i = n - 1; i > 0; i--)//Loop entre todos los numeros desde n hasta 0, multiplicandolos entre si.
    {
         num = num * i;
    }


    double num1 = k;//Almacena el numero fractorial de k.

    for (int i = k - 1; i > 0; i--)//Loop entre todos los numeros desde k hasta 0, multiplicandolos entre si.
    {
        num1 = num1 * i;
    }

    double num2 = n - k; //almacena el numero fractorial de (n-k).
    for (int i = n - k - 1; i > 0; i--)//Loop entre todos los numeros desde n - k hasta 0, multiplicandolos entre si.
    {
        num2 = num2 * i;
    }

    double resultado = num/(num1 * num2);//calcula el combinatorio y lo almacena en la variable resultado.

    
    return resultado;



}

