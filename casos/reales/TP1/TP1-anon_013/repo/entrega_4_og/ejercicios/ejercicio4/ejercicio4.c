

int maximo_comun_divisor(int primer_numero, int segundo_numero)
{
    int max_com_div = 0;
    int mayor = 0;
    int menor = 0;
    int resto = 0;

    if(primer_numero == 0 && segundo_numero == 0)
    {
        max_com_div = -1;
    }
    else
    {
        if(primer_numero > segundo_numero)
        {
            mayor = primer_numero;
            menor = segundo_numero;
        }
        else
        {
            mayor = segundo_numero;
            menor = primer_numero;
        }

        while(menor != 0)
        {
            resto = mayor % menor;
            mayor = menor;
            menor = resto;
        }
        max_com_div = mayor;
    }
    return max_com_div;
}

int minimo_comun_multiplo(int primer_numero, int segundo_numero)
{
    int min_com_mul = 0;
    int max_com_div = maximo_comun_divisor(primer_numero, segundo_numero);

    if(primer_numero <= 0 || segundo_numero <= 0)
    {
        min_com_mul = -1;
    }
    else
    {
        min_com_mul = (primer_numero / max_com_div) * segundo_numero;
    }
    return min_com_mul;
}