## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from cadenas.c:12:
cadenas.h:143:1: warning: ‘/*’ within comment [-Wcomment]
  143 | /* =========================================================================
In file included from prueba.c:11:
cadenas.h:143:1: warning: ‘/*’ within comment [-Wcomment]
  143 | /* =========================================================================
In file included from main.c:3:
../../libs/cadenas/cadenas.h:143:1: warning: ‘/*’ within comment [-Wcomment]
  143 | /* =========================================================================
In file included from texto.c:2:
../../libs/cadenas/cadenas.h:143:1: warning: ‘/*’ within comment [-Wcomment]
  143 | /* =========================================================================
In file included from prueba.c:10:
../../libs/cadenas/cadenas.h:143:1: warning: ‘/*’ within comment [-Wcomment]
  143 | /* =========================================================================

```

> 📄 **Salida completa:** registrada en `compilacion_bfd5194.log`.
