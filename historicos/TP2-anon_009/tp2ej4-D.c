
#include <stdio.h>

int linea (int n);
 
int main(int argc, char *argv[])
{
    int n = 0;

    while (n < 1)//chequea que el numero n sea natural
    {
        printf("Ingrese un número: ");
        scanf("%d", &n);
    }

    linea(n);
}



int linea (int n)
{

    for (int i = 0; i < n; i++)//imprime una linea de asteriscos de longitud n
    {
        printf("*");
    }
  
   return printf("\n");

}