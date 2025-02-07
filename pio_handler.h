#ifndef PIO_HANDLER_H
#define PIO_HANDLER_H

#include "hardware/pio.h"

// MACRO
#define LED_PIN 7
#define LED_COUNT 25

// Declaração de funções
void init_leds(void);
void clear_leds(void);
void set_led(int index, uint8_t r, uint8_t g, uint8_t b);
void set_all_leds(uint8_t r, uint8_t g, uint8_t b);
void write_leds(void);

#endif // PIO_HANDLER_H