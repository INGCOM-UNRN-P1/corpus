#include "procesador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int procesar_comando_op(comando_op_t op, lista_envios_t *lista,
                        const char *argumentos, FILE *salida)
{
    if (!lista || !salida)
    {
        return -1;
    }

    /*
     * Switch con casos densos (1 a 7).
     * Permite a la herramienta rachel verificar la generación de Jump Tables.
     */
    switch (op)
    {
        case OP_INSERTAR:
        {
            uint64_t id = 0;
            char codigo[CODIGO_MAX] = {0};
            char destino[DESTINO_MAX] = {0};
            unsigned int cp = 0;
            double peso = 0.0;
            unsigned int prio = 0;
            int inter = 0;

            if (sscanf(argumentos, "%lu %15s %31s %u %lf %u %d",
                       (unsigned long *)&id, codigo, destino, &cp, &peso, &prio,
                       &inter) != 7)
            {
                fprintf(salida, "ERROR: Formato de insercion invalido\n");
                return 1;
            }

            envio_t *env = envio_crear(id, codigo, destino, (uint16_t)cp, peso,
                                       (uint8_t)prio, inter != 0);
            if (!env)
            {
                fprintf(salida, "ERROR: Fallo de memoria o datos invalidos\n");
                return 2;
            }

            if (!lista_insertar_final(lista, env))
            {
                envio_destruir(env);
                fprintf(salida, "ERROR: No se pudo insertar en la lista\n");
                return 3;
            }

            fprintf(salida, "OK: Envio #%lu insertado correctamente\n",
                    (unsigned long)id);
            break;
        }

        case OP_BUSCAR:
        {
            uint64_t id = 0;
            if (sscanf(argumentos, "%lu", (unsigned long *)&id) != 1)
            {
                fprintf(salida, "ERROR: ID requerido para busqueda\n");
                return 1;
            }

            envio_t *env = lista_buscar_por_id(lista, id);
            if (env)
            {
                fprintf(salida, "ENCONTRADO: ");
                fprintf(salida,
                        "Envio #%lu [%s] -> %s (CP %u, Tarifa: $%.2f)\n",
                        (unsigned long)env->id_tracking, env->codigo,
                        env->destino, (unsigned int)env->codigo_postal,
                        envio_calcular_tarifa(env));
            }
            else
            {
                fprintf(salida, "NO ENCONTRADO: Envio #%lu no existe\n",
                        (unsigned long)id);
            }
            break;
        }

        case OP_ELIMINAR:
        {
            uint64_t id = 0;
            if (sscanf(argumentos, "%lu", (unsigned long *)&id) != 1)
            {
                fprintf(salida, "ERROR: ID requerido para eliminacion\n");
                return 1;
            }

            if (lista_eliminar_por_id(lista, id))
            {
                fprintf(salida, "OK: Envio #%lu eliminado\n",
                        (unsigned long)id);
            }
            else
            {
                fprintf(salida,
                        "ERROR: Envio #%lu no encontrado para eliminar\n",
                        (unsigned long)id);
            }
            break;
        }

        case OP_LISTAR:
        {
            size_t total = lista_largo(lista);
            fprintf(salida, "LISTADO DE ENVIOS (%zu total):\n", total);
            nodo_t *actual = lista->primero;
            while (actual)
            {
                if (actual->dato)
                {
                    fprintf(salida,
                            " - #%lu: %s a %s (%.2f kg, Tarifa $%.2f)\n",
                            (unsigned long)actual->dato->id_tracking,
                            actual->dato->codigo, actual->dato->destino,
                            actual->dato->peso_kg,
                            envio_calcular_tarifa(actual->dato));
                }
                actual = actual->siguiente;
            }
            break;
        }

        case OP_CONTAR_URGENTES:
        {
            unsigned int umbral = 5;
            if (argumentos && *argumentos)
            {
                sscanf(argumentos, "%u", &umbral);
            }
            size_t urgentes = lista_contar_prioritarios(lista, (uint8_t)umbral);
            fprintf(salida, "URGENTES (prioridad >= %u): %zu envios\n", umbral,
                    urgentes);
            break;
        }

        case OP_INVERTIR:
        {
            lista_invertir(lista);
            fprintf(salida,
                    "OK: Lista invertida correctamente (%zu elementos)\n",
                    lista_largo(lista));
            break;
        }

        case OP_SALIR:
        {
            fprintf(salida, "FIN: Procesamiento finalizado\n");
            return 0;
        }

        default:
        {
            fprintf(salida, "ERROR: Codigo de operacion desconocido (%d)\n",
                    op);
            return -1;
        }
    }

    return 0;
}

int procesar_flujo_instrucciones(FILE *entrada, FILE *salida)
{
    if (!entrada || !salida)
    {
        return -1;
    }

    lista_envios_t *lista = lista_crear();
    if (!lista)
    {
        fprintf(salida, "FATAL: Error al inicializar TDA Lista\n");
        return -1;
    }

    char buffer[256];
    int status = 0;

    while (fgets(buffer, sizeof(buffer), entrada))
    {
        /* Ignorar comentarios y líneas vacías */
        if (buffer[0] == '#' || buffer[0] == '\n' || buffer[0] == '\r')
        {
            continue;
        }

        int op_num = 0;
        char args[200] = {0};

        int leidos = sscanf(buffer, "%d %[^\n]", &op_num, args);
        if (leidos < 1)
        {
            continue;
        }

        comando_op_t op = (comando_op_t)op_num;
        status = procesar_comando_op(op, lista, args, salida);
        if (op == OP_SALIR)
        {
            break;
        }
    }

    lista_destruir(lista);
    return status;
}
