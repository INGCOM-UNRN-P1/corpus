#include <assert.h>
#include <stdbool.h>
#include <stdio.h>


#include "cajero.h"

static void probar_monto_valido_positivos_multiplos(void)
{
    assert(es_monto_valido(100));
    assert(es_monto_valido(200));
    assert(es_monto_valido(500));
    assert(es_monto_valido(1000));
    assert(es_monto_valido(2000));
    assert(es_monto_valido(5000));
    assert(es_monto_valido(7300));
    assert(es_monto_valido(10000));
    assert(es_monto_valido(20000));
    assert(es_monto_valido(38800));
    assert(es_monto_valido(40000));
    assert(es_monto_valido(100000));
}

static void probar_monto_invalido_no_positivos(void)
{
    assert(!es_monto_valido(0));
    assert(!es_monto_valido(-1));
    assert(!es_monto_valido(-100));
    assert(!es_monto_valido(-500));
    assert(!es_monto_valido(-1000));
    assert(!es_monto_valido(-38800));
}

static void probar_monto_invalido_no_multiplos(void)
{
    assert(!es_monto_valido(1));
    assert(!es_monto_valido(50));
    assert(!es_monto_valido(99));
    assert(!es_monto_valido(101));
    assert(!es_monto_valido(150));
    assert(!es_monto_valido(999));
    assert(!es_monto_valido(1050));
    assert(!es_monto_valido(7350));
    assert(!es_monto_valido(38801));
    assert(!es_monto_valido(38850));
}

static void probar_calcular_cantidad_billetes(void)
{
    
    assert(calcular_cantidad_billetes(20000, BILLETE_20000) == 1);
    assert(calcular_cantidad_billetes(40000, BILLETE_20000) == 2);
    assert(calcular_cantidad_billetes(60000, BILLETE_20000) == 3);
    assert(calcular_cantidad_billetes(10000, BILLETE_10000) == 1);
    assert(calcular_cantidad_billetes(20000, BILLETE_10000) == 2);
    assert(calcular_cantidad_billetes(5000, BILLETE_5000) == 1);
    assert(calcular_cantidad_billetes(2000, BILLETE_2000) == 1);
    assert(calcular_cantidad_billetes(1000, BILLETE_1000) == 1);
    assert(calcular_cantidad_billetes(500, BILLETE_500) == 1);
    assert(calcular_cantidad_billetes(200, BILLETE_200) == 1);
    assert(calcular_cantidad_billetes(100, BILLETE_100) == 1);

    
    assert(calcular_cantidad_billetes(10000, BILLETE_20000) == 0);
    assert(calcular_cantidad_billetes(1000, BILLETE_5000) == 0);
    assert(calcular_cantidad_billetes(50, BILLETE_100) == 0);
    assert(calcular_cantidad_billetes(0, BILLETE_100) == 0);

    
    assert(calcular_cantidad_billetes(38800, BILLETE_20000) == 1);
    assert(calcular_cantidad_billetes(18800, BILLETE_10000) == 1);
    assert(calcular_cantidad_billetes(8800, BILLETE_5000) == 1);
    assert(calcular_cantidad_billetes(3800, BILLETE_2000) == 1);
    assert(calcular_cantidad_billetes(1800, BILLETE_1000) == 1);
    assert(calcular_cantidad_billetes(800, BILLETE_500) == 1);
    assert(calcular_cantidad_billetes(300, BILLETE_200) == 1);
    assert(calcular_cantidad_billetes(100, BILLETE_100) == 1);
}

static void probar_calcular_resto_monto(void)
{
    
    assert(calcular_resto_monto(20000, BILLETE_20000) == 0);
    assert(calcular_resto_monto(40000, BILLETE_20000) == 0);
    assert(calcular_resto_monto(10000, BILLETE_10000) == 0);
    assert(calcular_resto_monto(5000, BILLETE_5000) == 0);
    assert(calcular_resto_monto(2000, BILLETE_2000) == 0);
    assert(calcular_resto_monto(1000, BILLETE_1000) == 0);
    assert(calcular_resto_monto(500, BILLETE_500) == 0);
    assert(calcular_resto_monto(200, BILLETE_200) == 0);
    assert(calcular_resto_monto(100, BILLETE_100) == 0);

    
    assert(calcular_resto_monto(10000, BILLETE_20000) == 10000);
    assert(calcular_resto_monto(50, BILLETE_100) == 50);
    assert(calcular_resto_monto(0, BILLETE_100) == 0);

    
    assert(calcular_resto_monto(38800, BILLETE_20000) == 18800);
    assert(calcular_resto_monto(18800, BILLETE_10000) == 8800);
    assert(calcular_resto_monto(8800, BILLETE_5000) == 3800);
    assert(calcular_resto_monto(3800, BILLETE_2000) == 1800);
    assert(calcular_resto_monto(1800, BILLETE_1000) == 800);
    assert(calcular_resto_monto(800, BILLETE_500) == 300);
    assert(calcular_resto_monto(300, BILLETE_200) == 100);
    assert(calcular_resto_monto(100, BILLETE_100) == 0);
}

static void probar_desglose_secuencial_38800(void)
{
    int monto = 38800;
    int b20k = calcular_cantidad_billetes(monto, BILLETE_20000);
    monto = calcular_resto_monto(monto, BILLETE_20000);

    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
    monto = calcular_resto_monto(monto, BILLETE_10000);

    int b5k = calcular_cantidad_billetes(monto, BILLETE_5000);
    monto = calcular_resto_monto(monto, BILLETE_5000);

    int b2k = calcular_cantidad_billetes(monto, BILLETE_2000);
    monto = calcular_resto_monto(monto, BILLETE_2000);

    int b1k = calcular_cantidad_billetes(monto, BILLETE_1000);
    monto = calcular_resto_monto(monto, BILLETE_1000);

    int b500 = calcular_cantidad_billetes(monto, BILLETE_500);
    monto = calcular_resto_monto(monto, BILLETE_500);

    int b200 = calcular_cantidad_billetes(monto, BILLETE_200);
    monto = calcular_resto_monto(monto, BILLETE_200);

    int b100 = calcular_cantidad_billetes(monto, BILLETE_100);
    monto = calcular_resto_monto(monto, BILLETE_100);

    assert(b20k == 1);
    assert(b10k == 1);
    assert(b5k == 1);
    assert(b2k == 1);
    assert(b1k == 1);
    assert(b500 == 1);
    assert(b200 == 1);
    assert(b100 == 1);
    assert(monto == 0);
}

static void probar_desglose_secuencial_7300(void)
{
    int monto = 7300;
    int b20k = calcular_cantidad_billetes(monto, BILLETE_20000);
    monto = calcular_resto_monto(monto, BILLETE_20000);

    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
    monto = calcular_resto_monto(monto, BILLETE_10000);

    int b5k = calcular_cantidad_billetes(monto, BILLETE_5000);
    monto = calcular_resto_monto(monto, BILLETE_5000);

    int b2k = calcular_cantidad_billetes(monto, BILLETE_2000);
    monto = calcular_resto_monto(monto, BILLETE_2000);

    int b1k = calcular_cantidad_billetes(monto, BILLETE_1000);
    monto = calcular_resto_monto(monto, BILLETE_1000);

    int b500 = calcular_cantidad_billetes(monto, BILLETE_500);
    monto = calcular_resto_monto(monto, BILLETE_500);

    int b200 = calcular_cantidad_billetes(monto, BILLETE_200);
    monto = calcular_resto_monto(monto, BILLETE_200);

    int b100 = calcular_cantidad_billetes(monto, BILLETE_100);
    monto = calcular_resto_monto(monto, BILLETE_100);

    assert(b20k == 0);
    assert(b10k == 0);
    assert(b5k == 1);
    assert(b2k == 1);
    assert(b1k == 0);
    assert(b500 == 0);
    assert(b200 == 1);
    assert(b100 == 1);
    assert(monto == 0);
}

static void probar_desglose_secuencial_40000(void)
{
    int monto = 40000;
    int b20k = calcular_cantidad_billetes(monto, BILLETE_20000);
    monto = calcular_resto_monto(monto, BILLETE_20000);

    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
    monto = calcular_resto_monto(monto, BILLETE_10000);

    int b5k = calcular_cantidad_billetes(monto, BILLETE_5000);
    monto = calcular_resto_monto(monto, BILLETE_5000);

    int b2k = calcular_cantidad_billetes(monto, BILLETE_2000);
    monto = calcular_resto_monto(monto, BILLETE_2000);

    int b1k = calcular_cantidad_billetes(monto, BILLETE_1000);
    monto = calcular_resto_monto(monto, BILLETE_1000);

    int b500 = calcular_cantidad_billetes(monto, BILLETE_500);
    monto = calcular_resto_monto(monto, BILLETE_500);

    int b200 = calcular_cantidad_billetes(monto, BILLETE_200);
    monto = calcular_resto_monto(monto, BILLETE_200);

    int b100 = calcular_cantidad_billetes(monto, BILLETE_100);
    monto = calcular_resto_monto(monto, BILLETE_100);

    assert(b20k == 2);
    assert(b10k == 0);
    assert(b5k == 0);
    assert(b2k == 0);
    assert(b1k == 0);
    assert(b500 == 0);
    assert(b200 == 0);
    assert(b100 == 0);
    assert(monto == 0);
}

int main(void)
{
    probar_monto_valido_positivos_multiplos();
    probar_monto_invalido_no_positivos();
    probar_monto_invalido_no_multiplos();
    probar_calcular_cantidad_billetes();
    probar_calcular_resto_monto();
    probar_desglose_secuencial_38800();
    probar_desglose_secuencial_7300();
    probar_desglose_secuencial_40000();
    printf("Todos los tests de cajero pasaron correctamente.\n");
    return 0;
}
