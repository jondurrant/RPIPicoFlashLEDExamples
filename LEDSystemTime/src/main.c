/**
 * Jon Durrant.
 * Blink LED on Raspberry PICO using System Time strategy
 */

#include "pico/stdlib.h"
#include "pico/types.h"

#define DELAY 500 // in microseconds

uint32_t nextAction = 0;
bool on=true;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void setupBlink(){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void blinkLED(){
	uint32_t now = to_ms_since_boot( get_absolute_time()	);
	if (now > nextAction ){
		gpio_put(LED_PIN, on);
		on = !on;
		nextAction = now + DELAY;
	}
}

int main() {
	setupBlink();
    while (true) { // Loop forever
        blinkLED();
        sleep_ms(DELAY/10);
    }

}
