#include <stdio.h>
#include <string.h>
#include <limits.h>

void print_arr(int arr[], size_t cantidad);
char bool_to_char(bool b);

char bool_to_char(bool b)
{
    if (b == true)
    {
        return 't';
    }
    else
    {
        return 'f';
    }
}
void arreglo_invertir(int arreglo[], size_t cantidad)
{
    size_t indice = cantidad - 1;
    for (size_t i = 0; i < cantidad / 2; i++)
    {
        printf("%d \n", i);
        print_arr(arreglo, cantidad);
        int temporal = arreglo[i];
        arreglo[i] = arreglo[indice - i];
        arreglo[indice - i] = temporal;
        print_arr(arreglo, cantidad);

    }
}

void print_arr(int arr[], size_t cantidad)
{
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%-1d ", arr[i]);
    }
    printf("\n");
}


bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool ordenado = true;
    for (size_t i = 0; i < cantidad - 1; i++)
    {
        if (arreglo[i] >= arreglo[i + 1])
        {
            ordenado = false;
        }
    }

    return ordenado;
}


size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    size_t ocurrencias = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        {
            ocurrencias++;
        }
    }
    return ocurrencias;
}

size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, 
                        const int segundo[], size_t cantidad_dos, 
                        int destino[], size_t capacidad)
{
    if (arreglo_ordenado(primero, cantidad_uno) == false || 
        arreglo_ordenado(segundo, cantidad_dos) == false)
    {
        return 0;
    }
    if (cantidad_uno + cantidad_dos > capacidad)
    {
        return 0;
    }

    // https://www.geeksforgeeks.org/c/c-program-for-merge-sort/
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < cantidad_uno && j < cantidad_dos)
    {
        if (primero[i] <= segundo[j])
        {
            destino[k] = primero[i];
            i++;
        }
        else
        {
            destino[k] = segundo[j];
            j++;
        }
        k++;
    }
    while (i < cantidad_uno)
    {
        destino[k] = primero[i];
        i++;
        k++;
    }
    while (j < cantidad_dos)
    {
        destino[k] = segundo[j];
        j++;
        k++;
    }

    return k;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    // Itera sobre todos los caracteres de origen que quepan en destino para 
    // buscar un caracter terminador, de no encontrarlo se entiende que no lo 
    // tenia u origen no cabe en destino y el retorno sera falso.
    bool origen_completo = false;
    size_t largo = 0;
    while(largo < capacidad && origen[largo] != '\0')
    {
        largo++;
    }
    if (largo < capacidad)
    {
        origen_completo = true;
    }

    for (size_t i = 0; i < largo; i++)
    {
        destino[i] = origen[i];
    }
    
    destino[largo] = '\0';

    return origen_completo;
}

bool cadena_completa(const char cadena[], size_t capacidad, size_t *largo)
{
    *largo = 0;
    bool es_completa = false;
    while(*largo < capacidad && cadena[*largo] != '\0')
    {
        *largo = *largo + 1;
    }
    if (*largo < capacidad)
    {
        es_completa = true;
    }
    else
    {
        *largo = *largo - 1;
    }
    return es_completa;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t convertidos = 0;
    size_t i = 0;
    while (i < capacidad || cadena[i] != '\0')
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            convertidos++;
            cadena[i] -= ('a' - 'A');
        }
        i++;
    }

    return convertidos;
}
size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }
    
    size_t contador = 0;
    bool contando = true;
    while (contando == true && contador < capacidad)
    {
        if (cadena[contador] == '\0')
        {
            contando = false;
        }
        else
        {
            contador++;
        }
    }

    return contador;
}

/**
 * Extraer una porción de una cadena origen a partir de una posición inicial
 * ('inicio'), copiando a lo sumo 'cantidad' caracteres en un búfer destino
 * seguro acotado por 'capacidad'. Si capacidad > 0, el destino debe quedar
 * siempre terminado en '\0'. Si inicio supera la longitud de origen, destino
 * debe quedar como cadena vacía ("").
 */
bool cadena_subcadena(char destino[], size_t capacidad_destino, 
                    const char origen[], size_t capacidad_origen, 
                    size_t inicio, size_t cantidad)
{
    if(destino == NULL || 
        origen == NULL ||
        capacidad_destino == 0)
    {
        return false;
    }

    size_t largo_origen = cadena_longitud(origen, capacidad_origen);
    if (inicio > largo_origen)
    {
        destino[0] = '\0';
        return false;
    }

    bool estado_exitoso = true;
    if ((inicio + cantidad) > largo_origen)
    {
        estado_exitoso = false;
    }
    
    if (cantidad > (capacidad_destino - 1))
    {
        cantidad = capacidad_destino - 1;
        estado_exitoso = false;
    }

    size_t i = 0;
    while(i < cantidad && origen[i + inicio] != '\0')
    {
        destino[i] = origen[i + inicio];
        i++;
    }

    destino[i] = '\0';
    return estado_exitoso;
}
void cadena_invertir(char cadena[], size_t capacidad)
{
    size_t i = 0;
    size_t largo = cadena_longitud(cadena, capacidad);
    while (i < largo) {
      
        char temporal = cadena[i];
        cadena[i] = cadena[largo - 1];
        cadena[largo - 1] = temporal;
        i++;
        largo--;
    }
}
/**
 * Convertir un entero con signo ('valor') a su representación textual en
 * base 10 dentro de un búfer destino seguro de tamaño 'capacidad'. 
 * Debe contemplar números negativos (con prefijo '-'), el cero ("0") y el valor
 * extremo INT_MIN. Si la capacidad es insuficiente, colocar '\0' y alertar
 * el error sin generar desbordamiento de búfer.
 */
bool cadena_de_entero(char destino[], size_t capacidad, int valor)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }
    if (valor == 0)
    {
        destino[0] = '0';
        destino[1] = '\0';
        return true;
    }


    bool es_negativo = false;
    bool es_intmin = false;
    if (valor == INT_MIN)
    {
        es_intmin = true;
        valor += 1;
    }
    if (valor < 0)
    {
        valor = -valor;
        es_negativo = true;
    }

    size_t digitos = 0;
    int valor_auxiliar = valor;
    while (valor_auxiliar != 0)
    {
        valor_auxiliar /= 10;
        digitos += 1;
    }
    int espacio_necesario = digitos + es_negativo + es_intmin + 1;
    if (espacio_necesario > capacidad)
    {
        return false;
    }

    size_t i = digitos + es_negativo;
    destino[i] = '\0';
    while(valor != 0)
    {
        int resto = valor % 10;
        // cascotazo salvaje aparece
        if (es_intmin)
        {
            resto++;
            es_intmin = false;
        }
        valor /= 10;
        destino[i - 1] = resto + '0';
        i--;
    }
    if (es_negativo)
    {
        destino[0] = '-';
    }

    return true;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t eliminados = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == valor)
        {
            eliminados++;
            for (size_t j = i; j < cantidad - 1; j++)
            {
                arreglo[j] = arreglo[j+1];
            }
        }
    }
    for(size_t i = (cantidad - eliminados); i < cantidad; i++)
    {
        arreglo[i] = 0;
    }

    return eliminados;
}

int main()
{
    printf("Comenzando test\n");

    int arreglo[10] = {0, 1, 2, 3, 4, 4, 4, 7, 8, 9};
    print_arr(arreglo, 10);

    arreglo_compactar(arreglo, 10, 4);

    print_arr(arreglo, 10);

    printf("Terminando test\n");
    return 0;
}

