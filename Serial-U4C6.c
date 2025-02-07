#include <stdio.h>
#include "pico/stdlib.h"

// PIO Handler
#include "pio_handler.h"

// Display SSD1306
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"

// Constantes
const uint BUTTON_B = 5;
const uint BUTTON_A = 6;
ssd1306_t ssd;

// Macros
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15

// Protótipos
void init_hardware(void);

int main()
{
    init_hardware();

    while (true) {
        

        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

void init_hardware(void) {
    // Inicializa os LEDs
    init_leds();
    stdio_init_all();

    // Inicializa os botões
    gpio_init(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);

    // Inicializa o display
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&ssd, WIDTH, HEIGHT, false, 0x3C, I2C_PORT);
    ssd1306_config(&ssd);
    ssd1306_send_data(&ssd);

    // Limpa o display
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);
}