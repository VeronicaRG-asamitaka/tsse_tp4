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

/**
 * @file leds.c
 * @brief Definiciones de la biblioteca para el control de LEDs.
 */

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */
/** @brief Máscara para apagar todos los LEDs. */
#define ALL_LEDS_OFF 0x0000
/** @brief Desplazamiento de los LEDs para obtener la máscara. */
#define LED_TO_BIT_OFFSET 1
/** @brief Constante con el primer bit en uno para generar la máscara. */
#define FIRST_BIT 1
/** @brief Constante para obtener el estado de un LED. */
#define BIT_STATUS 1
/** @brief Constante con el valor minimo de bit */
#define BIT_MIN 1
/** @brief Constante con el valor maximo de bit */
#define BIT_MAX 16

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/** @brief Variable privada para almacenar la dirección del puerto de salida. */
static uint16_t * portAdress;
/* === Private function declarations =========================================================== */

/**
 * @brief Funcion privada para convertir el número de un LED a una máscara de bits.
 *
 *@param numberLed Número de LED para el que se desea generar la máscara de bits.
 *@return uint16_t Máscara de bits con 1 en la posición correspondiente al LED.
 */
static uint16_t LedToMask(uint8_t numberLed);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

uint16_t LedToMask(uint8_t numberLed) {
    return (FIRST_BIT << (numberLed - LED_TO_BIT_OFFSET));
}
/* === Public function implementation ========================================================== */

void LedsInit(uint16_t * adressLeds) {
    portAdress = adressLeds;
    LedChangeStateAll(ALL_LEDS_OFF);
}

void LedTurnOnSingle(uint8_t numberLed) {
    if (isLedValid(numberLed)) {
        *portAdress |= LedToMask(numberLed);
    }
}

void LedTurnOffSingle(uint8_t numberLed) {
    if (isLedValid(numberLed)) {
        *portAdress &= ~(LedToMask(numberLed));
    }
}

void LedChangeStateAll(uint16_t stateLeds) {
    *portAdress = stateLeds;
}

uint8_t LedGetState(uint8_t numberLedtoGet) {
    if (isLedValid(numberLedtoGet)) {
        return ((*portAdress >> (numberLedtoGet - LED_TO_BIT_OFFSET)) & BIT_STATUS);
    }
}

uint8_t isLedValid(uint8_t numberLedValid) {
    return (numberLedValid >= BIT_MIN && numberLedValid <= BIT_MAX);
}

/* === End of documentation ==================================================================== */
