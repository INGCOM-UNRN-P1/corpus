

#include <stdio.h>

int es_primo(int numero){
    if (numero == 0 || numero == 1)
    {
        return 1;
    }

    for (int i = 2; i < numero/2; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
        
    }
    return 1;
    
}


int main(int argc, char const *argv[])
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("%d\n", es_primo(num));

    return 0;
}
