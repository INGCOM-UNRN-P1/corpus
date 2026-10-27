

int compara(int numero, int otronumero){

    if (numero<otronumero)
    {
        return -1;
    }
    else if (numero>otronunero)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main(int argc, char const *argv[])
{
    int numA;
    int numB;

    printf("Ingrese numero A: ");
    scanf("%d", &numA);
    printf("Ingrese numero B: ");
    scanf("%d", &numB);

    printf(compara(numA, numB));

    return 0;
}
