#include "leds.h"

#define LEDS_ALL_OFF 0x0000

static uint16_t* puerto;

void LedsCreate (uint16_t* direccion)
{
    puerto = direccion;
    *puerto = LEDS_ALL_OFF;
}

void LedsOn (int led)
{
    *puerto |= (1 << (led -1));
}

void LedsOff (int led)
{
    *puerto &= ~(1 << (led - 1));
}