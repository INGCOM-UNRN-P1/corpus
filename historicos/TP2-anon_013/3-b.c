

//Trabajo práctico 2:
//Ejercicio 3-b: Combinatorio de n sobre m

#include<stdio.h>
void main()
{
   int n, m, factorial_n=1, factorial_m=1, factorial_n_menos_m=1, combinatorio;
   printf("Ingrese dos numeros.\n");
   scanf("%d%d", &n, &m);
   for (int i=1; i<=n; i++)
   {
       factorial_n=factorial_n*i;
   }
   for (int i=1; i<=m; i++)
   {
       factorial_m=factorial_m*i;
   }
   for (int i=1; i<=n-m; i++)
   {
       factorial_n_menos_m=factorial_n_menos_m*i;
   }
   combinatorio=factorial_n/factorial_m/factorial_n_menos_m;
   printf("\nCombinatorio de %d sobre %d es: %d.\n", n, m, combinatorio);
}
