CESE - TSSE: TP3 - TDD
=======================

Este repositorio contiene la implementación de un driver para el manejo de leds, utilizando Test Driven Development (TDD)

## Requisitos

El driver implementado debe cumplir los siguientes requisitos

- Maneja 16 leds de dos estados (encendido y apagado).
- Se puede cambiar el estado de un led sin afectar a los otros.
- Se puede cambiar el estado de todos los led’s en una sola
operación.
- Se puede recuperar el estado actual de un led.
- Los led’s están mapeados en una palabra de 16 bits en
memoria en una dirección a determinar.
- Para encender el led se debe escribir un “1” en el bit y para
apagarlo se debe escribir un “0”.
- El led 1 corresponde al lsb y el led 16 al msb.
- El reset de hardware no define un estado conocido de los
led’s, estos deben ser apagados por software.