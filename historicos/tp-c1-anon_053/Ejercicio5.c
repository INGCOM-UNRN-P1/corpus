

#include <stdio.h>

int suma_lenta(int num, int otro_num);

int main()
{
  int num, otro_num;
  
  printf("Ingrese numeros a sumar:\n");
  scanf("%d ", &num);
  scanf("%d", &otro_num);
  printf("La suma de los nros es: %d\n", suma_lenta(num, otro_num));
  return 0;
}

int suma_lenta(int num, int otro_num)
{
    
    int res = num + otro_num;
        while(num<res){ 
            int i = 1;
            printf("+%d\n",i );
            num=num + 1;         
        }                
    return res;
}
    
    
