## Antipatrones Didácticos — Spunkmeyer

Se detectaron **138** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x7001h` | `main.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3008h` | `main.c:27` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `main.c:30` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `main.c:38` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3008h` | `main.c:47` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `main.c:51` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `main.c:59` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'pares' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:19` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:36` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector_enteros.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `vector_enteros.c:15` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `vector_enteros.c:42` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `vector_enteros.c:56` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `prueba.c:18` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:32` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `texto_dinamico.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `texto_dinamico.c:35` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `texto_dinamico.c:58` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `texto_dinamico.c:66` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `texto_dinamico.c:74` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `cadena_dinamica.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `cadena_dinamica.c:20` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `cadena_dinamica.c:20` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x7001h` | `cadena_dinamica.c:43` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `cadena_dinamica.c:55` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `cadena_dinamica.c:55` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x3008h` | `cadena_dinamica.c:69` | **Comparación sintáctica errónea de puntero con carácter nulo '\0'** | Comparación sintáctica errónea de puntero 'origen_2' con '\0' en lugar de desreferenciar. | Desreferenciá el puntero: '*str == '\0'' o 'str[0] == '\0''. |
| `0x7001h` | `main.c:12` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3008h` | `main.c:14` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x3008h` | `main.c:24` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `prueba.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:21` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:29` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon_vacio' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:36` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:39` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'unida' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `main.c:12` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:18` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `matriz_dinamica.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `matriz_dinamica.c:16` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `matriz_dinamica.c:16` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x300Ah` | `matriz_dinamica.c:21` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `matriz_dinamica.c:21` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x3008h` | `matriz_dinamica.c:45` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x3002h` | `matriz_dinamica.c:49` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `matriz_dinamica.c:58` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:19` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:12` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:21` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `registro_csv.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `registro_csv.c:26` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `registro_csv.c:26` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x300Ah` | `registro_csv.c:40` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `registro_csv.c:40` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x7001h` | `registro_csv.c:47` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `registro_csv.c:76` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3008h` | `registro_csv.c:81` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x3002h` | `registro_csv.c:87` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'arreglo' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `consulta_csv.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `consulta_csv.c:33` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `consulta_csv.c:33` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x7001h` | `consulta_csv.c:67` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `consulta_csv.c:67` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `consulta_csv.c:67` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x7001h` | `consulta_csv.c:109` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:12` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `main.c:26` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `main.c:26` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x3008h` | `main.c:41` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `main.c:44` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3008h` | `main.c:45` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `main.c:48` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `main.c:56` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `main.c:62` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'filtrada' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `main.c:64` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x300Ah` | `prueba.c:13` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `prueba.c:13` | **Casteo de retorno de malloc() con omisión de include stdlib.h** | Casteo explícito de 'malloc()' en archivo sin inclusión obligatoria de '<stdlib.h>'. | Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante. |
| `0x3008h` | `prueba.c:15` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `prueba.c:23` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3008h` | `prueba.c:27` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x3008h` | `prueba.c:31` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x301Fh` | `prueba.c:33` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:34` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x3002h` | `prueba.c:35` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'proms' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:37` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'filtrada' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:39` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'mat' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x200Ah` | `p1_arrays.h:36` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_double' declara 9 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:54` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_sorted' declara 8 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:73` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_str_array' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:93` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_contains' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:21` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_exists' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:40` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_line' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:58` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_contains' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:74` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_bin' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_stdio.h:133` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_stdio.h:175` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_test.h:132` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_test.h:216` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_int' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:233` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_int_between' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:250` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_uint' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:267` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_double' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:284` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_double_rel' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_test.h:288` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_test.h:305` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_str' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:324` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_ptr' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:345` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_int' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:363` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_mem' declara 10 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_test.h:375` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `p1_test.h:378` | **Comparación entre tipos enteros con y sin signo en condición** | Comparación entre tipos con signo ('int') y sin signo ('size_t') entre 'i' y 'end'. | Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0). |
| `0x1005h` | `p1_test.h:382` | **Comparación entre tipos enteros con y sin signo en condición** | Comparación entre tipos con signo ('int') y sin signo ('size_t') entre 'i' y 'end'. | Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0). |
| `0x7001h` | `p1_test.h:413` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_test.h:506` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1003h` | `p1_test.h:535` | **Modificación de variable de control dentro del cuerpo del for** | Variable de control 'i' modificada dentro del cuerpo del bucle for. | Si la lógica de avance no es regular o depende de condiciones dinámicas, utilizá un bucle 'while'. |
| `0x7001h` | `prueba.c:38` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:68` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x4001h` | `prueba.c:70` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'f' devuelto por fopen() en línea 68 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x7001h` | `prueba.c:89` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `cadenas.c:22` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `cadenas.c:46` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `cadenas.c:61` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `cadenas.c:102` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `cadenas.c:116` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `cadenas.c:139` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `cadenas.c:146` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `prueba.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:41` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:54` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:37` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:57` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:76` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `vector.c:15` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `vector.c:41` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:56` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `vector.c:59` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `vector.c:94` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |

### 🔍 Detalle Pedagógico de Antipatrones

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:13`
```c
    int datos[] = {15, 22, 8, 3, 40, 11, 6};
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:27`
```c
    if (clon != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:30`
```c
        int *ptr_clon = clon;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:38`
```c
        free(clon);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:47`
```c
    if (pares != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:51`
```c
        int *ptr_pares = pares;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:59`
```c
        free(pares);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:19`
```c
    int datos[] = {10, 20, 30, 40};
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:36`
```c
    int datos[] = {1, 4, 7, 8, 10, 13};
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `vector_enteros.c:15`
```c
    int *copia = (int *)malloc(cantidad * sizeof(int));
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `vector_enteros.c:15`
```c
    int *copia = (int *)malloc(cantidad * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `vector_enteros.c:42`
```c
    const int *ptr_lectura = origen;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `vector_enteros.c:56`
```c
    int *bloque_pares = (int *)malloc(contador_par * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:18`
```c
    char *limpio = cadena_recortar_espacios("   hola mundo   ");
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:32`
```c
    char *rep = cadena_repetir("abc", 3);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `texto_dinamico.c:15`
```c
    const char *inicio = origen;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `texto_dinamico.c:35`
```c
    char *resultado = (char *)malloc(largo + 1);
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `texto_dinamico.c:58`
```c
    const char *ptr = origen;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `texto_dinamico.c:66`
```c
        char *vacia = (char *)malloc(1);
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `texto_dinamico.c:74`
```c
    char *resultado = (char*)malloc(tamaño_total);
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cadena_dinamica.c:14`
```c
    const char *ptr = origen;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadena_dinamica.c:20`
```c
    char *copia = (char *)malloc(largo + 1);
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `cadena_dinamica.c:20`
```c
    char *copia = (char *)malloc(largo + 1);
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cadena_dinamica.c:43`
```c
    const char *ptr_1 = primera;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadena_dinamica.c:55`
```c
    char *resultado = (char *)malloc(largo_1 + largo_2 + 1);
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `cadena_dinamica.c:55`
```c
    char *resultado = (char *)malloc(largo_1 + largo_2 + 1);
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x3008h`: Comparación sintáctica errónea de puntero con carácter nulo '\0'
- **Ubicación:** `cadena_dinamica.c:69`
```c
    while(origen_2 != '\0')
```
- **Explicación:** 'str == '\0'' compara la dirección del puntero con 0 (equivalente a str == NULL). Para verificar el carácter terminador debe usarse '*str == '\0''.
- **Sugerencia:** Desreferenciá el puntero: '*str == '\0'' o 'str[0] == '\0''.
- **Ejemplo incorrecto:**
```c
if (str == '\0') { ... }
```
- **Ejemplo recomendado:**
```c
if (*str == '\0') { ... }
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:12`
```c
    const char *original = "Estructura de Datos";
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:14`
```c
    if (clon != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:24`
```c
    if (union_cadena != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:17`
```c
    const char *original = "Algoritmos";
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:21`
```c
    free(clon);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:29`
```c
    free(clon_vacio);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:36`
```c
    char *unida = unir_cadenas_dinamicas("Buenas ", "tardes");
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:39`
```c
    free(unida);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:12`
```c
    size_t filas = 3;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:18`
```c
        int **p_fila = matriz;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `matriz_dinamica.c:16`
```c
    int **matriz = (int **)malloc(filas * sizeof(int *));
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `matriz_dinamica.c:16`
```c
    int **matriz = (int **)malloc(filas * sizeof(int *));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `matriz_dinamica.c:16`
```c
    int **matriz = (int **)malloc(filas * sizeof(int *));
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `matriz_dinamica.c:21`
```c
    int *datos = (int *)malloc(filas * columnas * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `matriz_dinamica.c:21`
```c
    int *datos = (int *)malloc(filas * columnas * sizeof(int));
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `matriz_dinamica.c:45`
```c
    if(*matriz != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `matriz_dinamica.c:49`
```c
    free(matriz);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `matriz_dinamica.c:58`
```c
    FILE *archivo = fopen(ruta_archivo, "r");
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:19`
```c
        int *fila_0 = *matriz;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:12`
```c
    const char *linea = "Juan,Perez,30,Ingeniero,Argentina";
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:21`
```c
        char **ptr = tokens;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `registro_csv.c:16`
```c
    size_t num_tokens = 1;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `registro_csv.c:26`
```c
    char **arreglo = (char **)malloc(num_tokens * sizeof(char *));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `registro_csv.c:26`
```c
    char **arreglo = (char **)malloc(num_tokens * sizeof(char *));
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `registro_csv.c:40`
```c
            char *token = (char *)malloc(longitud + 1);
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `registro_csv.c:40`
```c
            char *token = (char *)malloc(longitud + 1);
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `registro_csv.c:47`
```c
            char *dst = token;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `registro_csv.c:76`
```c
    char **arreglo = *puntero_arreglo;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `registro_csv.c:81`
```c
        if (*ptr_actual != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `registro_csv.c:87`
```c
    free(arreglo);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consulta_csv.c:17`
```c
    size_t coincidencia = 0;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `consulta_csv.c:33`
```c
    int *matriz_filtrada = (int *)malloc(coincidencia * columnas * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `consulta_csv.c:33`
```c
    int *matriz_filtrada = (int *)malloc(coincidencia * columnas * sizeof(int));
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consulta_csv.c:67`
```c
    float *promedios = (float *)malloc(columnas * sizeof(float));
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `consulta_csv.c:67`
```c
    float *promedios = (float *)malloc(columnas * sizeof(float));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `consulta_csv.c:67`
```c
    float *promedios = (float *)malloc(columnas * sizeof(float));
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consulta_csv.c:109`
```c
    FILE *archivo = fopen(ruta_archivo, "w");
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:12`
```c
    const char *archivo_origen = "datos_entrada.csv";
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `main.c:26`
```c
    int *matriz = (int *)malloc(filas * columnas * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `main.c:26`
```c
    int *matriz = (int *)malloc(filas * columnas * sizeof(int));
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:41`
```c
    if (filtrada != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:44`
```c
        float *promedios = matriz_calcular_promedios_columna(filtrada, filas_filtradas, columnas);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:45`
```c
        if (promedios != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:48`
```c
            float *ptr = promedios;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:56`
```c
            free(promedios);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:62`
```c
        free(filtrada); 
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:64`
```c
    free(matriz); 
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `prueba.c:13`
```c
    int *mat = (int *)malloc(filas * columnas * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo de retorno de malloc() con omisión de include stdlib.h
- **Ubicación:** `prueba.c:13`
```c
    int *mat = (int *)malloc(filas * columnas * sizeof(int));
```
- **Explicación:** En C90/C99 sin '<stdlib.h>', el compilador asume que 'malloc()' retorna 'int'. El casteo explícito oculta la advertencia del compilador y en arquitecturas de 64 bits trunca la dirección de memoria a 32 bits.
- **Sugerencia:** Incluí obligatoriamente '#include <stdlib.h>' y retirá el casteo redundante.
- **Ejemplo incorrecto:**
```c
int *p = (int *)malloc(sizeof(int)); // Sin #include <stdlib.h>
```
- **Ejemplo recomendado:**
```c
#include <stdlib.h>
int *p = malloc(sizeof(*p));
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `prueba.c:15`
```c
    if (mat != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:23`
```c
        size_t f_out = 0;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `prueba.c:27`
```c
        if (filtrada != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `prueba.c:31`
```c
            if (proms != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:33`
```c
                ASSERT_TRUE(*proms == 20.0f);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:34`
```c
                ASSERT_TRUE(*(proms + 1) == 55.0f);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:35`
```c
                free(proms);
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:37`
```c
            free(filtrada); // Liberación directa con free()
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:39`
```c
        free(mat); // Liberación directa con free()
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:36`
```c
static inline void _p1_fail_array_double(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:54`
```c
static inline void _p1_fail_array_sorted(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:73`
```c
static inline void _p1_fail_str_array(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:93`
```c
static inline void _p1_fail_array_contains(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:21`
```c
static inline void _p1_fail_file_exists(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:40`
```c
static inline void _p1_fail_file_line(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:58`
```c
static inline void _p1_fail_file_contains(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:74`
```c
static inline void _p1_fail_file_bin(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_stdio.h:133`
```c
        size_t n = fread(buf, 1, max_len - 1, _p1_stdio_ctx.capture_stdout_file);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_stdio.h:175`
```c
        size_t n = fread(buf, 1, max_len - 1, _p1_stdio_ctx.capture_stderr_file);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:132`
```c
    const char *term = getenv("TERM");
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:216`
```c
static inline void _p1_fail_int(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:233`
```c
static inline void _p1_fail_int_between(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:250`
```c
static inline void _p1_fail_uint(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:267`
```c
static inline void _p1_fail_double(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:284`
```c
static inline void _p1_fail_double_rel(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:288`
```c
    double diff = _p1_abs_double(expected - actual);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:305`
```c
static inline void _p1_fail_str(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:324`
```c
static inline void _p1_fail_ptr(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:345`
```c
static inline void _p1_fail_array_int(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:363`
```c
static inline void _p1_fail_mem(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:375`
```c
        size_t start = (diff_offset >= 4) ? (diff_offset - 4) : 0;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x1005h`: Comparación entre tipos enteros con y sin signo en condición
- **Ubicación:** `p1_test.h:378`
```c
        for (size_t i = start; i < end; i++) {
```
- **Explicación:** En C, si un operando es con signo y el otro es sin signo del mismo o mayor rango, el valor con signo se convierte implícitamente a sin signo. Si 'i' es negativo (-1), se convierte a un número enorme mayor que cualquier límite positivo.
- **Sugerencia:** Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0).
- **Ejemplo incorrecto:**
```c
int i = -1;
size_t n = 10;
if (i < n) { ... }
```
- **Ejemplo recomendado:**
```c
size_t i = 0;
size_t n = 10;
if (i < n) { ... }
```

#### Regla `0x1005h`: Comparación entre tipos enteros con y sin signo en condición
- **Ubicación:** `p1_test.h:382`
```c
        for (size_t i = start; i < end; i++) {
```
- **Explicación:** En C, si un operando es con signo y el otro es sin signo del mismo o mayor rango, el valor con signo se convierte implícitamente a sin signo. Si 'i' es negativo (-1), se convierte a un número enorme mayor que cualquier límite positivo.
- **Sugerencia:** Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0).
- **Ejemplo incorrecto:**
```c
int i = -1;
size_t n = 10;
if (i < n) { ... }
```
- **Ejemplo recomendado:**
```c
size_t i = 0;
size_t n = 10;
if (i < n) { ... }
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:413`
```c
    const char *sig_name = "SEÑAL FATAL";
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:506`
```c
        size_t n = fread(out_buf, 1, max_buf - 1, _p1_capture_state.tmp_file);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x1003h`: Modificación de variable de control dentro del cuerpo del for
- **Ubicación:** `p1_test.h:535`
```c
    for (int i = 1; i < argc; i++) {
```
- **Explicación:** Alterar la variable de control dentro del cuerpo oculta el paso del bucle y dificulta el razonamiento estructurado.
- **Sugerencia:** Si la lógica de avance no es regular o depende de condiciones dinámicas, utilizá un bucle 'while'.
- **Ejemplo incorrecto:**
```c
for (int i = 0; i < n; i++) {
    if (cond) i += 2;
}
```
- **Ejemplo recomendado:**
```c
int i = 0;
while (i < n) {
    if (cond) i += 2;
    else i++;
}
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:38`
```c
    int x = 5;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:68`
```c
    FILE *f = fopen(f_path, "w");
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x4001h`: Omisión de verificación de retorno NULL en fopen()
- **Ubicación:** `prueba.c:70`
```c
    fputs("UNRN P1 Test Suite\n", f);
```
- **Explicación:** Si el archivo no existe o no tiene permisos de lectura/escritura, 'fopen()' retorna NULL. Desreferenciarlo en 'fread', 'fgets' o 'fgetc' causa caída inmediata por SIGSEGV.
- **Sugerencia:** Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'.
- **Ejemplo incorrecto:**
```c
FILE *f = fopen("datos.txt", "r");
fread(&elem, sizeof(elem), 1, f);
```
- **Ejemplo recomendado:**
```c
FILE *f = fopen("datos.txt", "r");
if (f == NULL) return -1;
fread(&elem, sizeof(elem), 1, f);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:89`
```c
    int num = 0;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cadenas.c:15`
```c
    const char *ptr_origen = origen;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadenas.c:22`
```c
    char *duplicado = (char *)malloc((largo + 1) * sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cadenas.c:46`
```c
    const char *ptr_origen = primera;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadenas.c:61`
```c
    char *resultado = (char *)malloc(total_bytes + sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cadenas.c:102`
```c
    const char *ptr_origen = origen;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadenas.c:116`
```c
    char *subcadena = (char *)malloc((copiar + 1) * sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cadenas.c:139`
```c
    const char *ptr_origen = origen;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadenas.c:146`
```c
    char *invertido = (char*)malloc((largo +1) * sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:13`
```c
    char *dup = cadena_duplicar_segura("Programacion 1", 30);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:27`
```c
    char *unida = cadena_unir_dinamica("Hola ", 10, "Mundo", 10);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:41`
```c
    char *sub1 = cadena_subcadena_dinamica("estructuras", 20, 2, 6);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:54`
```c
    char *invertida = cadena_invertir_dinamica("Hola", 10);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:16`
```c
    int *bloque = crear_bloque_enteros(5);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:37`
```c
    int *bloque = crear_bloque_enteros(2);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:57`
```c
    int b1[] = {1, 2, 3};
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:76`
```c
    int *bloque = NULL;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `vector.c:15`
```c
    char *bloque = (int *)calloc(cantidad, sizeof(int));
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `vector.c:15`
```c
    char *bloque = (int *)calloc(cantidad, sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `vector.c:41`
```c
    int *nuevo_bloque = (int *)realloc(bloque, nueva_cantidad * sizeof(int));
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `vector.c:56`
```c
    size_t largo1 = (primero != NULL) ? cant_primero : 0;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `vector.c:59`
```c
    int *resultado = (int *)malloc(total_elementos * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `vector.c:94`
```c
    size_t nueva_cantidad = *cantidad + 1;
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```

