

#include <stdio.h>

int comparar(int numero_a, int numero_b)

// Funcion que compara dos valores enteros y devuelve un flag
// con valores -1, 1 o 0 de acuerdo a cuál es mayor -o si son iguales-


{
   int bandera = 0;    		// empiezo suponiendo que son iguales - fñag es 0

   if (numero_a < numero_b)   //comparo ambos numeros
      {
		bandera = -1;     //modifico mi flag, que originalmente es cero
	}
   else				//evalúo una sit distinta -pero atento que podrian valores iguales
	{
		if (numero_b < numero_a)  //verifico que no sean iguales ni el caso anterior
			{
			bandera = 1;        //moodifico mi flag que todavía está en cero
			}
	} 
  return bandera;  		//fin

// en caso que los valores ingresados sean iguales, flag = 0 y nunca entró en los condicionales
}

// --------------------------------------

int main(int argc, char *argv[])
{
    int numero_a = 0;
    int numero_b = 0;
    int resultado = 0;

    printf("Ingrese su primer numero :  \n");
    scanf("%d",&numero_a);
    printf("Ingrese el segundo numero : \n");
    scanf("%d",&numero_b);

    resultado = comparar(numero_a, numero_b);
    printf("%d", resultado);
    return 0;
}