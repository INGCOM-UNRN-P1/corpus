# Repositorio de Ejemplo: Actividad de Estudiante (TDA Lista de Envíos)

Este repositorio es una actividad práctica de ejemplo diseñada para demostrar el uso integral de todas las herramientas de software estudiantiles de la cátedra de Programación y Algoritmos en C.

---

## 🚀 Inicio Rápido

### 1. Compilar el programa principal y ejecutar pruebas unitarias
```bash
make
```

### 2. Ejecutar la auditoría completa de pre-entrega
```bash
make audit-all
```
O mediante el script interactivo:
```bash
./evaluar_entrega.sh
```

---

## 📂 Contenido del Repositorio

- [`ENUNCIADO.md`](ENUNCIADO.md): Especificación técnica completa de la actividad práctica.
- [`MANUAL_ESTUDIANTE.md`](MANUAL_ESTUDIANTE.md): **Manual exhaustivo de uso** paso a paso de cada herramienta de desarrollo y diagnóstico del ecosistema.
- [`Makefile`](Makefile): Targets automatizados para compilar, auditar estilo, verificar memoria, trazar recursión y correr pruebas en sandbox.
- [`evaluar_entrega.sh`](evaluar_entrega.sh): Script validador para verificar que la entrega cumpla el 100% de los criterios antes de enviarla.
- `include/`: Cabeceras con structs para auditoría de alineación (`envio.h`), TDA lista (`lista_envios.h`) y contratos formales ACSL.
- `src/`: Implementación modular de envíos, lista simplemente enlazada y procesador de comandos con Jump Table $O(1)$.
- `tests/`: Batería de pruebas unitarias, resiliencia ante fallos de memoria y target para fuzzer.
- `testcases/`: Suite de casos de prueba `.in` y `.out` para evaluación aislada con `nostromo`.
- `canon/`: Implementación canónica de referencia para comparación estructural de AST con `weyl`.
- `samples_diagnostico/`: Archivos con fallas deliberadas para practicar diagnósticos con `hal` y `spunkmeyer`.

---

## 🧰 Comandos Más Usados por Estudiantes

```bash
# Diagnóstico de tu entorno de compilación
make doctor

# Compilación con explicaciones didácticas en español
make daedalus-build

# Chequeo de estilo y formato de código (GAFF)
make check-style

# Linter de reglas de cátedra 0xXXXXh (Ripley)
make check-ripley

# Detección de antipatrones de C (Spunkmeyer)
make check-antipatterns

# Auditoría de padding y optimización de structs (Brett)
make audit-structs

# Visualización de memoria Stack y Heap (Bishop)
make trace-memory

# Análisis de árbol recursivo y consumo de pila (Sebastian)
make trace-recursion

# Desensamblado de Jump Tables en switch (Rachel)
make disasm-switch

# Ejecución aislada de casos de prueba (Nostromo)
make test-sandbox

# Inyección de fallas de memoria malloc (Vasquez)
make test-faults

# Comparación estructural con solución canónica (Weyl)
make diff-canon
```

Para más detalles sobre cómo interpretar las salidas de cada herramienta, consultá el [Manual Completo del Estudiante](MANUAL_ESTUDIANTE.md).
