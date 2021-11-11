/**
 * Prender todos los leds juntos
 * Apagar todos los leds juntos
 * Consultar el estado de un led apagado
 * Consultar el estado de un led encendido
 * Revisar los límites de los parámetros
 */
#include "unity.h"
#include "leds.h"
//#include "mock_errores.h"
#include <string.h>

#define LED_BIT(x) (1 << (x - 1))

static uint16_t puertoVirtual;
static struct 
{
    int gravedad;
    char funcion[64];
}error;

void RegistrarMensaje (int gravedad, const char* funcion, int linea, const char* mensaje)
{
    error.gravedad = gravedad;
    strcpy(error.funcion, funcion);
}

void setUp (void)
{
    error.gravedad = -1;
    memset(error.funcion, 0, sizeof(error.funcion));
    LedsCreate(&puertoVirtual, RegistrarMensaje);
}

/* Después de la configuración todos los leds deben quedar apagados */
void test_todos_los_leds_inician_apagados (void) 
{
    uint16_t puertoVirtual = 0xFFFF;

    LedsCreate(&puertoVirtual, RegistrarMensaje);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual);
}

/* Prender un led cualquiera */
void test_prender_un_led (void) 
{
    LedsOn(3);

    TEST_ASSERT_EQUAL_HEX16(LED_BIT(3), puertoVirtual);
}


/* Apagar un led cualquiera */
void test_apagar_un_led (void) 
{
    LedsOn(3);
    LedsOff(3);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual);
}

/* Prender y apagar algunos leds */
void test_prender_y_apagar_varios_leds (void)
{
    LedsOn(6);
    LedsOn(3);
    LedsOff(3);

    TEST_ASSERT_EQUAL_HEX16(LED_BIT(6), puertoVirtual);
}

/* Probar valores inválidos para los parámetros */
void test_error_en_parametro_led_on (void) 
{
    //RegistrarMensaje_Expect(0, "LedsOn", 0, "Numero de led invalido");
    //RegistrarMensaje_IgnoreArg_linea();
    LedsOn(17);

    TEST_ASSERT_EQUAL(0, error.gravedad);
    TEST_ASSERT_EQUAL_STRING("LedsOn", error.funcion);
}