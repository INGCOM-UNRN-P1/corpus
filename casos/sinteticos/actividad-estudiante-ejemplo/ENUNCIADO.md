# Trabajo Práctico N° 1: TDA Lista de Envíos y Procesador de Paquetes

**Asignatura:** Algoritmos y Programación 1 / Programación Estructurada en C  
**Objetivo Pedagógico:** Implementación de un Tipo de Dato Abstracto (TDA) dinámico y un despachador de comandos bajo estándares estrictos de gestión de memoria, modularidad, estilo y robustez en C11.

---

## 1. Introducción y Contexto

Una empresa de logística postal requiere un sistema eficiente para registrar, ordenar, despachar y auditar envíos de paquetes. Dado que el volumen de paquetes varía dinámicamente durante el día, la estructura interna debe administrar memoria dinámica en el Heap sin desperdiciar recursos ni sufrir fugas de memoria (*memory leaks*).

---

## 2. Especificación Técnica

### 2.1 Estructura del Envío (`envio_t`)

Cada envío contiene los siguientes datos mínimos:
- `id_tracking`: Identificador numérico único de 64 bits (`uint64_t`).
- `codigo`: Cadena alfanumérica de identificación (máximo 16 caracteres).
- `destino`: Ciudad o provincia de entrega (máximo 32 caracteres).
- `codigo_postal`: Código postal numérico (`uint16_t`).
- `peso_kg`: Peso del paquete en kilogramos (`double`, estrictamente mayor a 0).
- `prioridad`: Nivel de urgencia de 1 a 10 (`uint8_t`).
- `estado`: Estado actual del paquete (`enum` con valores PENDIENTE, EN_TRANSITO, ENTREGADO, CANCELADO).
- `es_internacional`: Indicador booleano (`bool`).

> **Requisito de Optimización (Brett):** La definición del `struct` debe ser auditada para minimizar los bytes de padding desperdiciados por alineación en arquitecturas de 64 bits.

---

### 2.2 TDA Lista de Envíos (`lista_envios_t`)

El TDA debe implementar una lista simplemente enlazada con punteros al primer y último nodo, garantizando las siguientes operaciones:

1. `lista_envios_t* lista_crear(void)`: Crea e inicializa una lista vacía.
2. `bool lista_insertar_inicio(lista_envios_t* lista, envio_t* envio)`: Inserta un envío al principio ($O(1)$).
3. `bool lista_insertar_final(lista_envios_t* lista, envio_t* envio)`: Inserta un envío al final ($O(1)$).
4. `envio_t* lista_buscar_por_id(const lista_envios_t* lista, uint64_t id)`: Retorna el envío con el identificador dado o `NULL` si no existe ($O(N)$).
5. `bool lista_eliminar_por_id(lista_envios_t* lista, uint64_t id)`: Elimina el envío y libera su memoria ($O(N)$).
6. `size_t lista_largo(const lista_envios_t* lista)`: Retorna la cantidad de elementos en $O(1)$.
7. `void lista_destruir(lista_envios_t* lista)`: Libera todos los nodos y envíos contenidos.

#### Algoritmos Recursivos Requeridos (Sebastian):
- `size_t lista_contar_prioritarios(const lista_envios_t* lista, uint8_t prioridad_minima)`: Cuenta recursivamente cuántos paquetes superan el umbral de prioridad.
- `void lista_invertir(lista_envios_t* lista)`: Invierte el orden de la lista utilizando una función recursiva de nodos.

---

### 2.3 Procesador de Instrucciones por Lotes (`procesador.c`)

El programa debe aceptar comandos por `stdin` o mediante un archivo de entrada con los siguientes códigos de operación:

| Código | Operación | Argumentos esperados | Salida esperada |
| :---: | :--- | :--- | :--- |
| `1` | `INSERTAR` | `<id> <codigo> <destino> <cp> <peso> <prioridad> <internacional>` | `OK: Envio #<id> insertado correctamente` |
| `2` | `BUSCAR` | `<id>` | `ENCONTRADO: Envio #<id> ...` o `NO ENCONTRADO` |
| `3` | `ELIMINAR` | `<id>` | `OK: Envio #<id> eliminado` o `ERROR` |
| `4` | `LISTAR` | *(ninguno)* | `LISTADO DE ENVIOS (<total> total):` |
| `5` | `CONTAR_URGENTES` | `[umbral]` | `URGENTES (prioridad >= <umbral>): <N> envios` |
| `6` | `INVERTIR` | *(ninguno)* | `OK: Lista invertida correctamente (<N> elementos)` |
| `7` | `SALIR` | *(ninguno)* | `FIN: Procesamiento finalizado` |

> **Requisito de Despacho (Rachel):** El switch principal de operaciones debe generar una Jump Table de costo temporal constante $O(1)$ sin recurrir a cadenas de `if-else`.

---

## 3. Criterios de Evaluación y Calidad Docente

Para que la entrega sea considerada válida y aprobada, debe satisfacer:

1. **Compilación Estricta:** Cero warnings y cero errores bajo `-std=c11 -Wall -Wextra -Werror -pedantic`.
2. **Memoria Limpia:** Cero fugas de memoria con Valgrind y AddressSanitizer.
3. **Resiliencia ante Fallas:** Manejo correcto de `malloc` retornando `NULL` en cualquier punto de asignación.
4. **Estilo y Convenciones:** Cumplimiento total de reglas `GAFF` (nombres en `snake_case`, typedefs de puntero prohibidos, llaves K&R).
5. **Aislamiento:** Superar la suite de casos de prueba en sandbox `Nostromo`.
