/**
 * Jon Durrant.
 * Blink LED on Raspberry PICO using delay strategy
 */

#include "pico/stdlib.h"

#define DELAY 500 // in microseconds

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void setupBlink(){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void blinkLED(){
	gpio_put(LED_PIN, 1);
	sleep_ms(DELAY);
	gpio_put(LED_PIN, 0);
	sleep_ms(DELAY);
}

int main() {
	setupBlink();

    while (true) { // Loop forever
        blinkLED();
    }

}
