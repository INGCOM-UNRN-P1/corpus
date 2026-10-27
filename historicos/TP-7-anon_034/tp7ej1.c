

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_CADENA 32

typedef struct Calculo
{
    long * numeros;
    long cantidadNumeros;
    long cantidadGrupos;
    long * grupos;
    long cantidadOperadores;
    char * operadores;
} Calculo;

typedef struct Datos
{
    bool hayError;
    long cantidadCalculos;
    long * posicionCalculos;
    long posicionFinal;
    Calculo ** calculos;

    long cantidadLineas;
    long * posicionLineas;
} Datos;


// Verifica si el numero ingresado esta dentro del rango estipulado por la consigna.
bool verificarNumero(long numero)
{
    return (numero > -65536 && numero < 65536);
}

void contarLineasYPosiciones(FILE * archivo, Datos * datos)
{
    printf("================================\n");
    printf("Buscando Lineas:\n");
    // Contamos la cantidad de lineas que hay.
    datos->cantidadLineas = 1;
    fseek(archivo, 0 , SEEK_SET);
    while(1)
    {
        char c = fgetc(archivo);
        datos->cantidadLineas += (c == '\n');
        if (c == EOF)
        {
            datos->posicionFinal = ftell(archivo);
            printf("El final del archivo es en la pos: %ld.\n",datos->posicionFinal );
            break;
        }
    }
    printf("Detectadas %ld lineas.\n", datos->cantidadLineas);

    datos->posicionLineas = malloc(datos->cantidadLineas * sizeof(long));

    // Guardamos donde empieza cada linea, para usar despues.
    short pos = 0;
    fseek(archivo, 0 , SEEK_SET);
    datos->posicionLineas[0] = 0;
    for(int i = 1; i < datos->cantidadLineas;)
    {
        pos++;
        char c = fgetc(archivo);
        if (c == '\n')
        {
            datos->posicionLineas[i] = pos;
            //printf("Nueva linea en %d.\n",pos);
            i++;
        }
        if (c == EOF) break;
    }
}

void obtenerNumeros(FILE * archivo, Datos * datos)
{
    if (datos->hayError) return;
    // Busca y obtiene los numeros de cada calculo
    printf("================================\n");
    printf("Buscando Numeros:\n");
    fseek(archivo, 0, SEEK_SET);
    for(int i = 0; i < datos->cantidadCalculos; i++)
    {
        datos->calculos[i]->cantidadNumeros = 0;

        long primeraPos = datos->posicionCalculos[i];
        long ultimaPos = 0;

        if (i == datos->cantidadCalculos - 1)
        {
            ultimaPos = datos->posicionFinal;
        }
        else
        {
            ultimaPos = datos->posicionCalculos[i+1];
        }

        //printf("Calculo %d va desde %ld hasta %ld.\n", i, primeraPos, ultimaPos);

        char buffer[7];
        long currentPos = primeraPos;

        fseek(archivo, primeraPos, SEEK_SET);

        while(currentPos >= primeraPos && currentPos < ultimaPos)
        {
            if (fgets(buffer, 7, archivo) == NULL)
            {
                // Encontró un error, o llego al EoF
                break;
            }

            long numero;
            if (sscanf(buffer, "%ld", &numero) == 1)
            {
                //printf("Calculo %d, se encontro numero: %ld\n", i, numero);
                if (verificarNumero(numero))
                {
                    datos->calculos[i]->cantidadNumeros += 1;
                }
                else
                {
                    datos->hayError = true;
                    printf("Error en calculo %d, %ld esta fuera de rango.\n",i+1, numero);
                    return;
                }
            }
            currentPos = ftell(archivo);
        }

        printf("Calculo %d: Se encontraron %ld numeros.\n", i+1,datos->calculos[i]->cantidadNumeros);
        datos->calculos[i]->numeros = malloc(datos->calculos[i]->cantidadNumeros * sizeof(long));

        currentPos = primeraPos;
        fseek(archivo, primeraPos, SEEK_SET);
        long contadorNumeros = 0;
        while(currentPos >= primeraPos && currentPos < ultimaPos)
        {
            if (fgets(buffer, 7, archivo) == NULL)
            {
                // Encontró un error, o llego al EoF
                break;
            }
            //printf("Buffer: %s", buffer);
            long numero;
            if (sscanf(buffer, "%ld", &numero) == 1)
            {
                //printf("Calculo %d, se encontro numero: %ld\n", i, numero);

                if (verificarNumero(numero))
                {
                    datos->calculos[i]->numeros[contadorNumeros] = numero;
                    contadorNumeros++;
                }
            }
            currentPos = ftell(archivo);
        }
    }
}

void obtenerGrupos(FILE * archivo, Datos * datos)
{
    if (datos->hayError) return;
    printf("================================\n");
    printf("Buscando Grupos:\n");
    fseek(archivo, 0, SEEK_SET);
    for(int i = 0; i < datos->cantidadCalculos; i++)
    {
        datos->calculos[i]->cantidadGrupos = 0;

        long primeraPos = datos->posicionCalculos[i];
        long ultimaPos = 0;

        if (i == datos->cantidadCalculos - 1)
        {
            ultimaPos = datos->posicionFinal;
        }
        else
        {
            ultimaPos = datos->posicionCalculos[i+1];
        }

        char buffer[7];
        long currentPos = primeraPos;

        fseek(archivo, primeraPos, SEEK_SET);

        bool anteriorFueNumero = 0;
        long cantidadNumeros = 0;
        while(currentPos >= primeraPos && currentPos < ultimaPos)
        {
            if (fgets(buffer, 7, archivo) == NULL)
            {
                // Encontró un error, o llego al EoF
                break;
            }

            long numero;
            if (sscanf(buffer, "%ld", &numero) == 1)
            {
                cantidadNumeros++;
                anteriorFueNumero = true;
            }else
            {
                if (anteriorFueNumero)
                {
                    datos->calculos[i]->cantidadGrupos += 1;
                    cantidadNumeros = 0;
                    anteriorFueNumero = false;
                }
            }
            currentPos = ftell(archivo);
        }

        printf("Calculo %d: Se encontraron %ld grupos.\n", i+1,datos->calculos[i]->cantidadGrupos);
        datos->calculos[i]->grupos = malloc(datos->calculos[i]->cantidadGrupos * sizeof(long));

        currentPos = primeraPos;
        fseek(archivo, primeraPos, SEEK_SET);
        long contadorGrupos = 0;
        cantidadNumeros = 0;
        while(currentPos >= primeraPos && currentPos < ultimaPos)
        {
            // Encontró un error, o llego al EoF
            if (fgets(buffer, 7, archivo) == NULL) break;

            long numero;
            if (sscanf(buffer, "%ld", &numero) == 1)
            {
                cantidadNumeros++;
                anteriorFueNumero = true;
            }else
            {
                if (anteriorFueNumero)
                {
                    datos->calculos[i]->grupos[contadorGrupos] = cantidadNumeros;
                    cantidadNumeros = 0;
                    anteriorFueNumero = false;
                    //printf("Grupo %ld, %d\n", contadorGrupos, datos->calculos[i]->grupos[contadorGrupos]);
                    contadorGrupos++;
                }
            }
            currentPos = ftell(archivo);
        }
    }
}

// Se fija si un string tiene solo un tipo de caracter.
bool estaCompuestoPorSoloUnCharRepetido(char * entrada)
{
    char c = entrada[0];
    char leido = ' ';
    bool resultado = true;
    int i = 0;
    do{
        if (entrada[i] == '\0') break;
        resultado = (entrada[i] == c || entrada[i] == '\n');
        if (resultado == false) break;
        i++;
    }while(resultado == true);
    //if (!resultado) printf("Se rompio el ciclo en %d\n", entrada[i]);
    return resultado;
}

void obtenerCalculos(FILE * archivo, Datos * datos)
{
    if (datos->hayError) return;
    printf("================================\n");
    printf("Buscando Calculos:\n");
    char buffer[7];
    datos->cantidadCalculos = 0;

    // itero cada linea en busca de signos '=' para contabilizarlos
    for(int i = 0; i < datos->cantidadLineas; i++)
    {
        fseek(archivo, datos->posicionLineas[i], SEEK_SET);
        fgets(buffer, 7, archivo);
        //printf("En linea %d hay: %s", i+1, buffer);
        if (buffer[0] == '=')
        {
            if (estaCompuestoPorSoloUnCharRepetido(buffer))
            {
                datos->cantidadCalculos++;
            }
            else
            {
                datos->hayError = true;
                printf("Error, multiples operadores en una misma linea. En linea: %d.\n", i);
                return;
            }
        }
    }

    printf("Detectados %ld calculos.\n", datos->cantidadCalculos);

    // Creamos los calculos y las posiciones donde estan los calculos.
    datos->posicionCalculos = malloc(datos->cantidadCalculos * sizeof(long));
    datos->calculos = malloc(datos->cantidadCalculos * sizeof(Calculo));

    for(int i = 0; i < datos->cantidadCalculos; i++)
    {
        datos->calculos[i] = malloc(sizeof(Calculo));
    }

    // Buscar posiciones de los calculos.
    int idxCalculo = 0;
    long primeraPos = 0;
    for (int i = 0; i < datos->cantidadLineas;i++)
    {
        short pos = datos->posicionLineas[i];
        fseek(archivo, pos, SEEK_SET);
        fgets(buffer, 7, archivo);
        if (buffer[0] == '=')
        {
            if (estaCompuestoPorSoloUnCharRepetido(buffer))
            {
                datos->posicionCalculos[idxCalculo] = primeraPos;
                printf("Calculo %d encontrado en linea %ld.\n", idxCalculo+1, primeraPos);
                primeraPos = ftell(archivo);
                idxCalculo++;
            }
            else
            {
                datos->hayError = true;
                printf("Error, multiples operadores en una misma linea. En linea: %d.\n", i);
                return;
            }
        }
    }
}

void obtenerOperadores(FILE * archivo, Datos * datos)
{
    if (datos->hayError) return;
    printf("================================\n");
    printf("Buscando Operadores:\n");

    fseek(archivo, 0, SEEK_SET);
    for(int i = 0; i < datos->cantidadCalculos; i++)
    {
        datos->calculos[i]->cantidadOperadores = 0;

        long primeraPos = datos->posicionCalculos[i];
        long ultimaPos = 0;

        if (i == datos->cantidadCalculos - 1)
        {
            ultimaPos = datos->posicionFinal;
        }
        else
        {
            ultimaPos = datos->posicionCalculos[i+1];
        }

        char buffer[7];
        long currentPos = primeraPos;

        fseek(archivo, primeraPos, SEEK_SET);

        while(currentPos >= primeraPos && currentPos < ultimaPos)
        {
            if (fgets(buffer, 7, archivo) == NULL)
            {
                // Encontró un error, o llego al EoF
                break;
            }

            switch(buffer[0])
            {
                case '-':
                case '+':
                case '*':
                case 'a':
                case '=':
                    if (estaCompuestoPorSoloUnCharRepetido(buffer))
                    {
                        datos->calculos[i]->cantidadOperadores++;
                        //printf("Calculo %d Detectado operador %c\n",i,buffer[0]);
                    }
                    break;
                default:
                    if (buffer[0] != '\n' && (buffer[0] < '0' || buffer[0] > '9'))
                    {
                        datos->hayError = true;
                        printf("Error en calculo %d, operador %c no mapeado.\n",i+1, buffer[0]);
                        return;
                    }
                    break;
            }
            currentPos = ftell(archivo);
        }

        printf("Calculo %d: Se encontraron %ld operadores.\n", i+1,datos->calculos[i]->cantidadOperadores);
        datos->calculos[i]->operadores = malloc(datos->calculos[i]->cantidadOperadores * sizeof(char));

        currentPos = primeraPos;
        fseek(archivo, primeraPos, SEEK_SET);
        long contadorOperadores = 0;
        while(currentPos >= primeraPos && currentPos < ultimaPos)
        {
            // Encontró un error, o llego al EoF
            if (fgets(buffer, 7, archivo) == NULL) break;

            switch(buffer[0])
            {
                case '-':
                case '+':
                case '*':
                case 'a':
                case '=':
                    if (estaCompuestoPorSoloUnCharRepetido(buffer))
                    {
                        datos->calculos[i]->operadores[contadorOperadores] = buffer[0];
                        contadorOperadores++;
                    }
                    break;
                default:
                    if (buffer[0] != '\n' && (buffer[0] < '0' || buffer[0] > '9'))
                    {
                        datos->hayError = true;
                        printf("Error en calculo %d, operador %c no mapeado.\n",i+1, buffer[0]);
                        return;
                    }
                    break;
            }
            currentPos = ftell(archivo);
        }
    }
}

short ObtenerOffsetGrupo(int grpIdx, Calculo * calc)
{
    if (grpIdx >= calc->cantidadGrupos)
    {
        printf("Indice de grupo (%d) mayor al limite(%ld).\n", grpIdx, calc->cantidadGrupos);
        return -1;
    }
    int offset = 0;
    for(int i = 0; i < grpIdx; i++)
    {
        offset += calc->grupos[i];
    }
    return offset;
}

void sumarA(long * resultados,int calcIdx,long numero)
{
    printf("Sumando %ld a %ld.\n", numero, resultados[calcIdx]);
    resultados[calcIdx] += numero;
}

void restarA(long * resultados,int calcIdx,long numero)
{
    printf("Restando %ld a %ld.\n", numero, resultados[calcIdx]);
    resultados[calcIdx] -= numero;
}

void multiplicarA(long * resultados,int calcIdx,long numero)
{
    printf("Multiplicando %ld por %ld.\n", numero, resultados[calcIdx]);
    resultados[calcIdx] *= numero;
}

void asignarA(long * resultados,int calcIdx,long numero)
{
    resultados[calcIdx] = numero;
}

void promediarAnteriores(long * total, long * cant, long numero)
{
    (*total) += numero;
    (*cant) += 1;
    printf("Agregando %ld a Promediar (total: %ld/%ld) = %ld\n", numero, (*total), (*cant), (*total)/(*cant));
}

void calcularResultados(Datos * datos)
{
    if (datos->hayError) return;
    printf("================================\n");
    printf("Calculando Resultados:\n\n");
    for(int calcIdx = 0; calcIdx < datos->cantidadCalculos; calcIdx++)
    {
        printf("Calculando Resultado #%d\n", calcIdx+1);
        long * resultados = malloc(datos->calculos[calcIdx]->cantidadGrupos * sizeof(long));
        resultados[calcIdx] = 0;

        // Dato General
        bool primerValor = true;

        // Datos para el Promedio
        long promedioTotal = 0;
        long promedioCantN = 0;

        for(int grpIdx = 0; grpIdx < datos->calculos[calcIdx]->cantidadGrupos; grpIdx++)
        {
            char operador = datos->calculos[calcIdx]->operadores[grpIdx];
            long * numeros = malloc(datos->calculos[calcIdx]->cantidadNumeros * sizeof(long));

            short inicio = ObtenerOffsetGrupo(grpIdx, datos->calculos[calcIdx]);
            for(int nIdx = inicio; nIdx < inicio+datos->calculos[calcIdx]->grupos[grpIdx]; nIdx++)
            {
                long numero = datos->calculos[calcIdx]->numeros[nIdx];
                //printf("Calculo %d, Grupo %d, Numero %d: %ld\n", calcIdx, grpIdx, nIdx, numero);
                switch(operador)
                {
                    case '+':
                        sumarA(resultados, calcIdx,numero);
                        break;
                    case '-':
                        if (primerValor && datos->calculos[calcIdx]->grupos[grpIdx] == 1)
                        {
                            restarA(resultados, calcIdx, numero);
                        }
                        else if (primerValor)
                        {
                            asignarA(resultados,calcIdx, numero);
                        }
                        else
                        {
                            restarA(resultados, calcIdx, numero);
                        }
                        break;
                    case '*':
                        resultados[calcIdx] += (primerValor);
                        multiplicarA(resultados, calcIdx, numero);
                        break;
                    case 'a':
                        promediarAnteriores(&promedioTotal, &promedioCantN, numero);
                        break;
                    default:
                        break;
                }
               primerValor = false;
            }

            if (promedioCantN > 0)
            {
                resultados[calcIdx] = promedioTotal / promedioCantN;
                promedioTotal = resultados[calcIdx];
                promedioCantN = 1;
            }
        }

        if (datos->calculos[calcIdx]->operadores[datos->calculos[calcIdx]->cantidadOperadores-1] == '=')
        {
            printf("Resultado: %ld\n\n", resultados[calcIdx]);
        }
        free(resultados);
    }
}

void liberarMemoria(Datos * datos)
{
    for(int i = 0; i < datos->cantidadCalculos; i++)
    {
        free(datos->calculos[i]->numeros);
        free(datos->calculos[i]->grupos);
        free(datos->calculos[i]->operadores);
    }
    free(datos->calculos);
    free(datos->posicionCalculos);
    free(datos->posicionLineas);
}

//Convertimos saltos de linea de windows a unix (\r\n a \n)
bool limpiarArchivo(char * nombre)
{
    FILE * archivo = fopen(nombre,"rb");
    if (archivo == NULL)
    {
        return false;
    }
    FILE * limpio = fopen("limpio.txt", "wb");
    while(true)
    {
        char c = fgetc(archivo);
        if (c == EOF)
        {
            break;
        }
        
        if (c == '\r') 
        {
            continue;
        }

        fputc(c,limpio);
    }
    fclose(archivo);
    fclose(limpio);
    remove(nombre);
    limpio = fopen("limpio.txt", "rb");
    archivo = fopen(nombre, "wb");
    fseek(limpio,0,SEEK_SET);
    fseek(archivo,0,SEEK_SET);
    while(true)
    {
        char c = fgetc(limpio);
        if (c == EOF)
        {
            break;
        }
        fputc(c, archivo);
    }
    fclose(limpio);
    fclose(archivo);
    remove("limpio.txt");
    return true;
}

int main(int argc, char* argv[])
{
    Datos datos;
    datos.hayError = false;
    char nombre[MAX_CADENA];

    printf("Bienvenido a la calculadora de cintas de calculo.");
    printf("\nIngrese el nombre del archivo de texto que contiene su cinta de calculo (incluyendo extencion .txt): ");
    scanf("%s",nombre);

    if (!limpiarArchivo(nombre))
    {
        printf("ERROR: archivo no encontrado.\n");
        return 1;
    }

    FILE * archivo = fopen(nombre,"rb");

    printf("Leyendo archivo: %s\n", nombre);
    contarLineasYPosiciones(archivo, &datos);
    obtenerCalculos(archivo, &datos);

    obtenerNumeros(archivo, &datos);
    obtenerOperadores(archivo, &datos);
    obtenerGrupos(archivo, &datos);
    fclose(archivo);

    calcularResultados(&datos);

    return 0;
}