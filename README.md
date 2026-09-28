# corpus — casos reales y sintéticos para verificar los analizadores

Los falsos positivos (N-GAFF-01) y los tracebacks (N-ECO-05) de la revisión
aparecieron con código real que los fixtures de cada herramienta no cubrían.
Este repositorio junta casos —entregas anonimizadas y casos sintéticos que
reproducen hallazgos de la revisión— con la salida esperada de cada
analizador, y un script que los corre todos y falla ante diferencias.

## Estructura

```text
casos/
├── sinteticos/<caso>/        # escritos para reproducir un hallazgo
│   ├── caso.toml             # descripción, origen, hallazgo y comandos por herramienta
│   ├── main.c …              # el código
│   └── esperado/<herramienta>.json
└── reales/<consigna>/<caso>/ # entregas con consentimiento y anonimizadas (misma forma)
```

`esperado/<herramienta>.json` guarda la **firma** de la salida: el veredicto
(`ok`, `exito` o `passed`) y los hallazgos como `[código, línea]`. Se compara
la firma y no el texto: mejorar la redacción de un mensaje no rompe el corpus;
un falso positivo o un falso negativo, sí.

| Caso | Protege | Herramientas |
|:--|:--|:--|
| `switch-con-retorno-unico` | N-GAFF-05 (dead store en ramas de switch) | gaff |
| `literales-opacos` | N-GAFF-01, N-GAFF-06 (reglas de espaciado dentro de literales) | gaff |
| `strcpy-inseguro` | coincidencia kaneda/spunkmeyer en la misma línea | kaneda, spunkmeyer |
| `varios-archivos` | N-VASQUEZ-02 (src/ + include/, `-I`) | vasquez |
| `advertencias-de-compilacion` | traducción de `-Wunused-variable` y `-Wsign-compare` | daedalus |

## Uso

```bash
python3 scripts/correr.py                     # todos los casos; sale con 1 ante diferencias
python3 scripts/correr.py literales-opacos    # uno solo
python3 scripts/correr.py --actualizar        # reescribe los esperados (revisar el diff)
python3 scripts/anonimizar.py                 # busca datos personales en casos/
```

Los analizadores se instalan siempre desde git
(`uv tool install git+https://github.com/INGCOM-UNRN-P1/<herramienta>`); el CI
los instala así y corre el corpus todas las semanas.

## Sumar una entrega real

1. **Consentimiento**: firmado por el estudiante con la plantilla de
   [`CONSENTIMIENTO.md`](CONSENTIMIENTO.md) y guardado por la cátedra (no en
   este repositorio).
2. **Anonimizar**: `python3 scripts/anonimizar.py casos/reales/<consigna>/<caso> --corregir`
   quita nombres en comentarios de autoría, correos, legajos, DNI y usuarios de
   GitHub; revisar a mano identificadores y textos libres que el script no
   puede reconocer (nombres de variables con el apellido, anécdotas).
3. **Esperado**: correr `scripts/correr.py <caso> --actualizar` y **revisar**
   cada hallazgo; lo esperado es el comportamiento correcto, no el actual: si
   hay un falso positivo, se quita del esperado y se abre el hallazgo en la
   herramienta.
4. El CI rechaza cualquier caso con datos personales (`anonimizar.py` sale con 1).

## Licencia

Scripts: GPL-3.0-or-later (ver `LICENSE`). Los casos reales se usan solo con
fines de verificación de las herramientas de la cátedra, según el
consentimiento de cada estudiante.
