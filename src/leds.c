#include "leds.h"

#define LEDS_ALL_OFF    0x0000
#define LEDS_OFFSET     1
#define LEDS_ON_STATE   1

static uint16_t* puerto;
static logger_t RegistrarMensaje;


uint16_t LedToMask (int led)
{
    return (LEDS_ON_STATE << (led - LEDS_OFFSET));
}


void LedsCreate (uint16_t* direccion, logger_t logger)
{
    puerto = direccion;
    RegistrarMensaje = logger;

    *puerto = LEDS_ALL_OFF;
}

void LedsOn (int led)
{
    if ((led >= 1) && (led <= 16)) 
    {
        *puerto |= LedToMask(led);
    }
    else
    {
        RegistrarMensaje(0, __FUNCTION__, __LINE__, "Numero de led invalido");
    }
    
}

void LedsOff (int led)
{
    *puerto &= ~LedToMask(led);
}