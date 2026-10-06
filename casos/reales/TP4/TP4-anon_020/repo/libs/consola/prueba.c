#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "consola.h"

static void probar_esta_en_rango_entero(void)
{
    
    assert(esta_en_rango_entero(10, 10, 20));
    assert(esta_en_rango_entero(15, 10, 20));
    assert(esta_en_rango_entero(20, 10, 20));
    assert(!esta_en_rango_entero(9, 10, 20));
    assert(!esta_en_rango_entero(21, 10, 20));

    
    assert(esta_en_rango_entero(-5, -5, 5));
    assert(esta_en_rango_entero(0, -5, 5));
    assert(esta_en_rango_entero(5, -5, 5));
    assert(!esta_en_rango_entero(-6, -5, 5));
    assert(!esta_en_rango_entero(6, -5, 5));

    
    assert(esta_en_rango_entero(-20, -20, -10));
    assert(esta_en_rango_entero(-15, -20, -10));
    assert(esta_en_rango_entero(-10, -20, -10));
    assert(!esta_en_rango_entero(-21, -20, -10));
    assert(!esta_en_rango_entero(-9, -20, -10));

    
    assert(esta_en_rango_entero(7, 7, 7));
    assert(!esta_en_rango_entero(6, 7, 7));
    assert(!esta_en_rango_entero(8, 7, 7));

    
    assert(!esta_en_rango_entero(10, 20, 10));
}

static void probar_esta_en_rango_flotante(void)
{
    
    assert(esta_en_rango_flotante(1.5f, 1.5f, 4.5f));
    assert(esta_en_rango_flotante(3.0f, 1.5f, 4.5f));
    assert(esta_en_rango_flotante(4.5f, 1.5f, 4.5f));
    assert(!esta_en_rango_flotante(1.49f, 1.5f, 4.5f));
    assert(!esta_en_rango_flotante(4.51f, 1.5f, 4.5f));

    
    assert(esta_en_rango_flotante(-2.5f, -2.5f, 2.5f));
    assert(esta_en_rango_flotante(0.0f, -2.5f, 2.5f));
    assert(esta_en_rango_flotante(2.5f, -2.5f, 2.5f));
    assert(!esta_en_rango_flotante(-2.51f, -2.5f, 2.5f));
    assert(!esta_en_rango_flotante(2.51f, -2.5f, 2.5f));

    
    assert(esta_en_rango_flotante(-10.5f, -10.5f, -5.5f));
    assert(esta_en_rango_flotante(-7.2f, -10.5f, -5.5f));
    assert(esta_en_rango_flotante(-5.5f, -10.5f, -5.5f));
    assert(!esta_en_rango_flotante(-10.51f, -10.5f, -5.5f));
    assert(!esta_en_rango_flotante(-5.49f, -10.5f, -5.5f));

    
    assert(esta_en_rango_flotante(0.0f, 0.0f, 0.0f));
    assert(!esta_en_rango_flotante(0.001f, 0.0f, 0.0f));
    assert(!esta_en_rango_flotante(-0.001f, 0.0f, 0.0f));

    
    assert(!esta_en_rango_flotante(5.0f, 10.0f, 2.0f));
}

static void probar_lecturas_basicas(void)
{
    FILE *entrada_original = stdin;
    FILE *salida_original = stdout;
    FILE *entrada = NULL;
    FILE *salida = NULL;
    char salida_buffer[256] = {0};
    size_t leidos = 0U;
    int entero = 0;
    int entero_rango = 0;
    float flotante = 0.0f;
    float flotante_rango = 0.0f;
    char caracter = '\0';
    bool logico = false;

    entrada = tmpfile();
    salida = tmpfile();
    assert(entrada != NULL);
    assert(salida != NULL);
    fprintf(entrada, "42\n");
    rewind(entrada);
    stdin = entrada;
    stdout = salida;
    entero = leer_entero("Ingrese entero: ");
    fflush(stdout);
    rewind(salida);
    leidos = fread(salida_buffer, 1U, sizeof(salida_buffer) - 1U, salida);
    salida_buffer[leidos] = '\0';
    assert(entero == 42);
    assert(strcmp(salida_buffer, "Ingrese entero: ") == 0);
    fclose(entrada);
    fclose(salida);

    entrada = tmpfile();
    salida = tmpfile();
    assert(entrada != NULL);
    assert(salida != NULL);
    fprintf(entrada, "15\n");
    rewind(entrada);
    stdin = entrada;
    stdout = salida;
    entero_rango = leer_entero_entre("Rango: ", 10, 20);
    fflush(stdout);
    rewind(salida);
    leidos = fread(salida_buffer, 1U, sizeof(salida_buffer) - 1U, salida);
    salida_buffer[leidos] = '\0';
    assert(entero_rango == 15);
    assert(strcmp(salida_buffer, "Rango: ") == 0);
    fclose(entrada);
    fclose(salida);

    entrada = tmpfile();
    salida = tmpfile();
    assert(entrada != NULL);
    assert(salida != NULL);
    fprintf(entrada, "3.5\n");
    rewind(entrada);
    stdin = entrada;
    stdout = salida;
    flotante = leer_flotante("Flotante: ");
    fflush(stdout);
    rewind(salida);
    leidos = fread(salida_buffer, 1U, sizeof(salida_buffer) - 1U, salida);
    salida_buffer[leidos] = '\0';
    assert(flotante > 3.49f && flotante < 3.51f);
    assert(strcmp(salida_buffer, "Flotante: ") == 0);
    fclose(entrada);
    fclose(salida);

    entrada = tmpfile();
    salida = tmpfile();
    assert(entrada != NULL);
    assert(salida != NULL);
    fprintf(entrada, "4.25\n");
    rewind(entrada);
    stdin = entrada;
    stdout = salida;
    flotante_rango = leer_flotante_entre("Flotante rango: ", 1.0f, 5.0f);
    fflush(stdout);
    rewind(salida);
    leidos = fread(salida_buffer, 1U, sizeof(salida_buffer) - 1U, salida);
    salida_buffer[leidos] = '\0';
    assert(flotante_rango > 4.24f && flotante_rango < 4.26f);
    assert(strcmp(salida_buffer, "Flotante rango: ") == 0);
    fclose(entrada);
    fclose(salida);

    entrada = tmpfile();
    salida = tmpfile();
    assert(entrada != NULL);
    assert(salida != NULL);
    fprintf(entrada, "z\n");
    rewind(entrada);
    stdin = entrada;
    stdout = salida;
    caracter = leer_caracter("Caracter: ");
    fflush(stdout);
    rewind(salida);
    leidos = fread(salida_buffer, 1U, sizeof(salida_buffer) - 1U, salida);
    salida_buffer[leidos] = '\0';
    assert(caracter == 'z');
    assert(strcmp(salida_buffer, "Caracter: ") == 0);
    fclose(entrada);
    fclose(salida);

    entrada = tmpfile();
    salida = tmpfile();
    assert(entrada != NULL);
    assert(salida != NULL);
    fprintf(entrada, "n\n");
    rewind(entrada);
    stdin = entrada;
    stdout = salida;
    logico = leer_logico("Confirmar? [s/n]: ");
    fflush(stdout);
    rewind(salida);
    leidos = fread(salida_buffer, 1U, sizeof(salida_buffer) - 1U, salida);
    salida_buffer[leidos] = '\0';
    assert(logico == false);
    assert(strcmp(salida_buffer, "Confirmar? [s/n]: ") == 0);

    stdin = entrada_original;
    stdout = salida_original;
    fclose(entrada);
    fclose(salida);
}

int main(void)
{
    printf("Ejecutando pruebas unitarias de la libreria consola...\n");
    probar_esta_en_rango_entero();
    probar_esta_en_rango_flotante();
    probar_lecturas_basicas();
    printf("Todos los tests de la libreria consola pasaron exitosamente.\n");
    return 0;
}
