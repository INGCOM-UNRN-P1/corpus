
#include <stdio.h>
#define CARACTERES_MAXIMOS_CADENA 50
#define CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR 20
int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i=0;
    int largo=0;
    for (i=0;i<capacidad_cadena;i++){
        if(cadena[largo]!='\0')
        {
            largo=largo+1;
        }else{
            break;
        }
    }
	return largo;
}
int insercion(char *destino, int capacidad_destino, char *insertar, int posicion)
{
    char cadena_destino_auxiliar[CARACTERES_MAXIMOS_CADENA];
    int i,j,k,largo_destino,largo_insertar,largo_total;
    largo_destino=largo_cadena(destino,capacidad_destino);
    largo_insertar=largo_cadena(insertar,CARACTERES_MAXIMOS_CADENA);
    largo_total=largo_destino+largo_insertar;
    if(largo_total>capacidad_destino)
    {
        printf("No se puede insertar la cadena\n");
        return 0;
    }
    j=0;
    k=0;
    for(i=0;i<largo_total;i++)
    {
        if(i<posicion)
        {
            cadena_destino_auxiliar[i]=destino[i];
        }else if(i>posicion && i<=posicion+largo_insertar)
        {
            cadena_destino_auxiliar[i]=insertar[j];
            j++;
        }else{
            cadena_destino_auxiliar[i]=destino[k+posicion];
            k++;
        }
    }
    for(i=0;i<largo_total;i++)
    {
        destino[i]=cadena_destino_auxiliar[i];
    }
    return largo_total;
}
int copiadora(char *origen, char *destino, int capacidad_destino)
{
    int i,j,largo_cadena_origen,largo_cadena_destino,largo_total;
    largo_cadena_origen=largo_cadena(origen,CARACTERES_MAXIMOS_CADENA);
    largo_cadena_destino=largo_cadena(destino,CARACTERES_MAXIMOS_CADENA);
    largo_total=largo_cadena_origen+largo_cadena_destino;
    if(largo_total>capacidad_destino)
    {
        printf("No se puede copiar la cadena\n");
        return 0;
    }
    j=0;
    for(i=largo_cadena_destino;i<largo_total;i++)
    {
        destino[i]=origen[j];
        j++;
    }
    for(i=0;i<largo_cadena_origen;i++)
    {
        origen[i]='\0';
    }
    return largo_total;
}
int limpiadora(char *origen, char *destino, int capacidad_destino)
{
    char caracteres_aceptados[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i,j,k,largo_cadena_origen,largo_cadena_destino,largo_cadena_caracteres_aceptados,largo_cadena_limpiada;
    largo_cadena_origen=largo_cadena(origen,CARACTERES_MAXIMOS_CADENA);
    largo_cadena_destino=largo_cadena(destino,capacidad_destino);
    largo_cadena_caracteres_aceptados=largo_cadena(caracteres_aceptados,65);
    if(largo_cadena_origen>capacidad_destino)
    {
        printf("No se puede limpiar la cadena\n");
        return 0;
    }
    k=0;
    for(i=0;i<largo_cadena_origen;i++)
    {   
        if(origen[i]=='\0'){
            break;
        }
        for(j=0;j<65;j++)
        {   
            if(caracteres_aceptados[j]==origen[i])
            {   
                destino[k]=origen[i];
                k++;
            }          
        }
    }
    largo_cadena_limpiada=largo_cadena(destino,capacidad_destino);
    return largo_cadena_limpiada;    
}
int inversor(char *origen, char *destino, int capacidad_destino)
{
    int i,j,largo_cadena_origen,largo_cadena_destino;
    largo_cadena_origen=largo_cadena(origen,CARACTERES_MAXIMOS_CADENA);
    largo_cadena_destino=largo_cadena(destino,capacidad_destino);
    if(largo_cadena_origen>capacidad_destino)
    {
        printf("No se puede invertir la cadena\n");
        return 0;
    }
    for(i=0;i<largo_cadena_origen;i++)
    {
        destino[i]=origen[largo_cadena_origen-i-1];
    }
    destino[largo_cadena_origen]='\0';
    return 1;
    
}
int compara(char* primera, char *segunda)
{
    
}
int es_palindromo(char *cadena, int largo)
{
    char cadena_auxiliar[largo];
    char caracteres_aceptados_minuscula[32]="abcdefghijklmnopqrstuvwxyz";
    char caracteres_aceptados_mayuscula[32]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int posee,i,j,largo_cadena_espalindromo;
    largo_cadena_espalindromo=largo_cadena(cadena,largo);
    posee=1;
    for(i=0;i<largo_cadena_espalindromo;i++)
    {
        if(cadena[i]=='\0'){
            posee=0;
            break;
        }
    }
    if(posee!=1)
    {
        printf("la cadena no posee \\0\n");
    }
    for(i=0;i<largo_cadena_espalindromo;i++)
    {

        for(j=0;j<32;j++)
        {   
            if(cadena[i]==caracteres_aceptados_mayuscula[j] || cadena[i]==caracteres_aceptados_minuscula[j])
            {      
                cadena_auxiliar[i]=caracteres_aceptados_minuscula[j];
                break;
            }
        }
    }
    cadena_auxiliar[largo_cadena_espalindromo]='\0';
    for(i=1;i<largo_cadena_espalindromo;i++)
    {
        if(cadena_auxiliar[largo_cadena_espalindromo-i]!=cadena_auxiliar[i-1])
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[])
{
    char cadena_solicitada[CARACTERES_MAXIMOS_CADENA];
    char cadena_solicitada_a_insertar[CARACTERES_MAXIMOS_CADENA];
    char cadena_sin_limpiar[CARACTERES_MAXIMOS_CADENA]="Estacadena[noesta]{++}limpia";
    char cadena_limpiada[CARACTERES_MAXIMOS_CADENA];
    char cadena_a_invertir[CARACTERES_MAXIMOS_CADENA]="Hola";
    char cadena_es_palindromo[CARACTERES_MAXIMOS_CADENA];
    char cadena_invertida[CARACTERES_MAXIMOS_CADENA];
    int tamanio_caracteres_ingresados,tamanio_caracteres_ingresados_cadena_insertar,largo_cadena_es_palindromo;
    int posicion,resultado_insercion,resultado_copiadora,resultado_limpiadora,resultado_inversor,resultado_compara,resultado_es_palindromo;
    while(1)
    {
        printf("Ingrese una cadena menor a %d caracteres: ",CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);
        scanf("%s",&cadena_solicitada);
        tamanio_caracteres_ingresados=largo_cadena(cadena_solicitada,CARACTERES_MAXIMOS_CADENA);
        if(tamanio_caracteres_ingresados>CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR)
        {
            printf("\nIntentelo nuevamente\n");
        }else{
            break;
        }
    }
    printf("\nLa cadena %s tiene %d caracteres\n",cadena_solicitada,tamanio_caracteres_ingresados);
    while(1)
    {
        printf("Ingrese otra cadena menor a %d caracteres para insertar en %s: ",CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR,cadena_solicitada);
        scanf("%s",&cadena_solicitada_a_insertar);
        tamanio_caracteres_ingresados_cadena_insertar=largo_cadena(cadena_solicitada_a_insertar,CARACTERES_MAXIMOS_CADENA);
        if(tamanio_caracteres_ingresados_cadena_insertar>CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR)
        {
            printf("\nIntentelo nuevamente\n");
        }else{
            break;
        }
    }
    while(1)
    {
        printf("Ingrese un numero natural menor a %d para indicar la posicion desde donde desea insertar la cadena %s: ",tamanio_caracteres_ingresados,cadena_solicitada_a_insertar);
        scanf("%d",&posicion);
        if(posicion>tamanio_caracteres_ingresados || posicion<0)
        {
            printf("\nIntentelo nuevamente\n");
        }else{
            break;
        }
    
    }
    printf("\nLa cadena %s se intertara en %s en la posicion %d\n",cadena_solicitada_a_insertar,cadena_solicitada,posicion);
    resultado_insercion=insercion(cadena_solicitada, CARACTERES_MAXIMOS_CADENA, cadena_solicitada_a_insertar, posicion);
    printf("\nLa nueva cadena es %s",cadena_solicitada);
    resultado_copiadora=copiadora(cadena_solicitada,cadena_solicitada_a_insertar,CARACTERES_MAXIMOS_CADENA);
    printf("\nLa nueva cadena copiada es %s ",cadena_solicitada_a_insertar);
    printf("\nLa cadena inicial ahora tiene el valor %s",cadena_solicitada);
    resultado_limpiadora=limpiadora(cadena_sin_limpiar,cadena_limpiada,CARACTERES_MAXIMOS_CADENA);
    printf("\nLa cadena sin limpiar es %s, la cadena limpiada es %s\n",cadena_sin_limpiar,cadena_limpiada);
    resultado_inversor = inversor(cadena_a_invertir,cadena_invertida,CARACTERES_MAXIMOS_CADENA);
    printf("\nLa cadena a invertir es %s, la cadena invertida es %s\n",cadena_a_invertir,cadena_invertida); 
    printf("\nIngrese una cadena menor a %d caracteres: ",CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);
    scanf("%s",&cadena_es_palindromo);
    largo_cadena_es_palindromo=largo_cadena(cadena_es_palindromo,CARACTERES_MAXIMOS_CADENA);
    resultado_es_palindromo = es_palindromo(cadena_es_palindromo,largo_cadena_es_palindromo);
    printf("\nLa cadena %s ",cadena_es_palindromo);
    if(resultado_es_palindromo==1)
    {
        printf("es palindromo");
    }else{
        printf("no es palindromo");
    }
	return 0;
}
