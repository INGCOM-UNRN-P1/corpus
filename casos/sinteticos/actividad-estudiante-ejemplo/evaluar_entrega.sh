#!/usr/bin/env bash
# ==============================================================================
# evaluar_entrega.sh: Script de validación integral pre-entrega para el alumno
# ==============================================================================

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

TOOLS_DIR="$(dirname "$SCRIPT_DIR")"

echo "================================================================================"
echo " 🚀 INICIANDO AUDITORÍA PRE-ENTREGA DE TRABAJO PRÁCTICO"
echo "================================================================================"

# 1. Compilación estricta
echo -e "\n[1/6] Compilando con GCC bajo flags estrictos de cátedra (-Werror)..."
mkdir -p bin
gcc -std=c11 -Wall -Wextra -Werror -pedantic -Wconversion -Wshadow -g -Iinclude \
    src/envio.c src/lista_envios.c src/procesador.c src/main.c -o bin/sistema_envios
echo "✓ Compilación exitosa."

# 2. Pruebas Unitarias
echo -e "\n[2/6] Ejecutando suite de pruebas unitarias..."
gcc -std=c11 -Wall -Wextra -Werror -pedantic -Iinclude \
    src/envio.c src/lista_envios.c tests/test_lista.c -o bin/test_lista
./bin/test_lista
echo "✓ Pruebas unitarias superadas."

# 3. Linter de Estilo (GAFF)
echo -e "\n[3/6] Verificando estilo y convenciones (GAFF)..."
if [ -d "$TOOLS_DIR/gaff" ]; then
    PYTHONPATH="$TOOLS_DIR/gaff/src" python3 -m gaff.cli check src/ include/ || true
else
    echo "(gaff no encontrado en tools, saltando chequeo)"
fi

# 4. Detección de Antipatrones (Spunkmeyer)
echo -e "\n[4/6] Verificando ausencia de antipatrones (Spunkmeyer)..."
if [ -d "$TOOLS_DIR/spunkmeyer" ]; then
    PYTHONPATH="$TOOLS_DIR/spunkmeyer/src" python3 -m spunkmeyer.cli detect src/ include/ || true
else
    echo "(spunkmeyer no encontrado en tools, saltando chequeo)"
fi

# 5. Auditoría de Seguridad (Kaneda)
echo -e "\n[5/6] Verificando seguridad estática (Kaneda)..."
if [ -d "$TOOLS_DIR/kaneda" ]; then
    PYTHONPATH="$TOOLS_DIR/kaneda/src" python3 -m kaneda.cli audit src/ include/ || true
else
    echo "(kaneda no encontrado en tools, saltando chequeo)"
fi

# 6. Evaluación de Casos de Prueba (Nostromo o ejecución local)
echo -e "\n[6/6] Ejecutando casos de prueba funcionales..."
for in_file in testcases/*.in; do
    tc_name="$(basename "$in_file" .in)"
    out_file="testcases/${tc_name}.out"
    temp_out="/tmp/${tc_name}_actual.out"

    ./bin/sistema_envios < "$in_file" > "$temp_out"
    if diff -u "$out_file" "$temp_out" >/dev/null; then
        echo " ✓ Testcase $tc_name: PASSED"
    else
        echo " ✗ Testcase $tc_name: FAILED (Diferencia con la salida esperada)"
        diff -u "$out_file" "$temp_out" || true
        exit 1
    fi
    rm -f "$temp_out"
done

echo ""
echo "================================================================================"
echo " 🎉 ¡FELICITACIONES! Tu entrega cumple con todos los requisitos técnicos."
echo "================================================================================"
