




	
# include <stdio.h>

int IngresoNumeroEntero();
int Producto(int n, int m);
int Potencia(int n, int m);

int main()
{
    int n;
    int m;
    int resultado;
    
    
    
    
    
    printf("\nIngrese dos numeros naturales para calcular el producto entre ellos y la potencia entre el primero elevado al segundo: ");
    
    printf("\nNumero 1: ");
    n = IngresoNumeroEntero();
    printf("Numero 2: ");
    m = IngresoNumeroEntero();
    
    resultado = Producto(n, m);
  
    printf("El resultado de multiplicar %d por %d es: %d", n, m, resultado);

    
    
     
    resultado = Potencia(n, m);
  
    printf("\nEl resultado de elevar %d a la %d es: %d", n, m, resultado);
}





int Producto(int n, int m)
{
    return n * m;
}





int Potencia(int base, int exponente)
{
    int i;
    int resultado = base;
    
    for (i=1; i<exponente; i++)
    {
        resultado = base * resultado;
    }
    
    return resultado;
    
}





int IngresoNumeroEntero()
{
    int numero = -1;
    
    while(numero < 0)
    {
        scanf("\n%d", &numero);
        if(numero < 0)
        {
            printf("El numero ingresado es menor a 0. Por favor ingrese otro numero mayor o igual a 0: ");
        }
    }
	return numero;
}