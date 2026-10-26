

#include <stdio.h>


int contador_circular(int i, int limite);

//int vueltas(int cuenta);//cuenta la cantidad de repeticiones que quiera que se tengan

//pre:Se necesita que se ingresen 2 numeros enteros
//post:Se devolveran los numeros que hay entre el primer numero y el segundo, imprimiendo un 0 cuando el primer numero sea igual al segundo.
 

int main()
{
    int inicio = 0;
    int limite = 0;
    int maximo = 0; //cantidad de veces que se va a llamar a contador_circular.
    int valor_par = 0;
    int cont = 0; //Cuenta las veces que se llama la funcion y retorna 0
    int aux_inicio = 0;
    
    printf("\n");
    printf("-----------------------------------------------------------\n");
    printf("                     Contador circular                     \n");
    printf("-----------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero de inicio: ");
    scanf("%d",&inicio);
    
    printf("Ingrese el numero limite: ");
    scanf("%d",&limite);
    
    printf("Ingrese cuantas veces se llamara a que cuente: ");
    scanf("%d",&maximo);

    valor_par = inicio;//Guardo inicio en el resultado, que es donde empieza a sumar
    aux_inicio = inicio; //Guardo el valor inicial para que no se pierda
    
    //Es posible con otra funcion?
    while ( cont < maximo) //Mientras el contador de llamadas sea menor al maximo que se indico, sigue llamando
    {
        
        
        inicio = aux_inicio;//guardo el valor de donde tiene que iniciar la cuenta
        
        while (inicio < limite)//mientras el inicio sea menor a el limite, tiene que seguir sumando
        {
            valor_par = contador_circular(valor_par, limite); //Suma 1
            
            if (valor_par == limite)
            {
                valor_par = aux_inicio;//Reinicio el valor de la cuenta al valor de donde tiene que empezar a contar
                printf("0\n");//Imprime 0 por que ya llego al limire
            }
            else
            {
                printf("%d\n",valor_par);//Imprime el valor parcial de la suma
            }
            inicio++;//Modifico la "posicion" de inicio
        } 
        
        cont++; //Suma por cada llegada al limite
    }      
    
}




//pre:Se necesita que se ingresen 2 numeros enteros
//post:Se sumara 1 a  el primer numero

int contador_circular(int i, int limite)
{
    //no tengo que perder la i
    
    if (i<limite)
    {
        i = i + 1;
        //printf("%d\n",i);   
        return i;

    }

}