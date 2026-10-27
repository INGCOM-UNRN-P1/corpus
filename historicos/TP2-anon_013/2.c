

//Trabajo práctico 2:
//Ejercicio 2: Función producto y función potencia

#include <stdio.h>
int funcion_producto(int A, int B)
{
    int producto;
    producto=A*B;
    printf("\nn*m = %d\n", producto);
}
int funcion_potencia(int x, unsigned n)
{
    int pow=1;
    while (n)
    {
        if (n&1)
            pow*=x;
        n=n>>1;
        x=x*x;
    }
    printf("n^m = %d\n", pow);
    return pow;
}
void main()
{
    int n, m;
    printf("Ingrese dos numeros.\n");
    scanf("%d%d", &n, &m);
    funcion_producto(n, m);
    funcion_potencia(n, m);
}
