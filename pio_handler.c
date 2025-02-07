#include "pio_handler.h"
#include "ws2818b.pio.h"

// MACRO
#define LED_PIN 7
#define LED_COUNT 25

// State Machine
PIO np_pio;
uint sm;
struct pixel_t {
    uint8_t G, R, B;
};
typedef struct pixel_t npLED_t;
npLED_t leds[LED_COUNT];

void init_leds(void) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, true);
    ws2818b_program_init(np_pio, sm, offset, LED_PIN, 800000.f);
    for (int i = 0; i < LED_COUNT; i++) {
        leds[i].R = leds[i].G = leds[i].B = 0;
    }
}

// Limpa os LEDs
void clear_leds(void) {
    for (int i = 0; i < LED_COUNT; i++) {
        leds[i].R = leds[i].G = leds[i].B = 0;
    }
}

// Define a cor de um LED
void set_led(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < LED_COUNT) {
        leds[index].R = r;
        leds[index].G = g;
        leds[index].B = b;
    }
}

// Define a cor de todos os LEDs
void set_all_leds(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < LED_COUNT; i++) {
        leds[i].R = r;
        leds[i].G = g;
        leds[i].B = b;
    }
}

// Escreve os LEDs
void write_leds(void) {
    for (int i = 0; i < LED_COUNT; i++) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
}