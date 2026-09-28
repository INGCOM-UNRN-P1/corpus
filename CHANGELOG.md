# Changelog

Formato basado en [Keep a Changelog](https://keepachangelog.com/es-ES/1.1.0/);
versiones según [SemVer](https://semver.org/lang/es/).

## [0.1.0] - 2026-09-28

### Agregado

- `scripts/correr.py`: corre los analizadores sobre cada caso y compara la firma
  (veredicto y hallazgos por código y línea) con la esperada.
- `scripts/anonimizar.py`: detecta y corrige datos personales en los casos.
- Cinco casos sintéticos que reproducen hallazgos de la revisión (N-GAFF-01,
  N-GAFF-05, N-VASQUEZ-02) y el comportamiento de kaneda, spunkmeyer y daedalus.
- Plantilla de consentimiento para entregas reales.
