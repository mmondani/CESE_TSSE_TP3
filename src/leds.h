#include <stdint.h>
#include "errores.h"

void LedsCreate (uint16_t* direccion, logger_t logger);

void LedsOn (int led);

void LedsOff (int led);

void LedsAllOn (void);

void LedsAllOff (void);

int LedsGetState (int led);