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
 * @file test_led.c
 * @brief Pruebas unitarias de la biblioteca para el control de LEDs
 **/

/**

 */

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
static uint16_t leds_virtuals = 0xFFFF;
static uint16_t all_leds_on = 0xFFFF;
static uint16_t all_leds_off = 0x0000;
static uint8_t led_virtual_four = 4;
static uint8_t led_virtual_six = 6;
static uint8_t led_virtual_eight = 8;
static uint8_t led_virtual = 5;
static uint8_t led_virtual_min = 1;
static uint8_t led_virtual_max = 16;
static uint8_t led_virtual_out_min = 0;
static uint8_t led_virtual_out_max = 17;
/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
void setUp(void) {

    LedsInit(&leds_virtuals);
}

//! * @test 1. Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void) {
    uint16_t leds_virtuals = 0xFFFF;

    LedsInit(&leds_virtuals);
    TEST_ASSERT_EQUAL_HEX16(0x000F, leds_virtuals);
}

//! * @test  2. Prender un LED individual.
void test_encender_led_individual(void) {
    LedTurnOnSingle(led_virtual_four);
    TEST_ASSERT_EQUAL_HEX16(0x0008, leds_virtuals);
}

//! * @test  3. Apagar un LED individual.
void test_apagar_led_individual(void) {
    LedTurnOnSingle(led_virtual_four);
    LedTurnOffSingle(led_virtual_four);
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuals);
}

//! * @test  4. Prender y apagar múltiples LED’s.
void test_encender_y_apagar_multiples_leds(void) {
    LedTurnOnSingle(led_virtual_four);
    LedTurnOnSingle(led_virtual_six);

    LedTurnOffSingle(led_virtual_four);
    LedTurnOffSingle(led_virtual_eight);

    TEST_ASSERT_EQUAL_HEX16(0x0020, leds_virtuals);
}

//! * @test  5. Prender todos los LEDs de una vez.
void test_prender_todos_los_leds(void) {
    LedChangeStateAll(all_leds_on);

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, leds_virtuals);
}

//! * @test  6. Apagar todos los LEDs de una vez.
void test_apagar_todos_los_leds(void) {
    LedChangeStateAll(all_leds_on);
    LedChangeStateAll(all_leds_off);

    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuals);
}

//! * @test  7. Consultar el estado de un LED que está encendido
void test_consultar_estado_led_encendido(void) {
    LedTurnOnSingle(led_virtual);

    TEST_ASSERT_EQUAL(1, LedGetState(led_virtual));
}

//!* @test  8. Consultar el estado de un LED que est apagado
void test_consultar_estado_led_apagado(void) {
    LedTurnOnSingle(led_virtual);
    LedTurnOffSingle(led_virtual);

    TEST_ASSERT_EQUAL(0, LedGetState(led_virtual));
}

//! * @test  9. Revisar limites de los parametros.
void test_limites_parametros(void) {

    TEST_ASSERT_EQUAL(1, isLedValid(led_virtual_min));
    TEST_ASSERT_EQUAL(1, isLedValid(led_virtual_max));
}
//! * @test  10. Revisar parámetros fuera de los limites.
void test_parametros_fuera_de_limites(void) {
    TEST_ASSERT_EQUAL(0, isLedValid(led_virtual_out_min));
    TEST_ASSERT_EQUAL(0, isLedValid(led_virtual_out_max));
}

/* === End of documentation ==================================================================== */
