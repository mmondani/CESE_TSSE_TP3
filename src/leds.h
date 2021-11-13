#include <stdint.h>
#include "errores.h"

/**
 * @brief Inicializa un puerto para el manejo de leds
 *
 * La función recibe un puntero al puerto que va a manejar los leds. 
 * También recibe un callback que va a ser usado como un logger
 * cuando ocurra alguna condición de error.
 * Luego de llamar a esta función, todos los leds se encontrarán apagados.
 * 
 * @param direccion puntero a la posición de memoria del puerto que maneja los leds
 * @param logger callback a ser llamado cuando se produzca un error en alguna de las funciones
 */
void LedsCreate (uint16_t* direccion, logger_t logger);


/**
 * @brief Enciende un led
 *
 * La función recibe el número de led que debe encender. El led se va a encender poniendo
 * un nivel alto (un 1 lógico) en el puerto configurado con la función LedsCreate.
 * 
 * @param led número de led a encender. Rango: 1 a 16. El 1 corresponde al lsb del puerto
 * y el 16, al msb.
 * 
 * @see LedsCreate
 */
void LedsOn (int led);


/**
 * @brief Apaga un led
 *
 * La función recibe el número de led que debe apagar. El led se va a apagar poniendo
 * un nivel bajo (un 0 lógico) en el puerto configurado con la función LedsCreate.
 * 
 * @param led número de led a apagar. Rango: 1 a 16. El 1 corresponde al lsb del puerto
 * y el 16, al msb.
 * 
 * @see LedsCreate
 */
void LedsOff (int led);


/**
 * @brief Enciende todos los leds
 *
 * La función enciende todos los leds del puerto configurado con la función LedsCreate.
 * 
 * @see LedsCreate
 */
void LedsAllOn (void);


/**
 * @brief Apaga todos los leds
 *
 * La función apaga todos los leds del puerto configurado con la función LedsCreate.
 * 
 * @see LedsCreate
 */
void LedsAllOff (void);


/**
 * @brief Consulta el estado de un led
 *
 * La función permite conocer el estado (encendido o apagado) de cualquiera de los leds.
 * 
 * @param led número de led a consultar. Rango: 1 a 16.
 * 
 * @return 
 * 		\li 	<tt>  0 <\tt>	El led está apagado
 * 		\li 	<tt>  1 <\tt>	El led está encendido
 * 
 * @see LedsCreate
 */
int LedsGetState (int led);