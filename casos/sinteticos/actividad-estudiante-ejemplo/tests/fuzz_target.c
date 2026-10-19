#include "procesador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Target autónomo para fuzzer Drake */
int main(int argc, char* argv[]) {
    FILE* in = stdin;
    if (argc > 1) {
        in = fopen(argv[1], "r");
        if (!in) return 0;
    }

    FILE* out_null = fopen("/dev/null", "w");
    if (!out_null) {
        out_null = stdout;
    }

    procesar_flujo_instrucciones(in, out_null);

    if (out_null != stdout) {
        fclose(out_null);
    }
    if (in != stdin) {
        fclose(in);
    }
    return 0;
}
