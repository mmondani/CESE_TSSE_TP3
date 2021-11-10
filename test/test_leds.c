/**
 * Después de la configuración todos los leds deben quedar apagados
 * Prender un led cualquiera
 * Apagar un led cualquiera
 * Prender y apagar algunos leds
 * Prender todos los leds juntos
 * Apagar todos los leds juntos
 * Consultar el estado de un led apagado
 * Consultar el estado de un led encendido
 * Revisar los límites de los parámetros
 * Probar valores inválidos para los parámetros
 */
#include "unity.h"
#include "leds.h"

#define LED_BIT(x) (1 << (x - 1))

/* Después de la configuración todos los leds deben quedar apagados */
void test_todos_los_leds_inician_apagados (void) 
{
    uint16_t puertoVirtual = 0xFFFF;

    LedsCreate(&puertoVirtual);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual);
}

/* Prender un led cualquiera */
void test_prender_un_led (void) 
{
    uint16_t puertoVirtual;

    LedsCreate(&puertoVirtual);
    LedsOn(3);

    TEST_ASSERT_EQUAL_HEX16(LED_BIT(3), puertoVirtual);
}