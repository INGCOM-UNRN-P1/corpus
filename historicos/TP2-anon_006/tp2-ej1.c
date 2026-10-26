/****************************************************************
Ingenieria en Computación - UNRN Andina
Programación 1
Trabajo Práctico 2: Problemas Formalizados
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*****************************************************************/

/**********************************************************************************/
        


/**********************************************************************************/

# include <stdio.h>

int Raiz(int radicando);
int IngresoNumeroEntero();
void ImprimeResultado(int resultado, int radicando);

int main()
{
    int n = 0;
    int m = 0;
    int resultado;
    
    /**********/
    
    /**********/
    
    printf("\nInciso A");
    printf("\nIngrese un numero mayor a 0 para calcular su raiz cuadrada: ");
    
    n = IngresoNumeroEntero();

    resultado = Raiz(n);
    
    ImprimeResultado(resultado, n);
    
    printf("\n");
    
    /**********/
    
    /**********/
    
    n = 0;
    
    printf("\nInciso B");
    printf("\nIngrese dos numeros mayores a 0 para calcular sus respectivas raices: ");
    
    printf("\nNumero 1: ");
    n = IngresoNumeroEntero();
    printf("Numero 2: ");
    m = IngresoNumeroEntero();
 
    resultado = Raiz(n);
    ImprimeResultado(resultado, n);
    printf("\n");
    resultado = Raiz(m);
    ImprimeResultado(resultado,m);
    
    printf("\n");
}

/********************************************/

/********************************************/

int IngresoNumeroEntero()
{
    int numero;
    
    while(numero < 1)
    {
        scanf("\n%d", &numero);
        if(numero < 1)
        {
            printf("El numero ingresado es menor o igual a 0. Por favor ingrese otro numero mayor o igual a 1 para calcular su raiz: ");
        }
    }
}

/******************************************/

/******************************************/
    
int Raiz(int radicando)
{
    int i;
    int resultado;
    
    for (i=1; i<radicando; i++)
    {
        resultado = i*i;
        
        if (resultado == radicando)
        {
            return i;
        }
        
        if (resultado > radicando) 
        {
            return i - 1;
        }
    }    
}

/***************************/

/***************************/

void ImprimeResultado(int resultado, int radicando)
{
    if(resultado * resultado == radicando)
    {
        printf("La raiz cuadrada de %d es: %d", radicando, resultado);
    }
    else
    {
        printf("La parte entera de la raiz cuadrada de %d es: %d", radicando, resultado);
    }
}
