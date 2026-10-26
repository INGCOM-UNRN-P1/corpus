

#include <stdio.h>
#include <stdlib.h>

typedef struct fraccion
{
    int numerador;
    int denominador;
} fraccion_t;

int gcd(int numerador, int denominador)
//Pre: numerador, cualquier entero.
//Pre: denominador, cualquier entero mayor a zero.
//Post: numerador, cualquier entero.
//Argumento numerador: el numerador de la fracción.
//Argumento denominador el denominador de la facción.
//Retorno: numerador.
{
    int resultado;
    while (denominador != 0)
    {
        resultado = numerador % denominador;
        numerador = denominador;
        denominador = resultado;
    }
    return numerador;
}

int lcm(int a, int b)
//Pre: a, cualquier entero.
//Pre: b, cualquier entero.
//Post: a, b, cualquier entero.
//Argumento a: valor para comparar el denominador.
//Argumento b: valor para comprarar el denominador.
//Retorno: a, b.
{
    return (a / gcd(a,b)) * b;
}

fraccion_t simplificar (fraccion_t a)
//Pre: fraccion_t a, cualquier entero.
//Post: a, cualquier entero.
//Argumento a: valor para simplificar la fracción.
//Retorno: a.
{
    int cd;
    cd = gcd(a.numerador, a.denominador);
    a.numerador /= cd;
    a.denominador /= cd;
    return a;
}

fraccion_t sumar (fraccion_t a, fraccion_t b)
//Pre: fraccion_t a, cualquier entero.
//Pre: fraccion_t b, cualquier entero.
//Post: sum, cualquier entero.
//Argumento a: primera fracción para sumar.
//Argumento b: segunda fracción para sumar.
//Retorno: sum, resultado de la suma.
{
    fraccion_t sum;
    int lcmd;
    a = simplificar(a);
    b = simplificar(b);
    lcmd = lcm(a.denominador, b.denominador);
    sum.numerador = (lcmd / a.denominador * a.numerador) + lcmd / b.denominador * b.numerador;
    sum.denominador = lcmd;
    return simplificar(sum);
}

void swap(int *a, int *b)
//Pre: *a, cualquier entero.
//Pre: *b, cualquier entero.
//Post: a,b,tmp, cualquier entero.
//Argumento a: hacer swap de ubicación de memoria.
//Argumento b: hacer swap de ubicación de memoria.
//Retorno: a,b, swap de memoria.
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

fraccion_t multiplicar (fraccion_t a, fraccion_t b)
//Pre: fraccion_t a, cualquier entero.
//Pre: fraccion_t b, cualquier entero.
//Post: mul, cualquier entero.
//Argumento a: primera fracción para multiplicar.
//Argumento b: segunda fracción para multiplicar.
//Retorno: mul, resultado de la multiplicación.
{
    fraccion_t mul;
    a = simplificar(a);
    b = simplificar(b);
    swap(&a.numerador, &b.numerador);
    a = simplificar(a);
    b = simplificar(b);
    mul.numerador = (a.numerador * b.numerador);
    mul.denominador = (a.denominador * b.denominador);
    return mul;
}

void mostrar (fraccion_t a)
//Pre: fraccion_t a, cualquier entero.
//Post: a, cualquier entero.
//Argumento a: valores de la fracción.
//Retorno: a, fracción a mostrar.
{
    a = simplificar(a);
    printf("%d/%d\n", a.numerador, a.denominador);
}

fraccion_t sumentero (fraccion_t a, int entero)
//Pre: fraccion_t a, cualquier entero.
//Pre: entero, cualquier entero.
//Post: sum, cualquier entero.
//Argumento a: fracción para sumar.
//Argumento entero: entero para sumar.
//Retorno: a, resultado de la suma.
{
    //a.numerador = (a.numerador * entero) + entero;
    //a.denominador = (a.denominador * entero) + entero;
    entero = entero * a.denominador;
    a.numerador = a.numerador + entero;
    a = simplificar(a);
    return a;
}

int main()
{
    int a;
    int b;
    int entero;
    fraccion_t f1, f2, res;

    printf("Escriba el numerador de la primer fracción: \n");
    scanf("%d", &f1.numerador);
    printf("Escriba el denominador de la primer fracción: \n");
    scanf("%d", &f1.denominador);
    printf("Escriba el numerador de la segunda fracción: \n");
    scanf("%d", &f2.numerador);
    printf("Escriba el denominador de la segunda fracción: \n");
    scanf("%d", &f2.denominador);
    printf("Escriba el entero que desea sumar a las fracciones: \n");
    scanf("%d", &entero);

    printf("La primer fracción ingresada es: \n");
    mostrar(f1);
    printf("La segunda fracción ingresada es: \n");
    mostrar(f2);
    printf("La suma de fracciones es: \n");
    res = sumar(f1, f2);
    mostrar(res);
    printf("La multiplicación de fracciones es: \n");
    res = multiplicar(f1, f2);
    mostrar(res);
    printf("La suma de un entero en la primer fracción es: \n");
    res = sumentero(f1, entero);
    mostrar(res);
    printf("La suma del entero en la segunda fracción es: \n");
    res = sumentero(f2, entero);
    mostrar(res);
    return 0;
}