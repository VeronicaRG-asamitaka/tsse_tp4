/************************************************************************************************
Copyright (c) 2025, Veronica Ruiz Galvan <veronica.ruizgalvan@hotmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/
#ifndef LEDS_H
#define LEDS_H

/**
 * @file leds.h
 * @brief Declaraciones de la biblioteca para el control de LEDs.
 */

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Funcion para inicializar la biblioteca de LEDs
 *
 * @note Esta funcion debe ser llamada antes de utilizar cualquier otra funcion de la biblioteca.
 *
 * @param leds Puntero al puerto GPIO que controla los LEDs.
 *
 */

void LedsInit(uint16_t * adressLeds);

/**
 * @brief Funcion para encender un LED individual
 *
 * @param numberLed Numero de LED que se desea encender (1-16).
 *
 */

void LedTurnOnSingle(uint8_t numberLed);

/**
 * @brief Funcion para apagar un LED individual
 *
 * @param numberLed Numero de LED que se desea apagar (1-16).
 *
 */

void LedTurnOffSingle(uint8_t numberLed);

/**
 * @brief Funcion para cambiar el estado de todos los LEDs
 *
 * @param stateLeds Estado al que se quieren cambiar todos los LEDs (0x0000 o 0xFFFF)
 *
 */
void LedChangeStateAll(uint16_t stateLeds);

/**
 * @brief Funcion para obtener el estado de un LED
 *
 * @param numberLedtoGet Numero de LED del cual se quiere obtener su estado (1-16)
 *
 */
uint8_t LedGetState(uint8_t numberLedtoGet);

/**
* @brief Funcion para comprobar si el número de LED está dentro de rango válido.
*
*@param numberLedValid Número de LED.

*@return uint16_t Regresa 1 si es válido, 0 si es inválido.
*
*/
uint8_t isLedValid(uint8_t numberLedValid);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */
