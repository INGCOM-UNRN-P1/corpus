

#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int resto_lento(int dividendo, int divisor)
// Precondiciones: Los valores de entrada tienen que ser de tipo entero y el divisor debe ser distinto de 0
// Postcondiciones: Devolverá el resto de la división entre el dividendo y el divisor
{
    int resto = dividendo;
    if (dividendo > 0 && divisor > 0)
    {
        while (resto >= divisor)
        {
            resto = resto - divisor;
        }
        return resto;
    }
    else if (dividendo < 0 && divisor > 0)
    {
        while (resto <= divisor * -1)
        {
            resto = resto + divisor;
        }
        return resto;
    }
    else if (dividendo > 0 && divisor < 0)
    {
        while (resto >= divisor * -1)
        {
            resto = resto + divisor;
        }
        return resto;
    }
    else if (dividendo < 0 && divisor < 0)
    {
        while (resto <= divisor)
        {
            resto = resto - divisor;
        }
        return resto;
    }
}

int cociente_lento(int dividendo, int divisor)
// Precondiciones: Los valores de entrada tienen que ser de tipo entero y el divisor debe ser distinto de 0
// Postcondiciones: Devolverá el cociente de la división entre el dividendo y el divisor
{
    int cociente = 0;
    int resto = dividendo;
    if (dividendo > 0 && divisor > 0)
    {
        while (resto >= divisor)
        {
            resto = resto - divisor;
            cociente = cociente + 1;
        }
        return cociente;
    }
    else if (dividendo < 0 && divisor > 0)
    {
        while (resto <= divisor * -1)
        {
            resto = resto + divisor;
            cociente = cociente - 1;
        }
        return cociente;
    }
    else if (dividendo > 0 && divisor < 0)
    {
        while (resto >= divisor * -1)
        {
            resto = resto + divisor;
            cociente = cociente - 1;
        }
        return cociente;
    }
    else if (dividendo < 0 && divisor < 0)
    {
        while (resto <= divisor)
        {
            resto = resto - divisor;
            cociente = cociente + 1;
        }
        return cociente;
    }
}

int main()
{
    int dividendo;
    int divisor;
    float dividendoFloat;
    float divisorFloat;
    int cociente;
    int resto;
    printf(ANSI_COLOR_CYAN "\nEjercicio 6: Divisiones" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de dos números enteros, indicar el valor del cociente y el resto entre ellos\n\n");
    printf("Introduzca el dividendo: ");
    fflush(stdout);
    scanf("%f", &dividendoFloat);
    // Validación de número entero
    dividendo = dividendoFloat;
    if (dividendoFloat - dividendo)
    {
        printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero\n");
    }
    else
    {
        printf("Introduzca el divisor: ");
        fflush(stdout);
        scanf("%f", &divisorFloat);
        // Validación de número entero
        divisor = divisorFloat;
        if (divisorFloat - divisor)
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero\n");
        }
        else
        {
            // Validación distinto de 0
            if (divisor != 0)
            {
                cociente = cociente_lento(dividendo, divisor);
                resto = resto_lento(dividendo, divisor);
                printf("%d / %d = %d\n", dividendo, divisor, cociente);
                printf("Resto: %d\n", resto);
            }
            else
            {
                printf(ANSI_COLOR_RED "Error! El divisor no puede ser 0\n");
            }
        }
    }
    return 0;
}

//--------------------- OTRA RESOLUCIÓN CON UNA SOLA FUNCIÓN -----------------------------
// // Defino una estructura para almacenar los valores de cociente y resto dentro de "un solo valor"
// struct Division
// {
//     // Declaro el tipo y el nombre de las variables que contiene la estructura
//     int cociente, resto;
// };
//
// struct Division division_lenta(int dividendo, int divisor)
// {
//     // Inicializo la estructura y le asigno los valores
//     struct Division division = {0, dividendo};
//     // Accedo al valor "resto" de la estructura
//     if (dividendo > 0 && divisor > 0)
//     {
//         while (division.resto >= divisor)
//         {
//             division.resto = division.resto - divisor;
//             division.cociente++;
//         }
//         return division;
//     }
//     else if (dividendo < 0 && divisor > 0)
//     {
//         while (division.resto <= divisor * -1)
//         {
//             division.resto = division.resto + divisor;
//             division.cociente--;
//         }
//         return division;
//     }
//     else if (dividendo > 0 && divisor < 0)
//     {
//         while (division.resto >= divisor * -1)
//         {
//             division.resto = division.resto + divisor;
//             division.cociente--;
//         }
//         return division;
//     }
//     else if (dividendo < 0 && divisor < 0)
//     {
//         while (division.resto <= divisor)
//         {
//             division.resto = division.resto - divisor;
//             division.cociente++;
//         }
//         return division;
//     }
// }
// int main()
// {
//     int dividendo;
//     int divisor = 0;
//     printf("Introduzca el dividendo: ");
//     fflush(stdout);
//     scanf("%d", &dividendo);
//     while (divisor == 0)
//     {
//         printf("Introduzca el divisor: ");
//         fflush(stdout);
//         scanf("%d", &divisor);
//         if (divisor == 0)
//         {
//             printf("El divisor no puede ser 0\n");
//             fflush(stdout);
//         }
//     }
//     struct Division division = division_lenta(dividendo, divisor);
//     int cociente = division.cociente;
//     int resto = division.resto;
//     printf("%d / %d = %d\n", dividendo, divisor, cociente);
//     printf("Resto: %d\n", resto);
//     return 0;
// }