


 // #include <stdio.h>

int es_primo(int numero)
{
    int bandera = 1;
    if(numero <= 1)
    {
        bandera = 0;
    }
    else
    {
        for(int i = 2; i < numero; i++)
        {
            if (numero % i == 0)
            {
                bandera = 0;
            }
        }
    }
    return bandera;
}


// main para testing
// int main ()
// {
//     int numero = 0;
//     printf("Ingresar numero: ");
//     scanf("%d", &numero);
//     if(es_primo(numero)==1)
//     {
//         printf("Es primo\n");
//     }
//     else
//     {
//         printf("No es primo\n");
//     }
//     return 0;
// }

int proximo_primo(int numero_base)
{
    int siguiente_primo = 0;
    if(numero_base < 2)
    {
        siguiente_primo = 2;
    }
    else
    {
        for (int i = numero_base + 1; siguiente_primo == 0 ; i++)
        {
            if(es_primo(i) == 1)
            {
                siguiente_primo = i;
            }
        }
    }
    return siguiente_primo;
}

//main para testing
// int main ()
// {
//     int numero = 0;
//     printf("Ingresar numero: ");
//     scanf("%d", &numero);
    
//     printf("Proximo primo: %d\n", proximo_primo(numero));
//     return 0;
// }

int cantidad_divisores(int numero)
{
    int cant_divisores = 0;
    if(numero <= 0) {}
    else
    {
        for(int i = 1; i <= numero; i++)
        {
            if (numero % i == 0)
            {
                cant_divisores = cant_divisores + 1;
            }
        }
    }
    return cant_divisores;
}