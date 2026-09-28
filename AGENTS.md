# Instrucciones para el Agente (corpus)

1. **Commits semánticos en español**: `<tipo>(<alcance>): <descripción>`.
2. **Nunca** sumar una entrega real sin consentimiento firmado y sin pasar
   `scripts/anonimizar.py` (el CI lo exige).
3. El esperado es el comportamiento **correcto**: un falso positivo no se
   «acepta» actualizando el esperado; se abre el hallazgo en la herramienta.
4. `uvx pytest -q tests` y `python3 scripts/correr.py` antes de cada commit.
