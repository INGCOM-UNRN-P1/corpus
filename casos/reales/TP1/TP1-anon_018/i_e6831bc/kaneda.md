## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **1** llamadas o patrones de riesgo de seguridad:

| Regla | Archivo:Línea | Severidad | Detalle | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x000Fh` | `libs/consola/libProgramacion:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/libProgramacion' (Firma binaria ejecutable detectada (Biblioteca estática Unix ar (.a))). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
